#pragma once

#include "stdenum.h"
#include "Source Files/Application/Layer/LayerController.h"
class Layer;

#define INIT_CAMERA_CONTROLLER CameraController::createInstance();
#define CAMERA_CONTROLLER CameraController::getInstance()
#define CAMERA CAMERA_CONTROLLER
 
class CameraController : public QObject, public sf::View
{
	Q_OBJECT
// INSTANCE
private:	static CameraController* _t; 
public:		inline static void createInstance() { _t = new CameraController(); }
			inline static CameraController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	CameraController();
	~CameraController() {}

// MEMBERS
public:
	void updateView();
	void centerOnLayer(const Layer& layer);
	void follow(const sf::Vector2f& pos);

	void moveCamera(const sf::Vector2f& delta_move);
	void moveX(float x);
	void moveY(float y);
	sf::Vector2f getPosition(nStd::Corner corner) const;

	void zoomCamera(float factor, bool centered_on_mouse=true);
	inline float getZoom() const { return zoom_factor; }

// SIGNALS SLOTS
	signals:
		void moved(sf::Vector2f position) const;
		void zoomed(float zoom_factor) const;

// MEMBERS
private:
	float zoom_factor = 1.f;
};

