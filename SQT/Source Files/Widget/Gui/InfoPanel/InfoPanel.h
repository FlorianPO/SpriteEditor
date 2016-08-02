#pragma once

#include "stdenum.h"
#include "GeneratedFiles/Ui_InfoPanel.h"
class ViewLabel; // Forward declaration

class InfoPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	InfoPanel(QWidget *parent, const QPoint& position=QPoint());
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
