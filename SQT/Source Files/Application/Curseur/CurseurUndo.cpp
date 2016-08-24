#include "CurseurUndo.h"

#include "Curseur.h"

using namespace nUnk;

CurseurUndo::CurseurUndo(sf::Vector2f pos, sf::Vector2f ex_pos) {
	this->pos = pos;
	this->ex_pos = ex_pos;
}

void CurseurUndo::undo() {
	CURSEUR->setPosition(ex_pos);
}

void CurseurUndo::redo() {
	CURSEUR->setPosition(pos);
}