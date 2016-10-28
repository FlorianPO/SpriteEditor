#include "TPixelChecker.h"

#include "Source Files/Application/Brush/BrushController.h"

bool TPixelChecker::pixelCheck(const sf::Color& color) const {
	int seuil = BRUSH_CONTROLLER->getSeuil();
	return std::abs(base_color.a - color.a) <= seuil
		&& std::abs(base_color.r - color.r) <= seuil
		&& std::abs(base_color.g - color.g) <= seuil
		&& std::abs(base_color.b - color.b) <= seuil;
}