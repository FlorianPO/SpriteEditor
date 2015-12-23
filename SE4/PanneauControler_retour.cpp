#include "PanneauControler.h"

void PanneauControler::creer_retour(type_move* src_dst, type_retour t)
{
	i_retour_type++;
	retour_type.push_back(t);

	if (t == MOVE)
	{
		i_retour_move++;
		retour_move.push_back(*src_dst);
	}
}

void PanneauControler::ctrl_z()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type--;

	if (ex_t == MOVE) // c <- a
	{
		int which_group = retour_move[i_retour_move].which_group;
		int move_group = retour_move[i_retour_move].move_group;

		CPanneau* tmp = PANEL_LIST[which_group][retour_move[i_retour_move].i_dst];
		PANEL_LIST[which_group].erase(CPanneau::panneau_list[which_group].begin() + retour_move[i_retour_move].i_dst);
		PANEL_LIST[which_group].insert(CPanneau::panneau_list[which_group].begin() + retour_move[i_retour_move].i_src, tmp);

		if (function_list[move_group-1] != NULL)
			(*function_list[move_group-1])(retour_move[i_retour_move].i_dst, retour_move[i_retour_move].i_src);
	}
}

void PanneauControler::ctrl_y()
{
	i_retour_type++;
	type_retour t = retour_type[i_retour_type];

	if (t == MOVE) // c -> a
	{
		int which_group = retour_move[i_retour_move].which_group;
		int move_group = retour_move[i_retour_move].move_group;

		CPanneau* tmp = PANEL_LIST[which_group][retour_move[i_retour_move].i_src];
		PANEL_LIST[which_group].erase(CPanneau::panneau_list[which_group].begin() + retour_move[i_retour_move].i_src);
		PANEL_LIST[which_group].insert(CPanneau::panneau_list[which_group].begin() + retour_move[i_retour_move].i_dst, tmp);

		if (function_list[move_group-1] != NULL)
			(*function_list[move_group-1])(retour_move[i_retour_move].i_src, retour_move[i_retour_move].i_dst);
	}

	
}

void PanneauControler::delete_retour()
{
	retour_type.erase(retour_type.begin() + i_retour_type + 1, retour_type.end());
	retour_move.erase(retour_move.begin() + i_retour_move + 1, retour_move.end());
}
