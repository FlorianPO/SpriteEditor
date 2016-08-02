#pragma once

#include "stdenum.h"

class SignalInit
{
// CONSTRUCTOR
public:
	SignalInit();
	virtual ~SignalInit() {}

// METHODS
public:
	static void emitSignals();
protected:
	virtual void initSignals() = 0;

// MEMBERS
private:
	static std::vector<SignalInit*> init_list;
};

