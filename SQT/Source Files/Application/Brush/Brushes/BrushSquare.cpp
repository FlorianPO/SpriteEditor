#include "BrushSquare.h"

BrushSquare::BrushSquare() : Brush() {
	numero_brush = nBrh::SQUARE;
}

void BrushSquare::carre(sf::Image& image) {
	sf::Vector2f center = sf::Vector2f(image.getSize().x / 2, image.getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image.getSize().x % 2 == 0)*0.5f, (image.getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	FOR_I (image.getSize().x) {
		pos = sf::Vector2f(i + delta.x, delta.y);
		image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_carre(pos, center)));
	}
	for (int j = 1; j < image.getSize().y - 1; j++)
		FOR_I (image.getSize().x) {
			pos = sf::Vector2f(i + delta.x, j + delta.y);
			image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_carre(pos, center)));
		}
	FOR_I (image.getSize().x) {
		pos = sf::Vector2f(i + delta.x, image.getSize().y - 1 + delta.y);
		image.setPixel(ARG_VECTOR(pos), sf::Color(255, 255, 255, alpha_carre(pos, center)));
	}
}

int BrushSquare::alpha_carre(const sf::Vector2f& pos, const sf::Vector2f& center) {
	float ax = std::abs((pos.x - center.x) / (center.x + 1));
	float ay = std::abs((pos.y - center.y) / (center.y + 1));
	return 255 - std::max(ax, ay) * 254;
}

void BrushSquare::create(const sf::Vector2i& square_size) {
	sf::Image image;
	image.create(square_size.x, square_size.y, sf::Color::Transparent);
	carre(image);

	Brush::setSize(square_size);

	texture.loadFromImage(image);
	sprite.setTexture(texture, true);
}