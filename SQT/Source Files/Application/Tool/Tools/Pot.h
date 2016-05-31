#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolColorModifier.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolPixelChecker.h"

class CPot : public virtual CTool, virtual CToolColorModifier, virtual CToolPixelChecker
{
// CONSTRUCTOR
public:
	CPot();
	~CPot() {}

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

	std::queue<CTool::range_type> ranges;
};

