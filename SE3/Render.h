#pragma once
class CRender
{
public:
	CRender();
	virtual ~CRender();

	virtual void gerer() {}
	virtual void afficher() {}
};

