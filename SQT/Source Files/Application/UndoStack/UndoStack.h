#pragma once

#include "stdenum.h"

#define INIT_UNDO_STACK UndoStack::createInstance();
#define UNDO_STACK UndoStack::getInstance()
#define UNDO UNDO_STACK

class UndoStack : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static UndoStack* _t; 
public:		inline static void createInstance() { _t = new UndoStack(true); }
			inline static UndoStack* getInstance() { return _t; }

// CONSTRUCTOR
public:
	UndoStack(bool is_main_stack=false);
	~UndoStack() {}
	void freeWork();

// METHODS
public:
	void _printStack() const; // DEBUG

	void push(nUnk::UndoCommand& command);

	// Get previous command of a given object (index is stored when instance is the same beetween 
	// two consecutive calls for rescursive functionnality. Clearable with clear_tmp == true
	nUnk::UndoCommand& getPrevious(void* instance, bool clear_tmp=false);

	void beginSearching();
	void endSearching();

	void beginMacro();
	void endMacro();

	void beginFirst();
	void endFirst();

private:
	void clear(int from_index);

// SIGNALS SLOTS
	private slots:
		void undo();
		void redo();
	public slots:
		void startShortcut();
		void stopShortcut();

// MEMBERS
public:
	int sh_ctrlz, sh_ctrly;
	std::vector<std::vector<nUnk::UndoCommand*>> stack;
	int index;

	// Related to getPrevious(void* instance, bool clear_tmp)
	int search_index;
	int tmp_index;
	void* tmp_instance;

	bool undoing;
	int last_index;

	bool searching;
	int macro; // Not a boolean, for recursive call
	bool first;
	std::vector<nUnk::UndoCommand*> macro_stack;
};

