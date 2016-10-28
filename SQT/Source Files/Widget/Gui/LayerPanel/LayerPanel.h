#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_LayerPanel.h"
class Layer; // Forward declaration
class VerticalList; // Forward declaration
class State2Button; // Forward declaration

class LayerPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	LayerPanel(QWidget *parent);
	~LayerPanel() {}

// SIGNALS SLOTS
	private slots:
		void setTabOrder();

// MEMBERS
private:
	Ui_LayerPanel ui;

	State2Button* invert;
	VerticalList* verticalList;
};