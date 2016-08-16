#pragma once

#include "stdenum.h"
class Copy; //Forward declaration

#define INIT_COPY_CONTROLLER CopyController::createInstance();
#define COPY_CONTROLLER CopyController::getInstance()
#define COPY_LIST CopyController::getInstance()->getCopyList()
#define COPY CopyController::getInstance()->getCurrentCopy()

class CopyController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static CopyController* _t; 
public:		inline static void createInstance() { _t = new CopyController(); }
			inline static CopyController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	CopyController();
	~CopyController() {}
	void freeWork();

// METHODS
public:
	inline Copy* getCurrentCopy() { return current_copy; }
	inline const std::vector<Copy*>& getCopyList() { return copy_list; }

// SIGNALS SLOTS
	public slots:
		void copy();
		void cut();
		void paste();
		void createCopy(const sf::Image& image, sf::Vector2f position);
		void deleteCopy(Copy* copy=COPY);
		void applyCopy(Copy* copy=COPY);
		void dropCopy(Copy* copy=COPY);
	signals:
		void copyCreated(Copy*);
		void copyDeleted(Copy*);
		void copyDropped(Copy*);

// MEMBERS
private:
	Copy* current_copy;
	int space_shortcut_id;
	int shift_core_shortcut_id;
	int zqsd_core_shortcut_id[4];

	std::vector<Copy*> copy_list;
	sf::Vector2f apply_position;
	sf::Vector2f copy_position;

// UNDO
public:
	friend class CopyCreated;
	friend class CopyDropped;
	
	private: // Core context
		void _createCopy(Copy* copy);
		void _dropCopy(Copy* copy);
};

