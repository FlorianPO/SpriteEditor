#include "Hud.h"
#include "Panneau.h"
#include "SpriteAnim.h"

std::vector<CHud*> CHud::hud_liste;
bool CHud::force_scaling;

CHud::CHud(void) {force_scaling = true;}

CHud::~CHud(void) {}

bool CHud::isBusy()
{
	for (int i=0; i < hud_liste.size(); i++)
		if (hud_liste[i]->busy())
			return true;
	return PANEL_CONTROLER->busy();
}

void CHud::killMe(CHud* ptr)
{
	for (int i=0; i < hud_liste.size(); i++)
		if (hud_liste[i] == ptr)
		{
			hud_liste.erase(hud_liste.begin() + i);
			return;
		}
}

void CHud::afficherHud()
{
	for (int i=0; i < hud_liste.size(); i++)
	{
		hud_liste[i]->position();
		hud_liste[i]->afficher();
	}
}

bool CHud::is_it_me(CHud* c_hud)
{
	static CHud* cache;

	if (c_hud == NULL)
		cache = NULL;

	if (cache == NULL)
		for (int i = hud_liste.size()-1; i >= 0; i--)
			if (hud_liste[i]->test())
			{
				if (cache == NULL)
					cache = hud_liste[i];
				break;
			}
	
	return c_hud == cache;
}

bool CHud::onHud()
{
	for (int i = hud_liste.size()-1; i >= 0; i--)
		if (hud_liste[i]->test())
			return true;
	
	return false;
}

void CHud::gererHud(float factor_zoom, bool force)
{
	static float ex_factor = 0;
	if (!force && ex_factor != factor_zoom || force_scaling || force)
	{
		if (!force_scaling)
			ex_factor = factor_zoom;
		else
			force_scaling = false;
	}

	static int ex_size = hud_liste.size();
	for (int i=0; i < hud_liste.size(); i++)
	{
		if (is_it_me(hud_liste[i]))
			hud_liste[i]->gerer();

		hud_liste[i]->update();
		
		if (hud_liste.size() < ex_size) //If a Hud kills itself
		{
			i -= ex_size - hud_liste.size();
			ex_size = hud_liste.size();
		}
	}
	PANEL_CONTROLER->gerer();

	//Taking care of zoom
	for (int i = 0; i < hud_liste.size(); i++)
		hud_liste[i]->zoom(ex_factor);
}