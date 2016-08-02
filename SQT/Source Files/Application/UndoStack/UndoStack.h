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
public:		inline static void createInstance() { _t = new UndoStack(); }
			inline static UndoStack* getInstance() { return _t; }

// CONSTRUCTOR
public:
	UndoStack();
	~UndoStack() {}

// METHODS
public:
	void _printStack(); // DEBUG

	void push(nUnk::UndoCommand* command);

	// Get previous command of a given object (index is stored when instance is the same beetween 
	// two consecutive calls for rescursive functionnality. Clearable with clear_tmp == true
	nUnk::UndoCommand* getPrevious(void* instance, bool clear_tmp=false);
	// Get the previous command with TYPE relatively to index
	nUnk::UndoCommand* getPrevious(nUnk::TYPE type, void* instance = NULL); 
	// Get the previous command that matches any type of the types list relatively to index
	nUnk::UndoCommand* getPrevious(std::vector<nUnk::TYPE> type_list, void* instance = NULL); 

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
		void clear();

// MEMBERS
public:
	std::vector<std::vector<nUnk::UndoCommand*>> stack;
	int index=-1;

	// Related to getPrevious(void* instance, bool clear_tmp)
	int search_index;
	int tmp_index;
	void* tmp_instance = NULL;

	bool undoing = false;
	int last_index;

	bool searching = false;
	int macro = 0; // Not a boolean, for recursive call
	bool first = false;
	std::vector<nUnk::UndoCommand*> macro_stack;
};

