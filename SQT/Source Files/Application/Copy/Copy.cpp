#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Var/Var.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Res/Res.h"

CCopy::CCopy(const sf::Image& image, sf::Vector2f position)
{
	clicked = false;

	texture_copy.loadFromImage(image);
	sprite_copy.setTexture(texture_copy, true);

	sprite_copy.setPosition(position);
	rect_copy = CFonction::FloatRectToIntRect(sprite_copy.getGlobalBounds());

	lines = sf::VertexArray(sf::LinesStrip, 5);
	setPosLines();

	/*
	i_retour_type = -1;
	i_retour_pos = -1;
	i_retour_taille = -1;
	i_retour_rotation = -1;
	i_retour_origin = -1;

	RETOUR->add_retour({this});
	creer_retour(CRE);
	creer_retour(MOV);
	*/
}

void CCopy::setPosLines()
{
	lines[0].position = sf::Vector2f(0, 0);
	lines[1].position = sf::Vector2f(texture_copy.getSize().x * sprite_copy.getScale().x, 0);
	lines[2].position = sf::Vector2f(texture_copy.getSize().x * sprite_copy.getScale().x, texture_copy.getSize().y * sprite_copy.getScale().y);
	lines[3].position = sf::Vector2f(0, texture_copy.getSize().y * sprite_copy.getScale().y);

	float angle = -sprite_copy.getRotation() / 180 * VAR->PI;
	for (int i = 0; i < 4; i++)
	{
		sf::Vector2f temp = lines[i].position - sf::Vector2f(sprite_copy.getOrigin().x*sprite_copy.getScale().x, sprite_copy.getOrigin().y*sprite_copy.getScale().y);
		lines[i].position.x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
		lines[i].position.y = temp.y*std::cos(angle) - temp.x*std::sin(angle);

		lines[i].position += sprite_copy.getPosition();
	}

	lines[4].position = lines[0].position;
}

void CCopy::move()
{
	if (IO->pressed(Qt::RightButton) || IO->isZQSD() && !IO->isCMA())
	{
		if (!clicked)
		{
			posf = sprite_copy.getPosition();
			clicked = true;
		}

		sf::Vector2f move;
		if (!IO->isZQSD())
			if (IO->pressed(Qt::Key_Control))
			{
				if (IO->again(Qt::Key_Control))
				{
					posf = sprite_copy.getPosition();
					posf2 = CFonction::centerCorner(sprite_copy);
					IO->setMousePosition(CFonction::screened(posf2));
				}
				sf::Vector2f pos_mouse = CFonction::selecPointRect(posf2, IO->getPosition()).distance;
				pos_mouse.x = floor(pos_mouse.x);
				pos_mouse.y = floor(pos_mouse.y);
				move.x = pos_mouse.x + posf.x;
				move.y = pos_mouse.y + posf.y;
				sprite_copy.setPosition(move);
			}
			else
				sprite_copy.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
		setPosLines();
		rect_copy = CFonction::FloatRectToIntRect(sprite_copy.getGlobalBounds());
	}
	else
	{
		if (IO->pressed(Qt::LeftButton) || IO->pressed(Qt::Key_Enter) || IO->pressed(Qt::Key_Space))
			apply();
		else if (clicked)
		{
			//RETOUR->add_retour({this});
			//creer_retour(MOV);
			clicked = false;
		}
	}
}

void CCopy::grand()
{
	CURSEUR->gerer(&sprite_copy);

	if (IO->pressed(Qt::LeftButton))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite_copy);
			posf2 = sprite_copy.getScale();
			posf = IO->getPosition();
		}

		sf::Vector2f temp;
		sf::Vector2f dist_ini;
		float angle = sprite_copy.getRotation() / 180 * VAR->PI;

		if (IO->pressed(Qt::Key_Control)) {
			if (int(sprite_copy.getRotation()) == sprite_copy.getRotation() && int(sprite_copy.getRotation())%90 == 0)
			{
				temp = CFonction::selecPointRect(CURSEUR->getPosition(), IO->getPosition(), -1).distance;
				dist_ini = CFonction::selecPointRect(CURSEUR->getPosition(), posf, -1).distance;

				if (std::abs(temp.x) == 0) temp.x = dist_ini.x;
				if (std::abs(temp.y) == 0) temp.y = dist_ini.y;
				if (std::abs(dist_ini.x) == 0) dist_ini.x = temp.x;
				if (std::abs(dist_ini.y) == 0) dist_ini.y = temp.y;
			}
			else {
				temp = IO->getPosition() - CURSEUR->getPosition();
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
			temp = IO->getPosition() - CURSEUR->getPosition();
			dist_ini = posf - CURSEUR->getPosition();
		}

		temp = CFonction::rotationLocal(temp, -angle);
		dist_ini = CFonction::rotationLocal(dist_ini, -angle);

		sprite_copy.setScale(sf::Vector2f(static_cast<double>(temp.x) / static_cast<double>(dist_ini.x) * static_cast<double>(posf2.x), 
										static_cast<double>(temp.y) / static_cast<double>(dist_ini.y) * static_cast<double>(posf2.y)));
		setPosLines();
	}
	else
	{
		if (IO->pressed(Qt::Key_Enter) || IO->pressed(Qt::Key_Space))
			apply();
		else if (clicked)
		{
			//RETOUR->add_retour({this});
			//creer_retour(GRA);

			clicked = false;
			posf2 = sprite_copy.getScale();
			posf2 -= sf::Vector2f(1, 1);
		}
	}
}

