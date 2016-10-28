#pragma once

#include "stdenum.h"
class Action;

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
	void initWork(sf::Image& image);
	void freeWork();

	//void macro();
	sf::RenderWindow& getWindow() const { return *fenetre; }
	const sf::String& getFileName() const { return filename; }
	const sf::String& getPath() const { return path; }

	void run(); //Step the application
	void display(); //Global display

	inline unsigned int whichFrame() const { return frame; }
	void setAction(Action* action);

// MEMBERS
private:
	sf::RenderWindow* fenetre;
	sf::String filename; //Name of the loaded file
	sf::String path; //Path of the loaded file

	unsigned int frame; //Frame counter
	Action* action;

// TEST
	void test();
};

