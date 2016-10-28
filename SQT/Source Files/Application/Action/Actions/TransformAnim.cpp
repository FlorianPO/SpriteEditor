#include "TransformAnim.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Animation/Animation.h"
#include "Source Files/Application/Curseur/Curseur.h"

TransformAnim::TransformAnim(Animation& anim) {
	this->anim = &anim;
}

void TransformAnim::use() {
	if (INPUT->pressed(Qt::RightButton))
		move();
	else if (INPUT->pressed(Qt::LeftButton))
		grand();

	if (INPUT->again(Qt::Key_Space))
		emit ended();
}

void TransformAnim::move() {
	if (INPUT->again(Qt::RightButton)) {
		pos_init = Fonction::centerCorner(anim->getSprite());
		posf = anim->getSprite().getPosition();
	}

	if (INPUT->pressed(Qt::RightButton)) {
		if (INPUT->pressed(Qt::Key_Control)) {
			sf::Vector2f final_pos;
			sf::Vector2f pos_mouse = Fonction::selecPointRect(pos_init, INPUT->getPosition()).distance;
			pos_mouse = CALL_VECTOR2F(pos_mouse, floor);
			final_pos = pos_mouse + posf;
			anim->setOffsetPosition(final_pos);
		}
		else
			anim->setOffsetPosition(anim->getSprite().getPosition() + VECTOR2F(INPUT->getDeltaPixel()));
	}
}

void TransformAnim::grand() {
	if (INPUT->again(Qt::LeftButton)) {
		posf2 = anim->getSprite().getScale();
		posf = INPUT->getPosition();
		posf3 = anim->getSprite().getPosition();
	}

	if (INPUT->pressed(Qt::LeftButton)) {
		sf::Vector2f temp;
		sf::Vector2f dist_ini;

		if (INPUT->pressed(Qt::Key_Control)) {
			temp = Fonction::selecPointRect(CURSEUR->getPosition(), INPUT->getPosition()).distance;
			dist_ini = Fonction::selecPointRect(CURSEUR->getPosition(), posf).distance;

			if (std::abs(temp.x) == 0) temp.x = dist_ini.x;
			if (std::abs(temp.y) == 0) temp.y = dist_ini.y;
			if (std::abs(dist_ini.x) == 0) dist_ini.x = temp.x;
			if (std::abs(dist_ini.y) == 0) dist_ini.y = temp.y;
		}
		else {
			temp = INPUT->getPosition() - posf3;
			dist_ini = posf - posf3;
		}

		DEBUGN("loooool : " << temp.x << "   " << dist_ini.x << "    " << posf2.x)
		anim->setOffsetScale(static_cast<double>(temp.x) / static_cast<double>(dist_ini.x) * static_cast<double>(posf2.x));
	}
}