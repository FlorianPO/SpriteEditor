#include "Source Files/Application/Tool/Tools/Baguette.h"

#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Fonction/Fonction.h"
#include <QtWidgets/QApplication>

CBaguette::CBaguette() {
	numero_outil = CTool::BAGUETTE;
}

void CBaguette::algorithmNoSelec() {
	if (!CFonction::onCalque(IO->getPixel() - LAYER->getPosition_i(), LAYER->getTexture()))
		return;

	image = &LAYER->getImage();
	SELEC->initTest();

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);

	linearFillNoSelec(IO->getPixel().x - LAYER->getPosition_i().x, IO->getPixel().y - LAYER->getPosition_i().y);
	while (!ranges.empty()) {
		CTool::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0) {
				if (bit_image.getPixel(i, range.Y - 1).a != 0) {
					if (pixelCheck(image->getPixel(i, range.Y - 1)))
						linearFillNoSelec(i, range.Y - 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i + 1, range.Y);
						conf_lines.push_back(CTool::creer_conf_line(line, 0, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i + 1, range.Y);
				conf_lines.push_back(CTool::creer_conf_line(line, 0, i, range.Y));
			}

			if (range.Y < image->getSize().y - 1) {
				if (bit_image.getPixel(i, range.Y + 1).a != 0) {
					if (pixelCheck(image->getPixel(i, range.Y + 1)))
						linearFillNoSelec(i, range.Y + 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y + 1);
						line[1].position = sf::Vector2f(i + 1, range.Y + 1);
						conf_lines.push_back(CTool::creer_conf_line(line, 2, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y + 1);
				line[1].position = sf::Vector2f(i + 1, range.Y + 1);
				conf_lines.push_back(CTool::creer_conf_line(line, 2, i, range.Y));
			}
		}
	}
}

void CBaguette::linearFillNoSelec(int x, int y) {
	sf::VertexArray line(sf::LinesStrip, 2);

	int i_left = x;
	do {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y + 1);
	conf_lines.push_back(CTool::creer_conf_line(line, 3, i_left, y));

	int i_right = x;
	do {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).a != 0 && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right + 1, y);
	line[1].position = sf::Vector2f(i_right + 1, y + 1);
	conf_lines.push_back(CTool::creer_conf_line(line, 1, i_right, y));

	CTool::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

/////////////////////////////////

void CBaguette::algorithmWithSelec() {
	SELEC->initTest();
	if (!CFonction::onCalque(IO->getPixel() - LAYER->getPosition_i(), LAYER->getTexture()) || !SELEC->onSelec(IO->getPixel().x, IO->getPixel().y))
		return;

	bit_image.create(image->getSize().x, image->getSize().y, SELEC->ident_color);

	sf::VertexArray line(sf::LinesStrip, 2);

	linearFillWithSelec(IO->getPixel().x - LAYER->getPosition_i().x, IO->getPixel().y - LAYER->getPosition_i().y);
	while (!ranges.empty()) {
		CTool::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0) {
				if (bit_image.getPixel(i, range.Y - 1).a != 0) {
					if (SELEC->onSelec(i + LAYER->getPosition_i().x, range.Y - 1 + LAYER->getPosition_i().y) && pixelCheck(image->getPixel(i, range.Y - 1)))
						linearFillWithSelec(i, range.Y - 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y);
						line[1].position = sf::Vector2f(i + 1, range.Y);
						conf_lines.push_back(CTool::creer_conf_line(line, 0, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y);
				line[1].position = sf::Vector2f(i + 1, range.Y);
				conf_lines.push_back(CTool::creer_conf_line(line, 0, i, range.Y));
			}

			if (range.Y < image->getSize().y - 1) {
				if (bit_image.getPixel(i, range.Y + 1).a != 0) {
					if (SELEC->onSelec(i + LAYER->getPosition_i().x, range.Y + 1 + LAYER->getPosition_i().y) && pixelCheck(image->getPixel(i, range.Y + 1)))
						linearFillWithSelec(i, range.Y + 1);
					else {
						line[0].position = sf::Vector2f(i, range.Y + 1);
						line[1].position = sf::Vector2f(i + 1, range.Y + 1);
						conf_lines.push_back(CTool::creer_conf_line(line, 2, i, range.Y));
					}
				}
			}
			else {
				line[0].position = sf::Vector2f(i, range.Y + 1);
				line[1].position = sf::Vector2f(i + 1, range.Y + 1);
				conf_lines.push_back(CTool::creer_conf_line(line, 2, i, range.Y));
			}
		}
	}
}

void CBaguette::linearFillWithSelec(int x, int y) {
	sf::VertexArray line(sf::LinesStrip, 2);

	int i_left = x;
	do {
		bit_image.setPixel(i_left, y, SELEC->blend_color);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).a != 0 && SELEC->onSelec(i_left + LAYER->getPosition_i().x, y + LAYER->getPosition_i().y) && pixelCheck(image->getPixel(i_left, y)));
	i_left++;

	line[0].position = sf::Vector2f(i_left, y);
	line[1].position = sf::Vector2f(i_left, y + 1);
	conf_lines.push_back(CTool::creer_conf_line(line, 3, i_left, y));

	int i_right = x;
	do {
		bit_image.setPixel(i_right, y, SELEC->blend_color);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).a != 0 && SELEC->onSelec(i_right + LAYER->getPosition_i().x, y + LAYER->getPosition_i().y) && pixelCheck(image->getPixel(i_right, y)));
	i_right--;

	line[0].position = sf::Vector2f(i_right + 1, y);
	line[1].position = sf::Vector2f(i_right + 1, y + 1);
	conf_lines.push_back(CTool::creer_conf_line(line, 1, i_right, y));

	CTool::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

void CBaguette::end_selec(int type) {
	if (conf_lines.size() > 0) {
		CTool::move_line(&conf_lines, LAYER->getPosition_i());

		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i = 0; i < conf_lines.size(); i++) {
			if (conf_lines[i].x < x_min) x_min = conf_lines[i].x;
			else if (conf_lines[i].x > x_max) x_max = conf_lines[i].x;
			if (conf_lines[i].y < y_min) y_min = conf_lines[i].y;
			else if (conf_lines[i].y > y_max) y_max = conf_lines[i].y;
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

void CBaguette::use() {
	if (IO->again(Qt::LeftButton)) {
		setPointedColor(&base_color);
		conf_lines.clear();

		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ShiftModifier && special & Qt::ControlModifier) {
			algorithmWithSelec();
			end_selec(3);
		}
		else if (special & Qt::ControlModifier) {
			algorithmWithSelec();
			end_selec(2);
		}
		else if (special & Qt::ShiftModifier) {
			algorithmNoSelec();
			end_selec(1);
		}
		else {
			algorithmNoSelec();
			end_selec(0);
		}
	}
}