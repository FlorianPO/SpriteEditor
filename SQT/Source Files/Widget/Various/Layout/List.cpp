#include "List.h"

#include "ListObject.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Application/Input/InputController.h"
#include "ListUndo.h"

List::List(QWidget* parent, const param& parameters, const QPoint& topLeftpos, UndoStack* undo_stack, SignalList* binded_list) {
	this->topLeftPos = topLeftpos;
	this->parameters = parameters;
	this->binded_list = binded_list;	
	this->parent = parent;

	line = new QFrame(parent);
	line->setFrameShape(QFrame::Box);
	line->setFrameShadow(QFrame::Sunken);
	line->hide();

	if (undo_stack == NULL) {
		if (parameters.ensure_undo)
			this->undo_stack = new UndoStack(false);
	}
	else
		this->undo_stack = undo_stack;
}

bool List::eventFilter(QObject* object, QEvent* evnt) {
	if (object == parent) {
		if (evnt->type() == QEvent::Resize)
			refresh();
	}
	else {
		if (evnt->type() == QEvent::Resize && !_cstr)
			refresh();
		else if (evnt->type() == QEvent::MouseButtonPress || evnt->type() == QEvent::MouseButtonDblClick)
			mousePressed(object, static_cast<QMouseEvent*>(evnt));
		else if (evnt->type() == QEvent::MouseButtonRelease)
			mouseReleased(object, static_cast<QMouseEvent*>(evnt));
		else if (evnt->type() == QEvent::MouseMove)
			mouseMoved(object, static_cast<QMouseEvent*>(evnt));
	}
	return false;
}

void List::mousePressed(QObject* object, QMouseEvent* event) {
	if (event->button() == Qt::LeftButton)
		left_clicked = true;
	else if (event->button() == Qt::RightButton) 
		right_clicked = true;

	QMouseEvent* m_event = static_cast<QMouseEvent*>(event);
	click_pos = m_event->pos();
	
	i_widget_click = indexOf(*static_cast<ListObject*>(object));
	i_widget_tmp = i_widget_click;
}


void List::mouseMoved(QObject *object, QMouseEvent* event) {
	if (left_clicked) {
		if (parameters.dragable && !special)
			drag(object, event);
	}
}

void List::mouseReleased(QObject* object, QMouseEvent* event) {
	if (left_clicked) {
		left_clicked = false;
		if (!dragged_once) {
			if (parameters.multi_selection)
				multiSelection(object, event);
			if (!special) {
				if (parameters.selectable) {
					if (parameters.multi_selection)
						ex_i_widget_click = i_widget_click;
					selectOne(*widget_list[i_widget_click]);
				}
				else if (parameters.multi_selection)
					ex_i_widget_click = -1;
			}
		}
		else
			endDrag();
	}
	else if (right_clicked) {
		right_clicked = false;
		if (parameters.multi_selection) {
			_selectBegin();
			FOR_I(widget_list.size())
				widget_list[i]->unselect();
			_selectEnd();
			ex_i_widget_click = -1;
			emit noObject();
		}
	}

	special = false;
	dragging = false;
	dragged_once = false;
}

void List::multiSelection(QObject *object, QMouseEvent* event) {
	int indice_pointed = posOn(static_cast<QWidget*>(object)->pos() + event->pos());

	if (INPUT->pressed(Qt::Key_Shift)) {
		special = true;
		bool done = false;
		_selectBegin();
		if (ex_i_widget_click != -1 && ex_i_widget_click != i_widget_click) {
			int min = std::min(ex_i_widget_click, i_widget_click);
			int max = std::max(ex_i_widget_click, i_widget_click);
			for (int i=min; i <= max; i++)
				widget_list[i]->select();
			done = true;
		}
		if (!done) {
			ex_i_widget_click = i_widget_click;
			widget_list[i_widget_click]->select();
		}
		_selectEnd();
	}
	else if (INPUT->pressed(Qt::Key_Control)) {
		special = true;
		widget_list[indice_pointed]->inverseSelection();
		ex_i_widget_click = -1;
	}
}

