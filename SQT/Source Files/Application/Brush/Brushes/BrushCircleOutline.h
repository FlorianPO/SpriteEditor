#pragma once

#include "stdenum.h"
#include "Source Files/Application/Brush/Brushes/BrushCircle.h"

class BrushCircleOutline : public BrushCircle
{
// CONSTRUTOR
public:
	BrushCircleOutline();
	~BrushCircleOutline() {}

// METHODS
protected:
	virtual void cercle(float rx, float ry, sf::Image& image) override;
};



