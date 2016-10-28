#pragma once

#include "stdenum.h"
#include "List.h"
class SignalList;
class ListObject;
class UndoStack;

class HorizontalList : public List
{
// CONSTRUCTOR
public:
	HorizontalList(QWidget* parent, const param& parameters, const QPoint& topLeftpos=QPoint(), UndoStack* undo_stack=NULL, SignalList* binded_list=NULL);
	~HorizontalList() {}

private:
	void refresh() override;
	void setLineSize(const QSize& size) override;
};

