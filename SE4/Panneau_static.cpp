#include "Panneau.h"

bool CPanneau::testPanneau()
{
	for (int i = 0; i < panneau_list.size(); i++)
		for (int j = 0; j < panneau_list[i].size(); j++)
			if (panneau_list[i][j]->test())
				return true;
	return false;
}

void CPanneau::gererPanneau()
{
	static int ex_size = panneau_list.size();
	for (int i = 0; i < panneau_list.size(); i++)
	{
		static int ex_size_1 = panneau_list[i].size();
		for (int j = 0; j < panneau_list[i].size(); j++)
		{
			panneau_list[i][j]->gerer();

			if (panneau_list.size() < ex_size)
			{
				i -= ex_size - panneau_list.size();
				ex_size = panneau_list.size();
				j = 0;
			}
			else if (panneau_list[i].size() < ex_size_1)
			{
				j -= ex_size_1 - panneau_list[i].size();
				ex_size_1 = panneau_list[i].size();
			}
		}
	}
	PANEL_CONTROLER->gerer();
}

int CPanneau::whichPosition(CPanneau* panneau)
{
	int count = 0;
	for (int i=0; i < panneau_list[panneau->which_group].size(); i++)
	{
		if (panneau_list[panneau->which_group][i] == panneau)
			break;
		count ++;
	}
	return count;
}

void CPanneau::afficherPanneau()
{
	for (int i = 0; i < panneau_list.size(); i++)
		for (int j = 0; j < panneau_list[i].size(); j++)
			panneau_list[i][j]->afficher();
}

bool CPanneau::testButtons()
{
	for (int i = 0; i < bouton_list.size(); i++)
		for (int j = 0; j < bouton_list[i].size(); j++)
			if (bouton_list[i][j]->onSprite())
				return true;
	return false;
}