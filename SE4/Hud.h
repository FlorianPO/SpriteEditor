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
	virtual bool busy() {return false;}

	static bool isBusy();
	static bool onHud();
	
	static void addMe(CHud* ptr) {hud_liste.push_back(ptr);}
	static void killMe(CHud* ptr);
	
	static void gererHud(float factor_zoom, bool force = false);
	static void afficherHud();

private:
	static bool is_it_me(CHud* c_hud); //Null to init cache

	static std::vector<CHud*> hud_liste;
	static bool force_scaling;
};