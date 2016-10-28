#pragma once

#include "stdenum.h"
class List;

class ListOrdered : public nUnk::UndoCommand
{
public:
	ListOrdered(List& vl, int src, int dst);
	~ListOrdered() {}
	void undo() override;
	void redo() override;

private:
	List* list;
	int source;
	int destination;
};

class ListCreated : public nUnk::UndoCommand
{
public:
	ListCreated(void* instance, List& vertical_list);
	~ListCreated();
	void undo() override;
	void redo() override;
private:
	List* list;
};

class ListDropped : public nUnk::UndoCommand
{
public:
	ListDropped(void* instance, List& vertical_list);
	~ListDropped() {}
	void undo() override;
	void redo() override;
private:
	List* list;
};