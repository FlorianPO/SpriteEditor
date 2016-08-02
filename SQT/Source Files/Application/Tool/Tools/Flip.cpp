#include "Flip.h"

#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

Flip::Flip() {
	numero_outil = nTol::FLIP;
}

void Flip::use() {
	if (COPY != NULL)
		COPY->flip();
	else
		LAYER->flip();
}