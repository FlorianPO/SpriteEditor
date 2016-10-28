#include "QueueController.h"

QueueController* QueueController::_t;

////////////////////
// BEFORE DISPLAY //
////////////////////
void QueueController::beforeDisplay(QObject* receiver, const char* function_name, const char* overrides) {
	recv_slot recv_s = recv_slot(receiver, function_name);
	auto it_s = std::find(bd_slots.begin(), bd_slots.end(), recv_s);

	if (overrides != NULL) {
		recv_slot recv_o = recv_slot(receiver, overrides);
		auto it_o = std::find(bd_slots.begin(), bd_slots.end(), recv_o);
		if (it_o != bd_slots.end())
			bd_slots.erase(it_o);
	}

	if (it_s == bd_slots.end())
		bd_slots.push_back(recv_s);
}

void QueueController::beforeDisplay(const std::function<void()>& lambda) {
	bd_lambdas.push_back(lambda);
}

void QueueController::updateBeforeDisplay() {
	FOR_I (bd_slots.size())
		QMetaObject::invokeMethod(bd_slots[i].object, bd_slots[i].slot);
	bd_slots.clear();

	FOR_I (bd_lambdas.size())
		bd_lambdas[i]();
	bd_lambdas.clear();
}

//////////////
// AT START //
//////////////
void QueueController::atStart(QObject* receiver, const char* function_name, const char* overrides) {
	recv_slot recv_s = recv_slot(receiver, function_name);
	auto it_s = std::find(as_slots.begin(), as_slots.end(), recv_s);

	if (overrides != NULL) {
		recv_slot recv_o = recv_slot(receiver, overrides);
		auto it_o = std::find(as_slots.begin(), as_slots.end(), recv_o);
		if (it_o != as_slots.end())
			as_slots.erase(it_o);
	}

	if (it_s == as_slots.end())
		as_slots.push_back(recv_s);
}

void QueueController::atStart(const std::function<void()>& lambda) {
	as_lambdas.push_back(lambda);
}

void QueueController::updateAtStart() {
	FOR_I (as_slots.size())
		QMetaObject::invokeMethod(as_slots[i].object, as_slots[i].slot);
	as_slots.clear();

	FOR_I (as_lambdas.size())
		as_lambdas[i]();
	as_lambdas.clear();
}