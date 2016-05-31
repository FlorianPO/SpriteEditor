#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolColorModifier.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolPixelChecker.h"

class CSelecColor : public virtual CTool, virtual CToolColorModifier, virtual CToolPixelChecker
{
// CONSTRUCTOR
public:
	CSelecColor();
	~CSelecColor() {}

// METHODS
public:
	void use() override;
private:
	void pickNoSelec();
	void pickWithSelec();
	void end_selec(int type);

// MEMBERS
private:
	sf::Image* test_image;
	sf::Image bit_image;

	std::vector<CTool::line_conf> conf_lines;
};

