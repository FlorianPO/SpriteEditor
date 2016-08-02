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
#include "Source Files/SignalType/SignalInit.h"
#include "Source Files/Fonction/Fonction.h"

App* App::_t;

App::App(sf::RenderWindow* _f) {
	fenetre = _f;

	lines_bord = sf::VertexArray(sf::LinesStrip, 5);
	sprite_transparency = RES->getSprite(nRer::alpha_gimp);
	cache_fond[0] = sf::VertexArray(sf::Quads, 4);
	cache_fond[1] = sf::VertexArray(sf::Quads, 4);
	cache_fond[2] = sf::VertexArray(sf::Quads, 4);
	cache_fond[3] = sf::VertexArray(sf::Quads, 4);

	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerSelectedMoved(sf::Vector2f)), this, SLOT(cadreMoved()));
	QObject::connect(LAYER_CONTROLLER, SIGNAL(layerSelectedScaled(sf::Vector2f)), this, SLOT(cadreScaled()));
	QObject::connect(CAMERA, SIGNAL(zoomed(float)), this, SLOT(cameraZoomed(float)));
	QObject::connect(CAMERA, SIGNAL(moved(sf::Vector2f)), this, SLOT(cameraMoved()));
}

App::~App() { fenetre->close(); }

void App::cadreMoved()		{ QUEUE->beforeDisplay(this, "gererFond"); QUEUE->beforeDisplay(this, "gererLines"); }
void App::cadreScaled()		{ QUEUE->beforeDisplay(this, "gererFond"); QUEUE->beforeDisplay(this, "gererLines"); }
void App::cameraMoved()		{ QUEUE->beforeDisplay(this, "gererFond"); QUEUE->beforeDisplay(this, "gererLines"); }
void App::cameraZoomed(float zoom_factor) {
	QUEUE->beforeDisplay(this, "gererFond");
	QUEUE->beforeDisplay(this, "gererLines"); 
	sprite_transparency.setScale(10 / zoom_factor, 10 / zoom_factor);
}

void App::loadFromPath(std::string str) {
	filename = str;

	//Loading image_selec
	sf::Image* image = new sf::Image();
	if (!image->loadFromFile(RES->directory + str))
		std::cout << "Unable to load file at " + RES->directory.toAnsiString() + str << std::endl;

	init_work(image);
}

void App::init_work(sf::Image* image) {
	free_work();

	//Init some stuff
	SignalInit::emitSignals();

	BRUSH_CONTROLLER->selectBrush(nBrh::CIRCLE);
	TOOL_CONTROLLER->selectTool(nTol::AERO);
	UNDO->beginFirst();
	LAYER_CONTROLLER->createLayer(image);
	UNDO->endFirst();

	CAMERA->centerOnLayer();
}

void App::free_work() {
	//TODO
	//Free all pointers
	/*
	for (int i = 0; i < CALQUE_LIST.size(); i++)
	delete CALQUE_LIST[i];
	for (int i = 0; i < COPY_LIST.size(); i++)
	delete COPY_LIST[i];

	CALQUE_LIST.clear();
	COPY_LIST.clear();
	RETOUR->free();
	*/
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void App::gererFond() {
	sf::Vector2f pos = CAMERA->getPosition(nStd::UP_LEFT);
	sprite_transparency.setPosition(pos);

	sf::FloatRect rect = LAYER->getGlobalBounds();
	cache_fond[0][0] = sf::Vertex(pos, color_fond);
	cache_fond[0][1] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, pos.y), color_fond);
	cache_fond[0][2] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, rect.top), color_fond);
	cache_fond[0][3] = sf::Vertex(sf::Vector2f(pos.x, rect.top), color_fond);

	cache_fond[1][0] = sf::Vertex(sf::Vector2f(pos.x, rect.top), color_fond);
	cache_fond[1][1] = sf::Vertex(sf::Vector2f(rect.left, rect.top), color_fond);
	cache_fond[1][2] = sf::Vertex(sf::Vector2f(rect.left, rect.top + rect.height), color_fond);
	cache_fond[1][3] = sf::Vertex(sf::Vector2f(pos.x, rect.top + rect.height), color_fond);

	cache_fond[2][0] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top), color_fond);
	cache_fond[2][1] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, rect.top), color_fond);
	cache_fond[2][2] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, rect.top + rect.height), color_fond);
	cache_fond[2][3] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top + rect.height), color_fond);

	cache_fond[3][0] = sf::Vertex(sf::Vector2f(pos.x, rect.top + rect.height), color_fond);
	cache_fond[3][1] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, rect.top + rect.height), color_fond);
	cache_fond[3][2] = sf::Vertex(sf::Vector2f(pos.x + CAMERA->getSize().x, pos.y + CAMERA->getSize().y), color_fond);
	cache_fond[3][3] = sf::Vertex(sf::Vector2f(ARG_VECTOR(pos) + CAMERA->getSize().y), color_fond);
}

void App::gererLines() {
	sf::Sprite layer_sprite = LAYER->getSprite();
	lines_bord[0].position = Fonction::topLeftCorner(layer_sprite);
	lines_bord[1].position = Fonction::topRightCorner(layer_sprite);
	lines_bord[2].position = Fonction::bottomRightCorner(layer_sprite);
	lines_bord[3].position = Fonction::bottomLeftCorner(layer_sprite);
	lines_bord[4].position = lines_bord[0].position;
}

void App::displayLines() {
	static sf::Uint8 var = 0;
	static bool change = false;

	sf::Color color = sf::Color(255, 255, var);

	FOR_I (lines_bord.getVertexCount())
		lines_bord[i].color = color;
	fenetre->draw(lines_bord);

	if (!change) {
		if (var + 10 > 255) { var = 255; change = true; }
		else { var += 10; }
	}
	else {
		if (var - 10 < 0) { var = 0; change = false; }
		else { var -= 10; }
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	fenetre->clear(color_fond);

	fenetre->draw(sprite_transparency);
	FOR_I (4)
		fenetre->draw(cache_fond[i]);

	//Afficher les calques / la sélection
	FOR_I (LAYER_LIST.size()) {
		LAYER_LIST[i]->display();
		if (COPY != NULL && LAYER == LAYER_LIST[i])
			COPY->display();
	}

	displayLines();

	if (COPY != NULL)
		COPY->displayLines();

	//Afficher les lignes de la séléction
	SELEC->displayLines();

	//Afficher les objets relatifs à l'outil
	if (TOOL != NULL)
		TOOL->display();

	//static sf::Clock h;
	//std::cout << 1.f/(h.restart().asSeconds()) << std::endl;

	frame++;
}

