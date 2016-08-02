#pragma once

#include "stdenum.h"

#define INIT_APP App::createInstance
#define APP App::getInstance()

class App : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static App* _t; 
public:		inline static void createInstance(sf::RenderWindow* _f) { _t = new App(_f); }
			inline static App* getInstance() { return _t; }

// CONSTRUCTOR
public:
	App(sf::RenderWindow* _f);
	~App();

// METHODS
public:
	//void sauvegarder(std::string destination); //Save the current view
	void loadFromPath(std::string source); //Load an image_selec
	void init_work(sf::Image* image);
	void free_work();

	//void macro();
	sf::RenderWindow& getWindow() { return *fenetre; }

	void run(); //Step the application
	void display(); //Global display

	inline unsigned int whichFrame() {return frame;}
private:
	Q_INVOKABLE void gererFond();
	Q_INVOKABLE void gererLines();
	void displayLines();

// SIGNALS SLOTS
	private slots:
		void cadreMoved();
		void cadreScaled();
		void cameraZoomed(float zoom_factor);
		void cameraMoved();

// MEMBERS
private:
	sf::RenderWindow* fenetre;
	sf::String filename; //Name of the loaded file

	sf::VertexArray lines_bord; //Yellow lines around work zone
	sf::Color color_fond = sf::Color(128, 128, 128); //Background color
	sf::Sprite sprite_transparency; //Transparency squares (like GIMP)
	sf::VertexArray cache_fond[4];

	unsigned int frame = 0; //Frame counter
};

