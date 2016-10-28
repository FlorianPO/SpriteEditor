#pragma once

#include "stdenum.h"
#include "GeneratedFiles/Ui_InfoPanel_position.h"

class ViewLabel; // Forward declaration

class InfoPanel_position : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	InfoPanel_position(QWidget *parent);
	~InfoPanel_position() {};

// MEMBERS
private:
	Ui_InfoPanel_position ui_pos;

	ViewLabel* PosX;
	ViewLabel* PosY;
};
