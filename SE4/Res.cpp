#include "Res.h"
#include "Var.h"

CRes* RES;

CRes::CRes(void)
{
	texture[panneau].loadFromFile(directory + "Panneau.png");
	texture[optionColor].loadFromFile(directory + "OptionColor.png");
	texture[optionColor_1].loadFromFile(directory + "OptionColor_1.png");
	texture[optionColor_2].loadFromFile(directory + "OptionColor_2.png");
	texture[optionColor_3].loadFromFile(directory + "OptionColor_3.png");
	texture[anim].loadFromFile(directory + "Anim.png");

	sf::Image image; image.create(100, 100, sf::Color::White);
	texture[none].loadFromImage(image);

	sprite[alpha_gimp] = sf::Sprite(texture[panneau]);
	sprite[alpha_gimp].setTextureRect(sf::IntRect(220, 192, 200, 108));
	
	sprite[sprite_white] = sf::Sprite(texture[none]);

	//Shaders
	render[cut] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[cut]);
	shader[cut].loadFromFile(directory + "cut.frag" + ".txt", sf::Shader::Fragment);

	render[invert] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[invert]);
	shader[invert].loadFromFile(directory + "invert.frag" + ".txt", sf::Shader::Fragment);

	render[update] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[update]);
	shader[update].loadFromFile(directory + "update.frag" + ".txt", sf::Shader::Fragment);

	render[usual] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[usual]);
	shader[usual].loadFromFile(directory + "selec.frag" + ".txt", sf::Shader::Fragment);
	shader[usual].setParameter("opacity", VAR->opacity);

	render[fuse] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[fuse]);
	shader[fuse].loadFromFile(directory + "fuse.frag" + ".txt", sf::Shader::Fragment);

	render[pot] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[pot]);
	shader[pot].loadFromFile(directory + "pot.frag" + ".txt", sf::Shader::Fragment);
}

CRes::~CRes(void) {}

sf::Sprite CRes::getSprite(SPRITE s, sf::Vector2i size)
{
	sf::Sprite spr = sprite[s];
	if (size.x != 0 || size.y != 0)
		 spr.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	
	return spr;
}