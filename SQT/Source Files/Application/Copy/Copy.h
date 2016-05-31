#pragma once

#include "stdafx.h"
#include "CopyController.h"

class CCopy : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	CCopy(const sf::Image& image, sf::Vector2f position=sf::Vector2f());
	~CCopy() {}

// TRANSFORMATIONS
	void move();
	void grand();
	void rotation();
	void flip();

// METHODS
	inline const sf::Sprite& getSprite() { return sprite_copy; }

	void display();
	void displayLines();
	void apply();

// SIGNALS SLOTS
	signals:
		void copyApplied(CCopy*);
		void copyTransformed(CCopy*);

// MEMBERS
private:
	sf::VertexArray lines;
	sf::Texture texture_copy;
	sf::Sprite sprite_copy;
	sf::IntRect rect_copy;

	bool clicked;
	sf::Vector2f posf;
	sf::Vector2f posf2;
	float angle_ini;

	void setPosLines();

/*
// RETOUR
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

	int i_retour_type;			std::vector<type_retour> retour_type;
	int i_retour_pos;			std::vector<sf::Vector2f> retour_pos;
	int i_retour_taille;		std::vector<sf::Vector2f> retour_taille;
	int i_retour_origin;		std::vector	<sf::Vector2f> retour_origin;
	int i_retour_rotation;		std::vector<float> retour_rotation;
	sf::Vector2f ex_scale;

	void creer_retour(type_retour t);

public:
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
*/
};

