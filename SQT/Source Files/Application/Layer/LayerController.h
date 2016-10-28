#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalList.h"
#include "Layer.h" //class Layer; // Qt

#define INIT_LAYER_CONTROLLER LayerController::createInstance();
#define LAYER_CONTROLLER LayerController::getInstance()
#define LAYER_LIST LayerController::getInstance()->getList()
#define LAYER LayerController::getInstance()->getCurrentLayer()

class LayerController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static LayerController* _t; 
public:		inline static void createInstance() { _t = new LayerController(); }
			inline static LayerController* getInstance() { return _t; }
	
// CONSTRUCTOR
public:
	LayerController() {}
	~LayerController() {} 
	void freeWork();

// METHODS
public:
	inline Layer* getCurrentLayer() const { return current_layer; }
	inline SignalList& getList() { return layer_list; }

	int countLayer(bool count_dead = false) const;
	int positionList(const Layer& layer) const;
	const Layer& firstLayer() const;

// SIGNALS SLOTS
	public slots:
		Layer& createLayer(sf::Image& image); // Create a new LAYER based on a texture
		Layer& createLayer(); // Create a new LAYER
		void dropLayer(Layer& layer); inline void dropLayer() { dropLayer(*current_layer); }
		void fuseLayer(Layer& layer_src, Layer& layer_dst); // Fuse a layer on another, dst is drop
		void fuseLayer(); // Fuse selected layer with the one under it
		void selectLayer(Layer& layer);
		void selectLayer(); // Selection must be recalculated
	signals:
		void layerSelected(Layer&) const;
		void layerUnselected(Layer&) const;

// MEMBERS
private:
	Layer* current_layer = NULL;
	SignalList layer_list;

// UNDO
public:
	friend class LayerCreated;
	friend class LayerDropped;

	private: // Core context
		void _createLayer(Layer& layer);
		void _dropLayer(Layer& layer);
};
