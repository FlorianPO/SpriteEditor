#include "Source Files/Application/Tool/Tools/Move.h"

#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

CMove::CMove() {
	numero_outil = CTool::MOVE;
}

void CMove::use() {
	if (COPY != NULL)
		COPY->move();
	else
		LAYER->move();
}