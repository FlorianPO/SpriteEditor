#include "GridList.h"

#include "ListObject.h"

GridList::GridList(QWidget* parent, const param& parameters, UndoStack* undo_stack, SignalList* binded_list)
	: List(parent, parameters, QPoint(), undo_stack, binded_list) {
}

void GridList::setTopLeftCorner(const QPoint& point) {
	if (up_left.point != point || !up_left.defined) {
		up_left.point = point; 
		up_left.defined = true;

		if (!_cstr)
			refresh();
	}
}

void GridList::setBottomRightCorner(const QPoint& point) {
	if (down_right.point != point || !down_right.defined) {
		down_right.point = point;
		down_right.defined = true;

		if (!_cstr)
			refresh();	
	}
}

void GridList::setLineSize(const QSize& size) {
	line->resize(2, size.height());
}

void GridList::refresh() {
	int prevWidgetYBottom = 0;
	int prevWidgetXRight = 0;

	if (up_left.defined) {
		prevWidgetXRight = up_left.point.x();
		prevWidgetYBottom = up_left.point.y();
	}
	
	bool line_displayed = false;
	bool calculate_column = false;

	FOR_I (widget_list.size()) {
		if (!line_displayed && i_widget_click > line_index && i == line_index) {
			line->move(QPoint(prevWidgetXRight, prevWidgetYBottom));
			prevWidgetXRight += spacing + line->width();
			line_displayed = true;
		}

		if (!widget_list[i]->isDropped()) {
			widget_list[i]->move(QPoint(prevWidgetXRight, prevWidgetYBottom));
			prevWidgetXRight += spacing + widget_list[i]->width();
			calculate_column = true;
		}

		if (!line_displayed && i_widget_click < line_index && i+1 == line_index) {
			line->move(QPoint(prevWidgetXRight, prevWidgetYBottom));
			prevWidgetXRight += spacing + line->width();
			line_displayed = true;
		}

		if (calculate_column) {
			calculate_column = false;
			int limit_x;
			//int limit_y;
			if (down_right.defined) {
				limit_x = down_right.point.x();
				//limit_y = down_right.point.y();
			}
			else {
				limit_x = parent->width();
				//limit_y = parent->height();
			}

			if (prevWidgetXRight + widget_list[i]->width() >= limit_x) {
				prevWidgetYBottom += spacing + widget_list[i]->height();
				if (up_left.defined)
					prevWidgetXRight = up_left.point.x();
				else
					prevWidgetXRight = 0;
			}
		}
	}
	if (line_index != -1 && !line_displayed)
		line->move(QPoint(prevWidgetXRight, prevWidgetYBottom));

	if (!dragging)
		emit reordered();

	int size = count();
	if (size == 0)
		emit noObject();
	else if (size == 1)
		emit onlyOneObject();
	else if (size == 2)
		emit moreThanOneObject();
}