void List::drag(QObject *object, QMouseEvent* event) {
	if (!dragging) {
		QPoint point = event->pos() - click_pos;
		if (point.manhattanLength() > 3) {
			dragging = true;
			i_widget_tmp = -1;
		}
	}
	if (dragging) {
		int i_widget_pointed = posOn(static_cast<QWidget*>(object)->pos() + event->pos());
		if (i_widget_pointed == i_widget_click) {
			i_widget_tmp = i_widget_pointed;
			if (line->isVisible()) {
				line->hide();
				line_index = -1;

				refresh();
			}
		}
		else if (i_widget_pointed != -1 && i_widget_pointed != i_widget_tmp) {
			i_widget_tmp = i_widget_pointed;
			if (!line->isVisible())
				line->show();
			
			dragged_once = true;

			_cstr = true; 
			if (i_widget_pointed > i_widget_click)
				setLineAfter(*widget_list[i_widget_pointed]);
			else
				setLineBefore(*widget_list[i_widget_pointed]);
			_cstr = false;
			refresh();
		}
	}
}

void List::endDrag() {
	if (line->isVisible()) {
		int destination = line_index;
		if (destination > i_widget_click)
			destination = destination-1;

		if (parameters.multi_selection)
			ex_i_widget_click = i_widget_click;
				
		line->hide();
		line_index = -1;

		moveElement(i_widget_click, destination);
		if (parameters.ensure_drag)
			if (undo_stack != NULL)
				undo_stack->push(*new ListOrdered(*this, i_widget_click, destination));
	}
}

void List::widgetSelected(ListObject& widget) {
	if (&widget == &getFirstObject())
		emit firstObjectSelected(widget);
	
	if (countSelected() == 1)
		one_selected = &widget;
	else
		one_selected = NULL;

	if (!_slct)
		refreshSelection();
}

void List::widgetUnselected(ListObject& widget) {
	if (&widget == &getFirstObject())
		emit firstObjectUnselected(widget);

	if (!_slct)
		refreshSelection();
}

void List::refreshSelection() {
	if (countSelected() > 0) {
		if (countSelected() == 1) {
			one_object_selected = true;
			emit oneObjectSelected(getFirstObjectSelected());
		}
		else {
			if (one_object_selected) {
				one_object_selected = false;
				emit noMoreOneObjectSelected();
			}
			emit moreThanOneObjectSelected();
		}
			
		emit objectSelected();
	}
	else {
		if (one_object_selected) {
			one_object_selected = false;
			emit noMoreOneObjectSelected();
		}
		emit noObjectSelected();
	}
}

void List::moveElement(int src, int dst) {
	bool tmp_cstr = _cstr;
	_cstr = true;
	
	ListObject* widget_tmp = widget_list[src];
	removeWidget(*widget_list[src]);
	addWidgetAt(*widget_tmp, dst);

	if (!parameters.up_to_down) {
		src = widget_list.size()-1-src;
		dst = widget_list.size()-1-dst;
	}

	if (binded_list != NULL)
		binded_list->moveElement(src, dst);
	emit elementMoved(src, dst);

	_cstr = tmp_cstr;
	if (!_cstr)
		refresh();
}

void List::dropSelected() {
	if (countSelected() > 0) {
		if (parameters.ensure_undo)
			if (undo_stack != NULL)
				undo_stack->beginMacro();

		FOR_I (widget_list.size())
			if (widget_list[i]->isSelected()) {
				widget_list[i]->drop();
				if (parameters.ensure_undo)
					if (undo_stack != NULL)
						undo_stack->push(*new ListDropped(widget_list[i], *this));
			}

		if (parameters.ensure_undo)
			if (undo_stack != NULL)
				undo_stack->endMacro();

		if (!_cstr)
			refresh();
	}
}

void List::startUndoStack() {
	if (!stack_active) {
		stack_active = true;
		undo_stack->startShortcut();
	}
}

void List::stopUndoStack() {
	if (stack_active) {
		stack_active = false;
		undo_stack->stopShortcut();
	}
}

int List::posOn(const QPoint& pos) const {
	FOR_I (widget_list.size())
		if (widget_list[i]->isVisible() && widget_list[i]->geometry().contains(pos))
			return i;

	return -1;
}

