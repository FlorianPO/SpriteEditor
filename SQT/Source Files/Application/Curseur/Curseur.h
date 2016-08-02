#pragma once

#include "stdenum.h"

#define INIT_CURSEUR Curseur::createInstance();
#define CURSEUR Curseur::getInstance()

class Curseur 
{
// INSTANCE
private:	static Curseur* _t; 
public:		inline static void createInstance() { _t = new Curseur(); }
			inline static Curseur* getInstance() { return _t; }

// CONSTRUCTOR
public:
	Curseur();
	~Curseur() {}

// METHODS
public:
	void display();
	void setPosition(sf::Vector2f pos);

	inline sf::Vector2f getPosition() { return position; }
	void gerer(sf::Sprite* sprite);
	void init(sf::Sprite* sprite);

// MEMBERS
private:
	std::vector<sf::VertexArray> lines;
	sf::Vector2f position;
	sf::Vector2f start_pos;
};

