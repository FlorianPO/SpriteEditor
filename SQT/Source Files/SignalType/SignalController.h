#pragma once

#include "stdafx.h"

class SignalController
{
// CONSTRUCTOR
public:
	SignalController();
	virtual ~SignalController() {}

// METHODS
public:
	static void emitSignals();
protected:
	virtual void initSignals() = 0;

// MEMBERS
private:
	static std::vector<SignalController*> init_list;
};

