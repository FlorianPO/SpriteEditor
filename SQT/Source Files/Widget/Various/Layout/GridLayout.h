#pragma once

#include "stdenum.h"
#include "Source Files/Widget/Various/Layout/Layout.h"

class GridLayout : public Layout
{
// CONSTRUCTOR
public:
	GridLayout(QWidget* parent, bool up_to_down);
	~GridLayout() {}

// METHODS
public:
	void setTopLeftCorner(const QPoint& point);
	void setBottomRightCorner(const QPoint& point);
private:
	void refresh() override;
	bool eventFilter(QObject* object, QEvent *evnt) override;

// MEMBERS
private:
	struct _corner {
		bool defined = false;
		QPoint point = QPoint();
	};

	QWidget* parent;

	_corner up_left;
	_corner down_right;
};
