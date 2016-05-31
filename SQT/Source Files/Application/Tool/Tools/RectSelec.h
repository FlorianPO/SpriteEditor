#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"

class CRectSelec : public CTool
{
// CONSTRUCTOR
public:
	CRectSelec(void);
	~CRectSelec() {}

// METHODS
public:
	void afficher() override;
	void use() override;
private:
	void selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos);
	void end_selec(int type);

// MEMBERS
private:
	sf::IntRect rect;
	sf::Vector2i ex_center;
	bool active;

	std::vector<CTool::line_conf> conf_lines;
};

