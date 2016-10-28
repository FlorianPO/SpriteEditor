#pragma once

#include "stdenum.h"
#include "Layout.h"

class HorizontalLayout : public Layout
{
// CONSTRUCTOR
public:
	HorizontalLayout(bool up_to_down, QPoint topLeft=QPoint());
	~HorizontalLayout() {}

// METHODS
private:
	void refresh() override;
};

