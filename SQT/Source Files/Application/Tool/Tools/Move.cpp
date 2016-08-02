#include "Move.h"

#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

Move::Move() {
	numero_outil = nTol::MOVE;
}

void Move::use() {
	if (COPY != NULL)
		COPY->move();
	else
		LAYER->move();
}