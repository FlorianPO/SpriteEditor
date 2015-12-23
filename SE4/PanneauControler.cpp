#include "PanneauControler.h"
#include "Panneau.h"
#include "Res.h"
#include "App.h"
#include "Retour.h"
#include "Fonction.h"
#include "Input.h"

PanneauControler* PANEL_CONTROLER;

void PanneauControler::test(CPanneau* panel)
{
	static sf::Vector2i pos_click;
	if (global_moving == 1)
		if (CFonction::norme(pos_click - IO->getScreenPosition()) >= 5)
			global_moving = 2;

	if (IO->again(CInput::MLeft) && CFonction::onSprite(panel->getSprite()))
	{
		global_moving = 1;
		moving_src = panel;
		pos_click = IO->getScreenPosition();
	}
}

void PanneauControler::afficher(CPanneau* panel)
{
	if (global_moving == 2)
		if (moving_dst == panel)
		{
			sf::Sprite spr = RES->getSprite(CRes::SPRITE::panel_separator);
			if (moving_dst->getPosition().y > moving_src->getPosition().y)
				spr.setPosition(moving_dst->getPosition().x, moving_dst->getPosition().y + moving_dst->getSprite()->getGlobalBounds().height - 1);
			else
				spr.setPosition(moving_dst->getPosition().x, moving_dst->getPosition().y - 1);
			APP->fenetre.draw(spr);
		}
}

void PanneauControler::gerer()
{
	if (global_moving == 2)
	{
		int this_index = -1;
		int which_group = moving_src->getGroup();
		int move_group = moving_src->getMoveGroup();

		for (int i = 0; i < CPanneau::panneau_list[which_group].size(); i++)
			if (CPanneau::panneau_list[which_group][i]->getMoveGroup() == move_group)
				if (CPanneau::panneau_list[which_group][i]->test())
				{
					if (CPanneau::panneau_list[which_group][i] != moving_src)
						moving_dst = CPanneau::panneau_list[which_group][i];
					else
						moving_dst = NULL;

					break;
				}
	}
	if (global_moving > 0)
		if (IO->released(CInput::MLeft))
			end_move();
}

void PanneauControler::end_move()
{
	if (moving_dst != NULL)
	{
		int indice_src = 0;
		int indice_dst = 0;
		int which_group = moving_src->getGroup();
		int move_group = moving_src->getMoveGroup();

		for (int i = 0; i < PANEL_LIST[which_group].size(); i++)
			if (PANEL_LIST[which_group][i] == moving_src)
			{
				indice_src = i;
				PANEL_LIST[which_group].erase(PANEL_LIST[which_group].begin() + indice_src);
				break;
			}
				
		for (int i = 0; i < PANEL_LIST[which_group].size(); i++)
			if (PANEL_LIST[which_group][i] == moving_dst)
			{
				indice_dst = i + (moving_dst->getPosition().y > moving_src->getPosition().y);
				PANEL_LIST[which_group].insert(PANEL_LIST[which_group].begin() + indice_dst, moving_src);
				break;
			}

		if (function_list[move_group-1] != NULL)
			(*function_list[move_group-1])(indice_src, indice_dst);

		type_move tmp = {indice_src, indice_dst, which_group, move_group};
		creer_retour(&tmp, MOVE);
		RETOUR->add_retour({this});
	}

	global_moving = 0;
	moving_src = 0;
	moving_dst = 0;
}