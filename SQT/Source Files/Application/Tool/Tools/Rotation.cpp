#include "Source Files/Application/Tool/Tools/Rotation.h"

#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Layer/LayerController.h"

CRotation::CRotation() {
	numero_outil = CTool::ROTATION;
	if (COPY == NULL)
		CURSEUR->setPosition(CFonction::centerCorner(LAYER->getSprite()));
	else
		CURSEUR->setPosition(CFonction::centerCorner(COPY->getSprite()));
}

void CRotation::afficher() {
	CURSEUR->afficher();
}

void CRotation::use() {
	if (COPY != NULL)
		COPY->rotation();
	else
		LAYER->rotation();
}