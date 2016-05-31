#include "Source Files/Application/Tool/Tools/Pot.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Var/Var.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/Color/ColorController.h"
#include <QtWidgets/QApplication>

CPot::CPot(void) {
	numero_outil = CTool::POT;
}

void CPot::full_dessiner(sf::Color color) {
	RES->getShader(CRes::pot)->setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
	RES->getShader(CRes::pot)->setParameter("background", LAYER->getTexture());
	RES->getShader(CRes::pot)->setParameter("couleur", color);

	sf::Texture texture = LAYER->getTexture();
	LAYER->draw(sf::Sprite(texture), RES->getRender(CRes::pot));
}

void CPot::dessiner() {
	test_image = &LAYER->getImage();
	SELEC->initTest();

	if (!CFonction::onCalque(IO->getPixel() - LAYER->getPosition_i(), LAYER->getTexture()) || !SELEC->onSelec(IO->getPixel().x, IO->getPixel().y))
		return;

	image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Transparent);
	bit_image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Black);

	linearFill(IO->getPixel().x - LAYER->getPosition_i().x, IO->getPixel().y - LAYER->getPosition_i().y);
	while (!ranges.empty()) {
		CTool::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0 && bit_image.getPixel(i, range.Y - 1).r == 0 && SELEC->onSelec(i + LAYER->getPosition_i().x, range.Y - 1 + LAYER->getPosition_i().y) && pixelCheck(test_image->getPixel(i, range.Y - 1)))
				linearFill(i, range.Y - 1);

			if (range.Y < image.getSize().y - 1 && bit_image.getPixel(i, range.Y + 1).r == 0 && SELEC->onSelec(i + LAYER->getPosition_i().x, range.Y + 1 + LAYER->getPosition_i().y) && pixelCheck(test_image->getPixel(i, range.Y + 1)))
				linearFill(i, range.Y + 1);
		}
	}
	sf::Texture texture;
	texture.loadFromImage(image);

	LAYER->draw(sf::Sprite(texture), NULL);
}

void CPot::linearFill(int x, int y) {
	int i_left = x;
	do {
		image.setPixel(i_left, y, fill_color);
		bit_image.setPixel(i_left, y, sf::Color::White);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).r == 0 && SELEC->onSelec(i_left + LAYER->getPosition_i().x, y + LAYER->getPosition_i().y) && pixelCheck(test_image->getPixel(i_left, y)));
	i_left++;

	int i_right = x;
	do {
		image.setPixel(i_right, y, fill_color);
		bit_image.setPixel(i_right, y, sf::Color::White);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).r == 0 && SELEC->onSelec(i_right + LAYER->getPosition_i().x, y + LAYER->getPosition_i().y) && pixelCheck(test_image->getPixel(i_right, y)));
	i_right--;

	CTool::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

void CPot::use() {
	if (IO->again(Qt::LeftButton)) {
		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor1());
		else if (special & Qt::ShiftModifier)
			full_dessiner(COLOR_CONTROLLER->getColor1());
		else {
			fill_color = COLOR_CONTROLLER->getColor1();
			fill_color.a *= VAR->opacity / 255.f;
			setPointedColor(&base_color);
			dessiner();
		}
	}
	else if (IO->again(Qt::RightButton)) {
		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor2());
		else if (special & Qt::ShiftModifier)
			full_dessiner(COLOR_CONTROLLER->getColor2());
		else {
			fill_color = COLOR_CONTROLLER->getColor2();
			fill_color.a *= VAR->opacity / 255.f;
			setPointedColor(&base_color);
			dessiner();
		}
	}
}
