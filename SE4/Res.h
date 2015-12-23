#pragma once

#include "stdafx.h"

#define RES CRes::_t
class CRes
{
public:
	static CRes* _t;
public:
	CRes(void);
	~CRes(void);
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

	inline sf::Texture* getTexture(TEXTURE t) { return &texture[t]; }
	inline sf::Sprite getSprite(SPRITE s) { return sprite[s]; }
	sf::Sprite getSprite(SPRITE s, sf::Vector2i size);
	inline sf::Shader* getShader(SHADER s) { return &shader[s]; }
	inline sf::RenderStates* getRender(SHADER s) { return &render[s]; }

	sf::String directory = "Ressources/";

private:
	sf::Texture texture[LAST_TEXTURE];
	sf::Sprite sprite[LAST_SPRITE];

	sf::Shader shader[LAST_SHADER];
	sf::RenderStates render[LAST_SHADER];
};