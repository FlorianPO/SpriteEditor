#include "LayerUndo.h"

#include "Layer.h"
#include "LayerController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

using namespace nUnk;

//////////
// BASE //
//////////
sf::Image* LayerUndo::getImage()		{ return static_cast<LayerUndo*>(UNDO->getPrevious(instance))->getImage(); }
sf::Vector2f LayerUndo::getPosition()	{ return static_cast<LayerUndo*>(UNDO->getPrevious(instance))->getPosition(); }

/////////////
// CREATED //
/////////////
LayerCreated::LayerCreated(void* layer, sf::Image* image) : LayerUndo(layer) {
	type = LAYER_CREATED;
	this->image = image;
}

LayerCreated::~LayerCreated() {
	delete image;
	LAYER_CONTROLLER->deleteLayer(static_cast<Layer*>(instance));
}

void LayerCreated::undo() {
	LAYER_CONTROLLER->_dropLayer(static_cast<Layer*>(instance));
}

void LayerCreated::redo() {
	LAYER_CONTROLLER->_createLayer(static_cast<Layer*>(instance));
}

///////////
// DRAWN //
///////////
LayerDrawn::LayerDrawn(void* layer, sf::Image* image) : LayerUndo(layer) {
	type = LAYER_DRAWN;
	this->image = image;
}

LayerDrawn::~LayerDrawn() {
	delete image;
}

void LayerDrawn::undo() {
	auto image = static_cast<LayerUndo*>(UNDO->getPrevious(instance, true))->getImage(); 
	static_cast<Layer*>(instance)->setImage(image);
}

void LayerDrawn::redo() {
	static_cast<Layer*>(instance)->setImage(image);
}

///////////
// MOVED //
///////////
LayerMoved::LayerMoved(void* layer, sf::Vector2f position) : LayerUndo(layer) {
	type = LAYER_MOVED;
	this->position = position;
}

void LayerMoved::undo() {
	auto position = static_cast<LayerUndo*>(UNDO->getPrevious(instance, true))->getPosition(); 
	static_cast<Layer*>(instance)->setPosition(position);
}

void LayerMoved::redo() {
	static_cast<Layer*>(instance)->setPosition(position);
}

/////////////
// DROPPED //
/////////////
LayerDropped::LayerDropped(void* layer) : LayerUndo(layer) {
	type = LAYER_DROPPED;
}

void LayerDropped::undo() {
	LAYER_CONTROLLER->_createLayer(static_cast<Layer*>(instance));
}

void LayerDropped::redo() {
	LAYER_CONTROLLER->_dropLayer(static_cast<Layer*>(instance));
}

/////////////
// ORDERED //
/////////////
LayerOrdered::LayerOrdered(int src, int dst) {
	type = LAYER_ORDERED;
	this->source = src;
	this->destination = dst;
}

void LayerOrdered::undo() {
	LAYER_CONTROLLER->_orderLayer(destination, source);
}

void LayerOrdered::redo() {
	LAYER_CONTROLLER->_orderLayer(source, destination);
}