#pragma once

#include "stdenum.h"
#include "Source Files/Widget/Various/Layout/ListObject.h"
#include "GeneratedFiles/ui_SpriteFrameList.h"
class SpriteView;
class ClickLabel;
class State2Button;
class Layer;
class Rect;
class AnimationRect;
class Animation;

class SpriteFrameList : public ListObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SpriteFrameList(QWidget* parent, SignalListObject* binded_object=NULL);
	SpriteFrameList(QWidget* parent, QMainWindow& window, const sf::IntRect& rect, Layer& layer, SignalListObject& binded_object, Animation& anim);
	~SpriteFrameList();

// METHODS
public:
	ClickLabel& getClickLabel() const { return *time; }

// SIGNALS SLOTS
	public slots:
		void setLayer(Layer& layer);
		void selectRect();
		void endSelectRect();

// MEMBERS
public:
	Ui_SpriteFrameList ui;

	AnimationRect* anim_rect;
	Layer* layer = NULL;
	SpriteView* sprite_view;
	ClickLabel* time;
	State2Button* view_button;
	Rect* action;
};

