#pragma once

#include "stdafx.h"

#define APP CApp::_t
class CApp
{
public:
	static CApp* _t;
public:
	CApp(void);
	~CApp(void);

public:
	//void sauvegarder(std::string destination); //Save the current view
	void charger(std::string source); //Load an image
	void init_work(sf::Texture* text);
	void free_work();

	//void macro();

	void gerer(); //Step the application
	void afficher(); //Global draw

	void gererFond();

	//Camera related
	sf::Vector2f getPositionCamera(int coin);
	void init_camera(); //Init camera
	void zoomer(float z, bool s); //Zoomer la caméra (z : niveau de zoom) (s : zoomer sur la souris)
	void follow(sf::Vector2f pos); //Center camera on a position
	void follow(); //Center camera on mouse position

	//CCalque* firstCalque(); //Renvoie le premier calque vivant
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
	
	sf::RenderWindow fenetre;
	sf::View camera;
	float zoom;
	
	//sf::Vector2f pos_copy;
	//CSpriteCopy* copy_courante;
	//std::vector<CSpriteCopy*> copy_list;
};

