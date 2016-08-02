#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Application/Tool/ToolAbstract/TLiner.h"

class Crayon : public Tool, TLiner
{
// CONSTRUCT
public:
	Crayon();
	~Crayon() {}

// METHODS
public:
	void display() override;
	void use() override;
};

