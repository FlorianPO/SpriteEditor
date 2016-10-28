#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/ToolAbstract/TPixelChecker.h"
#include "Source Files/Application/Tool/ToolAbstract/TSelectionModifier.h"

class Snap : public TSelectionModifier, TPixelChecker
{
// CONSTRUCTOR
public:
	Snap();
	~Snap() {}

// METHODS
public:
	void use() override;
private:
	void snap(const sf::Vector2i& pos_ini, const sf::Vector2i& pos);
	void snapping(sf::IntRect rect, const sf::Vector2i& pos_click);

// MEMBERS
private:
	sf::Image bit_image;
	const sf::Image* test_image;
	sf::IntRect rect;
	sf::Vector2i pos_click;
};