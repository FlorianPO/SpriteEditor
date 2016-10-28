#pragma once

#include "stdenum.h"
#include "GeneratedFiles/Ui_InfoPanel_copy.h"

class ClickLabel; // Forward declaration
class ViewLabel;
class Copy;

class InfoPanel_copy : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	InfoPanel_copy(QWidget *parent);
	~InfoPanel_copy() {}

	private slots:
		void bind(Copy& copy);
		void unbind();

// MEMBERS
private:
	Ui_InfoPanel_copy ui_copy;

	ClickLabel* SizeX;
	ClickLabel* SizeY;
	ViewLabel* SizeW;
	ViewLabel* SizeH;

	std::vector<QMetaObject::Connection> lambdas;
};
