#pragma once

#include "stdafx.h"
#include "Retourable.h"
#include "Outil.h"

#define SELEC CSelec::_t
class CSelec : public CRetourable
{
public:
	static CSelec* _t;
public:
	CSelec(void);
	~CSelec(void);
public:
	sf::Color blend_color;
	sf::Color ident_color;

	inline int* getRefLeft() { return &cadre.left; }
	inline int* getRefTop() { return &cadre.top; }
	inline int* getRefWidth() { return &cadre.width; }
	inline int* getRefHeight() { return &cadre.height; }

	bool isMove();

	void initialiser();
	void move();
	void afficher_lines();

	void noSelec();
	void delete_selec();
	void new_selec(sf::IntRect rect, sf::Image* image, std::vector<COutil::line_conf>* conf_l, int type);

	void inverser_selec();
	void initTest();
	bool onSelec(int x, int y);
	inline bool isSelected() { return conf_lines.size()>0; }
	inline bool isInverted() { return invert; }
	inline sf::Vector2f getPosition() { return sprite_selec.getPosition(); }
	inline sf::IntRect getCadre() { return cadre; }

	void supr();

private:
	void update_cadre();
	void reline();
	void which_size(sf::IntRect rect, sf::Image* image_selec);
	void update_size(sf::IntRect rect, sf::Image* image_selec, int type);
	void intersect(sf::IntRect rect, sf::Image* image_selec);
	void setPosLines(sf::Vector2f ex_pos, sf::Vector2f pos);

private:
	bool refresh = true; 
	bool invert;

	sf::IntRect cadre;

	sf::Image image_selec;
	sf::RenderTexture renderTexture_selec;
	sf::Sprite sprite_selec;

	std::vector<COutil::line_conf> conf_lines;

private:
	enum type_retour
	{
		ACT = 0,
		POS,
		INV
	};

	void creer_retour(type_retour t);
	void update(type_retour t);

	int i_retour_type;
	std::vector<type_retour> retour_type;
	int i_retour_inv;
	std::vector<bool> retour_inv;
	int i_retour_pos;
	std::vector<sf::Vector2f> retour_pos;
	int i_retour_image;
	std::vector<sf::Image> retour_image;
	int i_retour_lines;
	std::vector<std::vector<COutil::line_conf>> retour_lines;

public:
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
};

