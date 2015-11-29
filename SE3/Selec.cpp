#include "Selec.h"

#include "Calque.h"
#include "Retour.h"
#include "Input.h"
#include "App.h"
#include "Fonction.h"
#include "Res.h"
#include "Outil.h"

CSelec* SELEC;

CSelec::CSelec(void)
{
	ident_color = sf::Color(255, 255, 255, 255);
	blend_color = sf::Color(255, 255, 255, 0);

	RES->getShader(CRes::cut)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::invert)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::usual)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::pot)->setParameter("texture", renderTexture_selec.getTexture());
}

CSelec::~CSelec(void) {}

bool CSelec::isMove()
{
	if (OUTIL != NULL)
		return OUTIL->numero_outil == COutil::RECTSELEC
		|| OUTIL->numero_outil == COutil::BAGUETTE
		|| OUTIL->numero_outil == COutil::SELECCOLOR
		|| OUTIL->numero_outil == COutil::SNAP;

	return false;
}

void CSelec::initialiser()
{
	noSelec();

	i_retour_type = -1;
	i_retour_inv = -1;
	i_retour_pos = -1;
	i_retour_lines = -1;
	i_retour_image = -1;

	creer_retour(ACT);
}

void CSelec::noSelec()
{
	invert = true;

	renderTexture_selec.create(1, 1);
	renderTexture_selec.clear(blend_color);

	renderTexture_selec.display();
	refresh = true;
	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);

	update_cadre();
}

void CSelec::delete_selec()
{
	if (isSelected())
	{
		conf_lines.clear();
		noSelec();
		RETOUR_VECTOR.push_back(this);
		RETOUR->add_retour();
		creer_retour(ACT);
	}
}

