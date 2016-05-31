#include "Source Files/Application/Brush/Brushes/BrushCircle.h"

CBrushCircle::CBrushCircle() : CBrush() {
	numero_brush = CIRCLE;
}

void CBrushCircle::cercle(float rx, float ry, sf::Image& image) {
	sf::Vector2f center = sf::Vector2f(image.getSize().x / 2, image.getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image.getSize().x % 2 == 0)*0.5f, (image.getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	float rxSq = rx*rx;
	float rySq = ry*ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq*y;

	for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++) {
		pos = sf::Vector2f(center.x + (x - delta.x), i);
		image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		pos = sf::Vector2f(center.x - (x - delta.x), i);
		image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
	}

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

		for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++) {
			pos = sf::Vector2f(center.x + (x - delta.x), i);
			image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			pos = sf::Vector2f(center.x - (x - delta.x), i);
			image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		}
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

		for (float i = center.x - (x - delta.x); i <= center.x + (x - delta.x); i++) {
			pos = sf::Vector2f(i, center.y + (y - delta.y));
			image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			pos = sf::Vector2f(i, center.y - (y - delta.y));
			image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		}
	}
}

int CBrushCircle::alpha_cercle(sf::Vector2f pos, sf::Vector2f center) {
	return 255 -
		std::sqrt(
		std::pow((pos.x - center.x) / (center.x + 1), 2)
		+
		std::pow((pos.y - center.y) / (center.y + 1), 2)
		)
		* 255;
}

void CBrushCircle::create(sf::Vector2i circle_size) {
	sf::Image image;
	image.create(circle_size.x, circle_size.y, sf::Color::Transparent);
	cercle(circle_size.x / 2, circle_size.y / 2, image);

	CBrush::setSize(circle_size);

	texture.loadFromImage(image);
	sprite.setTexture(texture, true);
}