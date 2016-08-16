#include "Copy.h"

#include "Source Files/Application/App.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Queue/QueueController.h"

Copy::Copy(const sf::Image& image, sf::Vector2f position) {
	texture_copy.loadFromImage(image);
	sprite_copy.setTexture(texture_copy);

	sprite_copy.setPosition(position);

	lines = sf::VertexArray(sf::LinesStrip, 5);
	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::emitStatus() {
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds())); 
	emit copyScaled(SIZE_RECT(sprite_copy.getGlobalBounds()));
	emit copyRotated(sprite_copy.getRotation());
}

void Copy::updateLines() {
	lines[0].position = sf::Vector2f(0, 0);
	lines[1].position = sf::Vector2f(texture_copy.getSize().x * sprite_copy.getScale().x, 0);
	lines[2].position = sf::Vector2f(texture_copy.getSize().x * sprite_copy.getScale().x, texture_copy.getSize().y * sprite_copy.getScale().y);
	lines[3].position = sf::Vector2f(0, texture_copy.getSize().y * sprite_copy.getScale().y);

	float angle = -sprite_copy.getRotation() / 180 * PI;
	FOR_I (4) {
		sf::Vector2f temp = lines[i].position - sf::Vector2f(sprite_copy.getOrigin().x*sprite_copy.getScale().x, sprite_copy.getOrigin().y*sprite_copy.getScale().y);
		lines[i].position.x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
		lines[i].position.y = temp.y*std::cos(angle) - temp.x*std::sin(angle);

		lines[i].position += sprite_copy.getPosition();
	}

	lines[4].position = lines[0].position;
}

void Copy::setPosition(sf::Vector2f pos) {
	sprite_copy.setPosition(pos);
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds()));

	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::setGlobalPosition(sf::Vector2f pos) {
	Fonction::setGlobalPosition(sprite_copy, pos);
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds()));

	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::setScale(sf::Vector2f scale) {
	sprite_copy.setScale(scale);
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds()));
	emit copyScaled(SIZE_RECT(sprite_copy.getGlobalBounds()));
	
	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::setRotation(float rotation) {
	sprite_copy.setRotation(rotation);
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds()));
	emit copyScaled(SIZE_RECT(sprite_copy.getGlobalBounds()));
	emit copyRotated(sprite_copy.getRotation());

	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::setOrigin(sf::Vector2f origin) {
	Fonction::setOriginLocally(sprite_copy, origin);
	
	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::translate(sf::Vector2f translation) {
	setPosition(getPosition() + translation);
	emit copyMoved(POS_RECT(sprite_copy.getGlobalBounds()));
	
	QUEUE->beforeDisplay(this, "updateLines");
}

void Copy::display() {
	APP->getWindow().draw(sprite_copy);
}

void Copy::displayLines() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	FOR_I (lines.getVertexCount())
		lines[i].color = color;
	APP->getWindow().draw(lines);

}