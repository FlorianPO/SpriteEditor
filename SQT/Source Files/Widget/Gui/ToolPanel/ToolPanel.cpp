#include "Source Files/Widget/Gui/ToolPanel/ToolPanel.h"
#include "Source Files/Application/Tool/ToolController.h"

ToolPanel::ToolPanel(QWidget *parent, const QPoint& position) : QWidget(parent) 
{
	move(position);
	ui.setupUi(this);
	show();

	ui.buttonGroup->setId(ui.Tool_crayon, CTool::CRAYON);
	ui.buttonGroup->setId(ui.Tool_gomme, CTool::GOMME);
	ui.buttonGroup->setId(ui.Tool_aero, CTool::AERO);
	ui.buttonGroup->setId(ui.Tool_pot, CTool::POT);
	ui.buttonGroup->setId(ui.Tool_rect_select, CTool::RECTSELEC);
	ui.buttonGroup->setId(ui.Tool_baguette, CTool::BAGUETTE);
	ui.buttonGroup->setId(ui.Tool_selec_color, CTool::SELECCOLOR);
	ui.buttonGroup->setId(ui.Tool_snap, CTool::SNAP);
	ui.buttonGroup->setId(ui.Tool_move, CTool::MOVE);
	ui.buttonGroup->setId(ui.Tool_grand, CTool::GRAND);
	ui.buttonGroup->setId(ui.Tool_rotation, CTool::ROTATION);
	ui.buttonGroup->setId(ui.Tool_flip, CTool::FLIP);

	QObject::connect(ui.buttonGroup, SIGNAL(buttonPressed(int)), 
					 TOOL_CONTROLLER, SLOT(selectTool(int)), 
					 Qt::DirectConnection);
	QObject::connect(TOOL_CONTROLLER, SIGNAL(toolSelected(CTool*)), 
					 this, SLOT(toolSelected(CTool*)), 
					 Qt::DirectConnection);
}

void ToolPanel::toolSelected(CTool* tool) {
	ui.buttonGroup->button(tool->getId())->setChecked(true);
}