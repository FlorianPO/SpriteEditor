#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/Var/Var.h"

CRes* CRes::_t;

CRes::CRes()
{
	//Brushes
	texture[brush_pixel].loadFromFile(directory + "Brushes/"			+ "brush_pixel.png");
	texture[brush_circle].loadFromFile(directory + "Brushes/"			+ "brush_circle.png");
	texture[brush_circle_outline].loadFromFile(directory + "Brushes/"	+ "brush_circle_outline.png");
	texture[brush_square].loadFromFile(directory + "Brushes/"			+ "brush_square.png");
	texture[brush_square_outline].loadFromFile(directory + "Brushes/"	+ "brush_square_outline.png");

	//
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
	
	sprite[panel_separator] = sf::Sprite(texture[panneau]);
	sprite[panel_separator].setTextureRect(sf::IntRect(1, 436, 129, 1));

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

	//Font
	font[base].loadFromFile(directory + "base.ttf");
}

sf::Sprite CRes::getSprite(SPRITE s, sf::Vector2i size)
{
	sf::Sprite spr = sprite[s];
	if (size.x != 0 || size.y != 0)
		 spr.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	
	return spr;
}