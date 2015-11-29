#pragma once

#include "stdafx.h"
#include "Calque.h"
#include "BoutonSwitch.h"
#include "BoutonSegment.h"

#define GUI CGui::_t
class CGui : public CHud
{
public:
	static CGui* _t;
public:
	CGui(void);
	~CGui(void);
public:
	//Affiche le Gui général
	void zoom(float z) override;
	void gerer() override;
	bool test() override;
	void update() override;

	void replaceCadre(sf::IntRect* cadre);
	void cancelCadreReplacement();
	inline bool isReplacing() { return replacing; }

	inline CPanneau* getPanneauAboveCalque() { return panneau_8; }
	inline CPanneau* getPanneauBelowCalque() { return panneau_9; }

private:
	bool replacing = false;

	//Part1 // OUTILS
	CPanneau* panneau_1;
	CBoutonSwitch* boutons_1[15];
	static bool predicat_1(fonction_type l);

	//Part2 // ANIM_SELEC
	CPanneau* panneau_2;
	CBoutonSwitch* bouton_2_sprite;
	CBoutonSwitch* bouton_2_tile;

	//Part 4 // COLOR
	CPanneau* panneau_4;
	CBouton* bouton_4_color_1[5];
	CBouton* bouton_4_color_2[5];
	CBoutonSegment* bouton_4_opacite;
	CBoutonSegment* bouton_4_seuil;

	//Part 6 // OUITL_SIZE
	CPanneau* panneau_6;
	CBoutonSwitch* boutons_6_shape[5]; static void fonction_6_shape(fonction_type l);
	CBoutonSegment* bouton_6_x;
	CBoutonSegment* bouton_6_y;
	CBoutonSwitch* bouton_6_chaine;
	CBoutonSegment* bouton_6_posx;
	CBoutonSegment* bouton_6_posy;

	//Part 7 // POSITION
	CPanneau* panneau_7;
	CBoutonSegment* boutons_7[4];

	//Part COPY
	CPanneau* panneau_copy;
	CBoutonSegment* boutons_copy[4];

	//Part 8 //FONCTIONS
	CPanneau* panneau_8;
	CBouton* boutons_8_fonction[5];
	static void fonction_8_1(fonction_type l);
	static void fonction_8_2(fonction_type l);

	//Part 9 //FIN
	CPanneau* panneau_9;
	sf::IntRect cadre_temp;
};

