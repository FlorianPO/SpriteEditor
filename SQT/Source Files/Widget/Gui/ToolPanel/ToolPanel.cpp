#include "ToolPanel.h"

#include "Source Files/Application/Tool/ToolController.h"
#include "Source Files/Application/Tool/Tool.h"

using namespace nTol;

ToolPanel::ToolPanel(QWidget *parent, const QPoint& position) : QWidget(parent) 
{
	move(position);
	ui.setupUi(this);
	show();

	ui.buttonGroup->setId(ui.Tool_crayon, CRAYON);
	ui.buttonGroup->setId(ui.Tool_gomme, GOMME);
	ui.buttonGroup->setId(ui.Tool_aero, AERO);
	ui.buttonGroup->setId(ui.Tool_pot, POT);
	ui.buttonGroup->setId(ui.Tool_rect_select, RECTSELEC);
	ui.buttonGroup->setId(ui.Tool_baguette, BAGUETTE);
	ui.buttonGroup->setId(ui.Tool_selec_color, SELECCOLOR);
	ui.buttonGroup->setId(ui.Tool_snap, SNAP);
	ui.buttonGroup->setId(ui.Tool_move, MOVE);
	ui.buttonGroup->setId(ui.Tool_grand, GRAND);
	ui.buttonGroup->setId(ui.Tool_rotation, ROTATION);
	ui.buttonGroup->setId(ui.Tool_flip, FLIP);

	QObject::connect(ui.buttonGroup, SIGNAL(buttonPressed(int)), 
					 TOOL_CONTROLLER, SLOT(selectTool(int)), 
					 Qt::DirectConnection);
	QObject::connect(TOOL_CONTROLLER, SIGNAL(toolSelected(Tool*)), 
					 this, SLOT(toolSelected(Tool*)), 
					 Qt::DirectConnection);
}

void ToolPanel::toolSelected(Tool* tool) {
	ui.buttonGroup->button(tool->getId())->setChecked(true);
}