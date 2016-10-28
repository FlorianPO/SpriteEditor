#include "BrushCircle.h"

BrushCircle::BrushCircle() : Brush() {
	numero_brush = nBrh::CIRCLE;
}

void BrushCircle::cercle(float rx, float ry, sf::Image& image) {
	sf::Vector2f center = sf::Vector2f(image.getSize().x / 2, image.getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image.getSize().x % 2 == 0)*0.5f, (image.getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	float rxSq = rx*rx;
	float rySq = ry*ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq*y;

	for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++) {
		pos = sf::Vector2f(center.x + (x - delta.x), i);
		image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		pos = sf::Vector2f(center.x - (x - delta.x), i);
		image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
	}

	//Region 1
	p = rySq - (rxSq*ry) + (0.25f*rxSq);
	while (px < py) {
		x++;
		px = px + 2.f * rySq;
		if (p < 0)
			p = p + rySq + px;
		else {
			y--;
			py = py - 2.f * rxSq;
			p = p + rySq + px - py;
		}

		for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++) {
			pos = sf::Vector2f(center.x + (x - delta.x), i);
			image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			pos = sf::Vector2f(center.x - (x - delta.x), i);
			image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		}
	}

	//Region 2
	p = rySq*(x + 0.5f)*(x + 0.5f) + rxSq*(y - 1.f)*(y - 1.f) - rxSq*rySq;
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
			image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			pos = sf::Vector2f(i, center.y - (y - delta.y));
			image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		}
	}
}

int BrushCircle::alpha_cercle(const sf::Vector2f& pos, const sf::Vector2f& center) {
	return 255 -
		std::sqrt(
			std::pow((pos.x - center.x) / (center.x + 1), 2)
			+
			std::pow((pos.y - center.y) / (center.y + 1), 2)
		) * 255;
}

void BrushCircle::create(const sf::Vector2i& circle_size) {
	sf::Image image;
	image.create(ARG_VECTOR(circle_size), sf::Color::Transparent);
	cercle(circle_size.x / 2, circle_size.y / 2, image);

	Brush::setSize(circle_size);

	texture.loadFromImage(image);
	sprite.setTexture(texture, true);
}