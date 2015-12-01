#include "Move.h"
#include "Copy.h"
#include "Calque.h"

CMove::CMove()
{
	numero_outil = COutil::MOVE;
}


CMove::~CMove()
{
}

void CMove::use()
{
	if (COPY != NULL)
		COPY->move();
	//Calque
	else
		CALQUE->move();
}