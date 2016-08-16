#pragma once

#include "stdenum.h"
#include "GeneratedFiles/Ui_InfoPanel_selection.h"

class ClickLabel; // Forward declaration
class ViewLabel;

class InfoPanel_selection : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	InfoPanel_selection(QWidget *parent, const QPoint& position=QPoint());
	~InfoPanel_selection() {}

	private slots:
		void bind();

// MEMBERS
private:
	Ui_InfoPanel_selection ui_selec;

	ClickLabel* SizeX;
	ClickLabel* SizeY;
	ViewLabel* SizeW;
	ViewLabel* SizeH;

	std::vector<QMetaObject::Connection> lambdas;
};
