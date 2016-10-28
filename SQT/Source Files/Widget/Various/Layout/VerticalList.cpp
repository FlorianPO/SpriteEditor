#include "VerticalList.h"

#include "ListObject.h"

VerticalList::VerticalList(QWidget* parent, const param& parameters, const QPoint& topLeftpos, UndoStack* undo_stack, SignalList* binded_list)
	: List(parent, parameters, topLeftpos, undo_stack, binded_list) {}

void VerticalList::setLineSize(const QSize& size) {
	line->resize(size.width(), 2);
}

void VerticalList::refresh() {
	int prevWidgetYBottom = topLeftPos.y();

	bool line_displayed = false;
	FOR_I (widget_list.size()) {
		if (i == line_index) {
			line->move(QPoint(topLeftPos.x(), prevWidgetYBottom));
			prevWidgetYBottom += spacing + line->height();
			line_displayed = true;
		}
		if (widget_list[i]->isVisible()) {
			if (i > 0)
				prevWidgetYBottom += spacing_list[i - 1];

			widget_list[i]->move(QPoint(topLeftPos.x(), prevWidgetYBottom));
			prevWidgetYBottom += spacing + widget_list[i]->height();
		}
	}
	if (line_index != -1 && !line_displayed)
		line->move(QPoint(topLeftPos.x(), prevWidgetYBottom));

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