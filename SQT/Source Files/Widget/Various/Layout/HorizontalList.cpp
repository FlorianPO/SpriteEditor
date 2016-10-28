#include "HorizontalList.h"

#include "ListObject.h"

HorizontalList::HorizontalList(QWidget* parent, const param& parameters, const QPoint& topLeftpos, UndoStack* undo_stack, SignalList* binded_list)
	: List(parent, parameters, topLeftpos, undo_stack, binded_list) {}

void HorizontalList::setLineSize(const QSize& size) {
	line->resize(2, size.height());
}

void HorizontalList::refresh() {
	int prevWidgetXRight = topLeftPos.x();

	bool line_displayed = false;
	FOR_I (widget_list.size()) {
		if (i == line_index) {
			line->move(QPoint(prevWidgetXRight, topLeftPos.y()));
			prevWidgetXRight += spacing + line->width();
			line_displayed = true;
		}
		if (widget_list[i]->isVisible()) {
			if (i > 0)
				prevWidgetXRight += spacing_list[i - 1];

			widget_list[i]->move(QPoint(prevWidgetXRight, topLeftPos.y()));
			prevWidgetXRight += spacing + widget_list[i]->width();
		}
	}
	if (line_index != -1 && !line_displayed)
		line->move(QPoint(prevWidgetXRight, topLeftPos.y()));

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