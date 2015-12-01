#include "Hud.h"

std::vector<CHud*> CHud::hud_liste;
bool CHud::force_scaling;

CHud::CHud(void) {force_scaling = true;}

CHud::~CHud(void) {}

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
		if (hud_liste[i]->f_position == NULL)
			hud_liste[i]->position();
		else
			(*hud_liste[i]->f_position)();

		if (hud_liste[i]->f_afficher == NULL)
			hud_liste[i]->afficher();
		else
			(*hud_liste[i]->f_afficher)();
	}
}

bool CHud::is_it_me(CHud* c_hud)
{
	for (int i = hud_liste.size()-1; i >= 0; i--)
	{
		if (hud_liste[i]->f_test == NULL)
		{
			if (hud_liste[i]->test())
				return c_hud == hud_liste[i];
		}
		else
			if ((*hud_liste[i]->f_test)())
				return c_hud == hud_liste[i];
	}
	return false;
}

bool CHud::onHud()
{
	for (int i = hud_liste.size()-1; i >= 0; i--)
	{
		if (hud_liste[i]->f_test == NULL)
		{
			if (hud_liste[i]->test())
				return true;
		}
		else
			if ((*hud_liste[i]->f_test)())
				return true;
	}
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

		for (int i = 0; i < hud_liste.size(); i++)
			if (hud_liste[i]->f_zoom == NULL)
				hud_liste[i]->zoom(ex_factor);
			else
				(*hud_liste[i]->f_zoom)(ex_factor);
	}

	static int ex_size = hud_liste.size();
	for (int i=0; i < hud_liste.size(); i++)
	{
		if (is_it_me(hud_liste[i]))
		{
			if (hud_liste[i]->f_gerer == NULL)
				hud_liste[i]->gerer();
			else
				(*hud_liste[i]->f_gerer)();
		}

		if (hud_liste[i]->f_update == NULL)
			hud_liste[i]->update();
		else
			(*hud_liste[i]->f_update)();
		

		if (hud_liste.size() < ex_size)
		{
			i -= ex_size - hud_liste.size();
			ex_size = hud_liste.size();
		}
	}	
}