#pragma once

#include "stdenum.h"
#include "List.h"
class SignalList;
class ListObject;
class UndoStack;

class VerticalList : public List
{
// CONSTRUCTOR
public:
	VerticalList(QWidget* parent, const param& parameters, const QPoint& topLeftpos=QPoint(), UndoStack* undo_stack=NULL, SignalList* binded_list=NULL);
	~VerticalList() {}

private:
	void refresh() override;
	void setLineSize(const QSize& size) override;
};
