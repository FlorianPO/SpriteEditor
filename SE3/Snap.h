#pragma once

#include "stdafx.h"
#include "Outil.h"

class CSnap : public COutil
{
public:
	CSnap();
	~CSnap();

	void afficher() override;
	void use() override;

private:
	void snap(sf::Vector2i pos_ini, sf::Vector2i pos);
	bool pixelCheck(sf::Color color);
	void snapping(sf::IntRect rect, sf::Vector2i pos_click);

	void end_selec(int type);

private:
	std::vector<COutil::line_conf> conf_lines;
	sf::Image bit_image;
	sf::Image* test_image;
	sf::Color target_color;

	sf::IntRect rect;
};