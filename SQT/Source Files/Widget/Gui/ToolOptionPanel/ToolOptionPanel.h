#pragma once

#include "stdafx.h"

#include "ui_ToolOptionPanel.h"
#include "Source Files/Widget/Various/TabSFML/TabSFML.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/Application/Brush/Brush.h"

class ToolOptionPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit ToolOptionPanel(QWidget* parent, const QPoint& position=QPoint());
	~ToolOptionPanel() {}

// SIGNALS SLOTS
	public slots:
		void brushCreated(CBrush* brush);

// MEMBERS
private:
	Ui_ToolOptionPanel ui;

	ClickLabel* Opacity;
	ClickLabel* Seuil;
	ClickLabel* SizeX;
	ClickLabel* SizeY;
	TabSFML* SFMLTab;
};
