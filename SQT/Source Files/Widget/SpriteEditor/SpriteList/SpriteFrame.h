#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_SpriteFrame.h"
class SignalListObject;
class GridList;
class SpriteFrameList;
class Layer;
class List;
class FComboBox;
class Animation;
class SpriteList;
class TransformAnim;

class SpriteFrame : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SpriteFrame(QWidget* parent, Animation& anim, SpriteList& sprite_list);
	~SpriteFrame();

// SIGNALS SLOTS
	private slots:
		void comboBoxChanged(int index);
		void setTabOrder();
		void handleWindowSize();
		void transformAnimation();
		void endTransformAnimation();

// METHODS
public:
	List& getList() const;
	inline Animation* getAnimation() const { return animation; }
	int getWidth();

private:
	void comboBoxAdd(Layer* layer, bool hidden);

// MEMBERS
private:
	Ui_SpriteFrame ui;

	bool update = false;
	QWidget* parent;
	GridList* gridLayout;
	FComboBox* combo_box;
	Animation* animation;
	SpriteList* sprite_list;
	int nbr_selected = 0;

	TransformAnim* action;
};