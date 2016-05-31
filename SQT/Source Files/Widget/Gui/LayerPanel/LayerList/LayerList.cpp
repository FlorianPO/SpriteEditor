#include "Source Files/Widget/Gui/LayerPanel/LayerList/LayerList.h"

#include "Source Files/Application/Layer/LayerController.h"

QHash<CLayer*, LayerList*> LayerList::hash;

LayerList::LayerList(QWidget* parent, CLayer& layer, const QPoint& position) : QWidget(parent) 
{
	move(position);
	ui.setupUi(this);
	show();

	this->layer = &layer;
	hash[this->layer] = this;

	view_button = new State2Button(this, &QString("Layers/layer_view"), NULL);
	view_button->move(QPoint(0, 4)); view_button->show();
	QObject::connect(this->layer, SIGNAL(layerVisible()), view_button, SLOT(enable()), Qt::DirectConnection);
	QObject::connect(this->layer, SIGNAL(layerUnvisible()), view_button, SLOT(disable()), Qt::DirectConnection);
	QObject::connect(view_button, SIGNAL(enabled()), this->layer, SLOT(show()), Qt::DirectConnection);
	QObject::connect(view_button, SIGNAL(disabled()), this->layer, SLOT(hide()), Qt::DirectConnection);

	ui.lineEdit->setText(layer.getName());

	sprite_view = new SpriteView(this, layer.getTexture(), sf::Vector2u(40, 29));
	sprite_view->setGeometry(QRect(32, 2, 40, 29));
	sprite_view->show();
	sprite_view->installEventFilter(this);

	QObject::connect(this->layer, SIGNAL(layerSelected()), sprite_view, SLOT(selected()), Qt::DirectConnection);
	QObject::connect(this->layer, SIGNAL(layerSelected()), this, SLOT(layerSelected()), Qt::DirectConnection);
	QObject::connect(this->layer, SIGNAL(layerUnselected()), sprite_view, SLOT(unselected()), Qt::DirectConnection);
	QObject::connect(this->layer, SIGNAL(layerUnselected()), this, SLOT(layerUnselected()), Qt::DirectConnection);

	ui.lineEdit->setStyleSheet("background-color:white;");
}

LayerList* LayerList::getFromLayer(CLayer* layer) {
	return hash[layer];
}

void LayerList::layerSelected() {
	setStyleSheet("background-color: rgb(200,200,200);");
}

void LayerList::layerUnselected() {
	setStyleSheet("background-color: none;");
}

void LayerList::mousePressEvent(QMouseEvent* qm) {
	if (qm->button() == Qt::LeftButton)
		LAYER_CONTROLLER->selectLayer(layer);
}

bool LayerList::eventFilter(QObject* object, QEvent* event) {
	if (object == sprite_view && event->type() == QEvent::MouseButtonPress) {
		mousePressEvent(static_cast<QMouseEvent*>(event));
		return true;
	}
	return false;
}
