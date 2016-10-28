#include "Snap.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Input/InputController.h"

using namespace nSet;

Snap::Snap() {
	numero_outil = nTol::SNAP;
}

void Snap::snap(const sf::Vector2i& pos_ini, const sf::Vector2i& pos) {
	bit_image.create(LAYER->getImage().getSize().x, LAYER->getImage().getSize().y, SELEC->ident_color);

	sf::VertexArray l(sf::LinesStrip, 2);
	oriented_lines.clear();

	rect = sf::IntRect(std::min(pos_ini.x, pos.x), std::min(pos_ini.y, pos.y), std::abs(pos_ini.x - pos.x) + 1, std::abs(pos_ini.y - pos.y) + 1);
	for (int i = rect.left; i < rect.left + rect.width; i++) {
		//Haut
		l[0].position = sf::Vector2f(i, rect.top);
		l[1].position = sf::Vector2f(i + 1, rect.top);
		oriented_lines.push_back(oLine(l, UP, i, rect.top));
		//Bas
		l[0].position = sf::Vector2f(i, rect.top + rect.height);
		l[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
		oriented_lines.push_back(oLine(l, DOWN, i, rect.top + rect.height));
	}
	for (int j = rect.top; j < rect.top + rect.height; j++) {
		//Gauche
		l[0].position = sf::Vector2f(rect.left, j);
		l[1].position = sf::Vector2f(rect.left, j + 1);
		oriented_lines.push_back(oLine(l, LEFT, rect.left, j));
		//Droite
		l[0].position = sf::Vector2f(rect.left + rect.width, j);
		l[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
		oriented_lines.push_back(oLine(l, RIGHT, rect.left + rect.width, j));
	}
}

void Snap::snapping(sf::IntRect rect, const sf::Vector2i& pos_click) {
	sf::VertexArray l(sf::LinesStrip, 2);
	oriented_lines.clear();

	rect.left -= int(LAYER->getPosition().x);
	rect.top -= int(LAYER->getPosition().y);
	if (Fonction::checkCadre(rect, sf::IntRect(0, 0, LAYER->getTexture().getSize().x, LAYER->getTexture().getSize().y)))
		return;

	test_image = &LAYER->getImage();
	setBaseColor(Fonction::getColor(pos_click, *test_image));

	for (int i = rect.left; i <= rect.left + rect.width - 1; i++) {
		bool var = false;
		for (int j = rect.top; j <= rect.top + rect.height - 1; j++) {
			if (!var && !pixelCheck(test_image->getPixel(i, j))) {
				l[0].position = sf::Vector2f(i, j);
				l[1].position = sf::Vector2f(i + 1, j);
				oriented_lines.push_back(oLine(l, UP, i, j));
				var = true;
			}
			if (var) {
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (j == bit_image.getSize().y - 1 || pixelCheck(test_image->getPixel(i, j + 1)) || j == rect.top + rect.height - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Bas
				{
					l[0].position = sf::Vector2f(i, j + 1);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					oriented_lines.push_back(oLine(l, DOWN, i, j));
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
				oriented_lines.push_back(oLine(l, LEFT, i, j));
				var = true;
			}
			if (var) {
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (i == bit_image.getSize().x - 1 || pixelCheck(test_image->getPixel(i + 1, j)) || i == rect.left + rect.width - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Droite
				{
					l[0].position = sf::Vector2f(i + 1, j);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					oriented_lines.push_back(oLine(l, RIGHT, i, j));
					var = false;
				}
			}
		}
	}
}

void Snap::use() {
	SELEC->move();

	if (INPUT->again(Qt::LeftButton))
		pos_click = INPUT->getPixel();

	if (INPUT->pressed(Qt::LeftButton))
		snap(pos_click, INPUT->getPixel());
	else if (INPUT->released(Qt::LeftButton)) {
		snapping(rect, pos_click);
		
		if (INPUT->pressed(Qt::Key_Shift) && INPUT->pressed(Qt::Key_Control))
			endSelection(INTERSECT, bit_image);
		else if (INPUT->pressed(Qt::Key_Control))
			endSelection(SUB, bit_image);
		else if (INPUT->pressed(Qt::Key_Shift))
			endSelection(ADD, bit_image);
		else
			endSelection(NO_FUSION, bit_image);
	}

}