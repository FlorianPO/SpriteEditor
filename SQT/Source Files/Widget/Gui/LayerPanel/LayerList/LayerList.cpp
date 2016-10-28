#include "LayerList.h"

#include "Source Files/Widget/Various/SpriteView/SpriteView.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Widget/Various/FLineEdit/FLineEdit.h"

QHash<Layer*, LayerList*> LayerList::hash;

LayerList::LayerList(QWidget* parent, SignalListObject* binded_object, QMainWindow* window) : ListObject(parent, binded_object) {
	ui.setupUi(this);
	show();

	layer = static_cast<Layer*>(binded_object);
	hash[layer] = this;

	view_button = new State2Button(this, &QString("Layers/layer_view"), NULL);
	view_button->move(QPoint(0, 4));
	view_button->show();
	QObject::connect(layer, SIGNAL(layerVisible()), view_button, SLOT(enable()));
	QObject::connect(layer, SIGNAL(layerUnvisible()), view_button, SLOT(disable()));
	QObject::connect(view_button, SIGNAL(enabled()), layer, SLOT(show()));
	QObject::connect(view_button, SIGNAL(disabled()), layer, SLOT(hide()));

	line_edit = new FLineEdit(this);
	line_edit->setGeometry(QRect(80, 4, 49, 25));
	line_edit->setText(layer->getName());
	line_edit->show();

	sprite_view = new SpriteView(this, layer->getTexture(), window);
	sprite_view->setGeometry(QRect(32, 2, 40, 29));
	sprite_view->show();

	QObject::connect(layer, SIGNAL(selected()), sprite_view, SLOT(select()));
	QObject::connect(layer, SIGNAL(unselected()), sprite_view, SLOT(unselect()));
	QObject::connect(layer, SIGNAL(layerUpdated()), sprite_view, SLOT(refreshOnce()));
	QObject::connect(this, &LayerList::leftClicked, [this](){ LAYER_CONTROLLER->selectLayer(*layer); });

	QObject::connect(layer, &Layer::nameChanged, [this](const QString& name){ line_edit->setText(name); });
	QObject::connect(line_edit, &QLineEdit::textChanged, [this](const QString& text){ layer->setName(text); });
}

LayerList::~LayerList() {
	delete sprite_view;
	delete view_button;
	delete line_edit;
	hash.erase(hash.find(layer));
}

LayerList& LayerList::getFromLayer(Layer& layer) {
	return *hash[&layer];
}