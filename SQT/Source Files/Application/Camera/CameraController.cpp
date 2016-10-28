#include "CameraController.h"

#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Fonction/Fonction.h"

#define MAX_ZOOM 64.f
#define MIN_ZOOM 0.125f
#define MOVE_FACTOR 10.f

CameraController* CameraController::_t;

CameraController::CameraController() {
	using namespace nInt;
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_Z, PRESSED), [this](){moveY(-MOVE_FACTOR*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_S, PRESSED), [this](){moveY(MOVE_FACTOR*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_Q, PRESSED), [this](){moveX(-MOVE_FACTOR*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + Qt::Key_D, PRESSED), [this](){moveX(MOVE_FACTOR*(1.f/getZoom()));});

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(WHEEL_UP,				 AGAIN), [this](){moveY(-40*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(WHEEL_DOWN,				 AGAIN), [this](){moveY(40*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + WHEEL_UP,	 AGAIN), [this](){moveX(-40*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + WHEEL_DOWN,	 AGAIN), [this](){moveX(40*(1.f/getZoom()));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::MiddleButton, PRESSED), [this](){moveCamera(sf::Vector2f(-INPUT->getDeltaScreen().x/getZoom(), 
																														-INPUT->getDeltaScreen().y/getZoom()));});
	// test
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + WHEEL_UP, AGAIN), [this](){rotate(-5);});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::ALT + WHEEL_DOWN, AGAIN), [this](){rotate(+5);});

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + WHEEL_UP,		AGAIN),	[this](){zoomCamera(0.5f);});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::CTRL + WHEEL_DOWN,	AGAIN),	[this](){zoomCamera(2);});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Plus,	AGAIN),	[this](){zoomCamera(0.5f);});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Minus,	AGAIN),	[this](){zoomCamera(2);});

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Alt,			DOUBLE_TAP), [this](){centerOnLayer(*LAYER);});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::MiddleButton,	DOUBLE_TAP), [this](){follow(INPUT->getPosition());});
}

void CameraController::updateView() {
	setSize(sf::Vector2f(SFML->width()/zoom_factor, SFML->height()/zoom_factor));
	emit moved(getCenter());
}

void CameraController::centerOnLayer(const Layer& layer) {
	setCenter(sf::Vector2f(layer.getSize().x / 2.f, layer.getSize().y / 2.f));
	setSize(sf::Vector2f(SFML->width(), SFML->height()));
	zoom_factor = 1.f;

	emit moved(getCenter());
	emit zoomed(zoom_factor);
}

void CameraController::zoomCamera(float factor, bool centered_on_mouse) {
	if (zoom_factor / factor > MAX_ZOOM || zoom_factor / factor < MIN_ZOOM)
		return;

	if (centered_on_mouse) {
		if (factor <= 1.f) {
			sf::Vector2f pos_mouse = INPUT->getPosition();
			sf::Vector2f pos = sf::Vector2f((pos_mouse.x + getCenter().x) / 2.f, (pos_mouse.y + getCenter().y) / 2.f);
			setCenter(pos);
			zoom(factor);
			zoom_factor /= factor;
		}
		else {
			sf::Vector2f pos_mouse = INPUT->getPosition();
			sf::Vector2f float_part = CALL_VECTOR2F(pos_mouse, Fonction::floatPart);
			float_part = OPER_VECTOR2F(float_part, *2);
			pos_mouse.x = int(pos_mouse.x) + float_part.x;
			pos_mouse.y = int(pos_mouse.y) + float_part.y;

			sf::Vector2f center = getCenter();
			sf::Vector2f pos = sf::Vector2f(2*center.x - pos_mouse.x, 2*center.y - pos_mouse.y);
			setCenter(pos);
			zoom(factor);
			zoom_factor /= factor;
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

sf::Vector2f CameraController::getPosition(nStd::Corner corner) const {
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

void CameraController::moveCamera(const sf::Vector2f& delta_move) {
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
