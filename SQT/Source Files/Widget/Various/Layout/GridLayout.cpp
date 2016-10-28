#include "GridLayout.h"

GridLayout::GridLayout(QWidget* parent, bool up_to_down) : Layout(up_to_down, QPoint()) {
	this->parent = parent;

	this->parent->installEventFilter(this);
}

bool GridLayout::eventFilter(QObject* object, QEvent* evnt) {
	if (evnt->type() == QEvent::Resize || evnt->type() == QEvent::Show || evnt->type() == QEvent::Hide)
		refresh();	
	return false;
}

void GridLayout::setTopLeftCorner(const QPoint& point) {
	up_left.point = point; 
	up_left.defined = true;
}

void GridLayout::setBottomRightCorner(const QPoint& point) {
	down_right.point = point; 
	down_right.defined = true;
}

void GridLayout::refresh() {
	int prevWidgetYBottom = 0;
	int prevWidgetXRight = 0;

	if (up_left.defined) {
		prevWidgetXRight = up_left.point.x();
		prevWidgetYBottom = up_left.point.y();
	}
	
	FOR_I (widget_list.size()) {
		if (widget_list[i]->isVisible()) {
			widget_list[i]->move(QPoint(prevWidgetXRight, prevWidgetYBottom));
			prevWidgetXRight += spacing + widget_list[i]->width();

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
}