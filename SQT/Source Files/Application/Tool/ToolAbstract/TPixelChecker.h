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
	inline void setBaseColor(const sf::Color& color) { base_color = color; }
	virtual bool pixelCheck(const sf::Color& color) const;
	
// MEMBERS
protected:
	sf::Color base_color;
};