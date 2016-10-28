#pragma once

#include "stdenum.h"

#define INIT_QUEUE_CONTROLLER QueueController::createInstance();
#define QUEUE_CONTROLLER QueueController::getInstance()
#define QUEUE QUEUE_CONTROLLER

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
	~QueueController() {}

// METHODS
public:
	void beforeDisplay(QObject* receiver, const char* function_name, const char* overrides=NULL);
	void beforeDisplay(const std::function<void(void)>& lambda);

	void atStart(QObject* receiver, const char* function_name, const char* overrides=NULL);
	void atStart(const std::function<void(void)>& lambda);

	void updateBeforeDisplay();
	void updateAtStart();

// MEMBERS
private:
	struct recv_slot {
		QObject* object;
		const char* slot;

		recv_slot(QObject* o, const char* s) {
			object = o;
			slot = s;
		}

		bool operator==(const recv_slot& obj) {
			return object == obj.object && !strcmp(slot, obj.slot);
		}
	};

	// Before display
	std::vector<recv_slot> bd_slots;
	std::vector<std::function<void(void)>> bd_lambdas;

	// At start
	std::vector<recv_slot> as_slots;
	std::vector<std::function<void(void)>> as_lambdas;
};


