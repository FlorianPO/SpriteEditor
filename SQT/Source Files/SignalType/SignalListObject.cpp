#include "SignalListObject.h"

SignalListObject::SignalListObject() {
	b_selected = false;
	b_dropped = false;
}

SignalListObject::~SignalListObject() {
	emit deleted();
}

void SignalListObject::drop() {
	if (!b_dropped) {
		unselect();
		b_dropped = true;
		emit dropped();
	}
}

void SignalListObject::undrop() {
	if (b_dropped) {
		b_dropped = false;
		emit undropped();
	}
}

void SignalListObject::select() {
	if (!b_selected) {
		b_selected = true;
		emit selected();
	}
}

void SignalListObject::unselect() {
	if (b_selected) {
		b_selected = false;
		emit unselected();
	}
}
