#pragma once

#include "stdenum.h"
#include "Source Files/Application/Action/Action.h"
class Layer;

class RectList : public Action
{
	Q_OBJECT
// CONSTRUCTOR
public:
	RectList() {}
	~RectList() {}

// METHODS
public:
	void use() override;
	const std::vector<sf::IntRect>& getRectList() const { return rect_list; }
	const Layer& getLayer() const { return *layer; }
private:
	sf::IntRect findRect(const sf::Vector2i& pixel_pointed, const sf::Image& image);
	void findRectList(sf::IntRect rect, const sf::Image& image);

// MEMBERS
private:
	std::vector<sf::IntRect> rect_list;
	const Layer* layer;
};