#include "BrushCircleOutline.h"

BrushCircleOutline::BrushCircleOutline() : BrushCircle() {
	numero_brush = nBrh::SQUARE;
}

void BrushCircleOutline::cercle(float rx, float ry, sf::Image& image) {
	sf::Vector2f center = sf::Vector2f(image.getSize().x / 2, image.getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image.getSize().x % 2 == 0)*0.5f, (image.getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	float rxSq = rx*rx;
	float rySq = ry*ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq*y;

	image.setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
	image.setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
	image.setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
	image.setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);

	//Region 1
	p = rySq - (rxSq*ry) + (0.25*rxSq);
	while (px < py) {
		x++;
		px = px + 2 * rySq;
		if (p < 0)
			p = p + rySq + px;
		else {
			y--;
			py = py - 2 * rxSq;
			p = p + rySq + px - py;
		}

		image.setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
		image.setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image.setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image.setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);

	}
	//Region 2
	p = rySq*(x + 0.5)*(x + 0.5) + rxSq*(y - 1)*(y - 1) - rxSq*rySq;
	while (y > 0) {
		y--;
		py = py - 2 * rxSq;
		if (p > 0)
			p = p + rxSq - py;
		else {
			x++;
			px = px + 2 * rySq;
			p = p + rxSq - py + px;
		}

		image.setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
		image.setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image.setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image.setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);
	}
}