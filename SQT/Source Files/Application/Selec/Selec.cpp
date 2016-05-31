#include "Source Files/Application/Selec/Selec.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Retour/Retour.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/App.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/Tool/ToolController.h"

CSelec* CSelec::_t;

CSelec::CSelec() : SignalController() {
	RES->getShader(CRes::cut)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::invert)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::usual)->setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(CRes::pot)->setParameter("texture", renderTexture_selec.getTexture());
}

bool CSelec::isMove() {
	if (TOOL != NULL)
		return TOOL->getEnum() == CTool::RECTSELEC
		|| TOOL->getEnum() == CTool::BAGUETTE
		|| TOOL->getEnum() == CTool::SELECCOLOR
		|| TOOL->getEnum() == CTool::SNAP;

	return false;
}

void CSelec::initSignals() {
	del();
	emit selectionDeleted();
	/*
	i_retour_type = -1;
	i_retour_inv = -1;
	i_retour_pos = -1;
	i_retour_lines = -1;
	i_retour_image = -1;

	creer_retour(ACT);*/
}

void CSelec::reline() {
	if (isSelected()) {
		initTest();
		sf::Vector2f pos = sprite_selec.getPosition();

		for (int i = conf_lines.size() - 1; i >= 0; i--)
			switch (conf_lines[i].conf) {
				case 0:
					if (image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - 1 - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
						conf_lines.erase(conf_lines.begin() + i);
					break;
				case 1:
					if (image_selec.getPixel(conf_lines[i].x + 1 - pos.x, conf_lines[i].y - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
						conf_lines.erase(conf_lines.begin() + i);
					break;
				case 2:
					if (image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y + 1 - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
						conf_lines.erase(conf_lines.begin() + i);
					break;
				case 3:
					if (image_selec.getPixel(conf_lines[i].x - 1 - pos.x, conf_lines[i].y - pos.y).a == image_selec.getPixel(conf_lines[i].x - pos.x, conf_lines[i].y - pos.y).a)
						conf_lines.erase(conf_lines.begin() + i);
					break;
		}

		if (conf_lines.size() == 0 && !inverted)
			del();
	}
}

void CSelec::del() {
	conf_lines.clear();
	inverted = false;

	renderTexture_selec.create(1, 1);
	renderTexture_selec.clear(blend_color);
	renderTexture_selec.display();

	refresh = true;
	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);

	update_cadre();
}

bool CSelec::onSelec(int x, int y) {
	if (!inverted)
		return x - sprite_selec.getPosition().x >= 0 &&
		x - sprite_selec.getPosition().x < image_selec.getSize().x &&
		y - sprite_selec.getPosition().y >= 0 &&
		y - sprite_selec.getPosition().y < image_selec.getSize().y &&
		image_selec.getPixel(x - sprite_selec.getPosition().x, y - sprite_selec.getPosition().y).a == 0;
	else {
		if (x - sprite_selec.getPosition().x >= 0
			&& x - sprite_selec.getPosition().x < image_selec.getSize().x
			&& y - sprite_selec.getPosition().y >= 0
			&& y - sprite_selec.getPosition().y < image_selec.getSize().y)
			return image_selec.getPixel(x - sprite_selec.getPosition().x, y - sprite_selec.getPosition().y).a == 0;
		return true;
	}
}

void CSelec::update_cadre() {
	cadre = sf::IntRect(sprite_selec.getPosition().x + 1, sprite_selec.getPosition().y + 1, sprite_selec.getTextureRect().width - 2, sprite_selec.getTextureRect().height - 2);
	if (conf_lines.size() > 0) {
		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i = 0; i < conf_lines.size(); i++) {
			if (conf_lines[i].x < x_min) { x_min = conf_lines[i].x; }
			else if (conf_lines[i].x > x_max) { x_max = conf_lines[i].x; }
			if (conf_lines[i].y < y_min) { y_min = conf_lines[i].y; }
			else if (conf_lines[i].y > y_max) { y_max = conf_lines[i].y; }
		}
	}
	emit cadreXChanged(cadre.left);
	emit cadreYChanged(cadre.top);
	emit cadreWChanged(cadre.width);
	emit cadreHChanged(cadre.height);
}

void CSelec::initTest() {
	if (refresh) {
		image_selec = sprite_selec.getTexture()->copyToImage();
		refresh = false;
	}
}

void CSelec::invert() {
	sf::Texture texture = renderTexture_selec.getTexture();
	renderTexture_selec.draw(sf::Sprite(texture), *RES->getRender(CRes::invert));
	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::supr() {
	RES->getShader(CRes::pot)->setParameter("offset", getPosition() - LAYER->getPosition());
	RES->getShader(CRes::pot)->setParameter("background", LAYER->getTexture());
	RES->getShader(CRes::pot)->setParameter("couleur", sf::Color::Transparent);

	sf::Texture texture = LAYER->getTexture();
	LAYER->draw(sf::Sprite(texture), RES->getRender(CRes::pot));
}

void CSelec::setPosLines(sf::Vector2f ex_pos, sf::Vector2f pos) {
	sf::Vector2f move(pos - ex_pos);
	for (int i = 0; i < conf_lines.size(); i++) {
		conf_lines[i].line[0].position.x += move.x;
		conf_lines[i].line[1].position.x += move.x;
		conf_lines[i].line[0].position.y += move.y;
		conf_lines[i].line[1].position.y += move.y;

		conf_lines[i].x += move.x;
		conf_lines[i].y += move.y;
	}
}

void CSelec::move() {
	if (conf_lines.size() > 0) {
		static bool clicked = false;
		static sf::Vector2i pos;
		static sf::Vector2f pos_selec;

		if (isMove() && IO->pressed(Qt::RightButton) || IO->isZQSD() && IO->pressed(Qt::Key_Shift)) {
			if (!clicked) {
				pos = IO->getPixel();
				pos_selec = sprite_selec.getPosition();
				clicked = true;
			}
			sf::Vector2f ex_pos = sprite_selec.getPosition();
			sf::Vector2f move;
			if (!IO->isZQSD()) {
				if (IO->pressed(Qt::Key_Control)) {
					sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(pos.x, pos.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y)).distance;
					pos_mouse.x = floor(pos_mouse.x);
					pos_mouse.y = floor(pos_mouse.y);
					move.x = pos_mouse.x + pos_selec.x;
					move.y = pos_mouse.y + pos_selec.y;
					sprite_selec.setPosition(move);
				}
				else
					sprite_selec.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
			}
			else {
				if (IO->log(Qt::Key_Z)) move.y = -1;
				if (IO->log(Qt::Key_D)) move.x = 1;
				if (IO->log(Qt::Key_S)) move.y = 1;
				if (IO->log(Qt::Key_Q)) move.x = -1;
				sprite_selec.move(move);
			}
			setPosLines(ex_pos, sprite_selec.getPosition());
			update_cadre();
		}
		else if (clicked) {
			if (sprite_selec.getPosition() != pos_selec) {
				//RETOUR->add_retour({this});
				//creer_retour(POS);
			}
			clicked = false;
		}
	}
}

void CSelec::afficher_lines() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i < conf_lines.size(); i++) {
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre->draw(conf_lines[i].line);
	}
}

/*
void CSelec::creer_retour(type_retour t)
{
initTest();

i_retour_type++;
retour_type.push_back(t);
i_retour_inv++;
retour_inv.push_back(inverted);

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
inverted = retour_inv[i_retour_inv];

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
inverted = retour_inv[i_retour_inv];

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
*/