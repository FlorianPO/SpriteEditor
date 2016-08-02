#pragma once

#include "stdenum.h"

#define INIT_QUEUE_CONTROLLER QueueController::createInstance();
#define QUEUE_CONTROLLER QueueController::getInstance()
#define QUEUE QUEUE_CONTROLLER

#define BEFORE_DISPLAY(group, i_type) static Function_Arg __static__function = NULL; if (!QUEUE->isBeforeDisplay(group)) { \
	if (__static__function == NULL) __static__function = new std::function<void(void*)>([](void* _arg) { i_type _this = static_cast<i_type>(_arg);
#define END_BEFOR_DISPLAY(group) QUEUE->beforeDisplay(group, _FunctionArg(this, __static__function)); }

/*	
BEFORE_DISPLAY(0, Copy*)
	_this->updateLines();
}); END_BEFOR_DISPLAY(0);
*/

class QueueController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static QueueController* _t; 
public:		inline static void createInstance() { _t = new QueueController(); }
			inline static QueueController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	QueueController() {}
	~QueueController();

// METHODS
public:
	void beforeDisplay(QObject* receiver, const char* slot);
	void beforeDisplay(int group, _FunctionArg function);
	bool isBeforeDisplay(int group);

	void updateBeforeDisplay();

// MEMBERS
private:
	std::vector<QObject*> before_display_receivers;
	std::vector<const char*> before_display_slots;
	std::vector<_FunctionArg> before_display;
	std::vector<int> group_before_display;
};


