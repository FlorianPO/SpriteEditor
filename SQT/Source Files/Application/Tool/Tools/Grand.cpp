#include "Source Files/Application/Tool/Tools/Grand.h"

#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Fonction/Fonction.h"

CGrand::CGrand() {
	numero_outil = CTool::GRAND;
	if (COPY == NULL)
		CURSEUR->setPosition(CFonction::topLeftCorner(LAYER->getSprite()));
	else
		CURSEUR->setPosition(CFonction::topLeftCorner(COPY->getSprite()));
}

void CGrand::afficher() {
	CURSEUR->afficher();
}

void CGrand::use() {
	if (COPY != NULL)
		COPY->grand();
	else
		LAYER->grand();
}