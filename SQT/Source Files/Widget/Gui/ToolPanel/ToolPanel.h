#pragma once

#include "stdafx.h"
#include "ui_ToolPanel.h"
#include "Source Files/Application/Tool/Tool.h"

class ToolPanel :  public QWidget
{
	Q_OBJECT
public:
	explicit ToolPanel(QWidget *parent, const QPoint& position=QPoint(0, 0));
	~ToolPanel() {};

	int getBottomY() { return ui.Frame->geometry().height() + pos().y(); }

	public slots:
		void toolSelected(CTool* tool);

private:
	Ui_ToolPanel ui;
};

