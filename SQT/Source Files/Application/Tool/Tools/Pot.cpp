#include "Pot.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/Resource/ResourceController.h"

Pot::Pot(void) {
	numero_outil = nTol::POT;
}

void Pot::full_dessiner(const sf::Color& color, bool additive) {
	RES->getShader(nRer::pot).setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
	RES->getShader(nRer::pot).setParameter("background", LAYER->getTexture());
	RES->getShader(nRer::pot).setParameter("couleur", color);
	if (additive)
		RES->getShader(nRer::pot).setParameter("mode", 0.f);
	else
		RES->getShader(nRer::pot).setParameter("mode", 1.f);

	sf::Texture texture = LAYER->getTexture();
	sf::Sprite sprite = sf::Sprite(texture);
	LAYER->drawSpriteLocaly(sprite, RES->getRender(nRer::pot));

	checkLayerUpdate(true);
}

void Pot::dessiner() {
	test_image = &LAYER->getImage();

	if (!Fonction::onCalque(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getTexture()) || !SELEC->onSelec(INPUT->getPixel()))
		return;

	image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Transparent);
	bit_image.create(test_image->getSize().x, test_image->getSize().y, sf::Color::Black);

	linearFill(INPUT->getPixel().x - VECTOR2I(LAYER->getPosition()).x, INPUT->getPixel().y - VECTOR2I(LAYER->getPosition()).y);
	while (!ranges.empty()) {
		nTol::range_type range = ranges.front(); ranges.pop();

		for (int i = range.debutX; i <= range.finX; i++) {
			if (range.Y > 0 && bit_image.getPixel(i, range.Y - 1).r == 0 && SELEC->onSelec(sf::Vector2i(i + LAYER->getPosition().x, range.Y - 1 + LAYER->getPosition().y)) && pixelCheck(test_image->getPixel(i, range.Y - 1)))
				linearFill(i, range.Y - 1);

			if (range.Y < image.getSize().y - 1 && bit_image.getPixel(i, range.Y + 1).r == 0 && SELEC->onSelec(sf::Vector2i(i + LAYER->getPosition().x, range.Y + 1 + LAYER->getPosition().y)) && pixelCheck(test_image->getPixel(i, range.Y + 1)))
				linearFill(i, range.Y + 1);
		}
	}
	sf::Texture texture;
	texture.loadFromImage(image);
	LAYER->drawSpriteLocaly(sf::Sprite(texture), sf::RenderStates::Default);

	checkLayerUpdate(true);
}

void Pot::linearFill(int x, int y) {
	int i_left = x;
	do {
		image.setPixel(i_left, y, fill_color);
		bit_image.setPixel(i_left, y, sf::Color::White);
		i_left--;

	} while (i_left >= 0 && bit_image.getPixel(i_left, y).r == 0 && SELEC->onSelec(sf::Vector2i(i_left + LAYER->getPosition().x, y + LAYER->getPosition().y)) && pixelCheck(test_image->getPixel(i_left, y)));
	i_left++;

	int i_right = x;
	do {
		image.setPixel(i_right, y, fill_color);
		bit_image.setPixel(i_right, y, sf::Color::White);
		i_right++;

	} while (i_right <= bit_image.getSize().x - 1 && bit_image.getPixel(i_right, y).r == 0 && SELEC->onSelec(sf::Vector2i(i_right + LAYER->getPosition().x, y + LAYER->getPosition().y)) && pixelCheck(test_image->getPixel(i_right, y)));
	i_right--;

	nTol::range_type range = {i_left, i_right, y};
	ranges.push(range);
}

void Pot::use() {
	if (INPUT->again(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Control) && INPUT->pressed(Qt::Key_Shift))
			full_dessiner(COLOR_CONTROLLER->getColor1(), false);
		else if (INPUT->pressed(Qt::Key_Shift))
			full_dessiner(COLOR_CONTROLLER->getColor1(), true);
		else if (INPUT->pressed(Qt::Key_Control))
			setBaseColor(COLOR_CONTROLLER->getColor1());
		else {
			fill_color = COLOR_CONTROLLER->getColor1();
			fill_color.a *= BRUSH_CONTROLLER->getOpacity() / 255.f;
			setBaseColor(Fonction::getPointedColor());
			dessiner();
		}
	}
	else if (INPUT->again(Qt::RightButton)) {
		if (INPUT->pressed(Qt::Key_Control) && INPUT->pressed(Qt::Key_Shift))
			full_dessiner(COLOR_CONTROLLER->getColor2(), false);
		else if (INPUT->pressed(Qt::Key_Shift))
			full_dessiner(COLOR_CONTROLLER->getColor2(), true);
		else if (INPUT->pressed(Qt::Key_Control))
			setBaseColor(COLOR_CONTROLLER->getColor2());
		else {
			fill_color = COLOR_CONTROLLER->getColor2();
			fill_color.a *= BRUSH_CONTROLLER->getOpacity() / 255.f;
			setBaseColor(Fonction::getPointedColor());
			dessiner();
		}
	}
}
