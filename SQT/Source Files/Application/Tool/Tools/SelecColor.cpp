#include "Source Files/Application/Tool/Tools/SelecColor.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selec/Selec.h"
#include <QtWidgets/QApplication>

CSelecColor::CSelecColor(void) {
	numero_outil = CTool::SELECCOLOR;
}

void CSelecColor::pickNoSelec() {
	SELEC->initTest();
	if (!CFonction::onCalque(IO->getPixel() - LAYER->getPosition_i(), LAYER->getTexture()))
		return;

	test_image = &LAYER->getImage();
	bit_image.create(test_image->getSize().x, test_image->getSize().x, SELEC->ident_color);
	sf::VertexArray line(sf::LinesStrip, 2);

	for (int j = 0; j < test_image->getSize().y; j++) {
		for (int i = 0; i < test_image->getSize().x; i++) {
			if (pixelCheck(test_image->getPixel(i, j))) {
				if (j == 0 || !pixelCheck(test_image->getPixel(i, j - 1))) {
					line[0].position = sf::Vector2f(i, j);
					line[1].position = sf::Vector2f(i + 1, j);
					conf_lines.push_back(CTool::creer_conf_line(line, 0, i, j));
				}
				if (i == test_image->getSize().x - 1 || !pixelCheck(test_image->getPixel(i + 1, j))) {
					line[0].position = sf::Vector2f(i + 1, j);
					line[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(line, 1, i, j));
				}

				if (j == test_image->getSize().y - 1 || !pixelCheck(test_image->getPixel(i, j + 1))) {
					line[0].position = sf::Vector2f(i + 1, j + 1);
					line[1].position = sf::Vector2f(i, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(line, 2, i, j));
				}
				if (i == 0 || !pixelCheck(test_image->getPixel(i - 1, j))) {
					line[0].position = sf::Vector2f(i, j + 1);
					line[1].position = sf::Vector2f(i, j);
					conf_lines.push_back(CTool::creer_conf_line(line, 3, i, j));
				}

				bit_image.setPixel(i, j, SELEC->blend_color);
			}
		}
	}
}

void CSelecColor::pickWithSelec() {
	SELEC->initTest();
	if (!CFonction::onCalque(IO->getPixel() - LAYER->getPosition_i(), LAYER->getTexture()))
		return;

	bit_image.create(test_image->getSize().x, test_image->getSize().x, SELEC->ident_color);
	sf::VertexArray line(sf::LinesStrip, 2);

	sf::IntRect cadre = SELEC->getCadre();
	CFonction::checkCadre(&cadre, sf::IntRect(0, 0, test_image->getSize().x, test_image->getSize().y));

	for (int j = 0; j < test_image->getSize().y; j++) {
		for (int i = 0; i < test_image->getSize().x; i++) {
			if (SELEC->onSelec(i + LAYER->getPosition_i().x, j + LAYER->getPosition_i().y) && pixelCheck(test_image->getPixel(i, j))) {
				if (j == 0 || !SELEC->onSelec(i + LAYER->getPosition_i().x, j - 1 + LAYER->getPosition_i().y) || !pixelCheck(test_image->getPixel(i, j - 1))) {
					line[0].position = sf::Vector2f(i, j);
					line[1].position = sf::Vector2f(i + 1, j);
					conf_lines.push_back(CTool::creer_conf_line(line, 0, i, j));
				}
				if (i == test_image->getSize().x - 1 || !SELEC->onSelec(i + 1 + LAYER->getPosition_i().x, j + LAYER->getPosition_i().y) || !pixelCheck(test_image->getPixel(i + 1, j))) {
					line[0].position = sf::Vector2f(i + 1, j);
					line[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(line, 1, i, j));
				}

				if (j == test_image->getSize().y - 1 || !SELEC->onSelec(i + LAYER->getPosition_i().x, j + 1 + LAYER->getPosition_i().y) || !pixelCheck(test_image->getPixel(i, j + 1))) {
					line[0].position = sf::Vector2f(i + 1, j + 1);
					line[1].position = sf::Vector2f(i, j + 1);
					conf_lines.push_back(CTool::creer_conf_line(line, 2, i, j));
				}
				if (i == 0 || !SELEC->onSelec(i - 1, j) || !pixelCheck(test_image->getPixel(i - 1 + LAYER->getPosition_i().x, j + LAYER->getPosition_i().y))) {
					line[0].position = sf::Vector2f(i, j + 1);
					line[1].position = sf::Vector2f(i, j);
					conf_lines.push_back(CTool::creer_conf_line(line, 3, i, j));
				}

				bit_image.setPixel(i, j, SELEC->blend_color);
			}
		}
	}
}

void CSelecColor::end_selec(int type) {
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

void CSelecColor::use() {
	if (IO->again(Qt::LeftButton)) {
		setPointedColor(&base_color);
		sf::VertexArray line(sf::LinesStrip, 2);
		conf_lines.clear();

		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ShiftModifier && special & Qt::ControlModifier) {
			pickWithSelec();
			end_selec(3);
		}
		else if (special & Qt::ControlModifier) {
			pickWithSelec();
			end_selec(2);
		}
		else if (special & Qt::ShiftModifier) {
			pickNoSelec();
			end_selec(1);
		}
		else {
			pickNoSelec();
			end_selec(0);
		}
	}
}
