#pragma once

#include "Source Files/Application/Action/Action.h"
class Layer;

class Rect : public Action
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Rect(const Layer& layer);
	~Rect() {}

// METHODS
public:
	void use() override;
	const sf::IntRect& getRect() const { return rect; }
	const Layer& getLayer() const { return *layer; }
private:
	sf::IntRect findRect(const sf::Vector2i& pixel_pointed, const sf::Image& image);

// MEMBERS
private:
	sf::IntRect rect;
	const Layer* layer;
};

