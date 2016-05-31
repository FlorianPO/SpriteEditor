#include "Source Files/SignalType/SignalController.h"

std::vector<SignalController*> SignalController::init_list;

SignalController::SignalController() {
	init_list.push_back(this);
}

void SignalController::emitSignals() {
	for (int i=init_list.size()-1; i >= 0; i--) {
		init_list[i]->initSignals();
		init_list.erase(init_list.begin() + i);
	}
}