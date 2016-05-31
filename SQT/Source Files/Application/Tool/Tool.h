#pragma once

#include "stdafx.h"

class CTool
{
// CONSTRUCTOR
public:
	CTool() {}
	virtual ~CTool() {}

// METHODS
	virtual void afficher() {}
	virtual void use() {}

	enum tool_enum
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

	inline tool_enum getEnum() { return numero_outil; }
	inline int getId() { return static_cast<int>(numero_outil); }

protected:
	tool_enum numero_outil;
	sf::Vector2f center;

public:

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

	static void move_line(std::vector<CTool::line_conf>* liste, sf::Vector2i mov);
};

