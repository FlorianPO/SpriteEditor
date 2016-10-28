#include "AnimationRectUndo.h"

#include "AnimationRect.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Application/Animation/AnimationController.h"

//////////
// BASE //
//////////
int AnimationRectUndo::getFrame() const			{ return static_cast<AnimationRectUndo*>(&ANIM_STACK.getPrevious(instance))->getFrame(); }
sf::IntRect AnimationRectUndo::getRect() const	{ return static_cast<AnimationRectUndo*>(&ANIM_STACK.getPrevious(instance))->getRect(); }

/////////////
// CREATED //
/////////////
AnimationRectCreated::AnimationRectCreated(void* anim_rect, const sf::IntRect& rect, int frame) : AnimationRectUndo(anim_rect) {
	this->rect = rect;
	this->frame = frame;
}

AnimationRectCreated::~AnimationRectCreated() {
	delete static_cast<AnimationRect*>(instance);
}

void AnimationRectCreated::undo() {
	static_cast<AnimationRect*>(instance)->drop();
}

void AnimationRectCreated::redo() {
	static_cast<AnimationRect*>(instance)->undrop();
}

/////////////
// DROPPED //
/////////////
AnimationRectDropped::AnimationRectDropped(void* anim_rect) : AnimationRectUndo(anim_rect) {}

void AnimationRectDropped::undo() {
	static_cast<AnimationRect*>(instance)->undrop();
}

void AnimationRectDropped::redo() {
	static_cast<AnimationRect*>(instance)->drop();
}

//////////
// RECT //
//////////
AnimationRectChanged::AnimationRectChanged(void* anim_rect, const sf::IntRect& rect) : AnimationRectUndo(anim_rect) {
	this->rect = rect;
}

void AnimationRectChanged::undo() {
	auto rect = static_cast<AnimationRectUndo*>(&ANIM_STACK.getPrevious(instance, true))->getRect();
	static_cast<AnimationRect*>(instance)->_setRect(rect);
}

void AnimationRectChanged::redo() {
	static_cast<AnimationRect*>(instance)->_setRect(rect);
}

///////////
// FRAME //
///////////
AnimationRectFrameChanged::AnimationRectFrameChanged(void* anim_rect, int frame) : AnimationRectUndo(anim_rect) {
	this->frame = frame;
}

void AnimationRectFrameChanged::undo() {
	auto frame = static_cast<AnimationRectUndo*>(&ANIM_STACK.getPrevious(instance, true))->getFrame();
	static_cast<AnimationRect*>(instance)->_setFrame(frame);
}

void AnimationRectFrameChanged::redo() {
	static_cast<AnimationRect*>(instance)->_setFrame(frame);
}