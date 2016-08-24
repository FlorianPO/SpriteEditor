#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_LayerList.h"
class Layer; // Forward declaration
class SpriteView; // Forward declaration
class State2Button; // Forward declaration
class FLineEdit; // Forward declaration

class LayerList : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	LayerList(QWidget* parent, Layer& layer, const QPoint& position=QPoint());
	~LayerList() {}
	
// SIGNALS SLOTS
	private slots:
		void layerUpdated();
		void layerSelected();
		void layerUnselected();
		void dropped();
		void undropped();

// METHODS
public:
	static LayerList* getFromLayer(Layer* layer);
	FLineEdit* getLineEdit() { return line_edit; }


private:
	bool eventFilter(QObject *object, QEvent *event) override;
	void mousePressEvent(QMouseEvent* Qm) override;
	void moveEvent(QMoveEvent *Qm) override;

// MEMBERS
private:
	static QHash<Layer*, LayerList*> hash;

	Ui_LayerList ui;
	Layer* layer;
	SpriteView* sprite_view = NULL;
	State2Button* view_button;
	FLineEdit* line_edit;
};

