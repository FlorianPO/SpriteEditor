#pragma once

#include "stdafx.h"

#define VAR CVar::_t
class CVar
{
public:
	static CVar* _t;
public:
	CVar(void);
	~CVar(void);

//Intern variables, don't mess with them
public:
	sf::Color color_fond, color1, color2;
	int opacity, seuil;

	const double PIH = 3.14159265358979323846 / 8.0;
	const double PI = 3.14159265358979323846;
	const int scroll_speed = 100;
};

