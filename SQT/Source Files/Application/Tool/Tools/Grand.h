#pragma once

#include "Source Files/Application/Tool/Tool.h"

class CGrand : public CTool
{
// CONSTRUCTOR
public:
	CGrand();
	~CGrand() {}

// METHODS
public:
	void use() override;
	void afficher() override;
};