void CCopy::rotation()
{
	CURSEUR->gerer(&sprite_copy);

	if (IO->pressed(Qt::LeftButton))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite_copy);
			angle_ini = -sprite_copy.getRotation() / 180 * VAR->PI + atan2(IO->getPosition().y - sprite_copy.getPosition().y, IO->getPosition().x - sprite_copy.getPosition().x);
		}
		float angle = atan2(IO->getPosition().y - sprite_copy.getPosition().y, IO->getPosition().x - sprite_copy.getPosition().x);
		if (IO->pressed(Qt::Key_Control))
		{
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sprite_copy.getPosition(), IO->getPosition()).distance;
			angle = atan2(pos_mouse.y, pos_mouse.x);
			sprite_copy.setRotation((angle - angle_ini) * 180 / VAR->PI);
		}
		else
		{
			angle = atan2(IO->getPosition().y - sprite_copy.getPosition().y, IO->getPosition().x - sprite_copy.getPosition().x);
			sprite_copy.setRotation((angle - angle_ini) * 180 / VAR->PI);
		}
		setPosLines();
	}
	else
	{
		if (IO->pressed(Qt::Key_Enter) || IO->pressed(Qt::Key_Space))
			apply();
		else if (clicked)
		{
			//RETOUR->add_retour({this, this, this});
			//creer_retour(ROT);
			//creer_retour(ORI);
			//creer_retour(MOV);
			clicked = false;
		}
	}
}

void CCopy::flip()
{
	if (IO->again(Qt::LeftButton) || IO->again(Qt::RightButton))
	{
		sf::Image image = texture_copy.copyToImage();
		if (IO->again(Qt::LeftButton))
			image.flipHorizontally();
		else
			image.flipVertically();

		texture_copy.loadFromImage(image);

		/*
		RETOUR->add_retour({this});
		if (IO->again(Qt::LeftButton))
			creer_retour(FLIPH);
		else
			creer_retour(FLIPV);
		*/
	}
	else if (IO->pressed(Qt::Key_Enter) || IO->pressed(Qt::Key_Space))
		apply();
}

void CCopy::apply()
{
	sf::Texture tex = *sprite_copy.getTexture();
	sf::Sprite spr = sprite_copy;
	spr.setPosition(sprite_copy.getPosition() - sf::Vector2f(sprite_copy.getGlobalBounds().left, sprite_copy.getGlobalBounds().top));
	spr.setTexture(tex, true);

	sf::RenderTexture render;
	render.create(sprite_copy.getGlobalBounds().width, sprite_copy.getGlobalBounds().height);
	render.clear(sf::Color::Transparent);
	render.draw(spr, sf::BlendNone);
	render.display();

	tex = render.getTexture();
	spr = sf::Sprite();
	spr.setPosition(sprite_copy.getGlobalBounds().left, sprite_copy.getGlobalBounds().top);
	spr.move(-LAYER->getPosition());
	spr.setTexture(tex, true);

	sf::Texture tex2 = LAYER->getRenderTexture()->getTexture();

	RES->getShader(RES->fuse)->setParameter("source", tex);
	RES->getShader(RES->fuse)->setParameter("background", tex2);
	RES->getShader(RES->fuse)->setParameter("position", spr.getPosition());

	LAYER->draw(spr, RES->getRender(RES->fuse), true);
	//pos_copy = sf::Vector2f(sprite_copy.getGlobalBounds().left, sprite_copy.getGlobalBounds().top);
	//_t = NULL;

	//RETOUR->add_retour({this, LAYER});
	//LAYER->creer_retour(&LAYER->getTexture()->copyToImage(), CLayer::ACT);
	//creer_retour(APL);
}

