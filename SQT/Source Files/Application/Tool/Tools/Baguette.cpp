#include "Baguette.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Fonction/Fonction.h"

using namespace nSet;

Baguette::Baguette() {
	numero_outil = nTol::BAGUETTE;
}

void Baguette::algorithmNoSelec() {
	if (!Fonction::onCalque(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getTexture()))
		return;

	image = LAYER->getImage();

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);

	linearFillNoSelec(INPUT->getPixel().x - VECTOR2I(LAYER->getPosition()).x, INPUT->getPixel().y - VECTOR2I(LAYER->getPosition()).y);
	while (!ranges.empty()) {
		nTol::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0) {
				if (bit_image.getPixel(i, range.Y - 1).a != 0) {
					if (pixelCheck(image->getPixel(i, range.Y - 1)))
						linearFillNoSelec(i, range.Y - 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i + 1, range.Y);
						oriented_lines.push_back(oLine(line, UP, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i + 1, range.Y);
				oriented_lines.push_back(oLine(line, UP, i, range.Y));
			}

			if (range.Y < image->getSize().y - 1) {
				if (bit_image.getPixel(i, range.Y + 1).a != 0) {
					if (pixelCheck(image->getPixel(i, range.Y + 1)))
						linearFillNoSelec(i, range.Y + 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y + 1);
						line[1].position = sf::Vector2f(i + 1, range.Y + 1);
						oriented_lines.push_back(oLine(line, DOWN, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y + 1);
				line[1].position = sf::Vector2f(i + 1, range.Y + 1);
				oriented_lines.push_back(oLine(line, DOWN, i, range.Y));
			}
		}
	}
}

void Baguette::linearFillNoSelec(int x, int y) {
	sf::VertexArray line(sf::LinesStrip, 2);

	int i_left = x;
	do {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y + 1);
	oriented_lines.push_back(oLine(line, LEFT, i_left, y));

	int i_right = x;
	do {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).a != 0 && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right + 1, y);
	line[1].position = sf::Vector2f(i_right + 1, y + 1);
	oriented_lines.push_back(oLine(line, RIGHT, i_right, y));

	nTol::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

/////////////////////////////////

void Baguette::algorithmWithSelec() {
	if (!Fonction::onCalque(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getTexture()) || !SELEC->onSelec(INPUT->getPixel().x, INPUT->getPixel().y))
		return;

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);

	linearFillWithSelec(INPUT->getPixel().x - VECTOR2I(LAYER->getPosition()).x, INPUT->getPixel().y - VECTOR2I(LAYER->getPosition()).y);
	while (!ranges.empty()) {
		nTol::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0) {
				if (bit_image.getPixel(i, range.Y - 1).a != 0) {
					if (SELEC->onSelec(i + VECTOR2I(LAYER->getPosition()).x, range.Y - 1 + VECTOR2I(LAYER->getPosition()).y) && pixelCheck(image->getPixel(i, range.Y - 1)))
						linearFillWithSelec(i, range.Y - 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i + 1, range.Y);
						oriented_lines.push_back(oLine(line, UP, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i + 1, range.Y);
				oriented_lines.push_back(oLine(line, UP, i, range.Y));
			}

			if (range.Y < image->getSize().y - 1) {
				if (bit_image.getPixel(i, range.Y + 1).a != 0) {
					if (SELEC->onSelec(i + VECTOR2I(LAYER->getPosition()).x, range.Y + 1 + VECTOR2I(LAYER->getPosition()).y) && pixelCheck(image->getPixel(i, range.Y + 1)))
						linearFillWithSelec(i, range.Y + 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y + 1);
						line[1].position = sf::Vector2f(i + 1, range.Y + 1);
						oriented_lines.push_back(oLine(line, DOWN, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y + 1);
				line[1].position = sf::Vector2f(i + 1, range.Y + 1);
				oriented_lines.push_back(oLine(line, DOWN, i, range.Y));
			}
		}
	}
}

void Baguette::linearFillWithSelec(int x, int y) {
	sf::VertexArray line(sf::LinesStrip, 2);

	int i_left = x;
	do {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && SELEC->onSelec(i_left + VECTOR2I(LAYER->getPosition()).x, y + VECTOR2I(LAYER->getPosition()).y) && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y + 1);
	oriented_lines.push_back(oLine(line, LEFT, i_left, y));

	int i_right = x;
	do {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).a != 0 && SELEC->onSelec(i_right + VECTOR2I(LAYER->getPosition()).x, y + VECTOR2I(LAYER->getPosition()).y) && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right + 1, y);
	line[1].position = sf::Vector2f(i_right + 1, y + 1);
	oriented_lines.push_back(oLine(line, RIGHT, i_right, y));

	nTol::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

void Baguette::use() {
	SELEC->move();

	if (INPUT->again(Qt::LeftButton)) {
		setBaseColor(Fonction::getPointedColor());
		oriented_lines.clear();

		if (INPUT->pressed(Qt::Key_Shift) && INPUT->pressed(Qt::Key_Control)) {
			algorithmWithSelec();
			endSelection(INTERSECT, bit_image);
		}
		else if (INPUT->pressed(Qt::Key_Control)) {
			algorithmWithSelec();
			endSelection(SUB, bit_image);
		}
		else if (INPUT->pressed(Qt::Key_Shift)) {
			algorithmNoSelec();
			endSelection(ADD, bit_image);
		}
		else {
			algorithmNoSelec();
			endSelection(NO_FUSION, bit_image);
		}
	}
}