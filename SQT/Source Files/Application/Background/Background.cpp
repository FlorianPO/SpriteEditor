#include "Background.h"

#include "Source Files/Application/Camera/CameraController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/App.h"

Background* Background::_t; 

Background::Background() {
	lines_bord = sf::VertexArray(sf::LinesStrip, 5);
	sprite_transparency = RES->getSprite(nRer::alpha_gimp);
	cache_fond[0] = sf::VertexArray(sf::Quads, 4);
	cache_fond[1] = sf::VertexArray(sf::Quads, 4);
	cache_fond[2] = sf::VertexArray(sf::Quads, 4);
	cache_fond[3] = sf::VertexArray(sf::Quads, 4);

	QUEUE->atStart([this]() {
		QObject::connect(LAYER_CONTROLLER, SIGNAL(layerSelected(Layer*)), this, SLOT(bindLayer(Layer*)));
		QObject::connect(LAYER_CONTROLLER, SIGNAL(layerUnselected(Layer*)), this, SLOT(unbindLayer(Layer*)));
		QObject::connect(CAMERA, SIGNAL(zoomed(float)), this, SLOT(cameraZoomed(float)));
		QObject::connect(CAMERA, SIGNAL(moved(sf::Vector2f)), this, SLOT(layerTransformed()));
	});
}

void Background::layerTransformed() {
	QUEUE->beforeDisplay(this, "updateFond"); 
	QUEUE->beforeDisplay(this, "updateLines");
}

void Background::cameraZoomed(float zoom_factor) {
	layerTransformed();
	sprite_transparency.setScale(10 / zoom_factor, 10 / zoom_factor);
}

void Background::bindLayer(Layer* layer) {
	QObject::connect(layer, SIGNAL(layerMoved(sf::Vector2f)), this, SLOT(layerTransformed()));
	QObject::connect(layer, SIGNAL(layerScaled(sf::Vector2f)), this, SLOT(layerTransformed()));
}

void Background::unbindLayer(Layer* layer) {
	QObject::disconnect(layer, SIGNAL(layerMoved(sf::Vector2f)), this, SLOT(layerTransformed()));
	QObject::disconnect(layer, SIGNAL(layerScaled(sf::Vector2f)), this, SLOT(layerTransformed()));
}

//////////////
//////////////
//////////////

void Background::updateFond() {
	sf::Vector2f pos = CAMERA->getPosition(nStd::UP_LEFT);
	sprite_transparency.setPosition(pos);

	sf::IntRect rect = LAYER->getGlobalBounds();
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

void Background::updateLines() {
	sf::Sprite layer_sprite = LAYER->getSprite();
	lines_bord[0].position = Fonction::topLeftCorner(layer_sprite);
	lines_bord[1].position = Fonction::topRightCorner(layer_sprite);
	lines_bord[2].position = Fonction::bottomRightCorner(layer_sprite);
	lines_bord[3].position = Fonction::bottomLeftCorner(layer_sprite);
	lines_bord[4].position = lines_bord[0].position;
}

//////////////
//////////////
//////////////

void Background::displayBack() {
	APP->getWindow().draw(sprite_transparency);
	FOR_I (4)
		APP->getWindow().draw(cache_fond[i]);
}

void Background::displayLines() {
	static sf::Uint8 var = 0;
	static bool change = false;

	sf::Color color = sf::Color(255, 255, var);

	FOR_I (lines_bord.getVertexCount())
		lines_bord[i].color = color;
	APP->getWindow().draw(lines_bord);

	if (!change) {
		if (var + 10 > 255) { var = 255; change = true; }
		else { var += 10; }
	}
	else {
		if (var - 10 < 0) { var = 0; change = false; }
		else { var -= 10; }
	}
}
