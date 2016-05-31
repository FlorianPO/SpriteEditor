
#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"

class ToolLiner : public virtual CTool
{
// CONSTRUCTOR
public:
	ToolLiner() {}
	virtual ~ToolLiner() {}

// METHODS
protected:
	void calculateLine();
	void drawLine(sf::Vector2f pos_ini, sf::Vector2f pos_fin);
	void displayLine();

// MEMBERS
protected:
	sf::Vertex line[2];
};

