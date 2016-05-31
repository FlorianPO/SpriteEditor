/*
#include "Source Files/Retour/Retour.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Selec/Selec.h"

CRetour* RETOUR;

CRetour::CRetour(void) {}

CRetour::~CRetour(void) {}

void CRetour::free()
{
	group_list.clear();
	vector_list.clear();
	retour_list.clear(); 
	retour_list.reserve(500);
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

	for (int i = 0; i < LAYER_LIST.size(); i++)
		if (LAYER_LIST[i]->nbr_retour == 0)
		{
			//delete LAYER_LIST[i];
			//LAYER_LIST.erase(LAYER_LIST.begin() + i);
			//i--;
		}
		else
			LAYER_LIST[i]->delete_retour();

	for (int i = 0; i< COPY_LIST.size(); i++)
		if (COPY_LIST[i]->nbr_retour == 0)
		{
			delete COPY_LIST[i];
			COPY_LIST.erase(COPY_LIST.begin() + i);
			i--;
		}
		else
			COPY_LIST[i]->delete_retour();

	LAYER_CONTROLLER->selectLayer();
	IO->delete_retour();
	SELEC->delete_retour();
}

void CRetour::add_retour(std::vector<CRetourable*> vector)
{
	if (i_retour != retour_list.size())
		delete_retour();

	if (group_list.size() > 0) //If a group has been set up
	{
		//Take friends of vector if a member of a group is found (available if take_friends == true)
		std::vector<bool> friends;
		bool refug_on = false; //Member found, we can pass friends later (if take_friends == true)
		for (int i=0; i < group_list[0].group_list.size(); i++)
			friends.push_back(group_list[0].take_friend);

		for (int j=0; j < group_list[0].group_list.size(); j++)
			for (int k=0; k < vector.size(); k++)
				if (vector[k] == group_list[0].group_list[j])
				{
					refug_on = true; //Member found
					vector_list.push_back(vector[k]);
					friends[k] = false; //No need to add him
					group_list[0].group_list.erase(group_list[0].group_list.begin() + j);
				
					if (group_list[0].group_list.size() == 0)
					{
						if (refug_on)
							for (int i=0; i < friends.size(); i++)
								if (friends[i])
									vector_list.push_back(vector[i]);

						group_list.erase(group_list.begin());
						goto group_completed; //I really need this + optimisation
					}
					j--;
				}
		
		return; //Ignore vector if no member found
	}

	for (int i = 0; i < vector.size(); i++)
		vector_list.push_back(vector[i]);

	if (avoiding > 0)
	{
		avoiding -= 1;
		return;
	}
		
group_completed:

	for (int i = 0; i < vector_list.size(); i++)
		vector_list[i]->nbr_retour++;

	retour_list.push_back(vector_list);
	vector_list.clear();
	i_retour++;
}

void CRetour::group(std::vector<CRetourable*> glist, bool take_refugee)
{
	group_type group;
	group.group_list = glist;
	group.take_friend = take_refugee;
	group_list.push_back(group);
}
*/