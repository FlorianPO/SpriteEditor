#include "ShortcutController.h"

#include "InputController.h"
#include "Source Files/QtApp/QtApp.h"

ShortcutController* ShortcutController::_t;

ShortcutController::ShortcutController() {
	mapper = new QSignalMapper(this);
	ID = 0;
	core_shortcut_enabled = false;

	enableCoreShortcut();
}

ShortcutController::~ShortcutController() {
	QHash<SHORTCUT_ID, QShortcut*>::iterator i;
	for (i = shortcut_hash.begin(); i != shortcut_hash.end(); ++i)
		delete i.value();

	delete mapper;
}

ShortcutController::SHORTCUT_ID ShortcutController::createShortcut(const QKeySequence& seq, const QObject* receiver, const char* slot, int arg) {
	QShortcut* sh = new QShortcut(seq, QTWINDOW);
		QObject::connect(sh, SIGNAL(activated()), mapper, SLOT(map()));
		mapper->setMapping(sh, static_cast<int>(arg));
		QObject::connect(mapper, SIGNAL(mapped(int)), receiver, slot);

	shortcut_hash[ID] = sh;
	ID++;

	return ID-1;
}

ShortcutController::SHORTCUT_ID ShortcutController::createShortcut(const QKeySequence& seq, const QObject* receiver, const char* slot) {
	QShortcut* sh = new QShortcut(seq, QTWINDOW);
	QObject::connect(sh, SIGNAL(activated()), receiver, slot);

	shortcut_hash[ID] = sh;
	ID++;

	return ID-1;
}

ShortcutController::SHORTCUT_CORE_ID ShortcutController::createCoreShortcut(const nInt::key_combinaison& keys, std::function<void(void)> function, int ntimes) {
	int hash_code = hashKeyCombinaison(keys);

	auto it = shortcut_core_hash.find(hash_code);
	if (it != shortcut_core_hash.end()) // Shortcut already exists
		sch_temp[hash_code] = (*it).second;

	shortcut_core_hash[hash_code] = shortcut(function, ntimes);
	return hash_code;
}

ShortcutController::SHORTCUT_CORE_ID ShortcutController::createCoreShortcutOnce(const nInt::key_combinaison& keys, std::function<void(void)> function) {
	int hash_code = hashKeyCombinaison(keys);

	auto it = shortcut_core_hash.find(hash_code);
	if (it == shortcut_core_hash.end()) // Shortcut doesn't exists
		shortcut_core_hash[hash_code] = shortcut(function, 1);
	
	return hash_code;
}

void ShortcutController::removeShortcut(SHORTCUT_ID id) {
	delete shortcut_hash[id];
	shortcut_hash.remove(id);
}

void ShortcutController::removeShortcut(std::vector<SHORTCUT_ID>& id_list) {
	FOR_I (id_list.size())
		shortcut_hash.remove(id_list[i]);
}

void ShortcutController::removeCoreShortcut(SHORTCUT_CORE_ID id) {
	shortcut_core_hash.erase(id);

	auto it = sch_temp.find(id);
	if (it != sch_temp.end()) // A shortcut was stored
		shortcut_core_hash[id] = (*it).second;
}

void ShortcutController::removeCoreShortcut(std::vector<SHORTCUT_CORE_ID>& id_list) {
	FOR_I (id_list.size())
		removeCoreShortcut(id_list[i]);
}

void ShortcutController::enableCoreShortcut() {
	if (core_shortcut_enabled == false) {
		QObject::connect(INPUT, SIGNAL(combinaisonPressed(nInt::key_combinaison*)), this, SLOT(checkKeyCombinaison(nInt::key_combinaison*)));
		core_shortcut_enabled = true;
	}
}

void ShortcutController::disableCoreShortcut() {
	if (core_shortcut_enabled == true) {
		QObject::disconnect(INPUT, SIGNAL(combinaisonPressed(nInt::key_combinaison*)), this, SLOT(checkKeyCombinaison(nInt::key_combinaison*)));
		core_shortcut_enabled = false;
	}
}

void ShortcutController::checkKeyCombinaison(nInt::key_combinaison* keys) {
	SHORTCUT_CORE_ID id = hashKeyCombinaison(*keys);
	auto it = shortcut_core_hash.find(id);

	if (it != shortcut_core_hash.end()) {
		(*it).second.function();
		if ((*it).second.ntimes != -1) {
			(*it).second.ntimes--;
			if ((*it).second.ntimes <= 0)
				removeCoreShortcut(id);
		}
	}
}