#include "ToolController.h"

// All tools
#include "Tools/Aero.h"
#include "Tools/Crayon.h"
#include "Tools/Gomme.h"
#include "Tools/Pot.h"
#include "Tools/RectSelec.h"
#include "Tools/Baguette.h"
#include "Tools/SelecColor.h"
#include "Tools/Snap.h"
#include "Tools/Move.h"
#include "Tools/Grand.h"
#include "Tools/Rotation.h"
#include "Tools/Flip.h"

#include "Source Files/Application/Input/ShortcutController.h"

using namespace nTol;

ToolController* ToolController::_t;

ToolController::ToolController() {
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_A), this, SLOT(selectTool(int)), static_cast<int>(CRAYON));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_Z), this, SLOT(selectTool(int)), static_cast<int>(GOMME));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_E), this, SLOT(selectTool(int)), static_cast<int>(AERO));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_R), this, SLOT(selectTool(int)), static_cast<int>(POT));
	//
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_Q), this, SLOT(selectTool(int)), static_cast<int>(RECTSELEC));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_S), this, SLOT(selectTool(int)), static_cast<int>(BAGUETTE));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_D), this, SLOT(selectTool(int)), static_cast<int>(SELECCOLOR));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_F), this, SLOT(selectTool(int)), static_cast<int>(SNAP));
	//
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_W), this, SLOT(selectTool(int)), static_cast<int>(MOVE));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_X), this, SLOT(selectTool(int)), static_cast<int>(GRAND));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_C), this, SLOT(selectTool(int)), static_cast<int>(ROTATION));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_V), this, SLOT(selectTool(int)), static_cast<int>(FLIP));
	//
}

void ToolController::selectTool(nTol::tool_enum tool) {
	if (current_tool != NULL)
		delete current_tool;

	switch (tool) {
		case CRAYON:		current_tool = new Crayon();		break;
		case GOMME:			current_tool = new Gomme();			break;
		case AERO:			current_tool = new Aero();			break;
		case POT:			current_tool = new Pot();			break;
		//case DEGRADE:		current_tool = new CDegrade();		break;
		case RECTSELEC:		current_tool = new RectSelec();		break;
		case BAGUETTE:		current_tool = new Baguette();		break;
		case SELECCOLOR:	current_tool = new SelecColor();	break;
		case SNAP:			current_tool = new Snap();			break;
		//case CHEMIN:		current_tool = new CChemin();		break;
		case MOVE:			current_tool = new Move();			break;
		case GRAND:			current_tool = new Grand();			break;
		case ROTATION:		current_tool = new Rotation();		break;
		case FLIP:			current_tool = new Flip();			break;
		//case ALIGN:		current_tool = new CAlign();		break;
		default:												break;
	}

	emit toolSelected(*current_tool);
}

void ToolController::selectTool(int tool_id) {
	selectTool(static_cast<tool_enum>(tool_id));
}