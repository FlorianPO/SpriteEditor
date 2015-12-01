#pragma once

#include "stdafx.h"
#include "Outil.h"

class CAero : public COutil
{
public:
	CAero(void);
	~CAero(void);

	void afficher() override;
	void use() override;

private:
	void use_line(sf::Vector2f pos_ini);
	void ctrl(sf::Color* color);

private:
	sf::Vertex line[2];
	sf::Vector2f center;
};

