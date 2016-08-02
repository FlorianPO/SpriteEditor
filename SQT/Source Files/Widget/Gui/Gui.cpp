#include "Gui.h"

#include "Source Files/Widget/Gui/ColorPanel/ColorPanel.h"
#include "Source Files/Widget/Gui/BrushPanel/BrushPanel.h"
#include "Source Files/Widget/Gui/ToolPanel/ToolPanel.h"
#include "Source Files/Widget/Gui/LayerPanel/LayerPanel.h"
#include "Source Files/Widget/Gui/InfoPanel/InfoPanel.h"
#include "Source Files/Widget/Various/VerticalLayout/VerticalLayout.h"

Gui* Gui::_t;

Gui::Gui(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	setMouseTracking(true);

	BrushPanel* top = new BrushPanel(this);
	LayerPanel* lp = new LayerPanel(this);

	ToolPanel* tp = new ToolPanel(this);
	ColorPanel* cp = new ColorPanel(this);
	InfoPanel* ip = new InfoPanel(this);

	verticalLayout = new VerticalLayout(QPoint(8, 8));

	verticalLayout->_fillBegin();
	verticalLayout->setSpacing(8);
	verticalLayout->addWidget(tp);
	verticalLayout->addWidget(cp);
	verticalLayout->addWidget(top);
	verticalLayout->setLocalSpacing(-8);
	verticalLayout->addWidget(ip);
	verticalLayout->setLocalSpacing(-4);
	verticalLayout->addWidget(lp);
	verticalLayout->_fillEnd();
}