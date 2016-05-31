#pragma once

#include "stdafx.h"
#include "Source Files/Application/Layer/Layer.h"

class CFonction
{
public:
	struct sl_PR
	{
		sf::Vector2f distance;
		int orientation;
	};

	static sf::Vector2f rotationGlobal(sf::Vector2f toRot, sf::Vector2f center, double angle);
	static sf::Vector2f rotationLocal(sf::Vector2f toRot, double angle);

	static bool onSprite(const sf::Sprite* sprite); //Test if mouse is on a given sprite
	static bool onSprite(const sf::Sprite& sprite, const sf::RenderWindow& fenetre); //Test if mouse is on a given sprite on a window
	static bool onRect(sf::FloatRect rect);
	static bool onRect(sf::FloatRect rect, const sf::RenderWindow& fenetre);
	static int change_number(); //Increment offset based on a normalized method

	static sl_PR selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos, int only = -1, double angle = 0, float seuil = 0);
	static sf::Vector2f* selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil);

	static sf::Vector2f pointed(sf::Vector2i vect); //Retourne la coordonnée pointée à l'écran
	static sf::Vector2i screened(sf::Vector2f vect); //Inverse de pointed

	static bool onCalque(sf::Vector2i vect, const sf::Image& image_courant);
	static bool onCalque(sf::Vector2i vect, const sf::Texture& texture_courant);
	static sf::Color getColor(sf::Vector2i vect, const sf::Image& image_courant);

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
	// CENTER
	static sf::Vector2f centerCorner(const sf::Sprite& sprite);
	static sf::Vector2f centerCorner(const sf::Texture& texture);
	static sf::Vector2f centerCorner(const sf::Image& image);
	static sf::Vector2f centerCorner(sf::Vector2i size);
	static sf::Vector2f centerCorner(sf::Vector2u size);
	static sf::Vector2f centerCorner(sf::Vector2f size);
	static sf::Vector2f centerCorner(sf::FloatRect rect);
	static sf::Vector2f centerCorner(sf::IntRect rect);
	// TOP LEFT
	static sf::Vector2f topLeftCorner(const sf::Sprite& sprite);
	// TOP RIGHT
	static sf::Vector2f topRightCorner(const sf::Sprite& sprite);
	// BOTTOM RIGHT
	static sf::Vector2f bottomRightCorner(const sf::Sprite& sprite);
	// BOTTOM LEFT
	static sf::Vector2f bottomLeftCorner(const sf::Sprite& sprite);

	static std::vector<sf::Vector2f>* getPoints(sf::Sprite* sprite);

	static sf::String get_macro();
	static sf::Image* get_clipboard();
};

