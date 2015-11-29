#include "Retour.h"
#include "Input.h"
#include "Calque.h"
#include "Copy.h"
#include "Selec.h"

CRetour* RETOUR;
std::vector<CRetourable*> RETOUR_VECTOR;
int CRetour::avoid;

CRetour::CRetour(void) {}

CRetour::~CRetour(void) {}

void CRetour::free()
{
	CRetour::avoid = 0;
	CRetour::vector.clear();

	retour_list.clear(); retour_list.reserve(500);
}

void CRetour::ctrl_z()
{
	if (i_retour > 1)
	{
		i_retour--;
		for (int i = 0; i < retour_list[i_retour].size(); i++)
		{
			retour_list[i_retour][i]->nbr_retour--; 
			retour_list[i_retour][i]->ctrl_z();
		}	
	}
}

void CRetour::ctrl_y()
{
	if (i_retour != retour_list.size())
	{
		for (int i = 0; i < retour_list[i_retour].size(); i++)
		{
			retour_list[i_retour][i]->nbr_retour++; 
			retour_list[i_retour][i]->ctrl_y();
		}
		i_retour++;
	}
}

void CRetour::delete_retour()
{
	retour_list.erase(retour_list.begin() + i_retour, retour_list.end());

	for (int i = 0; i < CALQUE_LIST.size(); i++)
		if (CALQUE_LIST[i]->nbr_retour == 0)
		{
			delete CALQUE_LIST[i];
			CALQUE_LIST.erase(CALQUE_LIST.begin() + i);
			i--;
		}
		else
			CALQUE_LIST[i]->delete_retour();

	for (int i = 0; i< COPY_LIST.size(); i++)
		if (COPY_LIST[i]->nbr_retour == 0)
		{
			delete COPY_LIST[i];
			COPY_LIST.erase(COPY_LIST.begin() + i);
			i--;
		}
		else
			COPY_LIST[i]->delete_retour();

	CCalque::choose_calque();
	IO->delete_retour();
	SELEC->delete_retour();
}

void CRetour::add_retour()
{
	if (i_retour != retour_list.size())
		delete_retour();

	if (CRetour::avoid)
	{
		CRetour::avoid--;
		return;
	}

	for (int i = 0; i < vector.size(); i++)
		CRetour::vector[i]->nbr_retour++;

	retour_list.push_back(CRetour::vector);
	i_retour++;
	CRetour::vector.clear();
}