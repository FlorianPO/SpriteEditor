#pragma once

#include "stdafx.h"

#define OUTIL COutil::_t
class COutil
{
public:
	static COutil* _t;

	COutil(void);
	virtual ~COutil(void) = 0;
public:
	virtual void afficher();
	virtual void use() = 0;

public:
	enum outil_enum
	{
		CRAYON = 0,
		GOMME,
		AERO,
		POT,
		DEGRADE,
		RECTSELEC,
		BAGUETTE,
		SELECCOLOR,
		SNAP,
		CHEMIN,
		MOVE,
		GRAND,
		ROTATION,
		FLIP,
		ALIGN
	};

	outil_enum numero_outil;

public:
	static void chooseOutil(outil_enum o);
	static bool isTransform();
	static bool isMove();
	static bool isOutil();

	struct line_conf
	{
		sf::VertexArray line;
		int conf;
		int x;
		int y;
	};
	static line_conf creer_conf_line(sf::VertexArray line, int conf, int x, int y);

	struct range_type
	{
		int debutX;
		int finX;
		int Y;
	};

	static void move_line(std::vector<COutil::line_conf>* liste, sf::Vector2i mov);
};

