#pragma once

#include "stdafx.h"
#include "Source Files/SignalType/SignalColor.h"

#define INIT_COLOR_CONTROLLER CColorController::createInstance();
#define COLOR_CONTROLLER CColorController::getInstance()

class CColorController : public QObject 
{
	Q_OBJECT
// INSTANCE
private:	static CColorController* _t; 
public:		inline static void createInstance() { _t = new CColorController(); }
			inline static CColorController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	CColorController();
	~CColorController();

// METHODS
	inline SignalColor* getSColor1() { return color1; }
	inline SignalColor* getSColor2() { return color2; }
	inline sf::Color getColor1() { return color1->getColor(); }
	inline sf::Color getColor2() { return color2->getColor(); }

// SIGNALS SLOTS

// MEMBERS
private:
	SignalColor* color1;
	SignalColor* color2;
};

