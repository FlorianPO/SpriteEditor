#pragma once

#include "List.h"

class GridList : public List
{
// CONSTRUCTOR
public:
	GridList(QWidget* parent, const param& parameters, UndoStack* undo_stack=NULL, SignalList* binded_list=NULL);
	~GridList() {}

// METHODS
public:
	void setTopLeftCorner(const QPoint& point);
	void setBottomRightCorner(const QPoint& point);
private:
	void refresh() override;
	void setLineSize(const QSize& size) override;

// MEMBERS
private:
	struct _corner {
		bool defined = false;
		QPoint point = QPoint();
	};

	_corner up_left;
	_corner down_right;
	int col_nbr;
};

