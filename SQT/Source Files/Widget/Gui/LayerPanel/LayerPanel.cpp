#include "LayerPanel.h"

#include "LayerList/LayerList.h"
#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/QtApp/QtApp.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"
#include "Source Files/Widget/Various/Layout/VerticalList.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/SignalType//SignalListObject.h"
#include "Source Files/SignalType//SignalList.h"

LayerPanel::LayerPanel(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	hide();

	VerticalList::param p;
	p.up_to_down = false;
	p.dragable = true;
	p.selectable = false;
	p.multi_selection = false;
	p.ensure_undo = false;
	p.ensure_drag = true;
	verticalList = new VerticalList(this, p, QPoint(0, ui.Layer_frame->pos().y()), UNDO, &LAYER_LIST);

	QObject::connect(ui.Layer_new, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(createLayer()));
	QObject::connect(&LAYER_LIST, &SignalList::created, this, [this](SignalListObject& layer) { verticalList->addWidget(*new LayerList(this, &layer, QTWINDOW)); });

	QObject::connect(ui.Layer_del, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(dropLayer()));
	QObject::connect(verticalList, &List::onlyOneObject, [this](){ ui.Layer_del->setEnabled(false); });
	QObject::connect(verticalList, &List::moreThanOneObject, [this](){ ui.Layer_del->setEnabled(true); });

	QObject::connect(ui.Layer_fuse, SIGNAL(clicked()), LAYER_CONTROLLER, SLOT(fuseLayer()));
	QObject::connect(verticalList, &List::firstObjectSelected, [this](ListObject&){ ui.Layer_fuse->setEnabled(false); });
	QObject::connect(verticalList, &List::firstObjectUnselected, [this](ListObject&){ ui.Layer_fuse->setEnabled(true); });

	invert = new State2Button(this, &QString("Selections/selec_invert_enabled"), &QString("Selections/selec_invert_disabled"), false);
	invert->move(QPoint(76, 4)); invert->show();
	QObject::connect(invert, SIGNAL(enabled()), SELEC, SLOT(invertSelection()));
	QObject::connect(invert, SIGNAL(disabled()), SELEC, SLOT(uninvertSelection()));
	QObject::connect(SELEC, SIGNAL(selectionInverted()), invert, SLOT(enable()));
	QObject::connect(SELEC, SIGNAL(selectionUninverted()), invert, SLOT(disable()));

	// Selection
	QObject::connect(ui.Selection_del, SIGNAL(clicked()), SELEC, SLOT(deleteSelection()));
	QObject::connect(SELEC, &SelectionController::selectionDeleted, [this](){ invert->setEnabled(false); ui.Selection_del->setEnabled(false); });
	QObject::connect(SELEC, &SelectionController::selectionCreated, [this](){ invert->setEnabled(true); ui.Selection_del->setEnabled(true); });
	// Copy
	QObject::connect(ui.Selection_del, SIGNAL(clicked()), COPY_CONTROLLER, SLOT(dropCopy()));
	QObject::connect(COPY_CONTROLLER, &CopyController::copyDropped, [this](const Copy&){ ui.Selection_del->setEnabled(false); });
	QObject::connect(COPY_CONTROLLER, &CopyController::copyCreated, [this](const Copy&){ ui.Selection_del->setEnabled(true); });

	QObject::connect(verticalList, SIGNAL(reordered()), this, SLOT(setTabOrder()));
}

void LayerPanel::setTabOrder() {
	auto list = verticalList->getList();

	for (int i=1; i < list.size(); i++)
		QWidget::setTabOrder(reinterpret_cast<QWidget*>(&static_cast<LayerList*>(list[i-1])->getLineEdit()), 
							 reinterpret_cast<QWidget*>(&static_cast<LayerList*>(list[i])->getLineEdit()));

}