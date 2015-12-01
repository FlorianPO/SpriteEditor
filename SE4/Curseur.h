#pragma once

#include "stdafx.h"

#define CURSEUR CCurseur::_t
class CCurseur
{
public:
	static CCurseur* _t;
public:
	CCurseur(void);
	~CCurseur(void);
public:
	void afficher();
	void setPosition(sf::Vector2f pos);
	inline sf::Vector2f getPosition() { return position; }
	void gerer(sf::Sprite* sprite);
	void ini(sf::Sprite* sprite);
private:
	std::vector<sf::VertexArray> lines;
	sf::Vector2f position;
};

