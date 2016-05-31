#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/BrushController.h"

class CBrushCircle : public CBrush
{
// CONSTRUCTOR
public:
	explicit CBrushCircle();
	virtual ~CBrushCircle() {}

// METHODS
protected:
	virtual void cercle(float rx, float ry, sf::Image& image);
	int alpha_cercle(sf::Vector2f pos, sf::Vector2f center);

	void create(sf::Vector2i circle_size) override;
};

