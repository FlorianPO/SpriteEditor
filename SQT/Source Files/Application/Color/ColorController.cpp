#include "Source Files/Application/Color/ColorController.h"

CColorController* CColorController::_t;

CColorController::CColorController() {
	color1 = new SignalColor(255, 255, 0);
	color2 = new SignalColor(255, 0, 0);
}

CColorController::~CColorController() {
	delete color1;
	delete color2;
}