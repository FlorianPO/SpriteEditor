#pragma once

#include "stdenum.h"
#include "Source Files/Application/Brush/Brushes/BrushSquare.h"

class BrushSquareOutline : public BrushSquare
{
// CONSTRUCTOR
public:
	BrushSquareOutline();
	~BrushSquareOutline() {}

// METHODS
protected:
	virtual void carre(sf::Image& image) override;
};

