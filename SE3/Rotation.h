#pragma once

#include "Outil.h"

class CRotation : public COutil
{
public:
	CRotation();
	~CRotation();

	void afficher() override;
	void use() override;
};