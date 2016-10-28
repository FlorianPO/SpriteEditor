#include "Gui.h"

#include "Source Files/Widget/Gui/ColorPanel/ColorPanel.h"
#include "Source Files/Widget/Gui/BrushPanel/BrushPanel.h"
#include "Source Files/Widget/Gui/ToolPanel/ToolPanel.h"
#include "Source Files/Widget/Gui/LayerPanel/LayerPanel.h"
#include "Source Files/Widget/Various/Layout/VerticalLayout.h"
#include "Source Files/QtApp/QtApp.h"
#include "Source Files/Widget/Menu/Menu.h"
#include "Source Files/Application/Queue/QueueController.h"

#include "Source Files/Widget/Gui/InfoPanel/InfoPanel_position.h"
#include "Source Files/Widget/Gui/InfoPanel/InfoPanel_selection.h"
#include "Source Files/Widget/Gui/InfoPanel/InfoPanel_copy.h"

Gui* Gui::_t;

Gui::Gui(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	setMouseTracking(true);

	QObject::connect(MENU, SIGNAL(globallyChanged()), this, SLOT(findSpace()));

	QUEUE->atStart([this]() {
		ToolPanel* tp = new ToolPanel(this);						tp->show();
		ColorPanel* cp = new ColorPanel(this);						cp->show();
		InfoPanel_position* ipp = new InfoPanel_position(this);		ipp->show();
		InfoPanel_selection* ips = new InfoPanel_selection(this);
		InfoPanel_copy* ipc = new InfoPanel_copy(this);
		BrushPanel* top = new BrushPanel(this);						top->show();
		LayerPanel* lp = new LayerPanel(this);						lp->show();

		verticalLayout = new VerticalLayout(true, QPoint(8, 8));

		verticalLayout->_fillBegin();
		verticalLayout->setSpacing(8);
		verticalLayout->addWidget(tp);
		verticalLayout->addWidget(cp);
		verticalLayout->addWidget(top);
		verticalLayout->setLocalSpacing(-8);
		verticalLayout->addWidget(ipp);
		verticalLayout->setLocalSpacing(-4);
		verticalLayout->addWidget(ips);
		verticalLayout->setLocalSpacing(-4);
		verticalLayout->addWidget(ipc);
		verticalLayout->setLocalSpacing(-6);
		verticalLayout->addWidget(lp);
		verticalLayout->_fillEnd();
	});
}

void Gui::showEvent(QShowEvent* evnt) {
	QWidget::showEvent(evnt);
	emit globallyChanged();
}

void Gui::hideEvent(QHideEvent* evnt) {
	QWidget::hideEvent(evnt);
	emit globallyChanged();
}

void Gui::findSpace() {
	QSize size;
	if (MENU->isVisible()) {
		move(QPoint(0, MENU->height()));
		size = QSize(width(), QTWINDOW->size().height() - MENU->height());
	}
	else {
		move(QPoint(0, 0));
		size = QSize(width(), QTWINDOW->size().height());
	}
	resize(size);
	emit globallyChanged();
}