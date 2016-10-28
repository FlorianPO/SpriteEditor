#include "SpriteFrameList.h"

#include "Source Files/Widget/Various/SpriteView/SpriteView.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Action/Actions/Rect.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Application/Animation/AnimationRect/AnimationRect.h"
#include "Source Files/Application/Animation/Animation.h"

SpriteFrameList::SpriteFrameList(QWidget* parent, SignalListObject* binded_object) : ListObject(parent, binded_object) {
	ui.setupUi(this);
	show();

	anim_rect = getBindedObject<AnimationRect*>();

	view_button = new State2Button(this, &QString("Layers/layer_view"), NULL);
	view_button->move(QPoint(5, 105));
	view_button->show();
	QObject::connect(anim_rect, SIGNAL(animationVisible()), view_button, SLOT(enable()));
	QObject::connect(anim_rect, SIGNAL(animationUnvisible()), view_button, SLOT(disable()));
	QObject::connect(view_button, SIGNAL(enabled()), anim_rect, SLOT(show()));
	QObject::connect(view_button, SIGNAL(disabled()), anim_rect, SLOT(hide()));

	time = new ClickLabel(this, sf::Vector2i(1, 999), ClickLabel::DEFAULT, false); 
	time->move(QPoint(56, 109)); 
	time->show();
	time->changeValue(7);

	QObject::connect(anim_rect, &AnimationRect::rectChanged, [&](const sf::IntRect& rect){ sprite_view->setTextureRect(rect); });
	QObject::connect(ui.SpriteFrameList_rect, SIGNAL(clicked()), this, SLOT(selectRect()));
	QObject::connect(time, SIGNAL(valueChanged(int)), anim_rect, SLOT(setFrame(int)));
	QObject::connect(anim_rect, SIGNAL(frameChanged(int)), time, SLOT(changeValue(int)));

	resize(QSize(110, 131));
}

SpriteFrameList::SpriteFrameList(QWidget* parent, QMainWindow& window, const sf::IntRect& rect, Layer& layer, SignalListObject& binded_object, Animation& anim) : SpriteFrameList(parent, &binded_object) {	
	sprite_view = new SpriteView(this, layer.getTexture(), rect, &window);
	sprite_view->setGeometry(QRect(5, 5, 100, 100));
	sprite_view->setOutLine(5);
	sprite_view->select();
	sprite_view->show();

	QObject::connect(&anim, SIGNAL(layerChanged(const Layer&)), this, SLOT(setLayer(const Layer&)));

	setLayer(layer);
}

SpriteFrameList::~SpriteFrameList() {
	delete sprite_view;
	delete view_button;
	delete time;
}

void SpriteFrameList::selectRect() {
	action = new Rect(*layer);
	APP->setAction(action);
	QObject::connect(action, SIGNAL(ended()), this, SLOT(endSelectRect()));
	SFML->activateWindow();
}

void SpriteFrameList::endSelectRect() {
	sf::IntRect rect = action->getRect();
	delete action;

	anim_rect->setRect(rect);
	activateWindow();
}

void SpriteFrameList::setLayer(Layer& layer) {
	if (this->layer != NULL) {
		QObject::disconnect(this->layer, SIGNAL(layerUpdated()), sprite_view, SLOT(refreshOnce()));	
		sprite_view->setTexture(layer.getTexture());
	}
	this->layer = &layer;
	QObject::connect(&layer, SIGNAL(layerUpdated()), sprite_view, SLOT(refreshOnce()));
}