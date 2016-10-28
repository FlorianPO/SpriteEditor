#include "HorizontalLayout.h"

HorizontalLayout::HorizontalLayout(bool up_to_down, QPoint topLeft) : Layout(up_to_down, topLeft) {}

void HorizontalLayout::refresh() {
	int prevWidgetXRight = topLeftPos.x();

	FOR_I (widget_list.size()) {
		if (widget_list[i]->isVisible()) {
			if (i > 0)
				prevWidgetXRight += spacing_list[i - 1];

			widget_list[i]->move(QPoint(prevWidgetXRight, topLeftPos.y()));
			prevWidgetXRight += spacing + widget_list[i]->width();
		}
	}
}