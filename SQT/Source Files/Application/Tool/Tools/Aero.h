#pragma once

#include "stdafx.h"

#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolColorModifier.h"
#include "Source Files/Application/Tool/ToolAbstract/ToolLiner.h"

class CAero : public virtual CTool, virtual CToolColorModifier, virtual ToolLiner
{
// CONSTRUCTOR
public:
	CAero();
	~CAero() {}

// METHODS
public:
	void afficher() override;
	void use() override;
private:
	void use_line(sf::Vector2f pos_ini);
};

