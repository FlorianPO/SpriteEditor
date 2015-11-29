#pragma once

#include "stdafx.h"
#include "Calque.h"

class CFonction
{
public:
	static bool onSprite(const sf::Sprite* sprite); //Test if mouse is on a given sprite
	static int change_number(); //Increment offset based on a normalized method

	static sf::Vector2f selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos);
	static sf::Vector2f* selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil);

	static sf::Vector2f pointed(sf::Vector2i vect); //Retourne la coordonnée pointée

	static bool onCalque(sf::Vector2i vect, const sf::Image* image_courant);
	static bool onCalque(sf::Vector2i vect, const sf::Texture* texture_courant);
	static sf::Color getColor(sf::Vector2i vect, const sf::Image* image_courant);

	static float hypothenus(float cote1, float cote2);
	static void increment(int* var, int incr, sf::Vector2i intervalle);
	static void increment(sf::Uint8* var, int incr);

	static int copy_to_clipboard(sf::Image *image);
	static int copy_to_clipboard(std::string string);

	static void copy();
	static void paste();
	static bool checkCadre(sf::IntRect* cadre, sf::IntRect cadre_in);

	static float norme(sf::Vector2f direction);
	static float norme(sf::Vector2i direction);
	static sf::IntRect FloatRectToIntRect(sf::FloatRect rect);
	static sf::Vector2f centerSprite(const sf::Sprite* sprite);
	static sf::Vector2f cornerSprite(const sf::Sprite* sprite);
	static std::vector<sf::Vector2f>* getPoints(sf::Sprite* sprite);

	static sf::String get_macro();
	static sf::Image* get_clipboard();

	static void line(sf::Vector2f pos_ini, sf::Vector2f pos_fin, CCalque* calque);
	static void maj(sf::Vector2f* pos, sf::Vertex* line);
};

