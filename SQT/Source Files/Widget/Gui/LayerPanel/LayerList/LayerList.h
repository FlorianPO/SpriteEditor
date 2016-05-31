#pragma once

#include "stdafx.h"

#include "GeneratedFiles/ui_LayerList.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Widget/Gui/LayerPanel/LayerList/SpriteView/SpriteView.h"
#include "Source Files/Widget/Various/StateButton/State2Button.h"

class LayerList : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit LayerList(QWidget* parent, CLayer& layer, const QPoint& position=QPoint());
	~LayerList() {}
	
// SIGNALS SLOTS
	public slots:
		void layerSelected();
		void layerUnselected();

// METHODS
public:
	static LayerList* getFromLayer(CLayer* layer);
private:
	bool eventFilter(QObject *object, QEvent *event) override;
	void mousePressEvent(QMouseEvent* qm) override;

// MEMBERS
private:
	static QHash<CLayer*, LayerList*> hash;

	Ui_LayerList ui;
	CLayer* layer;
	SpriteView* sprite_view;
	State2Button* view_button;
};

