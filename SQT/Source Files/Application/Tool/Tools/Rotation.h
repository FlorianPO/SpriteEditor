#pragma once

#include "Source Files/Application/Tool/Tool.h"

class Rotation : public Tool
{
// CONSTRUCTOR
public:
	Rotation();
	~Rotation() {}

// METHODS
public:
	void display() override;
	void use() override;
};