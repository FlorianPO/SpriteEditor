#pragma once

class CRetourable
{
public:
	CRetourable(void);
	virtual ~CRetourable(void) = 0;

	int nbr_retour = 0;

	virtual void ctrl_z();
	virtual void ctrl_y();
	virtual void delete_retour();
};

