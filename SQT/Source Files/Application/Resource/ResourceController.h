#pragma once

#include "stdenum.h"

#define INIT_RESOURCE_CONTROLLER ResourceController::createInstance();
#define RESOURCE_CONTROLLER ResourceController::getInstance()
#define RES RESOURCE_CONTROLLER

class ResourceController
{
// INSTANCE
private:	static ResourceController* _t; 
public:		inline static void createInstance() { _t = new ResourceController(); }
			inline static ResourceController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	ResourceController();
	~ResourceController() {}

// METHODS
public:
	inline const sf::Texture& getTexture(nRer::TEXTURE t) { return texture[t]; }
	inline const sf::Sprite& getSprite(nRer::SPRITE s) { return sprite[s]; }
	inline sf::Shader& getShader(nRer::SHADER s) { return shader[s]; }
	inline const sf::RenderStates& getRender(nRer::SHADER s) { return render[s]; }
	inline const sf::Font& getFont(nRer::FONT f) { return font[f]; }

	sf::String directory = "Resources/";
	QString directory_qt = QString("Resources/");

// MEMBERS
private:
	sf::Texture texture[nRer::LAST_TEXTURE];
	sf::Sprite sprite[nRer::LAST_SPRITE];
	sf::Font font[nRer::LAST_FONT];

	sf::Shader shader[nRer::LAST_SHADER];
	sf::RenderStates render[nRer::LAST_SHADER];
};