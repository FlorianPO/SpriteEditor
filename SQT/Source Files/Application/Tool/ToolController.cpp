#include "Source Files/Application/Tool/ToolController.h"

// All tools
#include "Source Files/Application/Tool/Tools/Aero.h"
#include "Source Files/Application/Tool/Tools/Crayon.h"
#include "Source Files/Application/Tool/Tools/Gomme.h"
#include "Source Files/Application/Tool/Tools/Pot.h"
#include "Source Files/Application/Tool/Tools/RectSelec.h"
#include "Source Files/Application/Tool/Tools/Baguette.h"
#include "Source Files/Application/Tool/Tools/SelecColor.h"
#include "Source Files/Application/Tool/Tools/Snap.h"
#include "Source Files/Application/Tool/Tools/Move.h"
#include "Source Files/Application/Tool/Tools/Grand.h"
#include "Source Files/Application/Tool/Tools/Rotation.h"
#include "Source Files/Application/Tool/Tools/Flip.h"

CToolController* CToolController::_t;

void CToolController::selectTool(CTool::tool_enum tool) {
	if (current_tool != NULL)
		delete current_tool;

	switch (tool)
	{
		case CTool::CRAYON:			current_tool = new CCrayon();		break;
		case CTool::GOMME:			current_tool = new CGomme();		break;
		case CTool::AERO:			current_tool = new CAero();			break;
		case CTool::POT:			current_tool = new CPot();			break;
		//case CTool::DEGRADE:		current_tool = new CDegrade();		break;
		case CTool::RECTSELEC:		current_tool = new CRectSelec();	break;
		case CTool::BAGUETTE:		current_tool = new CBaguette();		break;
		case CTool::SELECCOLOR:		current_tool = new CSelecColor();	break;
		case CTool::SNAP:			current_tool = new CSnap();			break;
		//case CTool::CHEMIN:		current_tool = new CChemin();		break;
		case CTool::MOVE:			current_tool = new CMove();			break;
		case CTool::GRAND:			current_tool = new CGrand();		break;
		case CTool::ROTATION:		current_tool = new CRotation();		break;
		case CTool::FLIP:			current_tool = new CFlip();			break;
		//case CTool::ALIGN:		current_tool = new CAlign();		break;
		default:														break;
	}

	emit toolSelected(current_tool);
}

void CToolController::selectTool(int tool_id) {
	selectTool(static_cast<CTool::tool_enum>(tool_id));
}