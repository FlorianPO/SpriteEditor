#include "VerticalLayout.h"

VerticalLayout::VerticalLayout(QPoint topLeft, bool upToDown, bool dragable, QWidget* parent) {
	topLeftPos = topLeft;
	this->upToDown = upToDown;
	this->dragable = dragable;
	if (dragable) {
		clicked = false;
		dragging = false;
	
		this->parent = parent;
		line = new QFrame(parent);
		line->resize(parent->size().width(), 2);
		line->setFrameShape(QFrame::HLine);
		line->setFrameShadow(QFrame::Sunken);
		line->hide();
	}
}

bool VerticalLayout::eventFilter(QObject* object, QEvent* evnt) {
	if (evnt->type() == QEvent::Resize || evnt->type() == QEvent::Show || evnt->type() == QEvent::Hide)
		refresh();
	else if (dragable) {
		if (evnt->type() == QEvent::MouseButtonPress) {
			clicked = true;
			QMouseEvent* m_event = static_cast<QMouseEvent*>(evnt);
			click_pos = m_event->pos();
		}
		else if (evnt->type() == QEvent::MouseButtonRelease) {
			clicked = false;
			if (dragging) {
				_fillBegin();

				int index_moved=0;
				bool line_found = false;
				FOR_I (widget_list.size()) {
					if (widget_list[i] == line)
						line_found = true;
					else if (widget_list[i] == widget_dragged) {
						index_moved = i;
						if (line_found)
							index_moved--;
						break;
					}
				}

				removeWidget(widget_dragged, false);
				addWidgetAfter(widget_dragged, line);
				
				dragging = false;
				line->hide();
				removeWidget(line, false);

				int destination=0;
				FOR_I (widget_list.size()) {
					if (widget_list[i] == widget_dragged) {
						destination = i;
						break;
					}
				}
				_fillEnd();

				if (!upToDown) {
					index_moved = widget_list.size()-1-index_moved;
					destination = widget_list.size()-1-destination;
				}
				emit elementMoved(index_moved, destination);	
			}
		}
		else if (evnt->type() == QEvent::MouseMove) {
			if (clicked) {
				QMouseEvent* m_event = static_cast<QMouseEvent*>(evnt);
				if (!dragging) {
					QPoint point = m_event->pos() - click_pos;
					if (point.manhattanLength() > 3) {
						dragging = true;
						widget_dragged = static_cast<QWidget*>(object);
						ex_widget_pointed = NULL;
					}
				}
				if (dragging) {
					QWidget* widget_pointed = posOn(static_cast<QWidget*>(object)->pos() + m_event->pos(), line);
					if (widget_pointed == widget_dragged) {
						dragging = false;
						line->hide();
						removeWidget(line, false);
					}
					else if (widget_pointed != NULL && widget_pointed != ex_widget_pointed) {
						if (!line->isVisible())
							line->show();
						ex_widget_pointed = widget_pointed;
						_fillBegin();
						removeWidget(line, false);
						if (widget_pointed->pos().y() > widget_dragged->pos().y())
							addWidgetAfter(line, widget_pointed, false);
						else
							addWidgetBefore(line, widget_pointed, false);
						_fillEnd();
					}
				}
			}
		}
	}
	return false;
}

void VerticalLayout::moveElement(int src, int dst) {
	if (!upToDown) {
		src = widget_list.size()-1-src;
		dst = widget_list.size()-1-dst;
	}
	QWidget* widget = widget_list[src];
	widget_list.erase(widget_list.begin() + src);
	widget_list.insert(widget_list.begin() + dst, widget);	

	if (!_cstr)
		refresh();
}

QWidget* VerticalLayout::posOn(const QPoint& pos, QWidget* ignore_me) {
	FOR_I (widget_list.size()) {
		if (widget_list[i] == ignore_me)
			continue;
		if (widget_list[i]->geometry().contains(pos))
			return widget_list[i];
	}
	return NULL;
}

void VerticalLayout::addWidget(QWidget* widget, bool filter) {
	if (filter)
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

void VerticalLayout::addWidgetAfter(QWidget* widget_to_add, QWidget* after, bool filter) {
	if (filter)
		widget_to_add->installEventFilter(this);

	FOR_I (widget_list.size()) {
		if (widget_list[i] == after) {
			widget_list.insert(widget_list.begin() + i+1, widget_to_add);
			spacing_list.insert(spacing_list.begin() + i+1, 0);
			break;
		}
	}
	widget_to_add->move(topLeftPos);
	if (!_cstr)
		refresh();
}

void VerticalLayout::addWidgetBefore(QWidget* widget_to_add, QWidget* before, bool filter) {
	if (filter)
		widget_to_add->installEventFilter(this);

	FOR_I (widget_list.size()) {
		if (widget_list[i] == before) {
			widget_list.insert(widget_list.begin() + i, widget_to_add);
			spacing_list.insert(spacing_list.begin() + i, 0);
			break;
		}
	}
	widget_to_add->move(topLeftPos);
	if (!_cstr)
		refresh();
}

void VerticalLayout::removeWidget(QWidget* widget, bool del) {
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

void VerticalLayout::setSpacing(int spacing) {
	this->spacing = spacing;
	if (!_cstr)
		refresh();
}

void VerticalLayout::setLocalSpacing(int spacing) {
	spacing_list[spacing_list.size() - 1] = spacing;
}

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