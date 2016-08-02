#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/ToolAbstract/TPixelChecker.h"
#include "Source Files/Application/Tool/ToolAbstract/TSelectionModifier.h"

class SelecColor : public TSelectionModifier, TPixelChecker
{
// CONSTRUCTOR
public:
	SelecColor();
	~SelecColor() {}

// METHODS
public:
	void use() override;
private:
	void pickNoSelec();
	void pickWithSelec();

// MEMBERS
private:
	sf::Image* test_image;
	sf::Image bit_image;
};

