#include "Source Files/Application/Tool/Tool.h"

CTool::line_conf CTool::creer_conf_line(sf::VertexArray line, int conf, int x, int y)
{
	struct line_conf lc = { line, conf, x, y };

	return lc;
}

void CTool::move_line(std::vector<CTool::line_conf>* liste, sf::Vector2i mov)
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

bool CTool::isTransform()
{
	/*if (TOOL != NULL)
		return TOOL->numero_outil == CTool::GRAND
		|| TOOL->numero_outil == CTool::ROTATION
		|| TOOL->numero_outil == CTool::FLIP;
		*/
	return false;
}

bool CTool::isMove()
{
	/*if (TOOL != NULL)
		return TOOL->numero_outil == CTool::GRAND
		|| TOOL->numero_outil == CTool::MOVE;
		*/
	return false;
}

bool CTool::isOutil()
{
	/*if (TOOL != NULL)
		return TOOL->numero_outil == CTool::DEGRADE
		|| TOOL->numero_outil == CTool::CHEMIN
		|| TOOL->numero_outil == CTool::ALIGN;
		*/
	return false;
}
