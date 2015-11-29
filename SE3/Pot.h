#pragma once

#include "stdafx.h"
#include "Outil.h"

class CPot : public COutil
{
public:
	CPot(void);
	~CPot(void);

	void use() override;

	static void full_dessiner(sf::Color color);

private:
	void dessiner();
	void linearFill(int x, int y);
	bool pixelCheck(sf::Color color);
	void ctrl(sf::Color* color);

private:
	sf::Color fill_color, target_color;
	sf::Image* test_image;
	sf::Image bit_image;
	sf::Image image;

	std::queue<COutil::range_type> ranges;
};

