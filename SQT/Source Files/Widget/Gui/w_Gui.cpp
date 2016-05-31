#include "Source Files/Widget/Gui/w_Gui.h"

#include <iostream>
#include "Source Files/Widget/Various/TabSFML/TabSFML.h"
#include "Source Files/Widget/Gui/ColorPanel/ColorPanel.h"
#include "Source Files/Widget/Gui/ToolOptionPanel/ToolOptionPanel.h"
#include "Source Files/Widget/Gui/ToolPanel/ToolPanel.h"
#include "Source Files/Widget/Gui/LayerPanel/LayerPanel.h"
#include "Source Files/Widget/Gui/InfoPanel/InfoPanel.h"

w_Gui::w_Gui(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	setMouseTracking(true);
	show();

	ToolOptionPanel* top = new ToolOptionPanel(this);
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

void w_Gui::mouseMoveEvent(QMouseEvent* event) {
	//std::cout << "move" << std::endl;
}

void w_Gui::mousePressEvent(QMouseEvent* Qm)
{
	std::cout << "event" << std::endl;
}