#pragma once

#include "stdafx.h"
#include "Retourable.h"

#define RETOUR CRetour::_t
class CRetour
{
public:
	static CRetour* _t;
public:
	CRetour(void);
	~CRetour(void);
public:
	struct group_type
	{
		std::vector<CRetourable*> group_list;
		bool take_friend = true;
	};

	void free();

	void ctrl_z();
	void ctrl_y();

	void add_retour(std::vector<CRetourable*> vector);
	void group(std::vector<CRetourable*> glist, bool take_friend = true);
	inline void avoid_next(int n = 1) {avoiding += n;}

private:
	void delete_retour();
	
	int i_retour = 0;
	std::vector<std::vector<CRetourable*>> retour_list;
	std::vector<CRetourable*> vector_list;
	std::vector<group_type> group_list;
	int avoiding = false;
};
