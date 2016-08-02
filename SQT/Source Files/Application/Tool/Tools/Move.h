#pragma once

#include "Source Files/Application/Tool/Tool.h"

class Move : public Tool
{
// CONSTRUCTOR
public:
	Move();
	~Move() {}

// METHODS
public:
	void use() override;
};

