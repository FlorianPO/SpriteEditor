#pragma once

#include "stdafx.h"

#define BROSSE CBrosse::_t
class CBrosse
{
public:
	static CBrosse* _t;
public:
	CBrosse(void);
	~CBrosse(void);
public:
	void afficher(sf::Vector2f center);
	void create_from(sf::Image* image);
	void setPosition(sf::Vector2f center);
	void setColor(sf::Color* color);
	void changeOpacity();
	sf::Vector2f centerOf(sf::Vector2f center);

	void changeBrosse(int x);

	inline sf::Vector2i getSize() { return size; }
	inline sf::Sprite* getSprite() { return &b_sprite; }

	bool onCadre();

	int which_brosse;
	sf::Vector2i size;
private:
	int alpha_cercle(sf::Vector2f pos, sf::Vector2f center);
	void cercle(float rx, float ry, sf::Image* image, bool plein = true);

	int alpha_carre(sf::Vector2f pos, sf::Vector2f center);
	void carre(float rx, float ry, sf::Image* image, bool plein = true);

private:
	sf::Texture b_texture;
	sf::Sprite b_sprite;

	sf::Vector2f hsize;
	sf::Vector2i parite;

	std::vector<sf::VertexArray> l;
	std::vector<sf::VertexArray> l_ini;
};