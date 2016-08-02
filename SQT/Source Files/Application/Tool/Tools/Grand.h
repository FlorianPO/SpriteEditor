#pragma once

#include "Source Files/Application/Tool/Tool.h"

class Grand : public Tool
{
// CONSTRUCTOR
public:
	Grand();
	~Grand() {}

// METHODS
public:
	void use() override;
	void display() override;
};