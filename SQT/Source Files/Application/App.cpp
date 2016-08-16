#include "App.h"

#include "Queue/QueueController.h"
#include "Resource/ResourceController.h"
#include "Layer/LayerController.h"
#include "Layer/Layer.h"
#include "Selection/SelectionController.h"
#include "Tool/ToolController.h"
#include "Tool/Tool.h"
#include "Brush/BrushController.h"
#include "Camera/CameraController.h"
#include "Copy/CopyController.h"
#include "Copy/Copy.h"
#include "UndoStack/UndoStack.h"
#include "Background/Background.h"

App* App::_t;

void App::load(std::string source) {
	filename = source;
	path = RES->directory;

	//Loading image
	sf::Image* image = new sf::Image();
	if (!image->loadFromFile(source))
		std::cout << "Unable to load file at " + path.toAnsiString() + filename.toAnsiString() << std::endl;

	initWork(image);
}

void App::loadAsLayer(std::string source) {
	filename = source;
	path = RES->directory;

	//Loading image
	sf::Image* image = new sf::Image();
	if (!image->loadFromFile(source))
		std::cout << "Unable to load file at " + path.toAnsiString() + filename.toAnsiString() << std::endl;

	LAYER_CONTROLLER->createLayer(image);
	CAMERA->centerOnLayer();
}

void App::initWork(sf::Image* image) {
	freeWork();

	BRUSH_CONTROLLER->selectBrush(nBrh::CIRCLE);
	TOOL_CONTROLLER->selectTool(nTol::AERO);
	UNDO->beginFirst();
	LAYER_CONTROLLER->createLayer(image);
	UNDO->endFirst();

	CAMERA->centerOnLayer();
}

void App::freeWork() {
	UNDO->freeWork();
	LAYER_CONTROLLER->freeWork();
	COPY_CONTROLLER->freeWork();
	SELEC->freeWork();
}

void App::run() {
	//Utiliser l'outil
	if (COPY == NULL || nTol::isTransform(TOOL->getEnum()))
		TOOL->use();
	else
		COPY->move();
}

void App::display() {
	QUEUE->updateBeforeDisplay();
	
	//Nettoyer fenêtre
	fenetre->setView(*CAMERA);
	fenetre->clear();

	BACKGROUND->displayBack();

	//Afficher les calques / la sélection
	FOR_I (LAYER_LIST.size()) {
		LAYER_LIST[i]->display();
		if (COPY != NULL && LAYER == LAYER_LIST[i])
			COPY->display();
	}

	BACKGROUND->displayLines();

	if (COPY != NULL)
		COPY->displayLines();

	//Afficher les lignes de la séléction
	SELEC->displayLines();

	//Afficher les objets relatifs à l'outil
	if (TOOL != NULL)
		TOOL->display();

	//static sf::Clock h;
	//float fps = 1.f/(h.restart().asSeconds());
	//std::cout << fps << std::endl;

	frame++;
}

