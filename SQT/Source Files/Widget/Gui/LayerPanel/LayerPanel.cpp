#include "Source Files/Widget/Gui/LayerPanel/LayerPanel.h"

#include "Source Files/Widget/Gui/LayerPanel/LayerList/LayerList.h"
#include "Source Files/Application/Selec/Selec.h"

LayerPanel::LayerPanel(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui.setupUi(this);
	show();

	QObject::connect(ui.Layer_new, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(createLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerCreated(CLayer*)), this, SLOT(layerCreated(CLayer*)), Qt::DirectConnection);

	QObject::connect(ui.Layer_del, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(deleteLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerDeleted(CLayer*)), this, SLOT(layerDeleted(CLayer*)), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(onlyOneLayer()), this, SLOT(onlyOneLayer()), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(moreThanOneLayer()), this, SLOT(moreThanOneLayer()), Qt::DirectConnection);

	QObject::connect(ui.Layer_fuse, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(fuseLayer()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(firstLayerSelected(CLayer*)), this, SLOT(firstLayerSelected(CLayer*)), Qt::DirectConnection);
	QObject::connect(LAYER_CONTROLLER, SIGNAL(firstLayerUnselected(CLayer*)), this, SLOT(firstLayerUnselected(CLayer*)), Qt::DirectConnection);

	invert = new State2Button(this, &QString("Selections/selec_invert_enabled"), &QString("Selections/selec_invert_disabled"), false);
	invert->move(QPoint(76, 4)); invert->show();
	QObject::connect(invert, SIGNAL(enabled()), SELEC, SLOT(invertSelection()), Qt::DirectConnection);
	QObject::connect(invert, SIGNAL(disabled()), SELEC, SLOT(uninvertSelection()), Qt::DirectConnection);
	QObject::connect(SELEC, SIGNAL(selectionInverted()), invert, SLOT(enable()));
	QObject::connect(SELEC, SIGNAL(selectionUninverted()), invert, SLOT(disable()));

	QObject::connect(ui.Selection_del, SIGNAL(clicked()), SELEC, SLOT(deleteSelection()));
	QObject::connect(SELEC, SIGNAL(selectionDeleted()), this, SLOT(selectionDeleted()), Qt::DirectConnection);
	QObject::connect(SELEC, SIGNAL(selectionCreated()), this, SLOT(selectionCreated()), Qt::DirectConnection);

	verticalLayout = new VerticalLayout(QPoint(0, ui.Layer_frame->pos().y()), false);
}

void LayerPanel::layerCreated(CLayer* layer) {
	LayerList* calque = new LayerList(this, *layer);
	verticalLayout->addWidget(calque);
}
void LayerPanel::layerDeleted(CLayer* layer) {
	verticalLayout->removeWidget(LayerList::getFromLayer(layer));
}

void LayerPanel::onlyOneLayer() {
	ui.Layer_del->setEnabled(false);
}
void LayerPanel::moreThanOneLayer() {
	ui.Layer_del->setEnabled(true);
}

void LayerPanel::firstLayerSelected(CLayer* layer) {
	ui.Layer_fuse->setEnabled(false);
}
void LayerPanel::firstLayerUnselected(CLayer* layer) {
	ui.Layer_fuse->setEnabled(true);
}

void LayerPanel::selectionCreated() {
	invert->setEnabled(true);
	ui.Selection_del->setEnabled(true);
}
void LayerPanel::selectionDeleted() {
	invert->setEnabled(false);
	ui.Selection_del->setEnabled(false);
}