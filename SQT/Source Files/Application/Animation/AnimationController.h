#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalList.h"
#include "Animation.h" // Qt reference
#include "Source Files/Application/UndoStack/UndoStack.h"

#define INIT_ANIMATION_CONTROLLER AnimationController::createInstance();
#define ANIMATION_CONTROLLER AnimationController::getInstance()
#define ANIM_LIST AnimationController::getInstance()->getList()
#define ANIM_STACK AnimationController::getInstance()->getUndoStack()
#define ANIM ANIMATION_CONTROLLER

class AnimationController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static AnimationController* _t; 
public:		inline static void createInstance() { _t = new AnimationController(); }
			inline static AnimationController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	AnimationController();
	~AnimationController();

// METHODS
public:
	void display();

	inline SignalList& getList() { return anim_list; }
	inline UndoStack& getUndoStack() { return undo_stack; }
private:
	void checkSelection(const Animation& anim);

// SIGNALS / SLOTS
	private slots:
		void moved(const sf::Vector2f& new_position);
		void zoomed(float new_factor);
	public slots:
		Animation& createAnimation();
		void dropSelected();

// MEMBERS
private:
	SignalList anim_list;
	UndoStack undo_stack;

// UNDO STACK
private:
	friend class AnimationCreated;
	friend class AnimationDropped;

	void _createAnimation(Animation& anim);
	void _dropAnimation(Animation& anim);
};

