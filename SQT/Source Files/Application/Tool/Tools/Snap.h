#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolPixelChecker.h"

class CSnap : public virtual CTool, virtual CToolPixelChecker
{
// CONSTRUCTOR
public:
	CSnap();
	~CSnap() {}

// METHODS
public:
	void afficher() override;
	void use() override;
private:
	void snap(sf::Vector2i pos_ini, sf::Vector2i pos);
	void snapping(sf::IntRect rect, sf::Vector2i pos_click);

	void end_selec(int type);

// MEMBERS
private:
	std::vector<CTool::line_conf> conf_lines;
	sf::Image bit_image;
	sf::Image* test_image;

	sf::IntRect rect;
};