#pragma once

#include "stdenum.h"

class TabObject : public QObject
{
	Q_OBJECT
// CONSTRUCTORS
public:
	TabObject() {}
	virtual ~TabObject() {}

// METHODS
public:
	virtual void draw(sf::RenderWindow& fenetre) = 0;
	virtual sf::FloatRect getBounds() const = 0;

	virtual void setPosition(const sf::Vector2f& pos) = 0;
	void setPosition(float x, float y) { setPosition(sf::Vector2f(x, y)); }
	void setPosition(const sf::Vector2i& pos) { setPosition(sf::Vector2f(ARG_VECTOR(pos))); }

// SIGNALS SLOTS
	public slots:
		virtual void tabSelect() = 0;
};

