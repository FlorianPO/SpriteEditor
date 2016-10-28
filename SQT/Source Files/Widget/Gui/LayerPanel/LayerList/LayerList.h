#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_LayerList.h"
#include "Source Files/Widget/Various/Layout/ListObject.h"
class Layer; // Forward declaration
class SpriteView; // Forward declaration
class State2Button; // Forward declaration
class FLineEdit; // Forward declaration

class LayerList : public ListObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	LayerList(QWidget* parent, SignalListObject* binded_object=NULL, QMainWindow* window=NULL);
	~LayerList();

// METHODS
public:
	static LayerList& getFromLayer(Layer& layer);
	FLineEdit& getLineEdit() const { return *line_edit; }

// MEMBERS
private:
	static QHash<Layer*, LayerList*> hash;

	Ui_LayerList ui;
	Layer* layer;
	SpriteView* sprite_view = NULL;
	State2Button* view_button;
	FLineEdit* line_edit;
};

