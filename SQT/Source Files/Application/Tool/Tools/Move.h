#pragma once

#include "Source Files/Application/Tool/Tool.h"

class CMove : public CTool
{
// CONSTRUCTOR
public:
	CMove();
	~CMove() {}

// METHODS
public:
	void use() override;
};

