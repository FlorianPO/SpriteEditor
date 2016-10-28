#include "CopyUndo.h"

#include "CopyController.h"
#include "Copy.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

using namespace nUnk;

//////////
// BASE //
//////////
sf::Vector2f CopyUndo::getPosition() const	{ return static_cast<CopyUndo*>(&UNDO->getPrevious(instance))->getPosition(); }
sf::Vector2f CopyUndo::getScale() const		{ return static_cast<CopyUndo*>(&UNDO->getPrevious(instance))->getScale(); }
float CopyUndo::getRotation() const			{ return static_cast<CopyUndo*>(&UNDO->getPrevious(instance))->getRotation(); }
sf::Vector2f CopyUndo::getOrigin() const	{ return static_cast<CopyUndo*>(&UNDO->getPrevious(instance))->getOrigin(); }

/////////////
// CREATED //
/////////////
CopyCreated::CopyCreated(void* copy, const sf::Vector2f& position) : CopyUndo(copy) {
	this->position = position;
}

CopyCreated::~CopyCreated() {
	COPY_CONTROLLER->deleteCopy(*static_cast<Copy*>(instance));
}

void CopyCreated::undo() {
	COPY_CONTROLLER->_dropCopy(*static_cast<Copy*>(instance));
}

void CopyCreated::redo() {
	COPY_CONTROLLER->_createCopy(*static_cast<Copy*>(instance));
}

/////////////
// DROPPED //
/////////////
CopyDropped::CopyDropped(void* copy) : CopyUndo(copy) {}

void CopyDropped::undo() {
	COPY_CONTROLLER->_createCopy(*static_cast<Copy*>(instance));
}

void CopyDropped::redo() {
	COPY_CONTROLLER->_dropCopy(*static_cast<Copy*>(instance));
}

///////////
// MOVED //
///////////
CopyMoved::CopyMoved(void* copy, const sf::Vector2f& position) : CopyUndo(copy) {
	this->position = position;
}

void CopyMoved::undo() {
	auto position = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getPosition(); 
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

void CopyMoved::redo() {
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

////////////
// SCALED //
////////////
CopyScaled::CopyScaled(void* copy, const sf::Vector2f& position, const sf::Vector2f& scale, const sf::Vector2f& origin) : CopyUndo(copy) {
	this->position = position;
	this->scale = scale;
	this->origin = origin;
}

void CopyScaled::undo() {
	UNDO->beginSearching();
	auto position = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getPosition(); 
	auto scale = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getScale(); 
	auto origin = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getOrigin();
	UNDO->endSearching();
	static_cast<Copy*>(instance)->setScale(scale);
	static_cast<Copy*>(instance)->setOrigin(origin);
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

void CopyScaled::redo() {
	static_cast<Copy*>(instance)->setOrigin(origin);
	static_cast<Copy*>(instance)->setScale(scale);
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

/////////////
// ROTATED //
/////////////
CopyRotated::CopyRotated(void* copy, const sf::Vector2f& position, float rotation, const sf::Vector2f& origin) : CopyUndo(copy) {
	this->position = position;
	this->rotation = rotation;
	this->origin = origin;
}

void CopyRotated::undo() {
	UNDO->beginSearching();
	auto position = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getPosition(); 
	auto rotation = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getRotation();
	auto origin = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getOrigin();
	UNDO->endSearching();
	static_cast<Copy*>(instance)->setRotation(rotation);
	static_cast<Copy*>(instance)->setOrigin(origin);
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

void CopyRotated::redo() {
	static_cast<Copy*>(instance)->setOrigin(origin);
	static_cast<Copy*>(instance)->setRotation(rotation);
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

/////////////
// FLIPPED //
/////////////
CopyFlipped::CopyFlipped(void* copy, const sf::Vector2f& position, const sf::Vector2f& scale) : CopyUndo(copy) {
	this->position = position;
	this->scale = scale;
}

void CopyFlipped::undo() {
	UNDO->beginSearching();
	auto position = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getPosition();
	auto scale = static_cast<CopyUndo*>(&UNDO->getPrevious(instance, true))->getScale(); 
	UNDO->endSearching();
	static_cast<Copy*>(instance)->setScale(scale);
	static_cast<Copy*>(instance)->setGlobalPosition(position);
}

void CopyFlipped::redo() {
	static_cast<Copy*>(instance)->setScale(this->scale);
	static_cast<Copy*>(instance)->setGlobalPosition(this->position);
}