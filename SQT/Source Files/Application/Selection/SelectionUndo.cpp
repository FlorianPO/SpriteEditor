#include "SelectionUndo.h"

#include "SelectionController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

using namespace nUnk;

//////////
// BASE //
//////////
sf::Image* SelecUndo::getImage()					{ return static_cast<SelecUndo*>(UNDO->getPrevious(instance))->getImage(); }
sf::Vector2f SelecUndo::getPosition()				{ return static_cast<SelecUndo*>(UNDO->getPrevious(instance))->getPosition(); }
nSet::positionned_olines* SelecUndo::getLines()		{ return static_cast<SelecUndo*>(UNDO->getPrevious(instance))->getLines(); }
bool SelecUndo::isInverted()						{ return static_cast<SelecUndo*>(UNDO->getPrevious(instance))->isInverted(); }

/////////////
// UPDATED //
/////////////
SelecUpdated::SelecUpdated(void* instance, sf::Image* image, sf::Vector2f position, nSet::positionned_olines* plines, bool inverted) : SelecUndo(instance) {
	this->image = image;
	this->position = position;
	this->plines = plines;
	this->inverted = inverted;
}

SelecUpdated::~SelecUpdated() {
	delete image;
	delete plines;
}

void SelecUpdated::undo() {
	UNDO->beginSearching();
	auto image = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getImage();
	auto position = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getPosition();
	auto plines = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getLines();
	auto inverted = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->isInverted();
	UNDO->endSearching();

	SELEC->setSelection(image, position, plines, inverted);
}

void SelecUpdated::redo() {
	SELEC->setSelection(image, position, plines, inverted);
}

///////////
// MOVED //
///////////
SelecMoved::SelecMoved(void* instance, sf::Vector2f position) : SelecUndo(instance) {
	this->position = position;
}

void SelecMoved::undo() {
	auto position = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getPosition();
	SELEC->setPosition(position);
}

void SelecMoved::redo() {
	SELEC->setPosition(position);
}

/////////////
// DELETED //
/////////////
SelecDeleted::SelecDeleted(void* instance) : SelecUndo(instance) {}

void SelecDeleted::undo() {
	UNDO->beginSearching();
	auto image = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getImage();
	auto position = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getPosition();
	auto lines = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getLines();
	auto inverted = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->isInverted();
	UNDO->endSearching();

	SELEC->setSelection(image, position, lines, inverted);
}

void SelecDeleted::redo() {
	SELEC->del();
}

//////////////
// INVERTED //
//////////////
SelecInverted::SelecInverted(void* instance, sf::Image* image, bool inverted) : SelecUndo(instance) {
	this->image = image;
	this->inverted = inverted;
}

SelecInverted::~SelecInverted() {
	delete image;
}

void SelecInverted::undo() {
	UNDO->beginSearching();
	auto image = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->getImage();
	auto inverted = static_cast<SelecUndo*>(UNDO->getPrevious(instance, true))->isInverted();
	UNDO->endSearching();

	SELEC->setImage(image);
	SELEC->setInverted(inverted);
}

void SelecInverted::redo() {
	SELEC->setImage(image);
	SELEC->setInverted(inverted);
}