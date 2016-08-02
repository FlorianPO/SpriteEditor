#include "QueueController.h"

QueueController* QueueController::_t;

QueueController::~QueueController() {
	FOR_I (before_display.size())
		delete before_display[i].function;
}

void QueueController::beforeDisplay(QObject* receiver, const char* slot) {
	auto it_r = std::find(before_display_receivers.begin(), before_display_receivers.end(), receiver);
	auto it_s = std::find(before_display_slots.begin(), before_display_slots.end(), slot);
	if (it_r == before_display_receivers.end() || it_s == before_display_slots.end()) {
		before_display_receivers.push_back(receiver);
		before_display_slots.push_back(slot);
	}
}

void QueueController::beforeDisplay(int group, _FunctionArg function) {
	before_display.push_back(function);
	group_before_display.push_back(group);
}

bool QueueController::isBeforeDisplay(int group) {
	std::vector<int>::iterator it = std::find(group_before_display.begin(), group_before_display.end(), group);
	return (it != group_before_display.end());
}

void QueueController::updateBeforeDisplay() {
	FOR_I (before_display_receivers.size())
		QMetaObject::invokeMethod(before_display_receivers[i], before_display_slots[i]);
	before_display_receivers.clear();
	before_display_slots.clear();

	FOR_I (before_display.size())
		(*before_display[i].function)(before_display[i].instance);
	before_display.clear();
	group_before_display.clear();
}