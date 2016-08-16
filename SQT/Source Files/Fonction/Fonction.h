#pragma once

#include "stdenum.h"

namespace Fonction
{
	struct sl_PR {
		sf::Vector2f distance;
		int orientation;
	};

	bool mouseOnSprite(const sf::Sprite* sprite); //Test if mouse is on a given sprite
	bool mouseOnSprite(const sf::Sprite& sprite, const sf::RenderWindow& fenetre); //Test if mouse is on a given sprite on a window
	bool mouseOnRect(sf::FloatRect rect);
	bool mouseOnRect(sf::FloatRect rect, const sf::RenderWindow& fenetre);

	sl_PR selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos, int only = -1, double angle = 0, float seuil = 0);
	sf::Vector2f* selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil);

	bool onCalque(sf::Vector2i vect, const sf::Image& image_courant);
	bool onCalque(sf::Vector2i vect, const sf::Texture& texture_courant);
	sf::Color getColor(sf::Vector2i vect, const sf::Image& image_courant);
	sf::Color getPointedColor();

	bool checkCadre(sf::IntRect* cadre, sf::IntRect cadre_in);
	std::vector<sf::Vector2f>* getPoints(sf::Sprite* sprite);

	void fuseTexture(sf::RenderTexture& render_texture, const sf::Texture& texture_src, sf::Vector2f pos_src);

	/////////////
	// SPECIAL //
	/////////////
	int copy_to_clipboard(sf::Image *image);
	int copy_to_clipboard(std::string string);
	sf::String get_macro();
	sf::Image* get_clipboard();

	//////////
	// MATH //
	//////////
	UINT8 numDigits(int32_t x);
	float floatPart(float f);
	float degToRad(float deg);
	float radToDeg(float rad);
	float norme(sf::Vector2f direction);
	float norme(sf::Vector2i direction);
	float hypothenus(double cote1, double cote2);
	sf::Vector2f rotationGlobal(sf::Vector2f toRot, sf::Vector2f center, double angle, nStd::Angle angle_type=nStd::DEG);
	sf::Vector2f rotationLocal(sf::Vector2f toRot, double angle, nStd::Angle angle_type=nStd::DEG);
	void moveLocaly(sf::Sprite& sprite, sf::Vector2f translation);
	void setGlobalPosition(sf::Sprite& sprite, sf::Vector2f position);
	void setOriginLocally(sf::Sprite& sprite, sf::Vector2f origin);
	void setOriginGlobally(sf::Sprite& sprite, sf::Vector2f origin);
	void flipVertically(sf::Sprite& sprite);
	void flipHorizontally(sf::Sprite& sprite);
	sf::IntRect unionRect(sf::IntRect r1, sf::IntRect r2);
	sf::FloatRect unionRect(sf::FloatRect r1, sf::FloatRect r2);

	//////////////
	// POSITION //
	//////////////
	// CENTER
	sf::Vector2f centerCorner(const sf::Sprite& sprite);
	sf::Vector2f centerCorner(const sf::Texture& texture);
	sf::Vector2f centerCorner(const sf::Image& image);
	sf::Vector2f centerCorner(sf::Vector2i size);
	sf::Vector2f centerCorner(sf::Vector2u size);
	sf::Vector2f centerCorner(sf::Vector2f size);
	sf::Vector2f centerCorner(sf::FloatRect rect);
	sf::Vector2f centerCorner(sf::IntRect rect);
	// TOP LEFT
	sf::Vector2f topLeftCorner(const sf::Sprite& sprite);
	sf::Vector2f topLeftCorner(const sf::Texture& texture);
	sf::Vector2f topLeftCorner(const sf::Image& image);
	sf::Vector2f topLeftCorner(sf::Vector2i size);
	sf::Vector2f topLeftCorner(sf::Vector2u size);
	sf::Vector2f topLeftCorner(sf::Vector2f size);
	sf::Vector2f topLeftCorner(sf::FloatRect rect);
	sf::Vector2f topLeftCorner(sf::IntRect rect);
	// TOP RIGHT
	sf::Vector2f topRightCorner(const sf::Sprite& sprite);
	sf::Vector2f topRightCorner(const sf::Texture& texture);
	sf::Vector2f topRightCorner(const sf::Image& image);
	sf::Vector2f topRightCorner(sf::Vector2i size);
	sf::Vector2f topRightCorner(sf::Vector2u size);
	sf::Vector2f topRightCorner(sf::Vector2f size);
	sf::Vector2f topRightCorner(sf::FloatRect rect);
	sf::Vector2f topRightCorner(sf::IntRect rect);
	// BOTTOM RIGHT
	sf::Vector2f bottomRightCorner(const sf::Sprite& sprite);
	sf::Vector2f bottomRightCorner(const sf::Texture& texture);
	sf::Vector2f bottomRightCorner(const sf::Image& image);
	sf::Vector2f bottomRightCorner(sf::Vector2i size);
	sf::Vector2f bottomRightCorner(sf::Vector2u size);
	sf::Vector2f bottomRightCorner(sf::Vector2f size);
	sf::Vector2f bottomRightCorner(sf::FloatRect rect);
	sf::Vector2f bottomRightCorner(sf::IntRect rect);
	// BOTTOM LEFT
	sf::Vector2f bottomLeftCorner(const sf::Sprite& sprite);
	sf::Vector2f bottomLeftCorner(const sf::Texture& texture);
	sf::Vector2f bottomLeftCorner(const sf::Image& image);
	sf::Vector2f bottomLeftCorner(sf::Vector2i size);
	sf::Vector2f bottomLeftCorner(sf::Vector2u size);
	sf::Vector2f bottomLeftCorner(sf::Vector2f size);
	sf::Vector2f bottomLeftCorner(sf::FloatRect rect);
	sf::Vector2f bottomLeftCorner(sf::IntRect rect);
};

