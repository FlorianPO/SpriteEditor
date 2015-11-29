#include "Var.h"

CVar* VAR;

CVar::CVar(void)
{
	//Default parameters
	color_fond = sf::Color(128, 128, 128);
	color1 = sf::Color::White;
	color2 = sf::Color::Black;

	opacity = 255;
	seuil = 10;
}

CVar::~CVar(void) {}
