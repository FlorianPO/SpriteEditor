#pragma once

#include "stdenum.h"

class AnimationCreated : public nUnk::UndoCommand
{
public:
	AnimationCreated(void* anim);
	~AnimationCreated();
	void undo() override;
	void redo() override;
};

class AnimationDropped : public nUnk::UndoCommand
{
public:
	AnimationDropped(void* anim);
	~AnimationDropped() {}
	void undo() override;
	void redo() override;
};