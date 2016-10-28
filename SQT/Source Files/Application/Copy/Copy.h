#pragma once

#include "stdenum.h"

class Copy : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Copy(const sf::Image& image, const sf::Vector2f& position);
	~Copy() {}

// METHODS
public:
	inline const sf::Sprite& getSprite() const { return sprite_copy; }
	inline const sf::Texture& getTexture() const { return *sprite_copy.getTexture(); }

	inline const sf::Vector2f& getPosition() const { return sprite_copy.getPosition(); }
	inline sf::Vector2f getGlobalPosition() const { return POS_RECT(sprite_copy.getGlobalBounds()); }
	inline sf::FloatRect getGlobalBounds() const { return sprite_copy.getGlobalBounds(); }
	void setPosition(const sf::Vector2f& pos);
	void setGlobalPosition(const sf::Vector2f& pos);
	void translate(const sf::Vector2f& translation);

	void setScale(const sf::Vector2f& scale);
	void setRotation(float rotation);
	void setOrigin(const sf::Vector2f& origin);
	
	void display();
	void displayLines();

	// TRANSFORMATIONS
	void move();
	void keyMove(const sf::Vector2f& delta);
	void grand();
	void rotation();
	void flip();

private:
	Q_INVOKABLE void updateLines();

// SIGNALS SLOTS
	public slots:
		void emitStatus() const;
	signals:
		void copyMoved(sf::Vector2f topLeftPos) const;
		void copyScaled(sf::Vector2f size) const;
		void copyRotated(float angle) const;

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

