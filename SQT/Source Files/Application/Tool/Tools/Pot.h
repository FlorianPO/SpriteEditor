#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/TPixelChecker.h"
#include "Source Files/Application/Tool/ToolAbstract/TLayerUpdater.h"

class Pot : public Tool, TPixelChecker, TLayerUpdater
{
// CONSTRUCTOR
public:
	Pot();
	~Pot() {}

// METHODS
public:
	void use() override;
	static void full_dessiner(sf::Color color);
private:
	void dessiner();
	void linearFill(int x, int y);

// MEMBERS
private:
	sf::Color fill_color;
	sf::Image* test_image;
	sf::Image bit_image;
	sf::Image image;

	std::queue<nTol::range_type> ranges;
};

