#pragma once

#include "stdenum.h"
class Brush; // Forward declaration

class Layer : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:		
	Layer(sf::Image* image_init);
	~Layer() {}

// METHODS
public:
	void drawSpriteLocaly(const sf::Sprite& spr, const sf::RenderStates& render); // Draw directly on render
	void drawSpriteLocaly(sf::Sprite& spr, sf::Vector2f position, const sf::RenderStates& render); // Draw directly on render
	void drawSprite(sf::Sprite& spr, const sf::RenderStates& render);
	void drawSprite(sf::Sprite& spr, sf::Vector2f position, const sf::RenderStates& render); // Optimized

	void drawBrushLocally(Brush& brush, sf::Vector2f position, const sf::RenderStates& render); // Draw directly on render
	void drawBrushLocally(Brush& brush, const sf::RenderStates& render); // Draw directly on render
	void drawBrush(Brush& brush, sf::Vector2f position, const sf::RenderStates& render); // Optimized
	void drawBrush(Brush& brush, const sf::RenderStates& render);  // Good if called occasionaly

	void update();
	void display(); //Display layer

	// CURRENT LAYER TRANSFORMATION
	void move();
	void grand();
	void rotation();
	void flip();

	//Sprite and texture						
	inline const sf::Sprite& getSprite() { return sprite; }
	inline const sf::Texture& getTexture() { return *sprite.getTexture(); }
	inline sf::Vector2f getSize() { return SIZE_RECT(sprite.getTextureRect()); }
	inline sf::IntRect getGlobalBounds() { return RECTI(sprite.getGlobalBounds()); }

	//Retrieve a sf::Image		
	inline sf::Image* getImage() { return image; }

	inline bool isDead() { return dead; }				
	inline bool isVisible() { return visible; }
	inline const QString& getName() { return name; }
	
	// TRANSFORMATION
	inline sf::Vector2f getPosition() { return sprite.getPosition(); }
	void setPosition(sf::Vector2f position);
	void translate(sf::Vector2f translation);
	void setScale(sf::Vector2f scale);
	void setRotation(float rotation);

// SIGNALS SLOTS
	public slots:
		void emitStatus();
		void show(); //Make visible
		void hide();
		void select(); //Select layer
		void unselect();
		void drop(); //Erase layer
		void undrop(); //Erase layer
	signals:
		void layerVisible();
		void layerUnvisible();
		void layerSelected();
		void layerUnselected();
		void layerDropped();
		void layerUndropped();
		void layerMoved(sf::Vector2f pos);
		void layerScaled(sf::Vector2f size);

// MEMBERS
private:
	bool dead = false;
	bool visible = true;
	bool clicked = false;
	sf::Image* image;

	sf::Sprite sprite;
	sf::RenderTexture renderTexture;
	QString name;

	//Related to transformation methods
	float angle_ini;
	sf::Vector2i posi;
	sf::Vector2f posf;

// UNDO
public:
	friend class LayerCreated;
	friend class LayerDrawn;
	friend class LayerMoved;

	private: // Core context
		void setImage(sf::Image* image_var, bool recreate=false);
};