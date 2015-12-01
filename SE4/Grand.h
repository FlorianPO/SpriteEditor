#pragma once

#include "Outil.h"

class CGrand : public COutil
{
public:
	CGrand();
	~CGrand();

	void use() override;
	void afficher() override;
};