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
	bool hasSmoothLine();

	void calculateLine();
	void drawLine(sf::Vector2f pos_from, sf::Vector2f pos_to);
	void drawSmoothLine();
	void displayLine();

private:
	void _drawLine(sf::Vector2f pos_from, sf::Vector2f pos_to);

// MEMBERS
protected:
	sf::Vertex line[2];
};

