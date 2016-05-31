#include "Source Files/Application/Brush/Brushes/BrushSquare.h"

CBrushSquare::CBrushSquare() : CBrush() {
	numero_brush = SQUARE;
}

void CBrushSquare::carre(float rx, float ry, sf::Image& image) {
	sf::Vector2f center = sf::Vector2f(image.getSize().x / 2, image.getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image.getSize().x % 2 == 0)*0.5f, (image.getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	for (int i = 0; i < image.getSize().x; i++) {
		pos = sf::Vector2f(i + delta.x, delta.y);
		image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
	}
	for (int j = 1; j < image.getSize().y - 1; j++)
		for (int i = 0; i < image.getSize().x; i++) {
			pos = sf::Vector2f(i + delta.x, j + delta.y);
			image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
		}
	for (int i = 0; i < image.getSize().x; i++) {
		pos = sf::Vector2f(i + delta.x, image.getSize().y - 1 + delta.y);
		image.setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
	}
}

int CBrushSquare::alpha_carre(sf::Vector2f pos, sf::Vector2f center) {
	float ax = std::abs((pos.x - center.x) / (center.x + 1));
	float ay = std::abs((pos.y - center.y) / (center.y + 1));
	return 255 - std::max(ax, ay) * 254;
}

void CBrushSquare::create(sf::Vector2i square_size) {
	sf::Image image;
	image.create(square_size.x, square_size.y, sf::Color::Transparent);
	carre(square_size.x / 2, square_size.y / 2, image);

	CBrush::setSize(square_size);

	texture.loadFromImage(image);
	sprite.setTexture(texture, true);
}