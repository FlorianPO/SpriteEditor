#pragma once

#include "stdenum.h"
#include "Source Files/Application/Brush/Brush.h"

class BrushCircle : public Brush
{
// CONSTRUCTOR
public:
	BrushCircle();
	virtual ~BrushCircle() {}

// METHODS
protected:
	virtual void cercle(float rx, float ry, sf::Image& image);
	int alpha_cercle(const sf::Vector2f& pos, const sf::Vector2f& center);

	void create(const sf::Vector2i& circle_size) override;
};

