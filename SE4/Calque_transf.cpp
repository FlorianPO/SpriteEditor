#include "BoutonSwitch.h"
#include "Retour.h"
#include "Input.h"
#include "Var.h"
#include "Curseur.h"
#include "Gui.h"
#include "Fonction.h"

void CCalque::move()
{
	if (IO->pressed(CInput::MRight) || IO->isZQSD() && !IO->isCMA())
	{
		if (!clicked)
		{
			posi = IO->getPixel();
			posf = sprite.getPosition();
			clicked = true;
		}

		sf::Vector2f move;
		if (!IO->isZQSD())
		{
			if (IO->pressed(CInput::Ctrl))
			{
				sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(posi.x, posi.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
				pos_mouse.x = floor(pos_mouse.x);
				pos_mouse.y = floor(pos_mouse.y);
				move.x = pos_mouse.x + posf.x;
				move.y = pos_mouse.y + posf.y;
				sprite.setPosition(move);
			}
			else
				sprite.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
		}
		else
		{
			if (IO->log(CInput::Z)) move.y = -1;
			if (IO->log(CInput::D)) move.x = 1;
			if (IO->log(CInput::S)) move.y = 1;
			if (IO->log(CInput::Q)) move.x = -1;
			sprite.move(move);
		}
	}
	else if (clicked)
	{
		RETOUR->add_retour({this});
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::grand()
{
	CURSEUR->gerer(&sprite);

	if (IO->pressed(CInput::MLeft))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite);
			posf.x = IO->getPixel().x;
			posf.y = IO->getPixel().y;
		}
		if (IO->pressed(CInput::Ctrl))
		{
			int max_size = std::max(sprite.getTextureRect().width, sprite.getTextureRect().height);
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(posf.x, posf.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
			sprite.setScale(1.f + pos_mouse.x / max_size, 1.f + pos_mouse.y / max_size);
		}
		else
			sprite.setScale(1.f + (IO->getPixel().x - posf.x) / _t->getSize().x, 1.f + (IO->getPixel().y - posf.y) / _t->getSize().y);
	}
	else if (clicked)
	{
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

		sprite.setScale(1, 1);
		refresh = true;

		RETOUR->add_retour({this, this});
		creer_retour(getImage(), ACT);
		sprite.setPosition(0, 0);
		sprite.setOrigin(0, 0);
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::rotation()
{
	CURSEUR->gerer(&sprite);

	if (IO->pressed(CInput::MLeft))
	{
		float angle;
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite);
			angle_ini = atan2(IO->getPosition().y - sprite.getPosition().y, IO->getPosition().x - sprite.getPosition().x);
		}
		if (IO->pressed(CInput::Ctrl))
		{
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sprite.getPosition(), IO->getPosition());
			angle = atan2(pos_mouse.y, pos_mouse.x);
			sprite.setRotation(-angle * 180 / VAR->PI);
		}
		else
		{
			angle = atan2(IO->getPosition().y - sprite.getPosition().y, IO->getPosition().x - sprite.getPosition().x);
			sprite.setRotation((angle - angle_ini) * 180 / VAR->PI);
		}
	}
	else if (clicked)
	{
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
		refresh = true;

		RETOUR->add_retour({this, this});
		creer_retour(getImage(), ACT);
		sprite.setOrigin(0, 0);
		sprite.setPosition(0, 0);
		sprite.setRotation(0);
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::flip()
{
	if (IO->again(CInput::MLeft) || IO->again(CInput::MRight))
	{
		sf::Image image = renderTexture.getTexture().copyToImage();
		if (IO->again(CInput::MLeft))
			image.flipHorizontally();
		else
			image.flipVertically();

		sf::Texture texture;
		texture.loadFromImage(image);

		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();
		refresh = true;
		RETOUR->add_retour({this});
		creer_retour(getImage(), ACT);
	}
}