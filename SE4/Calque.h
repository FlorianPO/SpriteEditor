#pragma once

#include "stdafx.h"
#include "Retourable.h"
#include "Panneau.h"
#include "Res.h"
#include "Brosse.h"

#define CALQUE CCalque::_t
#define CALQUE_LIST CCalque::calque_list
class CCalque : public CRetourable
{

public:
//STATIC//
	static CCalque* _t; //Selected calque
	static std::vector<CCalque*> calque_list; //All calques

	static void new_calque(sf::Texture* texture_var); //Create a new calque based on a texture
	static int nbrCalque(bool count_dead = false);
	static void choose_calque(); //Select a calque
	static bool isFirst();

	static const int hauteur_c = 34;
//

	CCalque(sf::Texture* texture_var);
	~CCalque();

	void draw(sf::Sprite* spr = BROSSE->getSprite(), sf::RenderStates* render = RES->getRender(CRes::SHADER::usual), bool no_retour = false);
	void draw_brosse(sf::Vector2f pos, sf::RenderStates* render = RES->getRender(CRes::SHADER::usual));
	void update(sf::Texture* texture_var); //Mettre à jour le calque (rafraîchir)
	void afficher(); //Afficher le calque

//TRANSF//
	void move();
	void grand();
	void rotation();
	void flip();
//

	bool changed = false; //True if the calque has been changed and needs to be save
	bool clicked = false;

	//Sprite and texture						
	public:		inline const sf::Sprite* getSprite() { return &sprite; }
				inline sf::RenderTexture* getRenderTexture() { return &renderTexture; }
				inline const sf::Texture* getTexture() { return sprite.getTexture(); }
				inline sf::Vector2f getSize() { return sf::Vector2f(sprite.getTextureRect().width, sprite.getTextureRect().height); }

											private:	sf::Sprite sprite;
														sf::RenderTexture renderTexture; //Texture de dessin

	//Retrieve a sf::Image		
	public:		sf::Image* getImage();		private:	bool refresh = false; 		
														sf::Image image_buffer;

	//Layer's position
	public:		inline sf::Vector2i getPosition_i() { return sf::Vector2i(sprite.getPosition().x, sprite.getPosition().y); }
	public:		inline sf::Vector2f getPosition() { return sprite.getPosition(); }
						
	//Some states
	public:		int getNumero();
	public:		inline bool isDead() { return dead; }				private:	bool dead = false;
	public:		inline bool isVisible() { return visible; }			private:	bool visible = true;
				inline void setVisible(bool v) { visible = v; }		
	
	//Gui
	public:		inline CPanneau* getPanneau()  { return panneau; }				private:	CPanneau* panneau;
	public:		inline sf::String getNom() { return nom; }						private:	sf::String nom; //Nom du calque
																							sf::RenderTexture renderNom; //Texture du nom du calque
																							sf::Sprite sprite_nom; //Sprite du nom
	public:		inline CBouton* getBoutonOeil() { return b_oeil; }				private:	CBouton* b_oeil;
	public:		inline CBouton* getBoutonVignette() { return b_vignette; }		private:	CBouton* b_vignette;
	
private:
	//Related to transformation methods
	float angle_ini;
	sf::Vector2i posi;
	sf::Vector2f posf;

//RETOUR//
private:
	enum type_retour;

	int i_retour_type = -1;		std::vector<type_retour> retour_type;
	int i_retour_image = -1;	std::vector<sf::Image> retour_image;
	int i_retour_pos = -1;		std::vector<sf::Vector2f> retour_pos;

public:
	enum type_retour
	{
		CRE = 0,
		ACT,
		DEL,
		MOV
	};

	void creer_retour(sf::Image* image, type_retour t);
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
//
};