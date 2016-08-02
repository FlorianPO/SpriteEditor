#include "ResourceController.h"

ResourceController* ResourceController::_t;

ResourceController::ResourceController() {
	using namespace nRer;

	sf::Image image; image.create(100, 100, sf::Color::White);
	texture[none].loadFromImage(image);
	texture[transparency].loadFromFile(directory + "Transparency.png");

	sprite[alpha_gimp] = sf::Sprite(texture[transparency]);
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

	render[fuse] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[fuse]);
	shader[fuse].loadFromFile(directory + "fuse.frag" + ".txt", sf::Shader::Fragment);

	render[pot] = sf::RenderStates(sf::BlendNone, sf::Transform::Identity, NULL, &shader[pot]);
	shader[pot].loadFromFile(directory + "pot.frag" + ".txt", sf::Shader::Fragment);

	//Font
	font[base].loadFromFile(directory + "base.ttf");
}