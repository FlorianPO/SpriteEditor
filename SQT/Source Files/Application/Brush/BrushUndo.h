#pragma once

#include "stdenum.h"

// LAYER_CONTROLLER
class BrushUndo : public nUnk::UndoCommand
{
public:
	BrushUndo(sf::Vector2f position);
	~BrushUndo() {}
	void undo() override;
	void redo() override;

	sf::Vector2f getPosition();

private:
	sf::Vector2f position;
};