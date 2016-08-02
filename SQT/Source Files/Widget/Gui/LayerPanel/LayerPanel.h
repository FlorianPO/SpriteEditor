#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_LayerPanel.h"
class Layer; // Forward declaration
class VerticalLayout; // Forward declaration
class State2Button; // Forward declaration

class LayerPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	LayerPanel(QWidget *parent, const QPoint& position=QPoint());
	~LayerPanel() {}

// SIGNALS SLOTS
	private slots:
		void layerCreated(Layer*);
		void layerDeleted(Layer*);
		void onlyOneLayer();
		void moreThanOneLayer();
		void firstLayerSelected(Layer*);
		void firstLayerUnselected(Layer*);
		void selectionCreated();
		void selectionDeleted();
		void copyCreated();
		void copyDropped();

// MEMBERS
private:
	Ui_LayerPanel ui;

	State2Button* invert;
	VerticalLayout* verticalLayout;
};