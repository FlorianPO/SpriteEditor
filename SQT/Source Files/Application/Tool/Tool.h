#pragma once

#include "stdenum.h"

class Tool
{
// CONSTRUCTOR
public:
	Tool() {}
	virtual ~Tool() {}

// METHODS
public:
	inline nTol::tool_enum getEnum() const { return numero_outil; }
	inline int getId() const { return static_cast<int>(numero_outil); }

	virtual void display() {}
	virtual void use() {}

// MEMBERS
protected:
	nTol::tool_enum numero_outil;
};

