#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/ToolAbstract/TSelectionModifier.h"

class RectSelec : public TSelectionModifier
{
// CONSTRUCTOR
public:
	RectSelec();
	~RectSelec() {}

// METHODS
public:
	void use() override;
private:
	void selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos);

// MEMBERS
private:
	sf::Vector2i ex_center;

// UNDO
public:
	friend class SelecUpdated;
	friend class SelecMoved;
	friend class SelecDeleted;
};

