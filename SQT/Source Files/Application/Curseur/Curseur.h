#pragma once

#include "stdafx.h"

#define INIT_CURSEUR CCurseur::createInstance();
#define CURSEUR CCurseur::getInstance()

class CCurseur 
{
// INSTANCE
private:	static CCurseur* _t; 
public:		inline static void createInstance() { _t = new CCurseur(); }
			inline static CCurseur* getInstance() { return _t; }


// CONSTRUCTOR
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

