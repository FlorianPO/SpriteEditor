#pragma once

#include "stdenum.h"

#define INIT_SHORTCUT_CONTROLLER ShortcutController::createInstance();
#define SHORTCUT_CONTROLLER ShortcutController::getInstance()

///////////////////////////////////
// NEVER CREATE A SHORTCUT TWICE //
///////////////////////////////////

class ShortcutController : public QObject
{
	Q_OBJECT
private:
	typedef int SHORTCUT_ID;
	typedef int SHORTCUT_CORE_ID;

	struct shortcut {
		std::function<void(void)> function;
		int ntimes = -1;

		shortcut(std::function<void(void)> f, int n) {
			this->function = f;
			this->ntimes = n;
		}
		shortcut() { // Default constructor
			this->ntimes = 0;
		}
	};

// INSTANCE
private:	static ShortcutController* _t; 
public:		inline static void createInstance() { _t = new ShortcutController(); }
			inline static ShortcutController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	ShortcutController();
	~ShortcutController();

// METHODS
public:
	SHORTCUT_ID createShortcut(const QKeySequence& seq, const QObject* receiver, const char* slot, int arg);
	SHORTCUT_ID createShortcut(const QKeySequence& seq, const QObject* receiver, const char* slot);
	void removeShortcut(SHORTCUT_ID id);
	void removeShortcut(std::vector<SHORTCUT_ID>& id_list);

	bool coreShortcutEnabled() { return core_shortcut_enabled; }
	SHORTCUT_CORE_ID createCoreShortcut(const nInt::key_combinaison& keys, std::function<void(void)> function, int ntimes=-1);
	SHORTCUT_CORE_ID createCoreShortcutOnce(const nInt::key_combinaison& keys, std::function<void(void)> function); // A shortcut can be called once, handles multiple definitions
	void removeCoreShortcut(SHORTCUT_CORE_ID id);
	void removeCoreShortcut(std::vector<SHORTCUT_CORE_ID>& id_list);

// SIGNALS SLOTS
	public slots:
		void enableCoreShortcut();
		void disableCoreShortcut();
		void checkKeyCombinaison(nInt::key_combinaison* keys);

// MEMBERS
private:
	QSignalMapper* mapper;
	QHash<SHORTCUT_ID, QShortcut*> shortcut_hash;
	int ID;
	bool core_shortcut_enabled;

// HASH
	typedef int _HashKeysCode;

	class EqualFn {
		public:
			bool operator()(const int& t1, const int& t2) const {
				if (int(t1 & 0xFF00FFFF) != int(t2 & 0xFF00FFFF))
					return false;
				return int(0x00FF0000 & t1 & t2) > 0;
			}
	};

	class HashFn {
		public:
			size_t operator()(const int& t) const {
				return t;
			}
	};

	inline _HashKeysCode hashKeyCombinaison(const nInt::key_combinaison& keys) {
		int result = keys.seq & 0xFF00FFFF;
		result += keys.press_mode << 16;
		return result;
	}

	std::unordered_map<_HashKeysCode, shortcut, HashFn, EqualFn> shortcut_core_hash;
	std::unordered_map<_HashKeysCode, shortcut, HashFn, EqualFn> sch_temp; // stores shortcut in double
};