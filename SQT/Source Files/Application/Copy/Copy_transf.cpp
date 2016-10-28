#include "Copy.h"

#include "CopyUndo.h"
#include "CopyController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Application/Input/ShortcutController.h"

void Copy::move() {
	if (INPUT->again(Qt::RightButton)) {
		pos_init = Fonction::centerCorner(sprite_copy);
		posf = sprite_copy.getPosition();
	}

	if (INPUT->pressed(Qt::RightButton)) {
		sf::Vector2f final_pos;
			if (INPUT->pressed(Qt::Key_Control)) {
				sf::Vector2f pos_mouse = Fonction::selecPointRect(pos_init, INPUT->getPosition()).distance;
				pos_mouse = CALL_VECTOR2F(pos_mouse, floor);
				final_pos = pos_mouse + posf;
				setPosition(final_pos);
			}
			else
				translate(VECTOR2F(INPUT->getDeltaPixel()));
	}
	else if (INPUT->released(Qt::RightButton))
		if (getPosition() != posf)
			UNDO->push(*new CopyMoved(this, POS_RECT(sprite_copy.getGlobalBounds())));
}

void Copy::keyMove(const sf::Vector2f& delta) {
	translate(delta);
	SHORTCUT_CONTROLLER->createCoreShortcutOnce(nInt::keyCombinaison(Qt::Key_Shift, nInt::RELEASED), [](){
		UNDO->push(*new CopyMoved(COPY, POS_RECT(COPY->sprite_copy.getGlobalBounds())));
	});
}

void Copy::grand() {
	CURSEUR->gerer(sprite_copy);

	if (INPUT->again(Qt::LeftButton)) {
		CURSEUR->init(sprite_copy);
		posf2 = sprite_copy.getScale();
		posf = INPUT->getPosition();
	}

	if (INPUT->pressed(Qt::LeftButton)) {
		sf::Vector2f temp;
		sf::Vector2f dist_ini;
		float angle = Fonction::degToRad(sprite_copy.getRotation());

		if (INPUT->pressed(Qt::Key_Control)) {
			if (int(sprite_copy.getRotation()) == sprite_copy.getRotation() && int(sprite_copy.getRotation()) % 90 == 0) {
				temp = Fonction::selecPointRect(CURSEUR->getPosition(), INPUT->getPosition()).distance;
				dist_ini = Fonction::selecPointRect(CURSEUR->getPosition(), posf).distance;

				if (std::abs(temp.x) == 0) temp.x = dist_ini.x;
				if (std::abs(temp.y) == 0) temp.y = dist_ini.y;
				if (std::abs(dist_ini.x) == 0) dist_ini.x = temp.x;
				if (std::abs(dist_ini.y) == 0) dist_ini.y = temp.y;
			}
			else {
				temp = INPUT->getPosition() - CURSEUR->getPosition();
				dist_ini = posf - CURSEUR->getPosition();

				float max = std::max(std::abs(temp.x), std::abs(temp.y));
				temp.x = max;
				temp.y = max;

				max = std::max(std::abs(dist_ini.x), std::abs(dist_ini.y));
				dist_ini.x = max;
				dist_ini.y = max;
			}
		}
		else {
			temp = INPUT->getPosition() - CURSEUR->getPosition();
			dist_ini = posf - CURSEUR->getPosition();
		}

		temp = Fonction::rotationLocal(temp, -angle);
		dist_ini = Fonction::rotationLocal(dist_ini, -angle);

		setScale(sf::Vector2f(static_cast<double>(temp.x) / static_cast<double>(dist_ini.x) * static_cast<double>(posf2.x),
							  static_cast<double>(temp.y) / static_cast<double>(dist_ini.y) * static_cast<double>(posf2.y)));
	}
	else if (INPUT->released(Qt::LeftButton)) 
		UNDO->push(*new CopyScaled(this, POS_RECT(sprite_copy.getGlobalBounds()), sprite_copy.getScale(), sprite_copy.getOrigin()));
}

void Copy::rotation() {
	CURSEUR->gerer(sprite_copy);

	if (INPUT->again(Qt::LeftButton)) {
		CURSEUR->init(sprite_copy);
		angle_ini = -Fonction::degToRad(sprite_copy.getRotation()) + atan2(INPUT->getPosition().y - sprite_copy.getPosition().y, 
																		   INPUT->getPosition().x - sprite_copy.getPosition().x);
	}

	if (INPUT->pressed(Qt::LeftButton)) {
		float angle = atan2(INPUT->getPosition().y - sprite_copy.getPosition().y, 
							INPUT->getPosition().x - sprite_copy.getPosition().x);
		if (INPUT->pressed(Qt::Key_Control)) {
			sf::Vector2f pos_mouse = Fonction::selecPointRect(sprite_copy.getPosition(), INPUT->getPosition()).distance;
			angle = atan2(pos_mouse.y, pos_mouse.x);
			setRotation(Fonction::radToDeg(angle));
		}
		else {
			angle = atan2(INPUT->getPosition().y - sprite_copy.getPosition().y, 
						  INPUT->getPosition().x - sprite_copy.getPosition().x);
			setRotation(Fonction::radToDeg(angle - angle_ini));
		}
	}
	else if (INPUT->released(Qt::LeftButton)) 
		UNDO->push(*new CopyRotated(this, POS_RECT(sprite_copy.getGlobalBounds()), sprite_copy.getRotation(), sprite_copy.getOrigin()));
}

void Copy::flip() {
	if (INPUT->again(Qt::LeftButton) || INPUT->again(Qt::RightButton)) {
		if (INPUT->again(Qt::LeftButton))
			Fonction::flipHorizontally(sprite_copy);
		else
			Fonction::flipVertically(sprite_copy);

		UNDO->push(*new CopyFlipped(this, POS_RECT(sprite_copy.getGlobalBounds()), sprite_copy.getScale()));
	}
}