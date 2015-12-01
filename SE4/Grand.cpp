#include "Grand.h"
#include "Copy.h"
#include "Curseur.h"
#include "Calque.h"
#include "Fonction.h"


CGrand::CGrand()
{
	numero_outil = COutil::GRAND;
	if (COPY == NULL)
		CURSEUR->setPosition(CFonction::cornerSprite(CALQUE->getSprite()));
	else
		CURSEUR->setPosition(CFonction::cornerSprite(COPY->getSprite()));
}


CGrand::~CGrand()
{
}

void CGrand::use()
{
	if (COPY != NULL)
		COPY->grand();
	else
		CALQUE->grand();
}

void CGrand::afficher()
{
	CURSEUR->afficher();
}