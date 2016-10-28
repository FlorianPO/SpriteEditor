#include "LayerUndo.h"

#include "Layer.h"
#include "LayerController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

//////////
// BASE //
//////////
sf::Image* LayerUndo::getImage() const			{ return static_cast<LayerUndo*>(&UNDO->getPrevious(instance))->getImage(); }
sf::Vector2f LayerUndo::getPosition() const		{ return static_cast<LayerUndo*>(&UNDO->getPrevious(instance))->getPosition(); }

/////////////
// CREATED //
/////////////
LayerCreated::LayerCreated(void* layer, sf::Image& image) : LayerUndo(layer) {
	this->image = &image;
}

LayerCreated::~LayerCreated() {
	delete image;
	delete static_cast<Layer*>(instance);
}

void LayerCreated::undo() {
	LAYER_CONTROLLER->_dropLayer(*static_cast<Layer*>(instance));
}

void LayerCreated::redo() {
	LAYER_CONTROLLER->_createLayer(*static_cast<Layer*>(instance));
}

///////////
// DRAWN //
///////////
LayerDrawn::LayerDrawn(void* layer, sf::Image& image) : LayerUndo(layer) {
	this->image = &image;
}

LayerDrawn::~LayerDrawn() {
	delete image;
}

void LayerDrawn::undo() {
	auto image = static_cast<LayerUndo*>(&UNDO->getPrevious(instance, true))->getImage(); 
	static_cast<Layer*>(instance)->setImage(*image);
	static_cast<Layer*>(instance)->layerUpdated();
}

void LayerDrawn::redo() {
	static_cast<Layer*>(instance)->setImage(*image);
	static_cast<Layer*>(instance)->layerUpdated();
}

///////////
// MOVED //
///////////
LayerMoved::LayerMoved(void* layer, const sf::Vector2f& position) : LayerUndo(layer) {
	this->position = position;
}

void LayerMoved::undo() {
	auto position = static_cast<LayerUndo*>(&UNDO->getPrevious(instance, true))->getPosition(); 
	static_cast<Layer*>(instance)->setPosition(position);
}

void LayerMoved::redo() {
	static_cast<Layer*>(instance)->setPosition(position);
}

/////////////
// DROPPED //
/////////////
LayerDropped::LayerDropped(void* layer) : LayerUndo(layer) {}

void LayerDropped::undo() {
	LAYER_CONTROLLER->_createLayer(*static_cast<Layer*>(instance));
}

void LayerDropped::redo() {
	LAYER_CONTROLLER->_dropLayer(*static_cast<Layer*>(instance));
}