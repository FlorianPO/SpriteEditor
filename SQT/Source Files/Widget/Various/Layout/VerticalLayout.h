#pragma once

#include "stdenum.h"
#include "Layout.h"

class VerticalLayout : public Layout
{
// CONSTRUCTOR
public:
	VerticalLayout(bool up_to_down, QPoint topLeft=QPoint());
	~VerticalLayout() {}

// METHODS
private:
	void refresh() override;
};