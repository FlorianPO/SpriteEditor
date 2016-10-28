#include "ListUndo.h"

#include "List.h"
#include "ListObject.h"

/////////////
// ORDERED //
/////////////
ListOrdered::ListOrdered(List& vl, int src, int dst) {
	this->list = &vl;
	this->source = src;
	this->destination = dst;
}

void ListOrdered::undo() {
	list->moveElement(destination, source);
	emit list->undoed();
}

void ListOrdered::redo() {
	list->moveElement(source, destination);
	emit list->undoed();
}

/////////////
// CREATED //
/////////////
ListCreated::ListCreated(void* instance, List& vertical_list) {
	this->instance = instance;
	this->list = &vertical_list;
}

ListCreated::~ListCreated() {
	delete static_cast<ListObject*>(instance);
}

void ListCreated::undo() {
	static_cast<ListObject*>(instance)->drop();
	emit list->undoed();
}

void ListCreated::redo() {
	static_cast<ListObject*>(instance)->undrop();
	emit list->undoed();
}

/////////////
// DROPPED //
/////////////
ListDropped::ListDropped(void* instance, List& vertical_list) {
	this->instance = instance;
	this->list = &vertical_list;
}

void ListDropped::undo() {
	static_cast<ListObject*>(instance)->undrop();
	emit list->undoed();
}

void ListDropped::redo() {
	static_cast<ListObject*>(instance)->drop();
	emit list->undoed();
}