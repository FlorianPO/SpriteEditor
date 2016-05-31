#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/BrushController.h"

class CBrushSquare : public CBrush
{
// CONSTRUCTOR
public:
	explicit CBrushSquare();
	virtual ~CBrushSquare() {}

// METHODS
protected:
	virtual void carre(float rx, float ry, sf::Image& image);
	int alpha_carre(sf::Vector2f pos, sf::Vector2f center);

	void create(sf::Vector2i square_size) override;
};

