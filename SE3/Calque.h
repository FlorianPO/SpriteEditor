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
	static CCalque* _t; //Selected calque
	static std::vector<CCalque*> calque_list; //All calques

	static void new_calque(sf::Texture* texture_var); //Create a new calque based on a texture
	static int nbrCalque(bool count_dead = false);
	static bool isFirst();
	static void choose_calque(); //Select a calque
	
public:
	static const int hauteur_c = 34;

	CCalque(sf::Texture* texture_var);
	~CCalque(void);

public:
	int getNumero(); //Numéro du calque
	sf::Image* getImage();

	void draw(sf::Sprite* spr = BROSSE->getSprite(), sf::RenderStates* render = RES->getRender(CRes::SHADER::usual));
	void draw_brosse(sf::Vector2f pos, sf::RenderStates* render = RES->getRender(CRes::SHADER::usual));
	void update(sf::Texture* texture_var); //Mettre à jour le calque (rafraîchir)
	void afficher(); //Afficher le calque

	void move();
	void grand();
	void rotation();
	void flip();

	//Related to getImage()
	bool refresh = false; 
	sf::Image image_buffer;

	bool changed = false; //True if the calque has been changed and needs to be save
	bool visible = true;
	bool dead = false;
	bool clicked = false;

	inline const sf::Sprite* getSprite() { return &sprite; }
	inline const sf::Texture* getTexture() { return sprite.getTexture(); }
	inline sf::Vector2f getSize() { return sf::Vector2f(sprite.getTextureRect().width, sprite.getTextureRect().height); }
	inline sf::RenderTexture* getRenderTexture() { return &renderTexture; }

	inline bool isDead() { return dead; }
	inline bool isVisible() { return visible; }
	inline void setVisible(bool v) { visible = v; }
	
	//Position du calque
	inline sf::Vector2i getPosition_i() { return sf::Vector2i(sprite.getPosition().x, sprite.getPosition().y); }
	inline sf::Vector2f getPosition() { return sprite.getPosition(); }

	inline CPanneau* getPanneau()  { return panneau; }

private:
	sf::RenderTexture renderTexture; //Texture de dessin
	sf::Sprite sprite;

	sf::String nom; //Nom du calque
	sf::RenderTexture renderNom; //Texture du nom du calque
	sf::Sprite sprite_nom; //Sprite du nom

	//Related to transformation methods
	float angle_ini;
	sf::Vector2i posi;
	sf::Vector2f posf;
	
	//GUI
	CPanneau* panneau;
	CBouton* oeil;
	CBouton* vignette;

///##################################################################################################################################################
///##################################################################################################################################################
///##################################################################################################################################################
private:
	enum type_retour;

	int i_retour_type;
	std::vector<type_retour> retour_type;
	int i_retour_image;
	std::vector<sf::Image> retour_image;
	int i_retour_pos;
	std::vector<sf::Vector2f> retour_pos;

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
};

