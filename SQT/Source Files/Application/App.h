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
	App(sf::RenderWindow* _f) { fenetre = _f; }
	~App() { fenetre->close(); }

// METHODS
public:
	void load(std::string source);
	void loadAsLayer(std::string source);
	void initWork(sf::Image* image);
	void freeWork();

	//void macro();
	sf::RenderWindow& getWindow() { return *fenetre; }
	sf::String getFileName() { return filename; }
	sf::String getPath() { return path; }


	void run(); //Step the application
	void display(); //Global display

	inline unsigned int whichFrame() {return frame;}
		
// MEMBERS
private:
	sf::RenderWindow* fenetre;
	sf::String filename; //Name of the loaded file
	sf::String path; //Path of the loaded file

	unsigned int frame = 0; //Frame counter
};

