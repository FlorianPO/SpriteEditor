#pragma once

#include "stdenum.h"

class BrushUndo : public nUnk::UndoCommand
{
public:
	BrushUndo(const sf::Vector2f& position);
	~BrushUndo() {}
	void undo() override;
	void redo() override;

	const sf::Vector2f& getPosition() const { return position; }

private:
	sf::Vector2f position;
};