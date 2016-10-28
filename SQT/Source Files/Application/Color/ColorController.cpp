#include "ColorController.h"

#include "Source Files/SignalType/SignalColor.h"

ColorController* ColorController::_t;

ColorController::ColorController() {
	color1 = new SignalColor(255, 255, 0);
	color2 = new SignalColor(255, 0, 0);
}

ColorController::~ColorController() {
	delete color1;
	delete color2;
}

sf::Color ColorController::getColor1() const {
	return color1->getColor();
}
	
sf::Color ColorController::getColor2() const {
	return color2->getColor();
}

void ColorController::setColor1(const sf::Color& c1) {
	color1->setColor(c1);
}

void ColorController::setColor2(const sf::Color& c2) {
	color2->setColor(c2);
}