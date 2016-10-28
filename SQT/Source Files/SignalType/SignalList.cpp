#include "SignalList.h"

void SignalList::push_back(SignalListObject& obj) {
	vector.push_back(&obj);
	QObject::connect(&obj, &SignalListObject::deleted, [&](){ remove(obj); });
	emit created(obj);
}

void SignalList::moveElement(int src, int dst) {
	SignalListObject* tmp = vector[src];
	erase(vector.begin() + src);
	insert(vector.begin() + dst, *tmp);
}

void SignalList::selectOne(SignalListObject& obj) {
	FOR_I (vector.size())
		if (!vector[i]->isDropped())
			if (vector[i] != &obj)
				vector[i]->unselect();
			else
				vector[i]->select();
}

void SignalList::dropSelected() {
	FOR_I (vector.size())
		if (!vector[i]->isDropped() && vector[i]->isSelected())
			vector[i]->drop();
}

void SignalList::erase(std::vector<SignalListObject*>::const_iterator i) {
	vector.erase(i);
}

void SignalList::insert(std::vector<SignalListObject*>::const_iterator at, SignalListObject& to_add) {
	vector.insert(at, &to_add);
}

void SignalList::clear() {
	vector.clear();
}

void SignalList::remove(const SignalListObject& object) {
	FOR_I (vector.size())
		if (vector[i] == &object) {
			erase(vector.begin() + i);
			return;
		}
}