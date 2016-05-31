#include "Source Files/Application/Tool/Tools/Flip.h"

#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/Layer.h"

CFlip::CFlip() {
	numero_outil = CTool::FLIP;
}

void CFlip::use() {
	if (COPY != NULL)
		COPY->flip();
	else
		LAYER->flip();
}