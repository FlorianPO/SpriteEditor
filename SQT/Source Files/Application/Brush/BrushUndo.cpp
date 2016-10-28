#include "BrushUndo.h"

#include "BrushController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

BrushUndo::BrushUndo(const sf::Vector2f& position) {
	this->position = position;
	this->instance = BRUSH_CONTROLLER;
}

void BrushUndo::undo() {
	auto position = static_cast<BrushUndo*>(&UNDO->getPrevious(BRUSH_CONTROLLER, true))->getPosition(); 
	BRUSH_CONTROLLER->_setExPosition(position);
}

void BrushUndo::redo() {
	BRUSH_CONTROLLER->_setExPosition(position);
}