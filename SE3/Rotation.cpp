#include "Rotation.h"
#include "Fonction.h"
#include "Copy.h"
#include "Curseur.h"
#include "Calque.h"

CRotation::CRotation()
{
	numero_outil = COutil::ROTATION;
	if (COPY == NULL)
		CURSEUR->setPosition(CFonction::centerSprite(CALQUE->getSprite()));
	else
		CURSEUR->setPosition(CFonction::centerSprite(COPY->getSprite()));
}


CRotation::~CRotation()
{
}

void CRotation::afficher()
{
	CURSEUR->afficher();
}

void CRotation::use()
{
	if (COPY != NULL)
		COPY->rotation();
	else
		CALQUE->rotation();
}