#include "Rotation.h"

#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

Rotation::Rotation() {
	numero_outil = nTol::ROTATION;
	if (COPY == NULL)
		CURSEUR->setPosition(Fonction::centerCorner(LAYER->getSprite()));
	else
		CURSEUR->setPosition(Fonction::centerCorner(COPY->getSprite()));
}

void Rotation::display() {
	CURSEUR->display();
}

void Rotation::use() {
	if (COPY != NULL)
		COPY->rotation();
	else
		LAYER->rotation();
}