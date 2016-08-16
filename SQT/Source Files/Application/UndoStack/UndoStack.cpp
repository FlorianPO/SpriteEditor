#include "UndoStack.h"

#include "Source Files/Application/Input/ShortcutController.h"

#define DEBUG_STACK 0

UndoStack* UndoStack::_t;

UndoStack::UndoStack() {
	using namespace nInt;
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + Qt::Key_Z, LOG), [this](){undo();});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + Qt::Key_Y, LOG), [this](){redo();});
}

//////////
// FREE //
//////////
void UndoStack::freeWork() {
	FOR_I (stack.size())
		FOR_J (stack[i].size())
			delete stack[i][j];
	stack.clear();
	FOR_I (macro_stack.size())
		delete macro_stack[i];
	macro_stack.clear();

	index = -1;

	tmp_instance = NULL;
	undoing = false;

	searching = false;
	macro = 0;
	first = false;
}

void UndoStack::_printStack() {
	std::cout << "BEGIN" << std::endl;
	std::cout << "Index : " << index << std::endl;
	FOR_I (stack.size()) {
		bool is_first = false;
		std::cout << i << " : { ";
		FOR_J (stack[i].size()) {
			if (stack[i][j]->isFirst())
				is_first = true;
			std::cout << stack[i][j]->getType() << " ";
		}
		std::cout << "}";
		if (is_first)
			std::cout << " FIRST";
		
		if (index == i)
			std::cout << " <-";
		std::cout << std::endl;
	}
	std::cout << "END" << std::endl;
}

void UndoStack::push(nUnk::UndoCommand* command) {
	if (first)
		command->setFirst();

	if (macro == 0) {
		if (stack.size()-1 != index)
			clear(index+1); // Delete top of the stack
		stack.push_back({command});
		index++;

		#if DEBUG_STACK
		_printStack();
		#endif
	}
	else
		macro_stack.push_back(command);
}

void UndoStack::clear(int from_index) {
	for (int i=stack.size()-1; i >= from_index; i--) {
		FOR_J (stack[i].size())
			delete stack[i][j];
		stack.erase(stack.begin() + i);
	}
}

void UndoStack::undo() {
	if (index >= 0) {
		bool retry = false;
		FOR_J_INV (stack[index].size())
			if (!stack[index][j]->isFirst())
				stack[index][j]->undo();
			else {
				retry = true;
				if (!undoing) {
					last_index = index;
					undoing = true;
				}
				break;
			}
		index--;
		if (retry)
			undo();
		#if DEBUG_STACK
		else {
			_printStack();
		}
		#endif
	}
	else if (undoing) {
		index = last_index;
		undoing = false;
	}

}

void UndoStack::redo() {
	if (index < int(stack.size()-1)) {
		index++;
		bool retry = false;
		FOR_J (stack[index].size())
			if (!stack[index][j]->isFirst())
				stack[index][j]->redo();
			else {
				retry = true;
				break;
			}
		if (retry)
			redo();
		#if DEBUG_STACK
		else {
			_printStack();
		}
		#endif
	}
}

nUnk::UndoCommand* UndoStack::getPrevious(void* instance, bool clear_tmp) {
	if (tmp_instance != instance || clear_tmp) {
		if (searching)
			tmp_index = search_index;
		else
			tmp_index = index;
		tmp_instance = instance;
	}

	FOR_I_INV (tmp_index)
		FOR_J (stack[i].size())
			if (stack[i][j]->getInstance() == tmp_instance) {
				tmp_index = i;
				#if DEBUG_STACK
				std::cout << "index found : " << i << std::endl;
				#endif
				return stack[i][j];
			}

	std::cout << "UNDO_STACK : instance not found (" << tmp_instance << ")" << std::endl;
	return NULL;
}

nUnk::UndoCommand* UndoStack::getPrevious(nUnk::TYPE type, void* instance) {
	if (instance == NULL) {
		FOR_I_INV (index)
			FOR_J (stack[i].size())
				if (stack[i][j]->getType() == type)
					return stack[i][j];
	}
	else
		FOR_I_INV (index)
			FOR_J (stack[i].size())
				if (stack[i][j]->getInstance() == instance && stack[i][j]->getType() == type)
					return stack[i][j];

	std::cout << "UNDO_STACK : type " << type << " not found (instance : " << instance << ")" << std::endl;
	return NULL;
}

nUnk::UndoCommand* UndoStack::getPrevious(std::vector<nUnk::TYPE> type_list, void* instance) {
	if (instance == NULL) {
		FOR_I_INV (index)
			FOR_J (stack[i].size())
				for (int k=0; k < type_list.size(); k++)
					if (stack[i][j]->getType() == type_list[k])
						return stack[i][j];
	}
	else
		FOR_I_INV (index)
			FOR_J (stack[i].size())
				if (stack[i][j]->getInstance() == instance)
					FOR_K (type_list.size())
						if (stack[i][j]->getType() == type_list[k])
							return stack[i][j];

	std::cout << "UNDO_STACK : types { ";
	FOR_I (type_list.size())
		std::cout << type_list[i] << " ";
	std::cout << "} not found (instance : " << instance << ")" << std::endl;
	return NULL;
}

void UndoStack::beginSearching() {
	searching = true;
	search_index = index;
}

void UndoStack::endSearching() {
	searching = false;
}

void UndoStack::beginMacro() {
	macro++;
}

void UndoStack::endMacro() {
	if (macro > 0) {
		macro--;
		if (macro == 0) {
			if (stack.size()-1 != index)
				clear(index+1); // Delete top of the stack
			stack.push_back(macro_stack);
			index++;

			#if DEBUG_STACK
			_printStack();
			#endif

			macro_stack.clear();	
		}
	}
}

void UndoStack::beginFirst() {
	first = true;
}

void UndoStack::endFirst() {
	first = false;
}