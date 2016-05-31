#pragma once

#include "stdafx.h"
#include "Source Files/Application/Tool/Tool.h"

#define INIT_TOOL_CONTROLLER CToolController::createInstance();

#define TOOL_CONTROLLER CToolController::getInstance()
#define TOOL CToolController::getInstance()->getCurrentTool()

class CToolController : public QObject
{
	Q_OBJECT
//Instance
private:	static CToolController* _t; 
public:		inline static void createInstance() { _t = new CToolController(); }
			inline static CToolController* getInstance() { return _t; }

// CONSTRUCTOR
	CToolController() {}
	~CToolController() {}

// METHODS
	CTool* getCurrentTool() { return current_tool; }

// SIGNALS SLOTS
	public slots:
		void selectTool(int tool_id);
		void selectTool(CTool::tool_enum tool);
	signals:
		void toolSelected(CTool*);

// MEMBERS
private:
	CTool* current_tool = NULL; 
};

