#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/ToolAbstract/TPixelChecker.h"
#include "Source Files/Application/Tool/ToolAbstract/TSelectionModifier.h"

class Baguette : public TSelectionModifier, TPixelChecker
{
// CONSTRUCTOR
public:
	Baguette();
	~Baguette() {}

// METHODS
public:
	void use() override;
private:
	void algorithmWithSelec();
	void algorithmNoSelec();
	void linearFillWithSelec(int x, int y);
	void linearFillNoSelec(int x, int y);

// MEMBERS
private:
	sf::Image* image;
	sf::Image bit_image;
	
	std::queue<nTol::range_type> ranges;
};

