#pragma once

#include "stdafx.h"

#include "Source Files/SignalType/SignalColor.h"

class CToolColorModifier
{
public:
	CToolColorModifier() {}
	virtual ~CToolColorModifier() {}

protected:
	void setPointedColor(SignalColor* color);
	void setPointedColor(sf::Color* color);
};