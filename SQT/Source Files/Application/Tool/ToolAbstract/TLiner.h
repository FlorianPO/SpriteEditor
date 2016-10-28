#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/ToolAbstract/TLayerUpdater.h"

class TLiner : public TLayerUpdater
{
// CONSTRUCTOR
public:
	TLiner() {}
	virtual ~TLiner() {}

// METHODS
protected:
	bool hasSmoothLine() const;

	void calculateLine();
	void drawLine(const sf::Vector2f& pos_from, const sf::Vector2f& pos_to);
	void drawSmoothLine();
	void displayLine();

private:
	void _drawLine(const sf::Vector2f& pos_from, const sf::Vector2f& pos_to);

// MEMBERS
protected:
	sf::Vertex line[2];
};

