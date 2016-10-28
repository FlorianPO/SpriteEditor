#pragma once

#include "stdenum.h"
class Tool; // Forward declaration

#define INIT_TOOL_CONTROLLER ToolController::createInstance();
#define TOOL_CONTROLLER ToolController::getInstance()
#define TOOL ToolController::getInstance()->getCurrentTool()

class ToolController : public QObject
{
	Q_OBJECT
//Instance
private:	static ToolController* _t; 
public:		inline static void createInstance() { _t = new ToolController(); }
			inline static ToolController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	ToolController();
	~ToolController() {}

// METHODS
public:
	inline Tool* getCurrentTool() const { return current_tool; }

// SIGNALS SLOTS
	public slots:
		void selectTool(int tool_id);
		void selectTool(nTol::tool_enum tool);
	signals:
		void toolSelected(Tool&) const;

// MEMBERS
private:
	Tool* current_tool = NULL; 
};

