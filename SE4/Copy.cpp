#include "Copy.h"
#include "Retour.h"
#include "Var.h"
#include "Input.h"
#include "Fonction.h"
#include "Curseur.h"
#include "Calque.h"
#include "App.h"
#include "Res.h"

CCopy* COPY;
std::vector<CCopy*> COPY_LIST;
sf::Vector2<float> CCopy::pos_copy;
sf::IntRect CCopy::rect_copy;

CCopy::CCopy(sf::Image* image)
{
	_t = this;

	clicked = false;

	texture_copy.loadFromImage(*image);
	sprite_copy.setTexture(texture_copy, true);

	sprite_copy.setPosition(pos_copy);
	rect_copy = CFonction::FloatRectToIntRect(sprite_copy.getGlobalBounds());

	lines = sf::VertexArray(sf::LinesStrip, 5);
	setPosLines();

	i_retour_type = -1;
	i_retour_pos = -1;
	i_retour_taille = -1;
	i_retour_rotation = -1;
	i_retour_origin = -1;

	RETOUR->add_retour({this});
	creer_retour(CRE);
	creer_retour(MOV);
}


CCopy::~CCopy(void)
{
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
	if (IO->pressed(CInput::MRight) || IO->isZQSD() && !IO->isCMA())
	{
		if (!clicked)
		{
			posi = IO->getPixel();
			posf = sprite_copy.getPosition();
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
				sprite_copy.setPosition(move);
			}
			else
				sprite_copy.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
		}
		else
		{
			if (IO->log(CInput::Z)) move.y = -1;
			if (IO->log(CInput::D)) move.x = 1;
			if (IO->log(CInput::S)) move.y = 1;
			if (IO->log(CInput::Q)) move.x = -1;
			sprite_copy.move(move);
		}
		setPosLines();
		rect_copy = CFonction::FloatRectToIntRect(sprite_copy.getGlobalBounds());
	}
	else
	{
		if (IO->pressed(CInput::MLeft) || IO->pressed(CInput::Enter) || IO->pressed(CInput::Space))
			apply();
		else if (clicked)
		{
			RETOUR->add_retour({this});
			creer_retour(MOV);
			clicked = false;
		}
	}
}

void CCopy::grand()
{
	CURSEUR->gerer(&sprite_copy);

	if (IO->pressed(CInput::MLeft))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite_copy);
			posf2 = sprite_copy.getScale();

			posf.x = IO->getPixel().x;
			posf.y = IO->getPixel().y;
		}

		float angle = sprite_copy.getRotation() / 180 * VAR->PI;
		sf::Vector2f temp;
		if (IO->pressed(CInput::Ctrl))
			temp = CFonction::selecPointRect(sf::Vector2f(posf.x, posf.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
		else
			temp = sf::Vector2f(IO->getPixel().x - posf.x, IO->getPixel().y - posf.y);

		float x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
		float y = temp.y*std::cos(angle) - temp.x*std::sin(angle);
		x /= posf2.x;
		y /= posf2.y;

		sf::Vector2f scale;
		if (IO->pressed(CInput::Ctrl))
		{
			int max_size = std::max(sprite_copy.getTextureRect().width, sprite_copy.getTextureRect().height);
			scale = sf::Vector2f(1.f + x / max_size, 1.f + y / max_size);
		}
		else
			scale = sf::Vector2f(1.f + x / sprite_copy.getTextureRect().width, 1.f + y / sprite_copy.getTextureRect().height);

		sprite_copy.setScale(sf::Vector2f(scale.x * posf2.x, scale.y * posf2.y));
		setPosLines();
	}
	else
	{
		if (IO->pressed(CInput::Enter) || IO->pressed(CInput::Space))
			apply();
		else if (clicked)
		{
			RETOUR->add_retour({this});
			creer_retour(GRA);

			clicked = false;
			posf2 = sprite_copy.getScale();
			posf2 -= sf::Vector2f(1, 1);
		}
	}
}

void CCopy::rotation()
{
	CURSEUR->gerer(&sprite_copy);

	if (IO->pressed(CInput::MLeft))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite_copy);
			angle_ini = -sprite_copy.getRotation() / 180 * VAR->PI + atan2(IO->getPosition().y - sprite_copy.getPosition().y, IO->getPosition().x - sprite_copy.getPosition().x);
		}
		float angle = atan2(IO->getPosition().y - sprite_copy.getPosition().y, IO->getPosition().x - sprite_copy.getPosition().x);
		if (IO->pressed(CInput::Ctrl))
		{
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sprite_copy.getPosition(), IO->getPosition());
			angle = atan2(pos_mouse.y, pos_mouse.x);
			sprite_copy.setRotation(angle * 180 / VAR->PI);
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
		if (IO->pressed(CInput::Enter) || IO->pressed(CInput::Space))
			apply();
		else if (clicked)
		{
			RETOUR->add_retour({this, this, this});
			creer_retour(ROT);
			creer_retour(ORI);
			creer_retour(MOV);
			clicked = false;
		}
	}
}

void CCopy::flip()
{
	if (IO->again(CInput::MLeft) || IO->again(CInput::MRight))
	{
		sf::Image image = texture_copy.copyToImage();
		if (IO->again(CInput::MLeft))
			image.flipHorizontally();
		else
			image.flipVertically();

		texture_copy.loadFromImage(image);

		RETOUR->add_retour({this});
		if (IO->again(CInput::MLeft))
			creer_retour(FLIPH);
		else
			creer_retour(FLIPV);
	}
	else if (IO->pressed(CInput::Enter) || IO->pressed(CInput::Space))
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
	spr.move(-CALQUE->getPosition());
	spr.setTexture(tex, true);

	sf::Texture tex2 = CALQUE->getRenderTexture()->getTexture();

	RES->getShader(RES->fuse)->setParameter("source", tex);
	RES->getShader(RES->fuse)->setParameter("background", tex2);
	RES->getShader(RES->fuse)->setParameter("position", spr.getPosition());

	CALQUE->draw(&spr, RES->getRender(RES->fuse), true);
	pos_copy = sf::Vector2f(sprite_copy.getGlobalBounds().left, sprite_copy.getGlobalBounds().top);
	_t = NULL;

	RETOUR->add_retour({this, CALQUE});
	CALQUE->creer_retour(&CALQUE->getTexture()->copyToImage(), CCalque::ACT);
	creer_retour(APL);
}

void CCopy::new_copy(sf::Image* image)
{
	_t = new CCopy(image);
	copy_list.push_back(_t);
}

void CCopy::afficher()
{
	APP->fenetre.draw(sprite_copy);
}

void CCopy::afficher_lines()
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i<lines.getVertexCount(); i++)
		lines[i].color = color;
	APP->fenetre.draw(lines);

}

//-----------------------------------------------------------------------//

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