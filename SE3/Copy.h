#pragma once

#include "stdafx.h"
#include "Retourable.h"

#define COPY CCopy::_t
#define COPY_LIST CCopy::copy_list

class CCopy : public CRetourable
{
public:
	static CCopy* _t;
	static std::vector<CCopy*> copy_list;
	static sf::Vector2f pos_copy;
	static void new_copy(sf::Image* image);

	CCopy(sf::Image* image);
	~CCopy(void);

public:
	inline const sf::Sprite* getSprite() { return &sprite_copy; }

	void afficher();
	void afficher_lines();

	void move();
	void grand();
	void rotation();
	void flip();

	void apply();

	inline int* getRefLeft() { return &rect_copy.left; }
	inline int* getRefTop() { return &rect_copy.top; }
	inline int* getRefWidth() { return &rect_copy.width; }
	inline int* getRefHeight() { return &rect_copy.height; }

private:
	sf::VertexArray lines;
	sf::Texture texture_copy;
	sf::Sprite sprite_copy;
	static sf::IntRect rect_copy;

	bool clicked;
	sf::Vector2i posi;
	sf::Vector2f posf;
	sf::Vector2f posf2;
	float angle_ini;

	void setPosLines();

private:
	enum type_retour
	{
		CRE = 0,
		MOV,
		APL,
		GRA,
		ORI,
		ROT,
		FLIPH,
		FLIPV
	};

	std::vector<type_retour> retour_type;
	std::vector<sf::Vector2f> retour_pos;
	std::vector<sf::Vector2f> retour_taille;
	std::vector<sf::Vector2f> retour_origin;
	std::vector<float> retour_rotation;
	sf::Vector2f ex_scale;

	int i_retour_type;
	int i_retour_pos;
	int i_retour_taille;
	int i_retour_origin;
	int i_retour_rotation;

	void creer_retour(type_retour t);

public:
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
};

