#include "SpriteEditor.h"

#include "Source Files/Widget/SpriteEditor/SpriteList/SpriteList.h"
#include "Source Files/Widget/SpriteEditor/SpriteList/SpriteFrame.h"
#include "Source Files/Widget/Various/Layout/VerticalList.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Action/Actions/RectList.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Application/Animation/AnimationController.h"
#include "Source Files/Application/Animation/Animation.h"
#include "Source Files/Application/Layer/Layer.h"

SpriteEditor* SpriteEditor::_t;

SpriteEditor::SpriteEditor(QWidget* parent) : QMainWindow(parent) {
	ui.setupUi(this);
	hide();

	List::param p;
	p.up_to_down = true;
	p.dragable = true;
	p.selectable = true;
	p.multi_selection = true;
	p.ensure_undo = false;
	p.ensure_drag = true;
	verticalLayout = new VerticalList(this, p, QPoint(0, ui.frame->pos().y()), &ANIM_STACK, &ANIM_LIST);

	QObject::connect(ui.Sprite_new, &QAbstractButton::clicked, [](){ ANIM->createAnimation(); });
	QObject::connect(&ANIM_LIST, &SignalList::created, [&](SignalListObject& anim){ this->addSpriteList(this, *verticalLayout, *static_cast<Animation*>(&anim)); });
	QObject::connect(ui.Sprite_del, SIGNAL(clicked()), ANIM, SLOT(dropSelected()));
	QObject::connect(ui.Sprite_new_grid, SIGNAL(clicked()), this, SLOT(addGridAnimation()));

	ui.Sprite_del->setEnabled(false);
	QObject::connect(verticalLayout, &List::noObjectSelected, [this](){ ui.Sprite_del->setEnabled(false); });
	QObject::connect(verticalLayout, &List::objectSelected, [this](){ ui.Sprite_del->setEnabled(true); });
	QObject::connect(verticalLayout, &List::oneObjectSelected, [](ListObject& object){ static_cast<SpriteList*>(&object)->getSpriteFrame().show(); });
}

SpriteEditor::~SpriteEditor() {
	delete verticalLayout;
}

void SpriteEditor::addSpriteList(QWidget* parent, List& list, Animation& anim) {
	verticalLayout->addWidget(*new SpriteList(parent, list, anim));
}

void SpriteEditor::addGridAnimation() {
	action = new RectList();
	APP->setAction(action);
	QObject::connect(action, SIGNAL(ended()), this, SLOT(endGridAnimation()));
	SFML->activateWindow();
}

void SpriteEditor::endGridAnimation() {
	std::vector<sf::IntRect> vector = action->getRectList();
	const Layer& layer = action->getLayer();
	delete action;

	ANIM_STACK.beginMacro();
	Animation* anim = &ANIM->createAnimation();
	SpriteList* sl = &SpriteList::getFromAnimation(*anim);

	sl->getSpriteFrame().getList()._fillBegin(); // Optimisation
	FOR_I (vector.size())
		anim->createAnimationRect(vector[i]);
	sl->getSpriteFrame().getList()._fillEnd();
	ANIM_STACK.endMacro();

	anim->setLayer(layer);
	verticalLayout->selectOne(*sl);
	
	resize(QSize(sl->width() + sl->getSpriteFrame().getWidth() + 5, height()));
	activateWindow();
}

void SpriteEditor::changeEvent(QEvent* event) {
	QWidget::changeEvent(event);
    if (!closed && event->type() == QEvent::ActivationChange) {
        if (isActiveWindow())
			verticalLayout->startUndoStack();
        else
			verticalLayout->stopUndoStack();
    }
}

void SpriteEditor::showEvent(QShowEvent* event) {
	closed = false;
	QMainWindow::showEvent(event);
	verticalLayout->startUndoStack();
}

void SpriteEditor::closeEvent(QCloseEvent* event) {
	closed = true;
	verticalLayout->stopUndoStack();
	QMainWindow::closeEvent(event);
}

void SpriteEditor::resizeEvent(QResizeEvent* evnt) {
	QMainWindow::resizeEvent(evnt);
	emit globallyChanged();
}