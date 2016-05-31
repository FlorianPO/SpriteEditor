#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"

class CToolPixelChecker : public virtual CTool
{
// CONSTRUCTOR
public:
	CToolPixelChecker() {}
	virtual ~CToolPixelChecker() {}

// METHODS
protected:
	virtual bool pixelCheck(sf::Color color);
	sf::Color base_color;
};

