#pragma once

#include "stdafx.h"
#include "Hud.h"
#include "Panneau.h"
#include "BoutonSwitch.h"
#include "BoutonSegment.h"
#include "BoutonDisplay.h"
#include "BoutonActive.h"

#define SPRITE_ANIM CSpriteAnim::_t
class CSpriteAnim : public CHud
{
public:
	void zoom(float z) override;
	void update() override;
	void gerer() override;
	bool test() override;
	void position() override;
	void afficher() override;
	bool busy() override; 

public:
	static CSpriteAnim* _t;

	struct type_anim
	{
		sf::IntRect rect;
		int nbr_anim;
	};
public:
	CSpriteAnim(void);
	~CSpriteAnim(void);

	inline CPanneau* getPanneau() { return panneau; }
	static type_anim searchAnimation(sf::Image* i_src, sf::Vector2i p_ini);

private:
	void selecAnimation(int i);

	std::vector<sf::IntRect> frame_list[3];	//The rectangle views among time
	sf::Sprite view_sprites[3]; //The sprite corresponding to the views
	sf::Vector2f offset_list[3]; //The position relatively to the down-left corner of the screen
	sf::Vector2i cpt_list[3]; //.x: number of rect in frame_list, .y: cpt
	sf::RectangleShape recteur_list[3]; //The rectangle showing what is displayed

	type_anim result;

// GUI + CORE //
private:
	CPanneau* panneau;
	CBoutonSwitch* boutons_numero[3];
	CBoutonSegment* boutons_frame[3];
	CBoutonDisplay* boutons_chrono[3];
	CBoutonSwitch* boutons_rect[3];
	CBoutonSwitch* boutons_oeil[3];
	CBoutonActive* boutons_del[3];

	CBoutonDisplay* all_numbers; static void fonction_numbers(fonction_type l);
	CBoutonSwitch* bouton_oeil; static bool predicat_oeil(fonction_type l); static void fonction_oeil(fonction_type l);
	CBoutonActive* bouton_sync; static bool predicat_sync(fonction_type l); static void fonction_sync(fonction_type l);
	CBoutonSwitch* bouton_ombre;
	CBoutonSwitch* bouton_chaine;
//
};

