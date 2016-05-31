#pragma once

#include "stdafx.h"

#define INIT_RES CRes::createInstance();
#define RES CRes::getInstance()

class CRes
{
// INSTANCE
private:	static CRes* _t; 
public:		inline static void createInstance() { _t = new CRes(); }
			inline static CRes* getInstance() { return _t; }

// CONSTRUCTOR
	CRes();
	~CRes() {}
public:
	enum TEXTURE
	{
		panneau = 0,
		optionColor,
		optionColor_1,
		optionColor_2,
		optionColor_3,
		anim,
		none,
		//Brushes
		brush_pixel,
		brush_circle,
		brush_circle_outline,
		brush_square,
		brush_square_outline,
		//LAST
		LAST_TEXTURE
	};

	enum SPRITE
	{
		alpha_gimp = 0,
		sprite_white,
		panel_separator,
		LAST_SPRITE
	};

	enum SHADER
	{
		invert = 0,
		update,
		fuse,
		pot,
		cut,
		usual,
		LAST_SHADER
	};

	enum FONT
	{
		base = 0,
		LAST_FONT
	};

	inline sf::Texture* getTexture(TEXTURE t) { return &texture[t]; }
	inline sf::Sprite getSprite(SPRITE s) { return sprite[s]; }
	sf::Sprite getSprite(SPRITE s, sf::Vector2i size);
	inline sf::Shader* getShader(SHADER s) { return &shader[s]; }
	inline sf::RenderStates* getRender(SHADER s) { return &render[s]; }
	inline sf::Font* getFont(FONT f) { return &font[f]; }

	sf::String directory = "Resources/";
	QString directory_qt = QString("Resources/");

private:
	sf::Texture texture[LAST_TEXTURE];
	sf::Sprite sprite[LAST_SPRITE];
	sf::Font font[LAST_FONT];

	sf::Shader shader[LAST_SHADER];
	sf::RenderStates render[LAST_SHADER];
};