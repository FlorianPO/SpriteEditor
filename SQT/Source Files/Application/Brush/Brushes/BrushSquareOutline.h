#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/Brushes/BrushSquare.h"

class CBrushSquareOutline : public CBrushSquare
{
// CONSTRUCTOR
public:
	explicit CBrushSquareOutline();
	virtual ~CBrushSquareOutline() {}

// METHODS
protected:
	virtual void carre(float rx, float ry, sf::Image& image) override;
};

