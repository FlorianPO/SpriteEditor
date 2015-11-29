#include "Outil.h"

#include "Aero.h"
#include "Crayon.h"
#include "Gomme.h"
#include "Pot.h"
#include "RectSelec.h"
#include "Baguette.h"
#include "SelecColor.h"
#include "Snap.h"
#include "Move.h"
#include "Grand.h"
#include "Rotation.h"
#include "Flip.h"

COutil* OUTIL;

COutil::COutil(void) {}

COutil::~COutil(void) {}

void COutil::afficher() {}

COutil::line_conf COutil::creer_conf_line(sf::VertexArray line, int conf, int x, int y)
{
	struct line_conf lc = { line, conf, x, y };

	return lc;
}

void COutil::move_line(std::vector<COutil::line_conf>* liste, sf::Vector2i mov)
{
	for (int i = 0; i < liste->size(); i++)
	{
		(*liste)[i].x += mov.x;
		(*liste)[i].y += mov.y;
		(*liste)[i].line[0].position.x += mov.x;
		(*liste)[i].line[0].position.y += mov.y;
		(*liste)[i].line[1].position.x += mov.x;
		(*liste)[i].line[1].position.y += mov.y;
	}
}


void COutil::chooseOutil(outil_enum o)
{
	if (_t != NULL && o == _t->numero_outil)
	{
		delete _t;
		_t = NULL;
	}
	else
	{
		if (_t != NULL)
			delete _t;

		switch (o)
		{
			case CRAYON:		_t = new CCrayon();			break;
			case GOMME:			_t = new CGomme();			break;
			case AERO:			_t = new CAero();			break;
			case POT:			_t = new CPot();			break;
			//case DEGRADE:		_t = new CDegrade();		break;
			case RECTSELEC:		_t = new CRectSelec();		break;
			case BAGUETTE:		_t = new CBaguette();		break;
			case SELECCOLOR:	_t = new CSelecColor();		break;
			case SNAP:			_t = new CSnap();			break;
			//case CHEMIN:		_t = new CChemin();			break;
			case MOVE:			_t = new CMove();			break;
			case GRAND:			_t = new CGrand();			break;
			case ROTATION:		_t = new CRotation();		break;
			case FLIP:			_t = new CFlip();			break;
			//case ALIGN:		_t = new CAlign();			break;
			default:										break;
		}
	}
}

bool COutil::isTransform()
{
	if (_t != NULL)
		return _t->numero_outil == COutil::GRAND
		|| _t->numero_outil == COutil::ROTATION
		|| _t->numero_outil == COutil::FLIP;

	return false;
}

bool COutil::isMove()
{
	if (_t != NULL)
		return _t->numero_outil == COutil::GRAND
		|| _t->numero_outil == COutil::MOVE;

	return false;
}

bool COutil::isOutil()
{
	if (_t != NULL)
		return _t->numero_outil == COutil::DEGRADE
		|| _t->numero_outil == COutil::CHEMIN
		|| _t->numero_outil == COutil::ALIGN;

	return false;
}
