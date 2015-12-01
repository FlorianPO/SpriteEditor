#pragma once

#include "stdafx.h"
#include "Outil.h"

class CSelecColor : public COutil
{
public:
	CSelecColor(void);
	~CSelecColor(void);

	void use() override;

private:
	void pickNoSelec();
	void pickWithSelec();
	void end_selec(int type);
	bool pixelCheck(sf::Color color);
	void ctrl(sf::Color* color);

private:
	sf::Color target_color;
	sf::Image* test_image;
	sf::Image bit_image;

	std::vector<COutil::line_conf> conf_lines;
};

