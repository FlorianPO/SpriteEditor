#pragma once

#include "stdenum.h"
#include "Source Files/Application/Brush/Brush.h"

class BrushSquare : public Brush
{
// CONSTRUCTOR
public:
	BrushSquare();
	virtual ~BrushSquare() {}

// METHODS
protected:
	virtual void carre(sf::Image& image);
	int alpha_carre(const sf::Vector2f& pos, const sf::Vector2f& center);

	void create(const sf::Vector2i& square_size) override;
};

