#include "Layout.h"

Layout::Layout(bool up_to_down, const QPoint& topLeft) {
	topLeftPos = topLeft;
	this->up_to_down = up_to_down;
}

bool Layout::eventFilter(QObject* object, QEvent* evnt) {
	if (evnt->type() == QEvent::Resize || evnt->type() == QEvent::Show || evnt->type() == QEvent::Hide)
		refresh();
	return false;
}

void Layout::addWidget(QWidget* widget) {
	widget->installEventFilter(this);

	if (up_to_down) {
		widget_list.push_back(widget);
		spacing_list.push_back(0);
	}
	else {
		widget_list.push_front(widget);
		spacing_list.push_front(0);
	}

	if (!_cstr)
		refresh();
}

void Layout::removeWidget(QWidget* widget, bool del) {
	FOR_I (widget_list.size())
		if (widget_list[i] == widget) {
			widget->removeEventFilter(this);
			if (del)
				delete widget;
			widget_list.erase(widget_list.begin() + i);
			spacing_list.erase(spacing_list.begin() + i);
			if (!_cstr)
				refresh();
			break;
		}
}

void Layout::setSpacing(int spacing) {
	this->spacing = spacing;
	if (!_cstr)
		refresh();
}

void Layout::setLocalSpacing(int spacing) {
	spacing_list[spacing_list.size() - 1] = spacing;
}
