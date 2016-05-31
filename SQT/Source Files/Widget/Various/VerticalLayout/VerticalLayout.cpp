#include "Source Files/Widget/Various/VerticalLayout/VerticalLayout.h"
#include <QtCore/QEvent>

VerticalLayout::VerticalLayout(QPoint topLeft, bool upToDown) 
{
	topLeftPos = topLeft;
	this->upToDown = upToDown;
}

bool VerticalLayout::eventFilter(QObject* object, QEvent* evnt) {
	if (evnt->type() == QEvent::Resize)
		refresh();
	return false;
}


void VerticalLayout::addWidget(QWidget* widget) {
	widget->installEventFilter(this);

	if (upToDown) {
		widget_list.push_back(widget);
		spacing_list.push_back(0);
	}
	else {
		widget_list.push_front(widget);
		spacing_list.push_front(0);
	}
		
	widget->move(topLeftPos);
	if (!_cstr)
		refresh();
}

void VerticalLayout::removeWidget(QWidget* widget) {
	for (int i=0; i < widget_list.size(); i++)
		if (widget_list[i] == widget) {
			delete widget;
			widget_list.erase(widget_list.begin()+i);
			if (!_cstr)
				refresh();
			break;
		}
}

void VerticalLayout::setSpacing(int spacing) {
	this->spacing = spacing;
	if (!_cstr)
		refresh();
}

void VerticalLayout::setLocalSpacing(int spacing) {
	spacing_list[spacing_list.size()-1] = spacing;
}

void VerticalLayout::refresh() {
	int prevWidgetYBottom;
	for (int i=0; i < widget_list.size(); i++) {
		if (i > 0)
			prevWidgetYBottom = widget_list[i-1]->size().height() + widget_list[i-1]->pos().y() + spacing_list[i-1];
		else
			prevWidgetYBottom = topLeftPos.y() + spacing_list[0];
		prevWidgetYBottom += spacing;

		widget_list[i]->move(QPoint(widget_list[i]->pos().x(), prevWidgetYBottom));
	}
}