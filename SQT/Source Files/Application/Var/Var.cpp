#include "Source Files/Application/Var/Var.h"

CVar* CVar::_t;

CVar::CVar(void)
{
	//Default parameters
	color_fond = sf::Color(128, 128, 128);

	opacity = 255;
	seuil = 10;
}
