#pragma once

#include "stdafx.h"
#include "Retourable.h"
#include "Panneau.h"

#define PANEL_CONTROLER PanneauControler::_t

class CPanneau;

class PanneauControler : public CRetourable
{
public:
	static PanneauControler* _t;

	PanneauControler() {}
	~PanneauControler() {}

	void gerer();
	void test(CPanneau* panel);
	void afficher(CPanneau* panel);
	bool justAClick() {return global_moving != 2;}
	
	public:		CPanneau* getMovingSrc() {return moving_src;}		private:	CPanneau* moving_src;
	public:		CPanneau* getMovingDst() {return moving_dst;}		private:	CPanneau* moving_dst;
	
	public:		inline void addFunction(std::function<void(int, int)>* function) {function_list.push_back(function);}
																	private:	std::vector<std::function<void(int, int)>*> function_list;	
private:
	void move();
	void end_move();
	int global_moving = 0;

///##################################################################################################################################################
///##################################################################################################################################################
///##################################################################################################################################################
private:
	struct type_move
	{
		int i_src;
		int i_dst;
		int which_group;
		int move_group;
	};
	enum type_retour;
	int i_retour_type = -1;		std::vector<type_retour> retour_type;
	int i_retour_move = -1;		std::vector<type_move> retour_move;

public:
	enum type_retour
	{
		MOVE = 0
	};

	void creer_retour(type_move* src_dst, type_retour t);
	void ctrl_z() override;
	void ctrl_y() override;
	void delete_retour() override;
};

