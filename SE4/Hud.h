#pragma once

#include "stdafx.h"

class CHud
{
public:
	CHud();
	virtual ~CHud(void) = 0;

	virtual void zoom(float z) {}
	virtual void afficher() {}
	virtual void update() {}
	virtual void gerer() {}
	virtual bool test() {return false;}
	virtual void position() {}

	static bool busy();
	static void killMe(CHud* ptr);
	static void addMe(CHud* ptr) {hud_liste.push_back(ptr);}
	static void afficherHud();
	
	static bool is_it_me(CHud* c_hud);
	static bool onHud();
	static void gererHud(float factor_zoom, bool force = false);

private:
	static std::vector<CHud*> hud_liste;
	static bool force_scaling;

protected:
	std::function<void(void)>* f_afficher = NULL;
	std::function<void(void)>* f_gerer = NULL;
	std::function<void(void)>* f_position = NULL;
	std::function<bool(void)>* f_test = NULL;
	std::function<void(float)>* f_zoom = NULL;
	std::function<void(void)>*  f_update = NULL;
};