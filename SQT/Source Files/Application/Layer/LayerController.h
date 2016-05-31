#pragma once

#include "stdafx.h"

#define INIT_LAYER_CONTROLLER CLayerController::createInstance();

#define LAYER_CONTROLLER CLayerController::getInstance()
#define LAYER_LIST CLayerController::getInstance()->getLayerList()
#define LAYER CLayerController::getInstance()->getCurrentLayer()

class CLayer;

class CLayerController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static CLayerController* _t; 
public:		inline static void createInstance() { _t = new CLayerController(); }
			inline static CLayerController* getInstance() { return _t; }
	
// CONSTRUCTOR
	CLayerController() {}
	~CLayerController() {} 

// METHODS
	inline CLayer* getCurrentLayer() { return current_layer; }
	inline const std::vector<CLayer*>& getLayerList() { return layer_list; }

	int countLayer(bool count_dead = false);
	int positionList(CLayer* layer);
	CLayer* firstLayer();

// SIGNALS SLOTS
	public slots:
		void createLayer(sf::Texture* texture_var=NULL); //Create a new LAYER based on a texture
		void selectLayer(CLayer* layer=NULL);
		void deleteLayer(CLayer* layer=NULL);
		void fuseLayer(CLayer* layer_src, CLayer* layer_dst);
		void fuseLayer();
	signals:
		void layerCreated(CLayer*);
		void layerDeleted(CLayer*);
		void firstLayerSelected(CLayer*);
		void firstLayerUnselected(CLayer*);
		void onlyOneLayer();
		void moreThanOneLayer();

// MEMBERS
private:
	CLayer* current_layer = NULL;
	std::vector<CLayer*> layer_list;
};

