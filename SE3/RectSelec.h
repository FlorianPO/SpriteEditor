#pragma once

#include "stdafx.h"
#include "Outil.h"

class CRectSelec : public COutil
{
public:
	CRectSelec(void);
	~CRectSelec(void);

	void afficher() override;
	void use() override;

private:
	void selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos);
	void end_selec(int type);

private:
	sf::IntRect rect;
	sf::Vector2i ex_center;
	int key;
	bool active;

	std::vector<COutil::line_conf> conf_lines;
};

