#include "VerticalLayout.h"

VerticalLayout::VerticalLayout(bool up_to_down, QPoint topLeft) : Layout(up_to_down, topLeft) {}

void VerticalLayout::refresh() {
	int prevWidgetYBottom = topLeftPos.y();

	FOR_I (widget_list.size()) {
		if (widget_list[i]->isVisible()) {
			if (i > 0)
				prevWidgetYBottom += spacing_list[i - 1];

			widget_list[i]->move(QPoint(topLeftPos.x(), prevWidgetYBottom));
			prevWidgetYBottom += spacing + widget_list[i]->height();
		}
	}
}