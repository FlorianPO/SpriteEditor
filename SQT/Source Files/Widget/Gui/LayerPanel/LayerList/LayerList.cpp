#include "LayerList.h"

#include "SpriteView/SpriteView.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Widget/Various/FLineEdit/FLineEdit.h"
#include "Source Files/Widget/Gui/Gui.h"

QHash<Layer*, LayerList*> LayerList::hash;

LayerList::LayerList(QWidget* parent, Layer& layer, const QPoint& position) : QWidget(parent) {
	move(position);
	ui.setupUi(this);
	show();

	this->layer = &layer;
	hash[this->layer] = this;

	view_button = new State2Button(this, &QString("Layers/layer_view"), NULL);
	view_button->move(QPoint(0, 4));
	view_button->show();
	QObject::connect(this->layer, SIGNAL(layerVisible()), view_button, SLOT(enable()));
	QObject::connect(this->layer, SIGNAL(layerUnvisible()), view_button, SLOT(disable()));
	QObject::connect(view_button, SIGNAL(enabled()), this->layer, SLOT(show()));
	QObject::connect(view_button, SIGNAL(disabled()), this->layer, SLOT(hide()));

	line_edit = new FLineEdit(this);
	line_edit->setGeometry(QRect(80, 4, 49, 25));
	line_edit->setText(layer.getName());
	line_edit->setStyleSheet("background-color:white;");
	line_edit->show();
	QObject::connect(line_edit, SIGNAL(focussed()), SHORTCUT_CONTROLLER, SLOT(disableCoreShortcut()));
	QObject::connect(line_edit, SIGNAL(unFocussed()), SHORTCUT_CONTROLLER, SLOT(enableCoreShortcut()));

	sprite_view = new SpriteView(this, layer.getTexture(), sf::Vector2u(40, 29));
	sprite_view->setGeometry(QRect(32, 2, 40, 29));
	sprite_view->show();
	sprite_view->installEventFilter(this);

	QObject::connect(this->layer, SIGNAL(layerSelected()), sprite_view, SLOT(selected()));
	QObject::connect(this->layer, SIGNAL(layerSelected()), this, SLOT(layerSelected()));
	QObject::connect(this->layer, SIGNAL(layerUnselected()), sprite_view, SLOT(unselected()));
	QObject::connect(this->layer, SIGNAL(layerUnselected()), this, SLOT(layerUnselected()));
	QObject::connect(this->layer, SIGNAL(layerDropped()), this, SLOT(dropped()));
	QObject::connect(this->layer, SIGNAL(layerUndropped()), this, SLOT(undropped()));
	
	QObject::connect(this->layer, SIGNAL(layerUpdated()), this, SLOT(layerUpdated()));
	QObject::connect(GUI, SIGNAL(globallyChanged()), this, SLOT(layerUpdated()));
}

LayerList* LayerList::getFromLayer(Layer* layer) {
	return hash[layer];
}

void LayerList::layerUpdated() {
	QUEUE->beforeDisplay([this](){sprite_view->refresh();});
}

void LayerList::layerSelected() {
	setStyleSheet("background-color: rgb(200,200,200);");
	layerUpdated();
}

void LayerList::layerUnselected() {
	setStyleSheet("background-color: none;");
	layerUpdated();
}

void LayerList::dropped() {
	hide();
}

void LayerList::undropped() {
	show();
}

void LayerList::mousePressEvent(QMouseEvent* Qm) {
	if (Qm->button() == Qt::LeftButton)
		LAYER_CONTROLLER->selectLayer(layer);
	Qm->accept();
}

void LayerList::moveEvent(QMoveEvent* Qm) {
	layerUpdated();
}

bool LayerList::eventFilter(QObject* object, QEvent* event) {
	if (object == sprite_view && event->type() == QEvent::MouseButtonPress)
		mousePressEvent(static_cast<QMouseEvent*>(event));
	return false;
}

/*const sf::Uint8* raw_data = layer->getImage()->getPixelsPtr();
QImage myImage = QImage(ARG_VECTOR(layer->getSize()), QImage::Format_ARGB32);
for (int y = 0; y < myImage.height(); y++)
	memcpy(myImage.scanLine(y), raw_data + y * myImage.bytesPerLine(), myImage.bytesPerLine());
myImage = myImage.rgbSwapped();

myLabel->setPixmap(QPixmap::fromImage(myImage));*/
