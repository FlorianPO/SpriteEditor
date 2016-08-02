#include "CameraController.h"

#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Widget/SQT/SFMLView.h"

CameraController* CameraController::_t;

CameraController::CameraController() {
	using namespace nInt;
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_Z, PRESSED), FUNCTION(CAMERA->moveY(-MOVE_FACTOR*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_S, PRESSED), FUNCTION(CAMERA->moveY(MOVE_FACTOR*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_Q, PRESSED), FUNCTION(CAMERA->moveX(-MOVE_FACTOR*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_D, PRESSED), FUNCTION(CAMERA->moveX(MOVE_FACTOR*(1.f/CAMERA->getZoom()))));

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(WHEEL_UP,				 AGAIN), FUNCTION(CAMERA->moveY(-40*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(WHEEL_DOWN,				 AGAIN), FUNCTION(CAMERA->moveY(40*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + WHEEL_UP,	 AGAIN), FUNCTION(CAMERA->moveX(-40*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + WHEEL_DOWN,	 AGAIN), FUNCTION(CAMERA->moveX(40*(1.f/CAMERA->getZoom()))));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::MiddleButton, PRESSED), FUNCTION(CAMERA->moveCamera(sf::Vector2f(-INPUT->getDeltaScreen().x/CAMERA->getZoom(), 
																																 -INPUT->getDeltaScreen().y/CAMERA->getZoom()))));

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + WHEEL_UP,		AGAIN),	FUNCTION(CAMERA->zoomCamera(0.5f)));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + WHEEL_DOWN,	AGAIN),	FUNCTION(CAMERA->zoomCamera(2)));

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Alt,			DOUBLE_TAP), FUNCTION(CAMERA->centerOnLayer()));
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::MiddleButton,	DOUBLE_TAP), FUNCTION(CAMERA->follow(INPUT->getPosition())));
}

void CameraController::centerOnLayer(Layer* layer) {
	setCenter(sf::Vector2f(layer->getSize().x / 2.f, layer->getSize().y / 2.f));
	setSize(sf::Vector2f(SFML->width(), SFML->height()));
	zoom_factor = 1.f;

	emit moved(getCenter());
	emit zoomed(zoom_factor);
}

void CameraController::zoomCamera(float factor, bool centered_on_mouse) {
	if (zoom_factor / factor > MAX_ZOOM || zoom_factor / factor < MIN_ZOOM)
		return;

	if (centered_on_mouse) {
		sf::Vector2f pos_mouse = INPUT->getPosition();
		if (factor <= 1.f) {
			setCenter((pos_mouse.x + getCenter().x) / 2.f, (pos_mouse.y + getCenter().y) / 2.f);
			zoom(factor);
			zoom_factor /= factor;
		}
		else {
			float x = getCenter().x - pos_mouse.x;
			float y = getCenter().y - pos_mouse.y;
			zoom(factor);
			zoom_factor /= factor;
			sf::View::move(x, y);
		}
		emit moved(getCenter());
	}
	else {
		zoom(factor);
		zoom_factor /= factor;
	}
	emit zoomed(zoom_factor);
}

void CameraController::follow(const sf::Vector2f& pos) {
	setCenter(pos);
	sf::Vector2i vect = sf::Vector2i(APP->getWindow().getSize().x / 2, APP->getWindow().getSize().y / 2);
	INPUT->setMousePosition(vect, true); // Reset ex_position

	emit moved(getCenter());
}

sf::Vector2f CameraController::getPosition(nStd::Corner corner) {
	using namespace nStd;
	switch (corner) {
		case CENTER:		return getCenter();
		case UP_LEFT:		return sf::Vector2f(getCenter().x - getSize().x / 2.f	, getCenter().y - getSize().y / 2.f);
		case UP:			return sf::Vector2f(getCenter().x						, getCenter().y - getSize().y / 2.f);
		case UP_RIGHT:		return sf::Vector2f(getCenter().x + getSize().x / 2.f	, getCenter().y - getSize().y / 2.f);
		case RIGHT:			return sf::Vector2f(getCenter().x + getSize().x / 2.f	, getCenter().y);
		case DOWN_RIGHT:	return sf::Vector2f(getCenter().x + getSize().x / 2.f	, getCenter().y + getSize().y / 2.f);
		case DOWN:			return sf::Vector2f(getCenter().x						, getCenter().y + getSize().y / 2.f);
		case DOWN_LEFT:		return sf::Vector2f(getCenter().x - getSize().x / 2.f	, getCenter().y + getSize().y / 2.f);
		case LEFT:			return sf::Vector2f(getCenter().x - getSize().x / 2.f	, getCenter().y);
	}
	return getCenter();
}

void CameraController::moveCamera(sf::Vector2f delta_move) {
	CAMERA->sf::View::move(delta_move.x, delta_move.y);
	emit moved(getCenter());
}

void CameraController::moveX(float x) {
	sf::View::move(x, 0);
	emit moved(getCenter());
}

void CameraController::moveY(float y) {
	sf::View::move(0, y);
	emit moved(getCenter());
}
