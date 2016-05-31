#pragma once

#include "Source Files/Application/Tool/Tool.h"

class CRotation : public CTool
{
// CONSTRUCTOR
public:
	CRotation();
	~CRotation() {}

// METHODS
public:
	void afficher() override;
	void use() override;
};