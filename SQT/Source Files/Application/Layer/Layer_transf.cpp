#include "Layer.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Fonction/Fonction.h"

#include "LayerUndo.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

void Layer::move() {
	if (INPUT->again(Qt::RightButton)) {
		posi = INPUT->getPixel();
		posf = getPosition();
	}

	if (INPUT->pressed(Qt::RightButton)) {
		sf::Vector2f move;
		if (INPUT->pressed(Qt::Key_Control)) {
			sf::Vector2f pos_mouse = Fonction::selecPointRect(VECTOR2F(posi), VECTOR2F(INPUT->getDeltaPixel())).distance;
			pos_mouse = CALL_VECTOR2F(pos_mouse, floor);
			move = pos_mouse + posf;
			setPosition(move);
		}
		else
			translate(VECTOR2F(INPUT->getDeltaPixel()));
	}
	else if (INPUT->released(Qt::RightButton))
		if (getPosition() != posf)
			UNDO->push(new LayerMoved(this, getPosition()));
}

void Layer::grand() {
	CURSEUR->gerer(&sprite);

	if (INPUT->again(Qt::LeftButton)) {
		CURSEUR->init(&sprite);
		posf = VECTOR2F(INPUT->getPixel());
	}

	if (INPUT->pressed(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Control)) {
			int max_size = std::max(sprite.getTextureRect().width, sprite.getTextureRect().height);
			sf::Vector2f pos_mouse = Fonction::selecPointRect(posf, VECTOR2F(INPUT->getPixel())).distance;
			setScale(sf::Vector2f(1.f + pos_mouse.x / max_size, 1.f + pos_mouse.y / max_size));
		}
		else
			setScale(sf::Vector2f(1.f + (INPUT->getPixel().x - posf.x) / this->getSize().x, 1.f + (INPUT->getPixel().y - posf.y) / this->getSize().y));
	}
	else if (INPUT->released(Qt::LeftButton)) {
		sf::Vector2f scale = sprite.getScale();
		sf::Texture text = renderTexture.getTexture();
		sf::Sprite spr(text);

		renderTexture.create(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		renderTexture.clear(sf::Color::Transparent);

		spr.setPosition(sprite.getPosition().x - sprite.getGlobalBounds().left, sprite.getPosition().y - sprite.getGlobalBounds().top);
		spr.setScale(scale);
		spr.setOrigin(sprite.getOrigin());

		renderTexture.draw(spr, sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);
		
		UNDO->beginMacro();
		update();
		UNDO->push(new LayerMoved(this, sf::Vector2f(0, 0)));
		UNDO->endMacro();

		sprite.setOrigin(0, 0);
		sprite.setPosition(0, 0);
		sprite.setScale(1, 1);

		sf::FloatRect bounds = sprite.getGlobalBounds();
		emit layerMoved(sf::Vector2f(bounds.left, bounds.top));
		emit layerScaled(sf::Vector2f(bounds.width, bounds.height));
	}
}

void Layer::rotation() {
	CURSEUR->gerer(&sprite);

	if (INPUT->again(Qt::LeftButton)) {
		CURSEUR->init(&sprite);
		angle_ini = atan2(INPUT->getPosition().y - sprite.getPosition().y, INPUT->getPosition().x - sprite.getPosition().x);
	}

	if (INPUT->pressed(Qt::LeftButton)) {
		float angle;
		if (INPUT->pressed(Qt::Key_Control)) {
			sf::Vector2f pos_mouse = Fonction::selecPointRect(sprite.getPosition(), INPUT->getPosition()).distance;
			angle = atan2(pos_mouse.y, pos_mouse.x);
			setRotation(Fonction::radToDeg(angle));
		}
		else {
			angle = atan2(INPUT->getPosition().y - sprite.getPosition().y, INPUT->getPosition().x - sprite.getPosition().x);
			setRotation(Fonction::radToDeg(angle - angle_ini));
		}
	}
	else if (INPUT->released(Qt::LeftButton)) {
		float angle = sprite.getRotation();

		sf::Texture text = renderTexture.getTexture();
		sf::Sprite spr(text);
		spr.setOrigin(sprite.getOrigin());
		spr.setRotation(angle);
		spr.setPosition(sprite.getPosition().x - sprite.getGlobalBounds().left, sprite.getPosition().y - sprite.getGlobalBounds().top);

		renderTexture.create(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(spr, sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);

		UNDO->beginMacro();
		update();
		UNDO->push(new LayerMoved(this, sf::Vector2f(0, 0)));
		UNDO->endMacro();

		sprite.setOrigin(0, 0);
		sprite.setPosition(0, 0);
		sprite.setRotation(0);
		
		sf::FloatRect bounds = sprite.getGlobalBounds();
		emit layerMoved(sf::Vector2f(bounds.left, bounds.top));
		emit layerScaled(sf::Vector2f(bounds.width, bounds.height));
	}
}

void Layer::flip() {
	if (INPUT->again(Qt::LeftButton) || INPUT->again(Qt::RightButton)) {
		sf::Image image = renderTexture.getTexture().copyToImage();
		
		if (INPUT->again(Qt::LeftButton))
			image.flipHorizontally();
		else
			image.flipVertically();

		sf::Texture texture;
		texture.loadFromImage(image);

		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();
		
		update();
	}
}