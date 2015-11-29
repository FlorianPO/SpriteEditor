#pragma once

#include "stdafx.h"
#include "Retourable.h"

#define RETOUR CRetour::_t
#define RETOUR_VECTOR CRetour::vector
class CRetour
{
public:
	static CRetour* _t;
public:
	CRetour(void);
	~CRetour(void);
public:
	static std::vector<CRetourable*> vector;
	static int avoid;

	void free();

	void ctrl_z();
	void ctrl_y();

	void add_retour();

private:
	void delete_retour();

	int i_retour = 0;
	std::vector<std::vector<CRetourable*>> retour_list;
};
