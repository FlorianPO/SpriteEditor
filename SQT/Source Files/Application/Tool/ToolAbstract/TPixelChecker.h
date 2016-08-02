#pragma once

#include "stdenum.h"

class TPixelChecker
{
// CONSTRUCTOR
public:
	TPixelChecker() {}
	virtual ~TPixelChecker() {}

// METHODS
protected:
	inline void setBaseColor(sf::Color color) { base_color = color; }
	virtual bool pixelCheck(sf::Color color);
	
// MEMBERS
protected:
	sf::Color base_color;
};