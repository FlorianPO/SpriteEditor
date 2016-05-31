#pragma once

#include "stdafx.h"

#include <QtWidgets/QWidget>
#include "GeneratedFiles/Ui_InfoPanel.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"

class InfoPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit InfoPanel(QWidget *parent, const QPoint& position=QPoint());
	~InfoPanel() {};

// SIGNALS SLOTS
	private slots:
		void selectionCreated();
		void selectionDeleted();

// MEMBERS
private:
	Ui_InfoPanel ui;

	ViewLabel* PosX;
	ViewLabel* PosY;

	ViewLabel* SizeX;
	ViewLabel* SizeY;
	ViewLabel* SizeW;
	ViewLabel* SizeH;
};
