#include "SelecColor.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selection/SelectionController.h"

using namespace nSet;

SelecColor::SelecColor(void) {
	numero_outil = nTol::SELECCOLOR;
}

void SelecColor::pickNoSelec() {
	if (!Fonction::onCalque(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getTexture()))
		return;

	test_image = LAYER->getImage();
	bit_image.create(test_image->getSize().x, test_image->getSize().y, SELEC->ident_color);
	sf::VertexArray line(sf::LinesStrip, 2);

	FOR_J (test_image->getSize().y) {
		FOR_I (test_image->getSize().x) {
			if (pixelCheck(test_image->getPixel(i, j))) {
				if (j == 0 || !pixelCheck(test_image->getPixel(i, j - 1))) {
					line[0].position = sf::Vector2f(i, j);
					line[1].position = sf::Vector2f(i + 1, j);
					oriented_lines.push_back(oLine(line, UP, i, j));
				}
				if (i == test_image->getSize().x - 1 || !pixelCheck(test_image->getPixel(i + 1, j))) {
					line[0].position = sf::Vector2f(i + 1, j);
					line[1].position = sf::Vector2f(i + 1, j + 1);
					oriented_lines.push_back(oLine(line, RIGHT, i, j));
				}

				if (j == test_image->getSize().y - 1 || !pixelCheck(test_image->getPixel(i, j + 1))) {
					line[0].position = sf::Vector2f(i + 1, j + 1);
					line[1].position = sf::Vector2f(i, j + 1);
					oriented_lines.push_back(oLine(line, DOWN, i, j));
				}
				if (i == 0 || !pixelCheck(test_image->getPixel(i - 1, j))) {
					line[0].position = sf::Vector2f(i, j + 1);
					line[1].position = sf::Vector2f(i, j);
					oriented_lines.push_back(oLine(line, LEFT, i, j));
				}

				bit_image.setPixel(i, j, SELEC->blend_color);
			}
		}
	}
}

void SelecColor::pickWithSelec() {
	if (!Fonction::onCalque(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getTexture()))
		return;

	bit_image.create(test_image->getSize().x, test_image->getSize().x, SELEC->ident_color);
	sf::VertexArray line(sf::LinesStrip, 2);

	sf::IntRect cadre = SELEC->getCadre();
	Fonction::checkCadre(&cadre, sf::IntRect(0, 0, test_image->getSize().x, test_image->getSize().y));

	FOR_J (test_image->getSize().y) {
		FOR_I (test_image->getSize().x) {
			if (SELEC->onSelec(i + VECTOR2I(LAYER->getPosition()).x, j + VECTOR2I(LAYER->getPosition()).y) && pixelCheck(test_image->getPixel(i, j))) {
				if (j == 0 || !SELEC->onSelec(i + VECTOR2I(LAYER->getPosition()).x, j - 1 + VECTOR2I(LAYER->getPosition()).y) || !pixelCheck(test_image->getPixel(i, j - 1))) {
					line[0].position = sf::Vector2f(i, j);
					line[1].position = sf::Vector2f(i + 1, j);
					oriented_lines.push_back(oLine(line, UP, i, j));
				}
				if (i == test_image->getSize().x - 1 || !SELEC->onSelec(i + 1 + VECTOR2I(LAYER->getPosition()).x, j + VECTOR2I(LAYER->getPosition()).y) || !pixelCheck(test_image->getPixel(i + 1, j))) {
					line[0].position = sf::Vector2f(i + 1, j);
					line[1].position = sf::Vector2f(i + 1, j + 1);
					oriented_lines.push_back(oLine(line, RIGHT, i, j));
				}

				if (j == test_image->getSize().y - 1 || !SELEC->onSelec(i + VECTOR2I(LAYER->getPosition()).x, j + 1 + VECTOR2I(LAYER->getPosition()).y) || !pixelCheck(test_image->getPixel(i, j + 1))) {
					line[0].position = sf::Vector2f(i + 1, j + 1);
					line[1].position = sf::Vector2f(i, j + 1);
					oriented_lines.push_back(oLine(line, DOWN, i, j));
				}
				if (i == 0 || !SELEC->onSelec(i - 1, j) || !pixelCheck(test_image->getPixel(i - 1 + VECTOR2I(LAYER->getPosition()).x, j + VECTOR2I(LAYER->getPosition()).y))) {
					line[0].position = sf::Vector2f(i, j + 1);
					line[1].position = sf::Vector2f(i, j);
					oriented_lines.push_back(oLine(line, LEFT, i, j));
				}

				bit_image.setPixel(i, j, SELEC->blend_color);
			}
		}
	}
}

void SelecColor::use() {
	SELEC->move();

	if (INPUT->again(Qt::LeftButton)) {
		setBaseColor(Fonction::getPointedColor());
		sf::VertexArray line(sf::LinesStrip, 2);
		oriented_lines.clear();

		if (INPUT->pressed(Qt::Key_Shift) && INPUT->pressed(Qt::Key_Control)) {
			pickWithSelec();
			endSelection(INTERSECT, bit_image);
		}
		else if (INPUT->pressed(Qt::Key_Control)) {
			pickWithSelec();
			endSelection(SUB, bit_image);
		}
		else if (INPUT->pressed(Qt::Key_Shift)) {
			pickNoSelec();
			endSelection(ADD, bit_image);
		}
		else {
			pickNoSelec();
			endSelection(NO_FUSION, bit_image);
		}
	}
}
