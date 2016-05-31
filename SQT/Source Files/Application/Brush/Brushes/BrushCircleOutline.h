#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/Brushes/BrushCircle.h"

class CBrushCircleOutline : public CBrushCircle
{
// CONSTRUTOR
public:
	explicit CBrushCircleOutline();
	virtual ~CBrushCircleOutline() {}

// METHODS
protected:
	virtual void cercle(float rx, float ry, sf::Image& image) override;
};



