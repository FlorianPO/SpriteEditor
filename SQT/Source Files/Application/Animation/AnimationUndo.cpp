#include "AnimationUndo.h"

#include "Animation.h"
#include "AnimationController.h"

/////////////
// CREATED //
/////////////
AnimationCreated::AnimationCreated(void* anim) {
	this->instance = anim;
}

AnimationCreated::~AnimationCreated() {
	delete static_cast<Animation*>(instance);
}

void AnimationCreated::undo() {
	ANIM->_dropAnimation(*static_cast<Animation*>(instance));
}

void AnimationCreated::redo() {
	auto anim =  static_cast<Animation*>(instance);
	ANIM->_createAnimation(*anim);
}

/////////////
// DROPPED //
/////////////
AnimationDropped::AnimationDropped(void* anim) {
	this->instance = anim;
}

void AnimationDropped::undo() {
	auto anim =  static_cast<Animation*>(instance);
	ANIM->_createAnimation(*anim);
}

void AnimationDropped::redo() {
	ANIM->_dropAnimation(*static_cast<Animation*>(instance));
}