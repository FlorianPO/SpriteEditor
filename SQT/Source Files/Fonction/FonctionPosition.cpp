#include "Fonction.h"

////////////
// CENTER //
////////////
sf::Vector2f Fonction::centerCorner(const sf::Sprite& sprite)		{ return centerCorner(sprite.getGlobalBounds()); }
sf::Vector2f Fonction::centerCorner(const sf::Texture& texture)		{ return H_VECTOR2F(texture.getSize()); }
sf::Vector2f Fonction::centerCorner(const sf::Image& image)			{ return H_VECTOR2F(image.getSize()); }
sf::Vector2f Fonction::centerCorner(sf::Vector2i size)				{ return H_VECTOR2F(size); }
sf::Vector2f Fonction::centerCorner(sf::Vector2u size)				{ return H_VECTOR2F(size); }
sf::Vector2f Fonction::centerCorner(sf::Vector2f size)				{ return H_VECTOR2F(size); }
sf::Vector2f Fonction::centerCorner(sf::FloatRect rect)				{ return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f); }
sf::Vector2f Fonction::centerCorner(sf::IntRect rect)				{ return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f); }

//////////////
// TOP LEFT //
//////////////
sf::Vector2f Fonction::topLeftCorner(const sf::Sprite& sprite)		{ return topLeftCorner(sprite.getGlobalBounds()); }
sf::Vector2f Fonction::topLeftCorner(const sf::Texture& texture)	{ return sf::Vector2f(); }
sf::Vector2f Fonction::topLeftCorner(const sf::Image& image)		{ return sf::Vector2f(); }
sf::Vector2f Fonction::topLeftCorner(sf::Vector2i size)				{ return sf::Vector2f(); }
sf::Vector2f Fonction::topLeftCorner(sf::Vector2u size)				{ return sf::Vector2f(); }
sf::Vector2f Fonction::topLeftCorner(sf::Vector2f size)				{ return sf::Vector2f(); }
sf::Vector2f Fonction::topLeftCorner(sf::FloatRect rect)			{ return sf::Vector2f(rect.left, rect.top); }
sf::Vector2f Fonction::topLeftCorner(sf::IntRect rect)				{ return sf::Vector2f(rect.left, rect.top); }

///////////////
// TOP RIGHT //
///////////////
sf::Vector2f Fonction::topRightCorner(const sf::Sprite& sprite)			{ return topRightCorner(sprite.getGlobalBounds()); }
sf::Vector2f Fonction::topRightCorner(const sf::Texture& texture)		{ return sf::Vector2f(texture.getSize().x, 0); }
sf::Vector2f Fonction::topRightCorner(const sf::Image& image)			{ return sf::Vector2f(image.getSize().x, 0); }
sf::Vector2f Fonction::topRightCorner(sf::Vector2i size)				{ return sf::Vector2f(size.x, 0); }
sf::Vector2f Fonction::topRightCorner(sf::Vector2u size)				{ return sf::Vector2f(size.x, 0); }
sf::Vector2f Fonction::topRightCorner(sf::Vector2f size)				{ return sf::Vector2f(size.x, 0); }
sf::Vector2f Fonction::topRightCorner(sf::FloatRect rect)				{ return sf::Vector2f(rect.left + rect.width, rect.top); }
sf::Vector2f Fonction::topRightCorner(sf::IntRect rect)					{ return sf::Vector2f(rect.left + rect.width, rect.top); }

//////////////////
// BOTTOM RIGHT //
//////////////////
sf::Vector2f Fonction::bottomRightCorner(const sf::Sprite& sprite)		{ return bottomRightCorner(sprite.getGlobalBounds()); }
sf::Vector2f Fonction::bottomRightCorner(const sf::Texture& texture)	{ return VECTOR2F(texture.getSize()); }
sf::Vector2f Fonction::bottomRightCorner(const sf::Image& image)		{ return VECTOR2F(image.getSize()); }
sf::Vector2f Fonction::bottomRightCorner(sf::Vector2i size)				{ return VECTOR2F(size); }
sf::Vector2f Fonction::bottomRightCorner(sf::Vector2u size)				{ return VECTOR2F(size); }
sf::Vector2f Fonction::bottomRightCorner(sf::Vector2f size)				{ return VECTOR2F(size); }
sf::Vector2f Fonction::bottomRightCorner(sf::FloatRect rect)			{ return sf::Vector2f(rect.left + rect.width, rect.top + rect.height); }
sf::Vector2f Fonction::bottomRightCorner(sf::IntRect rect)				{ return sf::Vector2f(rect.left + rect.width, rect.top + rect.height); }

/////////////////
// BOTTOM LEFT //
/////////////////
sf::Vector2f Fonction::bottomLeftCorner(const sf::Sprite& sprite)		{ return bottomLeftCorner(sprite.getGlobalBounds()); }
sf::Vector2f Fonction::bottomLeftCorner(const sf::Texture& texture)		{ return sf::Vector2f(0, texture.getSize().y); }
sf::Vector2f Fonction::bottomLeftCorner(const sf::Image& image)			{ return sf::Vector2f(0, image.getSize().y); }
sf::Vector2f Fonction::bottomLeftCorner(sf::Vector2i size)				{ return sf::Vector2f(0, size.y); }
sf::Vector2f Fonction::bottomLeftCorner(sf::Vector2u size)				{ return sf::Vector2f(0, size.y); }
sf::Vector2f Fonction::bottomLeftCorner(sf::Vector2f size)				{ return sf::Vector2f(0, size.y); }
sf::Vector2f Fonction::bottomLeftCorner(sf::FloatRect rect)				{ return sf::Vector2f(rect.left, rect.top + rect.height); }
sf::Vector2f Fonction::bottomLeftCorner(sf::IntRect rect)				{ return sf::Vector2f(rect.left, rect.top + rect.height); }