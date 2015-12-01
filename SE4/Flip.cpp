#include "Flip.h"
#include "Copy.h"
#include "Calque.h"

CFlip::CFlip()
{
	numero_outil = COutil::FLIP;
}


CFlip::~CFlip()
{
}

void CFlip::use()
{
	if (COPY != NULL)
		COPY->flip();
	else
		CALQUE->flip();
}