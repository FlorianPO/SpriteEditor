#pragma once

#include "stdenum.h"
class Layer;

#define INIT_BACKGROUND Background::createInstance();
#define BACKGROUND Background::getInstance()

class Background : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static Background* _t; 
public:		inline static void createInstance() { _t = new Background(); }
			inline static Background* getInstance() { return _t; }

// CONSTRUCTOR
public:
	Background();
	~Background() {}

// SIGNALS SLOTS
	private slots:
		void bindLayer(Layer& layer);
		void unbindLayer(Layer& layer);
		void layerTransformed();
		void cameraZoomed(float zoom_factor);

// METHODS
public:
	void displayBack();
	void displayLines();
private:
	Q_INVOKABLE void updateFond();
	Q_INVOKABLE void updateLines();

// MEMBERS
private:
	sf::VertexArray lines_bord; //Yellow lines around work zone
	sf::Sprite sprite_transparency; //Transparency squares (like GIMP)
	sf::VertexArray cache_fond[4];

	sf::Color color_fond = sf::Color(128, 128, 128); //Background color
};

