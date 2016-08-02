#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/TLiner.h"

class Aero : public Tool, TLiner
{
// CONSTRUCTOR
public:
	Aero();
	~Aero() {}

// METHODS
public:
	void display() override;
	void use() override;
};

