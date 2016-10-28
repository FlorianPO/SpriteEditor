#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_SpriteEditor.h"
class VerticalList;
class List;
class SpriteList;
class RectList;
class Animation;

#define INIT_SPRITE_EDITOR SpriteEditor::createInstance
#define SPRITE_EDITOR SpriteEditor::getInstance()

class SpriteEditor : public QMainWindow
{
	Q_OBJECT
// INSTANCE
private:	static SpriteEditor* _t; 
public:		inline static void createInstance(QWidget* parent=NULL) { _t = new SpriteEditor(parent); }
			inline static SpriteEditor* getInstance() { return _t; }
// CONSTRUCTOR
public:
	SpriteEditor(QWidget* parent);
	~SpriteEditor();

// SIGNALS / SLOTS
	private slots:
		void addSpriteList(QWidget* parent, List& list, Animation& anim);
		void addGridAnimation();
		void endGridAnimation();
	signals:
		void globallyChanged() const;

// METHODS
private:
	void resizeEvent(QResizeEvent* evnt) override;

// MEMBERS
private:
	Ui_SpriteEditor ui;
	VerticalList* verticalLayout;
	RectList* action;

	bool closed = true;
	void changeEvent(QEvent *event) override;
	void showEvent(QShowEvent* event) override;
	void closeEvent(QCloseEvent* event) override;
};

