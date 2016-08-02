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
	void calculateLine();
	void drawLine(sf::Vector2f pos_from, sf::Vector2f pos_to);
	void displayLine();

// MEMBERS
protected:
	sf::Vertex line[2];
};