void CSelec::which_size(sf::IntRect rect, sf::Image* image_selec)
{
	invert = false;

	renderTexture_selec.create(rect.width + 2, rect.height + 2);
	renderTexture_selec.clear(ident_color);
	sprite_selec.setPosition(rect.left - 1, rect.top - 1);

	sf::Texture texture;
	if (image_selec == NULL)
	{
		sf::Image image; image.create(rect.width, rect.height, blend_color);
		texture.loadFromImage(image);
	}
	else
		texture.loadFromImage(*image_selec, sf::IntRect(sf::Vector2i(rect.left, rect.top) - CALQUE->getPosition_i(),
		sf::Vector2i(rect.width, rect.height)));

	sf::Sprite spr(texture); spr.setPosition(1, 1);
	renderTexture_selec.draw(spr, sf::BlendNone);
	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::intersect(sf::IntRect rect, sf::Image* image_selec)
{
	sf::Texture texture = *sprite_selec.getTexture();
	sf::Sprite spr(texture, sf::IntRect(rect.left - cadre.left + 1, rect.top - cadre.top + 1, rect.width, rect.height));

	sprite_selec.setPosition(rect.left - 1, rect.top - 1);
	renderTexture_selec.create(rect.width + 2, rect.height + 2);
	renderTexture_selec.clear(ident_color);

	if (image_selec == NULL)
	{
		spr.setPosition(1, 1);
		renderTexture_selec.draw(spr, sf::BlendMultiply);
	}
	else
	{
		spr.setPosition(1, 1);
		renderTexture_selec.draw(spr, sf::BlendNone);

		RES->getShader(CRes::update)->setParameter("mode", 3);
		RES->getShader(CRes::update)->setParameter("offset", sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image_selec, sf::IntRect(sf::Vector2i(rect.left, rect.top) - CALQUE->getPosition_i(),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("brosse", texture);
		RES->getShader(CRes::update)->setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, *RES->getRender(CRes::update));
	}

	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::update_size(sf::IntRect rect, sf::Image* image_selec, int type)
{
	float min_x = std::min(rect.left, cadre.left);
	float min_y = std::min(rect.top, cadre.top);

	sf::Texture texture = *sprite_selec.getTexture();
	sf::Sprite spr(texture);

	sprite_selec.setPosition(min_x - 1, min_y - 1);
	renderTexture_selec.create(std::max(rect.left + rect.width, cadre.left + cadre.width) - min_x + 2,
		std::max(rect.top + rect.height, cadre.top + cadre.height) - min_y + 2);

	if (!invert)
		renderTexture_selec.clear(ident_color);
	else
		renderTexture_selec.clear(blend_color);

	spr.setPosition(cadre.left - min_x, cadre.top - min_y);
	renderTexture_selec.draw(spr, sf::BlendNone);

	renderTexture_selec.display();

	if (image_selec == NULL)
	{
		sf::Image image;
		if (type == 1)
			image.create(rect.width, rect.height, blend_color);
		else
			image.create(rect.width, rect.height, ident_color);
		texture.loadFromImage(image);

		spr.setTexture(texture, true); spr.setPosition(rect.left - min_x + 1, rect.top - min_y + 1);
		renderTexture_selec.draw(spr, sf::BlendNone);
	}
	else
	{
		RES->getShader(CRes::update)->setParameter("mode", type);
		RES->getShader(CRes::update)->setParameter("offset", sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image_selec, sf::IntRect(sf::Vector2i(rect.left, rect.top) - CALQUE->getPosition_i(),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("brosse", texture);
		RES->getShader(CRes::update)->setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, *RES->getRender(CRes::update));
	}
	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::new_selec(sf::IntRect rect, sf::Image* image, std::vector<COutil::line_conf>* conf_l, int type)
{
	if (IO->pressed(CInput::Maj) && conf_lines.size() == 0)
		type = 0;

	if (type == 0)
	{
		if (conf_l != NULL)
			conf_lines = *conf_l;
		which_size(rect, image);
	}
	else if (type == 1 || type == 2)
		update_size(rect, image, type);
	else
		intersect(rect, image);

	if (type == 0 || conf_l->size() > 0)
	{
		if (type != 0)
		{
			if (type == 3)
				for (int i = conf_lines.size() - 1; i >= 0; i--)
					if (!rect.contains(conf_lines[i].x, conf_lines[i].y))
						conf_lines.erase(conf_lines.begin() + i);

			conf_lines.insert(conf_lines.end(), conf_l->begin(), conf_l->end());
			reline();
		}
		update_cadre();

		RETOUR_VECTOR.push_back(this);
		RETOUR->add_retour();
		creer_retour(ACT);
	}
}

bool CSelec::onSelec(int x, int y)
{
	if (!invert)
		return x - sprite_selec.getPosition().x >= 0 &&
		x - sprite_selec.getPosition().x < image_selec.getSize().x &&
		y - sprite_selec.getPosition().y >= 0 &&
		y - sprite_selec.getPosition().y < image_selec.getSize().y &&
		image_selec.getPixel(x - sprite_selec.getPosition().x, y - sprite_selec.getPosition().y).a == 0;
	else
	{
		if (x - sprite_selec.getPosition().x >= 0
			&& x - sprite_selec.getPosition().x < image_selec.getSize().x
			&& y - sprite_selec.getPosition().y >= 0
			&& y - sprite_selec.getPosition().y < image_selec.getSize().y)
			return image_selec.getPixel(x - sprite_selec.getPosition().x, y - sprite_selec.getPosition().y).a == 0;
		return true;
	}
}

void CSelec::update_cadre()
{
	cadre = sf::IntRect(sprite_selec.getPosition().x + 1, sprite_selec.getPosition().y + 1, sprite_selec.getTextureRect().width - 2, sprite_selec.getTextureRect().height - 2);
	if (cadre.width == -1)
		cadre = sf::IntRect(0, 0, CALQUE->getTexture()->getSize().x, CALQUE->getTexture()->getSize().y);

	if (conf_lines.size() > 0)
	{
		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i = 0; i<conf_lines.size(); i++)
		{
			if (conf_lines[i].x < x_min) { x_min = conf_lines[i].x; }
			else if (conf_lines[i].x > x_max) { x_max = conf_lines[i].x; }
			if (conf_lines[i].y < y_min) { y_min = conf_lines[i].y; }
			else if (conf_lines[i].y > y_max) { y_max = conf_lines[i].y; }
		}
	}
}

void CSelec::inverser_selec()
{
	if (isSelected())
	{
		invert = !invert;

		sf::Texture texture = renderTexture_selec.getTexture();
		renderTexture_selec.draw(sf::Sprite(texture), *RES->getRender(CRes::invert));
		renderTexture_selec.display();
		refresh = true;

		sprite_selec.setTexture(renderTexture_selec.getTexture(), true);

		RETOUR_VECTOR.push_back(this);
		RETOUR->add_retour();
		creer_retour(INV);
	}
}

void CSelec::initTest()
{
	if (refresh)
	{
		image_selec = sprite_selec.getTexture()->copyToImage();
		refresh = false;
	}
}

void CSelec::reline()
{
	if (conf_lines.size() > 0)
	{
		initTest();
		sf::Vector2f pos = sprite_selec.getPosition();

		for (int i = conf_lines.size() - 1; i >= 0; i--)
			if (conf_lines[i].conf == 0)
			{
				if (image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - 1 - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
					conf_lines.erase(conf_lines.begin() + i);
			}
			else if (conf_lines[i].conf == 1)
			{
				if (image_selec.getPixel(conf_lines[i].x + 1 - pos.x, conf_lines[i].y - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
					conf_lines.erase(conf_lines.begin() + i);
			}
			else if (conf_lines[i].conf == 2)
			{
				if (image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y + 1 - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
					conf_lines.erase(conf_lines.begin() + i);		
			}
			else if (conf_lines[i].conf == 3)
			{
				if (image_selec.getPixel(conf_lines[i].x - 1 - pos.x, conf_lines[i].y - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
					conf_lines.erase(conf_lines.begin() + i);
			}
		if (conf_lines.size() == 0 && !invert)
			noSelec();
	}
}

void CSelec::supr()
{
	RES->getShader(CRes::pot)->setParameter("offset", getPosition() - CALQUE->getPosition());
	RES->getShader(CRes::pot)->setParameter("background", *CALQUE->getTexture());
	RES->getShader(CRes::pot)->setParameter("couleur", sf::Color::Transparent);

	sf::Texture texture = *CALQUE->getTexture();
	CALQUE->draw(&sf::Sprite(texture), RES->getRender(CRes::pot));
}

void CSelec::setPosLines(sf::Vector2f ex_pos, sf::Vector2f pos)
{
	sf::Vector2f move(pos - ex_pos);
	for (int i = 0; i<conf_lines.size(); i++)
	{
		conf_lines[i].line[0].position.x += move.x;
		conf_lines[i].line[1].position.x += move.x;
		conf_lines[i].line[0].position.y += move.y;
		conf_lines[i].line[1].position.y += move.y;

		conf_lines[i].x += move.x;
		conf_lines[i].y += move.y;
	}
}

void CSelec::move()
{
	if (conf_lines.size() > 0)
	{
		static bool noMove = false;
		static bool clicked = false;
		static sf::Vector2i pos;
		static sf::Vector2f pos_selec;

		if (isMove() && IO->pressed(CInput::MRight) || IO->isZQSD() && IO->pressed(CInput::Maj))
		{
			if (!clicked)
			{
				pos = IO->getPixel();
				pos_selec = sprite_selec.getPosition();
				clicked = true;
			}
			sf::Vector2f ex_pos = sprite_selec.getPosition();
			sf::Vector2f move;
			if (!IO->isZQSD())
			{
				if (IO->pressed(CInput::Ctrl))
				{
					sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(pos.x, pos.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
					pos_mouse.x = floor(pos_mouse.x);
					pos_mouse.y = floor(pos_mouse.y);
					move.x = pos_mouse.x + pos_selec.x;
					move.y = pos_mouse.y + pos_selec.y;
					sprite_selec.setPosition(move);
				}
				else
					sprite_selec.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
			}
			else
			{
				if (IO->log(CInput::Z)) move.y = -1;
				if (IO->log(CInput::D)) move.x = 1;
				if (IO->log(CInput::S)) move.y = 1;
				if (IO->log(CInput::Q)) move.x = -1;
				sprite_selec.move(move);
			}
			setPosLines(ex_pos, sprite_selec.getPosition());
			update_cadre();

			if (sprite_selec.getPosition() == pos_selec)
				noMove = true;
		}
		else if (clicked)
		{
			if (!noMove)
			{
				RETOUR_VECTOR.push_back(this);
				RETOUR->add_retour();
				creer_retour(POS);
			}
			clicked = false;
			noMove = false;
		}
	}
}

void CSelec::afficher_lines()
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i<conf_lines.size(); i++)
	{
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre.draw(conf_lines[i].line);
	}
}

void CSelec::creer_retour(type_retour t)
{
	initTest();

	i_retour_type++;
	retour_type.push_back(t);
	i_retour_inv++;
	retour_inv.push_back(invert);

	if (t == ACT)
	{
		i_retour_pos++;
		retour_pos.push_back(sprite_selec.getPosition());
		i_retour_image++;
		retour_image.push_back(image_selec);
		i_retour_lines++;
		retour_lines.push_back(conf_lines);
	}
	else if (t == POS)
	{
		i_retour_pos++;
		retour_pos.push_back(sprite_selec.getPosition());
		i_retour_lines++;
		retour_lines.push_back(conf_lines);
	}
	else //if (t == INV)
	{
		i_retour_image++;
		retour_image.push_back(image_selec);
	}
}

void CSelec::ctrl_z()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type--;

	i_retour_inv--;
	invert = retour_inv[i_retour_inv];

	if (ex_t == ACT) //x <- a
	{
		i_retour_lines--;
		i_retour_pos--;
		i_retour_image--;
		update(ACT);
	}
	else if (ex_t == POS)
	{
		i_retour_lines--;
		i_retour_pos--;
		update(POS);
	}
	else if (ex_t == INV)
	{
		i_retour_image--;
		update(INV);
	}
}

void CSelec::ctrl_y()
{
	i_retour_type++;
	type_retour t = retour_type[i_retour_type];

	i_retour_inv++;
	invert = retour_inv[i_retour_inv];

	if (t == ACT) //x -> a
	{
		i_retour_lines++;
		i_retour_pos++;
		i_retour_image++;
		update(ACT);
	}
	else if (t == POS) //x -> p
	{
		i_retour_lines++;
		i_retour_pos++;
		update(POS);
	}
	else if (t == INV) //x -> i
	{
		i_retour_image++;
		update(INV);
	}
}

void CSelec::update(type_retour t)
{
	if (t == ACT || t == INV)
	{
		sf::Texture texture; texture.loadFromImage(retour_image[i_retour_image]);
		sf::Sprite spr(texture);

		renderTexture_selec.create(spr.getTextureRect().width, spr.getTextureRect().height);
		renderTexture_selec.draw(spr, sf::BlendNone);
		renderTexture_selec.display();

		sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	}
	if (t != INV)
	{
		conf_lines = retour_lines[i_retour_lines];
		sprite_selec.setPosition(retour_pos[i_retour_pos]);
	}
	update_cadre();
}

void CSelec::delete_retour()
{
	retour_type.erase(retour_type.begin() + i_retour_type + 1, retour_type.end());
	retour_inv.erase(retour_inv.begin() + i_retour_inv + 1, retour_inv.end());
	retour_pos.erase(retour_pos.begin() + i_retour_pos + 1, retour_pos.end());
	retour_image.erase(retour_image.begin() + i_retour_image + 1, retour_image.end());
	retour_lines.erase(retour_lines.begin() + i_retour_lines + 1, retour_lines.end());
}
