#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolColorModifier.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolPixelChecker.h"

class CBaguette : public virtual CTool, virtual CToolColorModifier, virtual CToolPixelChecker
{
// CONSTRUCTOR
public:
	CBaguette();
	~CBaguette() {}

// METHODS
public:
	void use() override;
private:
	void algorithmWithSelec();
	void algorithmNoSelec();
	void linearFillWithSelec(int x, int y);
	void linearFillNoSelec(int x, int y);

	void end_selec(int type);

// MEMBERS
private:
	sf::Image* image;
	sf::Image bit_image;
	
	std::queue<CTool::range_type> ranges;
	std::vector<CTool::line_conf> conf_lines;
};

