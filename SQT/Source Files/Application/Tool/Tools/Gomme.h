#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/TLiner.h"

class Gomme : public virtual Tool, TLiner
{
// CONSTRUCTOR
public:
	Gomme();
	~Gomme() {}

// METHODS
public:
	void display() override;
	void use() override;
};

