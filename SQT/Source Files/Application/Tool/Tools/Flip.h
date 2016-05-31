#pragma once

#include "Source Files/Application/Tool/Tool.h"

class CFlip : public CTool
{
// CONSTRUCTOR
public:
	CFlip();
	~CFlip() {}

// METHODS
public:
	void use() override;
};