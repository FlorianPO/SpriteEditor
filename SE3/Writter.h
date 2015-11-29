#pragma once

#include "stdafx.h"

#define WRITTER CWritter::_t
class CWritter
{
public:
	static CWritter* _t;
public:
	CWritter(void);
	~CWritter(void);
public:
	sf::String intToString(int x);
	void ecrire(int value, sf::RenderTexture* renderTexture, sf::Vector2i pos = sf::Vector2i(0, 0), sf::Color color = sf::Color::White);
	void ecrire(sf::String string, sf::RenderTexture* renderTexture, sf::Vector2i pos = sf::Vector2i(0, 0), sf::Color color = sf::Color::White);

private:
	std::vector<sf::Sprite> sprite_list;
};

