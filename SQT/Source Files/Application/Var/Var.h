#pragma once

#include "stdafx.h"

#define INIT_VAR CVar::createInstance();
#define VAR CVar::getInstance()

class CVar
{
// INSTANCE
private:	static CVar* _t; 
public:		inline static void createInstance() { _t = new CVar(); }
			inline static CVar* getInstance() { return _t; }

// CONSTRUCTOR
	CVar();
	~CVar() {}

//Intern variables, don't mess with them
public:
	sf::Color color_fond;
	int opacity, seuil;

	const double PIH = 3.14159265358979323846 / 8.0;
	const double PI = 3.14159265358979323846;
	const int scroll_speed = 100;
};

