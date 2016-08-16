#include "LayerPanel.h"

#include "LayerList/LayerList.h"
#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"
#include "Source Files/Widget/Various/VerticalLayout/VerticalLayout.h"

LayerPanel::LayerPanel(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui.setupUi(this);
	hide();

	QObject::connect(ui.Layer_new, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(createLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerCreated(Layer*)), this, SLOT(layerCreated(Layer*)), Qt::DirectConnection);

	QObject::connect(ui.Layer_del, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(dropLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerDeleted(Layer*)), this, SLOT(layerDeleted(Layer*)), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(onlyOneLayer()), this, SLOT(onlyOneLayer()), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(moreThanOneLayer()), this, SLOT(moreThanOneLayer()), Qt::DirectConnection);

	QObject::connect(ui.Layer_fuse, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(fuseLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(firstLayerSelected(Layer*)), this, SLOT(firstLayerSelected(Layer*)), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(firstLayerUnselected(Layer*)), this, SLOT(firstLayerUnselected(Layer*)), Qt::DirectConnection);

	invert = new State2Button(this, &QString("Selections/selec_invert_enabled"), &QString("Selections/selec_invert_disabled"), false);
	invert->move(QPoint(76, 4)); invert->show();
	QObject::connect(invert, SIGNAL(enabled()), SELEC, SLOT(invertSelection()));
	QObject::connect(invert, SIGNAL(disabled()), SELEC, SLOT(uninvertSelection()));
	QObject::connect(SELEC, SIGNAL(selectionInverted()), invert, SLOT(enable()));
	QObject::connect(SELEC, SIGNAL(selectionUninverted()), invert, SLOT(disable()));

	// Selection
	QObject::connect(ui.Selection_del, SIGNAL(clicked()), SELEC, SLOT(deleteSelection()));
	QObject::connect(SELEC, SIGNAL(selectionDeleted()), this, SLOT(selectionDeleted()));
	QObject::connect(SELEC, SIGNAL(selectionCreated()), this, SLOT(selectionCreated()));
	// Copy
	QObject::connect(ui.Selection_del, SIGNAL(clicked()), COPY_CONTROLLER, SLOT(dropCopy()));
	QObject::connect(COPY_CONTROLLER, SIGNAL(copyDropped(Copy*)), this, SLOT(copyDropped()));
	QObject::connect(COPY_CONTROLLER, SIGNAL(copyCreated(Copy*)), this, SLOT(copyCreated()));

	verticalLayout = new VerticalLayout(QPoint(0, ui.Layer_frame->pos().y()), false, true, this);
	QObject::connect(verticalLayout, SIGNAL(elementMoved(int, int)), LAYER_CONTROLLER, SLOT(orderLayer(int, int)));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerOrdered(int, int)), verticalLayout, SLOT(moveElement(int, int)));

	QObject::connect(verticalLayout, SIGNAL(reordered()), this, SLOT(setTabOrder()));
}

void LayerPanel::layerCreated(Layer* layer) {
	LayerList* calque = new LayerList(this, *layer);
	verticalLayout->addWidget(calque);
}
void LayerPanel::layerDeleted(Layer* layer) {
	verticalLayout->removeWidget(LayerList::getFromLayer(layer));
}

void LayerPanel::onlyOneLayer() {
	ui.Layer_del->setEnabled(false);
}
void LayerPanel::moreThanOneLayer() {
	ui.Layer_del->setEnabled(true);
}

void LayerPanel::firstLayerSelected(Layer* layer) {
	ui.Layer_fuse->setEnabled(false);
}
void LayerPanel::firstLayerUnselected(Layer* layer) {
	ui.Layer_fuse->setEnabled(true);
}

// When a selection is created
void LayerPanel::selectionCreated() {
	invert->setEnabled(true);
	ui.Selection_del->setEnabled(true);
}
void LayerPanel::selectionDeleted() {
	invert->setEnabled(false);
	ui.Selection_del->setEnabled(false);
}

// When a copy is created
void LayerPanel::copyCreated() {
	ui.Selection_del->setEnabled(true);
}

void LayerPanel::copyDropped() {
	ui.Selection_del->setEnabled(false);
}

void LayerPanel::setTabOrder() {
	auto list = verticalLayout->getList();

	for (int i=1; i < list.size(); i++)
		QWidget::setTabOrder(reinterpret_cast<QWidget*>(static_cast<LayerList*>(list[i-1])->getLineEdit()), 
							 reinterpret_cast<QWidget*>(static_cast<LayerList*>(list[i])->getLineEdit()));

}