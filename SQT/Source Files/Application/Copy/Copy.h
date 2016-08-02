#pragma once

#include "stdenum.h"

class Copy : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Copy(const sf::Image& image, sf::Vector2f position);
	~Copy() {}

// METHODS
public:
	inline const sf::Sprite& getSprite() { return sprite_copy; }
	inline const sf::Texture& getTexture() { return *sprite_copy.getTexture(); }

	inline sf::Vector2f getPosition() { return sprite_copy.getPosition(); }
	void setPosition(sf::Vector2f pos);
	void setGlobalPosition(sf::Vector2f pos);
	void translate(sf::Vector2f translation);

	void setScale(sf::Vector2f scale);
	void setRotation(float rotation);
	void setOrigin(sf::Vector2f origin);

	void display();
	void displayLines();

	// TRANSFORMATIONS
	void move();
	void keyMove(int x, int y);
	void grand();
	void rotation();
	void flip();

private:
	Q_INVOKABLE void updateLines();

// SIGNALS SLOTS
	signals:
		void copyMoved(sf::Vector2f topLeftPos);
		void copyScaled(sf::Vector2f size);
		void copyRotated(float angle);

// MEMBERS
private:
	sf::VertexArray lines;
	sf::Texture texture_copy;
	sf::Sprite sprite_copy;

	// Related to void move(nInt::on_key)
	sf::Vector2f pos_init;

	sf::Vector2f posf;
	sf::Vector2f posf2;
	float angle_ini;
};

