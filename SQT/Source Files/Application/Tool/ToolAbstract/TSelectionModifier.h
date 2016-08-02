#pragma once

#include "stdenum.h"
#include "Source Files/Application/Tool/Tool.h"

class TSelectionModifier : public Tool
{
// CONSTRUCTOR
public:
	TSelectionModifier() {}
	virtual ~TSelectionModifier() {}

// METHODS
protected:
	void display() override;

	void endSelection(nSet::FuseMode fuse_mode);
	void endSelection(nSet::FuseMode fuse_mode, const sf::Image& bit_image);

// MEMBERS
protected:
	nSet::OrientedLines oriented_lines;
};
