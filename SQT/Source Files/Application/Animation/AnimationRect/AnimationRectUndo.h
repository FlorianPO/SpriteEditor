#pragma once

#include "stdenum.h"

class AnimationRectUndo : public nUnk::UndoCommand
{
public:
	AnimationRectUndo(void* instance) { this->instance = instance; }
	~AnimationRectUndo() {}

	virtual int getFrame() const;
	virtual sf::IntRect getRect() const;
};

class AnimationRectCreated : public AnimationRectUndo
{
public:
	AnimationRectCreated(void* anim_rect, const sf::IntRect& rect, int frame);
	~AnimationRectCreated();
	void undo() override;
	void redo() override;

	sf::IntRect getRect() const override { return rect; }
	int getFrame() const override { return frame; }
private:
	sf::IntRect rect; 
	int frame;
};

class AnimationRectDropped : public AnimationRectUndo
{
public:
	AnimationRectDropped(void* anim_rect);
	~AnimationRectDropped() {}
	void undo() override;
	void redo() override;
};

class AnimationRectChanged : public AnimationRectUndo
{
public:
	AnimationRectChanged(void* anim_rect, const sf::IntRect& rect);
	~AnimationRectChanged() {}
	void undo() override;
	void redo() override;

	sf::IntRect getRect() const override { return rect; }
private:
	sf::IntRect rect;
};

class AnimationRectFrameChanged : public AnimationRectUndo
{
public:
	AnimationRectFrameChanged(void* anim_rect, int frame);
	~AnimationRectFrameChanged() {}
	void undo() override;
	void redo() override;

	int getFrame() const override { return frame; }
private:
	int frame;
};