int List::indexOf(const ListObject& widget) const {
	FOR_I (widget_list.size())
		if (widget_list[i] == &widget)
			return i;
	return 0;
}

void List::addWidget(ListObject& widget) {
	widget.installEventFilter(this);

	QObject::connect(&widget, &ListObject::deleted, [&](){ this->removeWidget(widget); });
	QObject::connect(&widget, &ListObject::selected, [&](){ this->widgetSelected(widget); });
	QObject::connect(&widget, &ListObject::unselected, [&](){ this->widgetUnselected(widget); });
	QObject::connect(&widget, &ListObject::dropped, [=](){ this->refresh(); });
	QObject::connect(&widget, &ListObject::undropped, [=](){ this->refresh(); });

	if (parameters.up_to_down) {
		widget_list.push_back(&widget);
		spacing_list.push_back(0);
	}
	else {
		widget_list.push_front(&widget);
		spacing_list.push_front(0);
	}

	if (!line_found) {
		setLineSize(widget.size());
		line_found = true;
	}
	
	if (parameters.ensure_undo)
		if (undo_stack != NULL)
			undo_stack->push(*new ListCreated(&widget, *this));

	if (!_cstr)
		refresh();
}

void List::addWidgetAt(ListObject& widget_to_add, int index) {
	widget_to_add.installEventFilter(this);

	widget_list.insert(widget_list.begin() + index, &widget_to_add);
	spacing_list.insert(spacing_list.begin() + index, 0);

	if (!_cstr)
		refresh();
}

void List::setLineAfter(const ListObject& widget) {
	FOR_I (widget_list.size())
		if (widget_list[i] == &widget) {
			line_index = i+1;
			break;
		}
}

void List::setLineBefore(const ListObject& widget) {
	FOR_I (widget_list.size())
		if (widget_list[i] == &widget) {
			line_index = i;
			break;
		}
}

void List::selectOne(ListObject& widget) {
	FOR_I (widget_list.size())
		if (!widget_list[i]->isDropped())
			if (widget_list[i] != &widget)
				widget_list[i]->unselect();
			else
				widget_list[i]->select();
}

ListObject& List::getFirstObject() const {
	if (parameters.up_to_down) {
		FOR_I (widget_list.size())
			if (!widget_list[i]->isDropped())
				return *widget_list[i];	
	}
	else
		FOR_I_INV (widget_list.size())
			if (!widget_list[i]->isDropped())
				return *widget_list[i];

	std::cout << "No object ..." << std::endl;
	return *widget_list[-1];
}

ListObject& List::getFirstObjectSelected() const {
	if (parameters.up_to_down) {
		FOR_I (widget_list.size())
			if (widget_list[i]->isSelected())
				return *widget_list[i];	
	}
	else
		FOR_I_INV (widget_list.size())
			if (widget_list[i]->isSelected())
				return *widget_list[i];
	std::cout << "No widget selected ..." << std::endl;
	return *widget_list[-1];
}

int List::count(bool count_dropped) const {
	if (count_dropped)
		return widget_list.size();

	int nbr = 0;
	FOR_I (widget_list.size())
		if (widget_list[i]->isVisible())
			nbr++;
	return nbr;
}

int List::countSelected() const {
	int nbr = 0;
	FOR_I (widget_list.size())
		if (widget_list[i]->isVisible() && widget_list[i]->isSelected())
			nbr++;
	return nbr;
}

void List::removeWidget(ListObject& widget) {
	FOR_I (widget_list.size())
		if (widget_list[i] == &widget) {
			widget.removeEventFilter(this);
			widget_list.erase(widget_list.begin() + i);
			spacing_list.erase(spacing_list.begin() + i);
			break;
		}
	if (!_cstr)
		refresh();
}

void List::setSpacing(int spacing) {
	this->spacing = spacing;
	if (!_cstr)
		refresh();
}

void List::setLocalSpacing(int spacing) {
	spacing_list[spacing_list.size() - 1] = spacing;
}

void List::_fillBegin() {
	_cstr = true; 
	undo_stack->beginMacro();
}

void List::_fillEnd() {
	_cstr = false; 
	undo_stack->endMacro();
	refresh();
}