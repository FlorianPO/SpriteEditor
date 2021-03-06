#pragma once

#include "stdenum.h"
#include "ui_ToolPanel.h"
class Tool; // Forward declaration

class ToolPanel :  public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	ToolPanel(QWidget *parent);
	~ToolPanel() {};

// SIGNALS SLOTS
	public slots:
		void toolSelected(Tool& tool);

// MEMBERS
private:
	Ui_ToolPanel ui;
};

