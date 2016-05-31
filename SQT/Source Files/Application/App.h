#pragma once

#include "stdafx.h"

#define INIT_APP CApp::createInstance
#define APP CApp::getInstance()

class CApp : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static CApp* _t; 
public:		inline static void createInstance(sf::RenderWindow* _f) { _t = new CApp(_f); }
			inline static CApp* getInstance() { return _t; }

// CONSTRUCTOR
	CApp(sf::RenderWindow* _f);
	~CApp(void);

public:
	//void sauvegarder(std::string destination); //Save the current view
	void loadFromPath(std::string source); //Load an image
	void init_work(sf::Texture* text);
	void free_work();

	//void macro();

	void run(); //Step the application
	void display(); //Global display

	void gererFond();

	//Camera related
	sf::Vector2f getPositionCamera(int coin); //Up-left: 1, Up-right: 2, Down-right: 3, Down-left: 4
	void init_camera(); //Init camera
	void zoomer(float z, bool s); //Zoomer la caméra (z : niveau de zoom) (s : zoomer sur la souris)
	void follow(sf::Vector2f pos); //Center camera on a position
	void follow(); //Center camera on mouse position

	//CCalque* firstCalque(); //Renvoie le premier LAYER vivant
	//void choose_calque();
	
	inline unsigned int whichFrame() {return frame;}

private:
	sf::String filename; //Name of the loaded file
	sf::IntRect patron; //Work zone

	sf::VertexArray lines_bord; //Yellow lines around work zone
	sf::Color color_fond; //Background color
	sf::Sprite sprite_transparency; //Transparency squares (like GIMP)
	sf::VertexArray cache_fond[4];

	void afficher_lines_bord();

	unsigned int frame = 0; //Frame counter

public:
	//sf::String directory = "Ressources/";
	
	sf::RenderWindow* fenetre;
	sf::View camera;
	float zoom;
	
	//sf::Vector2f pos_copy;
	//CSpriteCopy* copy_courante;
	//std::vector<CSpriteCopy*> copy_list;
};

