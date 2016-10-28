#include "ListObject.h"

#include "Source Files/SignalType/SignalListObject.h"

ListObject::ListObject(QWidget* parent, SignalListObject* binded_object) : QWidget(parent) {
	this->binded_object = binded_object;

	if (this->binded_object != NULL) {
		QObject::connect(this->binded_object, &SignalListObject::deleted, [this](){ delete this; });
		QObject::connect(this->binded_object, SIGNAL(dropped()), this, SLOT(_drop()));
		QObject::connect(this->binded_object, SIGNAL(undropped()), this, SLOT(_undrop()));
		QObject::connect(this->binded_object, SIGNAL(selected()), this, SLOT(_select()));
		QObject::connect(this->binded_object, SIGNAL(unselected()), this, SLOT(_unselect()));

		b_selected = this->binded_object->isSelected();
		b_dropped = this->binded_object->isDropped();
	}
	else {
		b_selected = false;
		b_dropped = false;
	}
}

ListObject::~ListObject() {
	emit deleted();
}

void ListObject::_drop() {
	b_dropped = true;
	hide();
	emit dropped();
}
void ListObject::drop() {
	if (!b_dropped) {
		unselect();
		if (binded_object != NULL)
			binded_object->drop();
		else
			_drop();
	}
}

void ListObject::_undrop() {
	b_dropped = false;
	show();
	emit undropped();
}

void ListObject::undrop() {
	if (b_dropped) {
		if (binded_object != NULL)
			binded_object->undrop();
		else
			emit _undrop();	
	}
}

void ListObject::_select() {
	b_selected = true;
	setStyleSheet("background-color: rgb(200,200,200);");
	emit selected();
}

void ListObject::select() {
	if (!b_selected) {
		if (binded_object != NULL)
			binded_object->select();
		else
			_select();
	}
}

void ListObject::_unselect() {
	b_selected = false;
	setStyleSheet("background-color: none;");
	emit unselected();	
}

void ListObject::unselect() {
	if (b_selected) {
		if (binded_object != NULL)
			binded_object->unselect();
		else
			_unselect();
	}
}

void ListObject::inverseSelection() {
	if (b_selected)
		unselect();
	else
		select();
}

void ListObject::mousePressEvent(QMouseEvent* Qm) {
	if (Qm->button() == Qt::LeftButton)
		emit leftClicked();
	else if (Qm->button() == Qt::RightButton)
		emit rightClicked();
	Qm->accept();
}

void ListObject::moveEvent(QMoveEvent* Qm) {
	emit moved();
}