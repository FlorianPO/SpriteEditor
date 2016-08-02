#pragma once

#include "stdenum.h"

class TLayerUpdater
{
// CONSTRUCTOR
public:
	TLayerUpdater() {}
	virtual ~TLayerUpdater() {}

// METHODS
protected:
	inline static void setLayerChanged() { layer_changed = true; }
	static void checkLayerUpdate(bool force=false);

// MEMBERS
protected:
	static bool layer_changed;
};

