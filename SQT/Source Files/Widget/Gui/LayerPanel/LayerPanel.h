#pragma once

#include "stdafx.h"

#include "GeneratedFiles/ui_LayerPanel.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Widget/Various/VerticalLayout/VerticalLayout.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"

class LayerPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit LayerPanel(QWidget *parent, const QPoint& position=QPoint());
	~LayerPanel() {}

// SIGNALS SLOTS
	private slots:
		void layerCreated(CLayer*);
		void layerDeleted(CLayer*);
		void onlyOneLayer();
		void moreThanOneLayer();
		void firstLayerSelected(CLayer*);
		void firstLayerUnselected(CLayer*);
		void selectionCreated();
		void selectionDeleted();

// MEMBERS
private:
	Ui_LayerPanel ui;

	State2Button* invert;
	VerticalLayout* verticalLayout;
};