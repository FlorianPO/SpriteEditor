#include "Grand.h"

#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Fonction/Fonction.h"

Grand::Grand() {
	numero_outil = nTol::GRAND;
	if (COPY == NULL)
		CURSEUR->setPosition(Fonction::topLeftCorner(LAYER->getSprite()));
	else
		CURSEUR->setPosition(Fonction::topLeftCorner(COPY->getSprite()));
}

void Grand::display() {
	CURSEUR->display();
}

void Grand::use() {
	if (COPY != NULL)
		COPY->grand();
	else
		LAYER->grand();
}