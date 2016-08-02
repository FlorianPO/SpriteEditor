#include "SignalInit.h"

std::vector<SignalInit*> SignalInit::init_list;

SignalInit::SignalInit() {
	init_list.push_back(this);
}

void SignalInit::emitSignals() {
	FOR_I_INV (init_list.size()) {
		init_list[i]->initSignals();
		init_list.erase(init_list.begin() + i);
	}
}