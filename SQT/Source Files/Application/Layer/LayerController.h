#pragma once

#include "stdenum.h"
class Layer; // Forward declaration

#define INIT_LAYER_CONTROLLER LayerController::createInstance();
#define LAYER_CONTROLLER LayerController::getInstance()
#define LAYER_LIST LayerController::getInstance()->getLayerList()
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

// METHODS
public:
	inline Layer* getCurrentLayer() { return current_layer; }
	inline const std::vector<Layer*>& getLayerList() { return layer_list; }

	int countLayer(bool count_dead = false);
	int positionList(Layer* layer);
	Layer* firstLayer();

// SIGNALS SLOTS
	private slots:
		void _layerSelectedMoved(sf::Vector2f position);
		void _layerSelectedScaled(sf::Vector2f size);
	public slots:
		void createLayer(sf::Image* image=NULL); // Create a new LAYER based on a texture
		void deleteLayer(Layer* layer=LAYER); // Hard delete a LAYER (forever)
		void dropLayer(Layer* layer=LAYER); // Delete a LAYER
		void fuseLayer(Layer* layer_src, Layer* layer_dst); // Fuse a layer on another, dst is dropped
		void fuseLayer(); // Fuse selected layer with the one under it
		void selectLayer(Layer* layer=NULL); // NULL if selection must be recalculated
		void orderLayer(int src, int dst); // Doesn't emit layerOrdered(...)
	signals:
		void layerCreated(Layer*);
		void layerDeleted(Layer*);
		void layerOrdered(int src, int dst);
		void firstLayerSelected(Layer*);
		void firstLayerUnselected(Layer*);
		void onlyOneLayer();
		void moreThanOneLayer();
		void layerSelectedMoved(sf::Vector2f position);
		void layerSelectedScaled(sf::Vector2f size);

// MEMBERS
private:
	Layer* current_layer = NULL;
	std::vector<Layer*> layer_list;

// UNDO
public:
	friend class LayerCreated;
	friend class LayerDropped;
	friend class LayerOrdered;

	private: // Core context
		void _createLayer(Layer* layer);
		void _dropLayer(Layer* layer);
		void _orderLayer(int src, int dst);
};