void CCopy::display() {
	APP->fenetre->draw(sprite_copy);
}

void CCopy::displayLines()
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i<lines.getVertexCount(); i++)
		lines[i].color = color;
	APP->fenetre->draw(lines);

}

//-----------------------------------------------------------------------//
/*
void CCopy::creer_retour(type_retour t)
{
	i_retour_type++;
	retour_type.push_back(t);

	if (t == MOV)
	{
		i_retour_pos++;
		retour_pos.push_back(sprite_copy.getPosition());
	}
	else if (t == GRA)
	{
		i_retour_taille++;
		retour_taille.push_back(sprite_copy.getScale());
	}
	else if (t == ORI)
	{
		i_retour_origin++;
		retour_origin.push_back(sprite_copy.getOrigin());
	}
	else if (t == ROT)
	{
		i_retour_rotation++;
		retour_rotation.push_back(sprite_copy.getRotation());
	}
	else if (t == CRE)
	{
		i_retour_taille++;
		retour_taille.push_back(sprite_copy.getScale());
		i_retour_origin++;
		retour_origin.push_back(sprite_copy.getOrigin());
		i_retour_rotation++;
		retour_rotation.push_back(sprite_copy.getRotation());
	}
}

void CCopy::ctrl_z()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type--;
	type_retour t = retour_type[i_retour_type];

	if (t == CRE)
		_t = NULL;
	else if (ex_t == APL)
		_t = this;
	else if (ex_t == MOV)
	{
		i_retour_pos--;
		sprite_copy.setPosition(retour_pos[i_retour_pos]);
		setPosLines();
	}
	else if (ex_t == FLIPH)
	{
		sf::Image image = texture_copy.copyToImage();
		image.flipHorizontally();
		texture_copy.loadFromImage(image);
	}
	else if (ex_t == FLIPV)
	{
		sf::Image image = texture_copy.copyToImage();
		image.flipVertically();
		texture_copy.loadFromImage(image);
	}
	else if (ex_t == GRA)
	{
		i_retour_taille--;
		sprite_copy.setScale(retour_taille[i_retour_taille]);
		setPosLines();
	}
	else if (ex_t == ORI)
	{
		i_retour_origin--;
		sprite_copy.setOrigin(retour_origin[i_retour_origin]);
		setPosLines();
	}
	else if (ex_t == ROT)
	{
		i_retour_rotation--;
		sprite_copy.setRotation(retour_rotation[i_retour_rotation]);
		setPosLines();
	}
}

void CCopy::ctrl_y()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type++;
	type_retour t = retour_type[i_retour_type];

	if (t == APL)
		_t = NULL;
	else if (ex_t == CRE)
		_t = this;
	else if (t == MOV)
	{
		i_retour_pos++;
		sprite_copy.setPosition(retour_pos[i_retour_pos]);
		setPosLines();
	}
	else if (t == FLIPH)
	{
		sf::Image image = texture_copy.copyToImage();
		image.flipHorizontally();
		texture_copy.loadFromImage(image);
	}
	else if (t == FLIPV)
	{
		sf::Image image = texture_copy.copyToImage();
		image.flipVertically();
		texture_copy.loadFromImage(image);
	}
	else if (t == GRA)
	{
		i_retour_taille++;
		sprite_copy.setScale(retour_taille[i_retour_taille]);
		setPosLines();
	}
	else if (t == ORI)
	{
		i_retour_origin++;
		sprite_copy.setOrigin(retour_origin[i_retour_origin]);
		setPosLines();
	}
	else if (t == ROT)
	{
		i_retour_rotation++;
		sprite_copy.setRotation(retour_rotation[i_retour_rotation]);
		setPosLines();
	}
}

void CCopy::delete_retour()
{
	retour_type.erase(retour_type.begin() + i_retour_type + 1, retour_type.end());
	retour_pos.erase(retour_pos.begin() + i_retour_pos + 1, retour_pos.end());
	retour_taille.erase(retour_taille.begin() + i_retour_taille + 1, retour_taille.end());
	retour_origin.erase(retour_origin.begin() + i_retour_origin + 1, retour_origin.end());
	retour_rotation.erase(retour_rotation.begin() + i_retour_rotation + 1, retour_rotation.end());
}
*/