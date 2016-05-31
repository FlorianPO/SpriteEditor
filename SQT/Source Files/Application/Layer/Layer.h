#pragma once

#include "stdafx.h"
#include "Source Files/Retour/Retourable.h"
#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Layer/LayerController.h"

class CLayer : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:		
	CLayer(sf::Texture* texture_var);
	~CLayer() {}

// METHODS
	void draw(const sf::Sprite& spr, sf::RenderStates* render = RES->getRender(CRes::SHADER::usual), bool no_retour = false);
	void draw_brush(CBrush& brush, sf::Vector2f pos, sf::RenderStates* render = RES->getRender(CRes::SHADER::usual));
	void update(sf::Texture* texture_var); //Update layer (refresh)
	void display(); //Display layer

	// TRANSFORMATIONS
	void move();
	void grand();
	void rotation();
	void flip();

	//Sprite and texture						
	inline const sf::Sprite& getSprite() { return sprite; }
	inline sf::RenderTexture* getRenderTexture() { return &renderTexture; }
	inline const sf::Texture& getTexture() { return *sprite.getTexture(); }
	inline sf::Vector2u getSize() { return sf::Vector2u(sprite.getTextureRect().width, sprite.getTextureRect().height); }
	inline sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }

	//Retrieve a sf::Image		
	sf::Image& getImage();

	//Layer's position
	inline sf::Vector2i getPosition_i() { return sf::Vector2i(sprite.getPosition().x, sprite.getPosition().y); }
	inline sf::Vector2f getPosition() { return sprite.getPosition(); }

	inline bool isDead() { return dead; }				
	inline bool isVisible() { return visible; }
	inline const QString& getName() { return name; }
	
// SIGNALS SLOTS
	public slots:
		void show(); //Make visible
		void hide();
		void select(); //Select layer
		void unselect();
		void drop(); //Erase layer
	signals:
		void layerChanged();
		void layerVisible();
		void layerUnvisible();
		void layerSelected();
		void layerUnselected();
		void layerDropped();

// MEMBERS
private:
	bool dead = false;
	bool visible = true;
	bool refresh = false;
	bool changed = false;
	bool clicked = false;
	sf::Image image_buffer;

	sf::Sprite sprite;
	sf::RenderTexture renderTexture;
	QString name;

	//Related to transformation methods
	float angle_ini;
	sf::Vector2i posi;
	sf::Vector2f posf;

/*
// RETOUR
private:
	enum type_retour
	{
		CRE = 0,
		ACT,
		DEL,
		MOV
	};

	int i_retour_type = -1;		std::vector<type_retour> retour_type;
	int i_retour_image = -1;	std::vector<sf::Image> retour_image;
	int i_retour_pos = -1;		std::vector<sf::Vector2f> retour_pos;

	void creer_retour(sf::Image* image, type_retour t);

public:
	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
*/
};