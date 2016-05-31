#include "Source Files/Application/Brush/Brushes/BrushSquareOutline.h"

CBrushSquareOutline::CBrushSquareOutline() : CBrushSquare() {
	numero_brush = SQUARE_OUTLINE;
}

void CBrushSquareOutline::carre(float rx, float ry, sf::Image& image) {
	for (int i = 0; i < image.getSize().x; i++)
		image.setPixel(i, 0, sf::Color::White);
	for (int j = 1; j < image.getSize().y - 1; j++) {
		image.setPixel(0, j, sf::Color::White);
		image.setPixel(image.getSize().x - 1, j, sf::Color::White);
	}
	for (int i = 0; i < image.getSize().x; i++)
		image.setPixel(i, image.getSize().y - 1, sf::Color::White);
}