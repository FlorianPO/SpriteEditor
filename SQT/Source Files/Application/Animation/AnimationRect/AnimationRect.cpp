#include "AnimationRect.h"

#include "Source Files/Application/UndoStack/UndoStack.h"
#include "AnimationRectUndo.h"

AnimationRect::AnimationRect(const sf::IntRect& rect, int frame, UndoStack& undo_stack) {
	this->rect = rect;
	this->frame = frame;
	this->undo_stack = &undo_stack;

	undo_stack.push(*new AnimationRectCreated(this, rect, frame));
}

void AnimationRect::setRect(const sf::IntRect& rect) {
	undo_stack->push(*new AnimationRectChanged(this, rect));
	_setRect(rect);
}

void AnimationRect::setFrame(int frame) {
	undo_stack->push(*new AnimationRectFrameChanged(this, frame));
	_setFrame(frame);
}

void AnimationRect::show() {
	visible = true;
	emit animationVisible();
}

void AnimationRect::hide() {
	visible = false;
	emit animationUnvisible();
}

void AnimationRect::_setFrame(int frame) {
	this->frame = frame;
	emit frameChanged(frame);
}

void AnimationRect::_setRect(const sf::IntRect& rect) {
	this->rect = rect;
	emit rectChanged(rect);
}