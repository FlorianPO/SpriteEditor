#pragma once

#include "stdafx.h"

class TabObject : public QObject
{
	Q_OBJECT
// CONSTRUCTORS
public:
	TabObject() {}
	virtual ~TabObject() {}

// METHODS
	virtual void draw(sf::RenderWindow* fenetre) = 0;
	virtual sf::FloatRect getBounds() = 0;

	virtual void setPosition(sf::Vector2f pos) = 0;
	void setPosition(float x, float y) { setPosition(sf::Vector2f(x, y)); }
	void setPosition(sf::Vector2i pos) { setPosition(sf::Vector2f(pos.x, pos.y)); }

// SIGNALS SLOTS
	public slots:
		virtual void tabSelect() = 0;
};

