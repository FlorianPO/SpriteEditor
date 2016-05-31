#include "Source Files/Application/Tool/Tools/Snap.h"

#include "Source Files/Application/App.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Retour/Retour.h"
#include <QtWidgets/QApplication>

CSnap::CSnap() {
	numero_outil = CTool::SNAP;
}

void CSnap::afficher() {
	sf::Color color = sf::Color(100 * bool(rand() % 2), 100 * bool(rand() % 2), 100 * bool(rand() % 2));
	for (int i = 0; i < conf_lines.size(); i++) {
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre->draw(conf_lines[i].line);
	}
}


void CSnap::snap(sf::Vector2i pos_ini, sf::Vector2i pos) {
	bit_image.create(LAYER->getImage().getSize().x, LAYER->getImage().getSize().y, SELEC->ident_color);

	sf::VertexArray l(sf::LinesStrip, 2);
	conf_lines.clear();

	rect = sf::IntRect(std::min(pos_ini.x, pos.x), std::min(pos_ini.y, pos.y), std::abs(pos_ini.x - pos.x) + 1, std::abs(pos_ini.y - pos.y) + 1);

	for (int i = rect.left; i < rect.left + rect.width; i++) {
		//Haut
		l[0].position = sf::Vector2f(i, rect.top);
		l[1].position = sf::Vector2f(i + 1, rect.top);
		conf_lines.push_back(CTool::creer_conf_line(l, 0, i, rect.top));
		//Bas
		l[0].position = sf::Vector2f(i, rect.top + rect.height);
		l[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
		conf_lines.push_back(CTool::creer_conf_line(l, 2, i, rect.top + rect.height));
	}
	for (int j = rect.top; j < rect.top + rect.height; j++) {
		//Gauche
		l[0].position = sf::Vector2f(rect.left, j);
		l[1].position = sf::Vector2f(rect.left, j + 1);
		conf_lines.push_back(CTool::creer_conf_line(l, 3, rect.left, j));
		//Droite
		l[0].position = sf::Vector2f(rect.left + rect.width, j);
		l[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
		conf_lines.push_back(CTool::creer_conf_line(l, 1, rect.left + rect.width, j));
	}
}

void CSnap::snapping(sf::IntRect rect, sf::Vector2i pos_click) {
	sf::VertexArray l(sf::LinesStrip, 2);
	conf_lines.clear();

	rect.left -= LAYER->getPosition_i().x;
	rect.top -= LAYER->getPosition_i().y;
	if (CFonction::checkCadre(&rect, sf::IntRect(0, 0, LAYER->getTexture().getSize().x, LAYER->getTexture().getSize().y)))
		return;

	test_image = &LAYER->getImage();
	base_color = CFonction::getColor(pos_click, *test_image);

	for (int i = rect.left; i <= rect.left + rect.width - 1; i++) {
		bool var = false;
		for (int j = rect.top; j <= rect.top + rect.height - 1; j++) {
			if (!var && !pixelCheck(test_image->getPixel(i, j))) {
				l[0].position = sf::Vector2f(i, j);
				l[1].position = sf::Vector2f(i + 1, j);
				conf_lines.push_back(CTool::creer_conf_line(l, 0, i, j));
				var = true;
			}
			if (var) {
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (j == bit_image.getSize().y - 1 || pixelCheck(test_image->getPixel(i, j + 1)) || j == rect.top + rect.height - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Bas
				{
					l[0].position = sf::Vector2f(i, j + 1);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(l, 2, i, j));
					var = false;
				}
			}
		}
	}

	for (int j = rect.top; j <= rect.top + rect.height - 1; j++) {
		bool var = false;
		for (int i = rect.left; i <= rect.left + rect.width - 1; i++) {
			if (!var && !pixelCheck(test_image->getPixel(i, j))) {
				l[0].position = sf::Vector2f(i, j);
				l[1].position = sf::Vector2f(i, j + 1);
				conf_lines.push_back(CTool::creer_conf_line(l, 3, i, j));
				var = true;
			}
			if (var) {
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (i == bit_image.getSize().x - 1 || pixelCheck(test_image->getPixel(i + 1, j)) || i == rect.left + rect.width - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Droite
				{
					l[0].position = sf::Vector2f(i + 1, j);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(l, 1, i, j));
					var = false;
				}
			}
		}
	}
}

void CSnap::end_selec(int type) {
	if (conf_lines.size() > 0) {
		CTool::move_line(&conf_lines, LAYER->getPosition_i());

		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i = 0; i < conf_lines.size(); i++) {
			if (conf_lines[i].x < x_min) { x_min = conf_lines[i].x; }
			else if (conf_lines[i].x > x_max) { x_max = conf_lines[i].x; }
			if (conf_lines[i].y < y_min) { y_min = conf_lines[i].y; }
			else if (conf_lines[i].y > y_max) { y_max = conf_lines[i].y; }
		}

		switch (type) {
			case 0:	SELEC->createSelection(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), bit_image, conf_lines);
				break;
			case 1: SELEC->addSelection(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), bit_image, conf_lines);
				break;
			case 2: SELEC->subSelection(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), bit_image, conf_lines);
				break;
			case 3: SELEC->intersectSelection(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), bit_image, conf_lines);
				break;
		}
		conf_lines.clear();
	}
}

void CSnap::use() {
	static bool active = false;
	static sf::Vector2i pos_click;
	static int key;
	sf::Vector2i center = IO->getPixel();

	if (IO->again(Qt::LeftButton)) {
		pos_click = IO->getPixel();
		active = true;
	}

	if (active) {
		if (IO->pressed(Qt::LeftButton))
			snap(pos_click, center);
		else {
			//RETOUR->group({IO, LAYER});
			//IO->creer_retour();

			snapping(rect, pos_click);
			Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
			if (special & Qt::ShiftModifier && special & Qt::ControlModifier)
				end_selec(3);
			else if (special & Qt::ControlModifier)
				end_selec(2);
			else if (special & Qt::ShiftModifier)
				end_selec(1);
			else
				end_selec(0);
			active = false;
		}
	}

}