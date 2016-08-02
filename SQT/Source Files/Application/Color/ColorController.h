#pragma once

#include "stdenum.h"
class SignalColor; // Forward declaration

#define INIT_COLOR_CONTROLLER ColorController::createInstance();
#define COLOR_CONTROLLER ColorController::getInstance()

class ColorController : public QObject 
{
	Q_OBJECT
// INSTANCE
private:	static ColorController* _t; 
public:		inline static void createInstance() { _t = new ColorController(); }
			inline static ColorController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	ColorController();
	~ColorController();

// METHODS
public:
	inline SignalColor* getSColor1() { return color1; }
	inline SignalColor* getSColor2() { return color2; }
	sf::Color getColor1();
	sf::Color getColor2();

	void setColor1(sf::Color c1);
	void setColor2(sf::Color c2);

// MEMBERS
private:
	SignalColor* color1;
	SignalColor* color2;
};

