#include "SpriteFrame.h"

#include "Source Files/Widget/Various/Layout/GridList.h"
#include "Source Files/Widget/SpriteEditor/SpriteList/SpriteFrameList.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Widget/Various/FComboBox/FComboBox.h"
#include "Source Files/Application/Animation/AnimationController.h"
#include "Source Files/Application/Animation/Animation.h"
#include "Source Files/Application/Animation/AnimationRect/AnimationRect.h"
#include "Source Files/Widget/SpriteEditor/SpriteEditor.h"
#include "SpriteList.h"
#include "Source Files/Application/App.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Application/Action/Actions/TransformAnim.h"

SpriteFrame::SpriteFrame(QWidget* parent, Animation& anim, SpriteList& sprite_list) : QWidget(parent) {
	ui.setupUi(this);

	this->parent = parent;
	this->animation = &anim;
	this->sprite_list = &sprite_list;

	combo_box = new FComboBox(this);
	combo_box->setGeometry(80, 4, 73, 25);
	combo_box->show();

	List::param p;
	p.up_to_down = true;
	p.dragable = true;
	p.selectable = true;
	p.multi_selection = true;
	p.ensure_undo = false;
	p.ensure_drag = true;
	gridLayout = new GridList(this, p, &ANIM_STACK);
	gridLayout->setTopLeftCorner(QPoint(0, 32));

	QObject::connect(static_cast<SpriteEditor*>(parent), SIGNAL(globallyChanged()), this, SLOT(handleWindowSize()));

	QObject::connect(ui.SpriteFrameList_new, SIGNAL(clicked()), &anim, SLOT(createAnimationRect()));
	QObject::connect(&anim.getList(), &SignalList::created, this, [&](SignalListObject& anim_rect) {
		gridLayout->addWidget(*new SpriteFrameList(this, 
												   *static_cast<QMainWindow*>(parent), 
												   static_cast<AnimationRect*>(&anim_rect)->getRect(), 
												   *combo_box->get<Layer*>(combo_box->currentIndex()), 
												   anim_rect,
												   anim));
	});
	QObject::connect(ui.SpriteFrameList_del, &QAbstractButton::clicked, [&](){ anim.dropSelected(); });

	ui.SpriteFrameList_del->setEnabled(false);
	QObject::connect(gridLayout, &List::noObjectSelected, [this](){ ui.SpriteFrameList_del->setEnabled(false); });
	QObject::connect(gridLayout, &List::objectSelected, [this](){ ui.SpriteFrameList_del->setEnabled(true); });

	FOR_I (LAYER_LIST.size())
		comboBoxAdd(LAYER_LIST.at<Layer*>(i), LAYER_LIST.at<Layer*>(i)->isDropped());
	QObject::connect(&LAYER_LIST, &SignalList::created, [this](SignalListObject& object){ comboBoxAdd(static_cast<Layer*>(&object), false); });
	QObject::connect(combo_box, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxChanged(int)));

	QObject::connect(gridLayout, SIGNAL(reordered()), this, SLOT(setTabOrder()));

	QObject::connect(ui.SpriteFrame_transf, SIGNAL(clicked()), this, SLOT(transformAnimation()));
}

SpriteFrame::~SpriteFrame() {
	delete gridLayout;
	delete combo_box;
}


void SpriteFrame::setTabOrder() {
	auto list = gridLayout->getList();

	for (int i=1; i < list.size(); i++)
		QWidget::setTabOrder(reinterpret_cast<QWidget*>(&static_cast<SpriteFrameList*>(list[i-1])->getClickLabel()), 
							 reinterpret_cast<QWidget*>(&static_cast<SpriteFrameList*>(list[i])->getClickLabel()));

}

List& SpriteFrame::getList() const {
	return *gridLayout;
}

int SpriteFrame::getWidth() {
	auto list = gridLayout->getList();
	int width = 0;
	FOR_I (list.size())
		if (list[i]->pos().x() + list[i]->width() > width)
			width = list[i]->pos().x() + list[i]->width();
	return width;
}

void SpriteFrame::comboBoxAdd(Layer* layer, bool hidden) {
	combo_box->addItem(layer->getName(), layer);
	QObject::connect(layer, &Layer::nameChanged, [=](const QString& name){ combo_box->setItemText(layer, name); });
	QObject::connect(layer, &SignalListObject::dropped, [=](){ combo_box->hideItem(layer); });
	QObject::connect(layer, &SignalListObject::undropped, [=](){ combo_box->showItem(layer); });
	QObject::connect(layer, &SignalListObject::deleted, [=](){ combo_box->removeItem(layer); });

	if (hidden)
		combo_box->hideItem(layer);
}

void SpriteFrame::comboBoxChanged(int index) {
	animation->setLayer(*combo_box->get<Layer*>(index));
}


void SpriteFrame::handleWindowSize() {
	resize(QSize(SPRITE_EDITOR->width() - sprite_list->width(), SPRITE_EDITOR->height()));
	gridLayout->setBottomRightCorner(QPoint(width(), height()));
}

void SpriteFrame::transformAnimation() {
	action = new TransformAnim(*animation);
	APP->setAction(action);
	QObject::connect(action, SIGNAL(ended()), this, SLOT(endTransformAnimation()));
	SFML->activateWindow();
}

void SpriteFrame::endTransformAnimation() {
	activateWindow();
}