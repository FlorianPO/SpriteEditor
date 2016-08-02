#pragma once

#include "Source Files/Application/Tool/Tool.h"

class Flip : public Tool
{
// CONSTRUCTOR
public:
	Flip();
	~Flip() {}

// METHODS
public:
	void use() override;
};