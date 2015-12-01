#pragma once

#include "stdafx.h"
#include "Outil.h"

class CBaguette : public COutil
{
public:
	CBaguette(void);
	~CBaguette(void);

	void use() override;

private:
	void algorithmWithSelec();
	void algorithmNoSelec();
	void linearFillWithSelec(int x, int y);
	void linearFillNoSelec(int x, int y);

	bool pixelCheck(sf::Color color);
	void end_selec(int type);
	void ctrl(sf::Color* color);

private:
	sf::Color target_color;
	sf::Image* image;
	sf::Image bit_image;
	
	std::queue<COutil::range_type> ranges;
	std::vector<COutil::line_conf> conf_lines;
};

