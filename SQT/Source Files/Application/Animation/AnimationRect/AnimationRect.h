#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalListObject.h"
class UndoStack;

class AnimationRect : public SignalListObject
{
	Q_OBJECT
public:
	AnimationRect(const sf::IntRect& rect, int frame, UndoStack& undo_stack);
	~AnimationRect() {}
	
// METHODS
public:
	inline const sf::IntRect& getRect() const { return rect; }
	inline int getFrame() const { return frame; }
	inline bool isVisible() const { return visible; }

// SIGNALS SLOTS
	public slots:
		void setRect(const sf::IntRect& rect);
		void setFrame(int frame);
		void show();
		void hide();
	signals:
		void rectChanged(const sf::IntRect& rect) const;
		void frameChanged(int rect) const;
		void animationVisible() const;
		void animationUnvisible() const;

// MEMBERS
private:
	bool visible = true;

	sf::IntRect rect;
	int frame;
	UndoStack* undo_stack;

// UNDO STACK
private:
	friend class AnimationRectChanged;
	friend class AnimationRectFrameChanged;

	void _setFrame(int frame);
	void _setRect(const sf::IntRect& rect);
};
