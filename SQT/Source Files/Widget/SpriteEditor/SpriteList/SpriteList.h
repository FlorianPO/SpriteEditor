#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_SpriteList.h"
#include "Source Files/Widget/Various/Layout/ListObject.h"
class UndoStack;
class FLineEdit;
class List;
class SpriteFrame;
class Animation;

class SpriteList : public ListObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SpriteList(QWidget* parent, List& list, SignalListObject& binded_object);
	~SpriteList();

// METHODS
public:
	static SpriteList& getFromAnimation(Animation& anim);

	inline SpriteFrame& getSpriteFrame() const { return *sprite_frame; }
	inline FLineEdit& getLineEdit() const { return *line_edit; }
	void setName(const QString& name);

// MEMBERS
private:
	static QHash<Animation*, SpriteList*> hash;

	Ui_SpriteList ui;

	FLineEdit* line_edit;
	SpriteFrame* sprite_frame;
	Animation* anim;
};