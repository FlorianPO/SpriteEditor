#pragma once

#include "stdenum.h"

class CurseurUndo : public nUnk::UndoCommand
{
public:
	CurseurUndo(sf::Vector2f pos, sf::Vector2f ex_pos);
	~CurseurUndo() {}
	void undo() override;
	void redo() override;

private:
	sf::Vector2f pos, ex_pos;
};

