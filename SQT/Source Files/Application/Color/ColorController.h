#pragma once

#include "stdenum.h"
class SignalColor;

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
	inline const SignalColor& getSColor1() const { return *color1; }
	inline const SignalColor& getSColor2() const { return *color2; }
	sf::Color getColor1() const;
	sf::Color getColor2() const;

	void setColor1(const sf::Color& c1);
	void setColor2(const sf::Color& c2);

// MEMBERS
private:
	SignalColor* color1;
	SignalColor* color2;
};

