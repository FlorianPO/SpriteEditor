#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalListObject.h"
class Brush; // Forward declaration

class Layer : public SignalListObject
{
	Q_OBJECT
// CONSTRUCTOR
public:		
	Layer(sf::Image& image_init);
	~Layer() {}

// METHODS
public:
	void drawSpriteLocaly(const sf::Sprite& spr, const sf::RenderStates& render); // Draw directly on render
	void drawSpriteLocaly(sf::Sprite& spr, const sf::Vector2f& position, const sf::RenderStates& render); // Draw directly on render
	void drawSprite(sf::Sprite& spr, const sf::RenderStates& render);
	void drawSprite(sf::Sprite& spr, const sf::Vector2f&, const sf::RenderStates& render); // Optimized

	void drawBrushLocally(Brush& brush, const sf::Vector2f&, const sf::RenderStates& render); // Draw directly on render
	void drawBrushLocally(Brush& brush, const sf::RenderStates& render); // Draw directly on render
	void drawBrush(Brush& brush, const sf::Vector2f&, const sf::RenderStates& render); // Optimized
	void drawBrush(Brush& brush, const sf::RenderStates& render);  // Good if called occasionaly

	void update();
	void display(); //Display layer

	// CURRENT LAYER TRANSFORMATION
	void move();
	void grand();
	void rotation();
	void flip();

	//Sprite and texture						
	inline const sf::Sprite& getSprite() const { return sprite; }
	inline const sf::Texture& getTexture() const { return *sprite.getTexture(); }
	inline sf::Vector2f getSize() const { return SIZE_RECT(sprite.getTextureRect()); }
	inline sf::IntRect getGlobalBounds() const { return RECTI(sprite.getGlobalBounds()); }

	//Retrieve a sf::Image		
	inline const sf::Image& getImage() const { return *image; }
				
	inline bool isVisible() const { return visible; }
	inline const QString& getName() const { return name; }
	void setName(const QString& string);

	// TRANSFORMATION
	inline const sf::Vector2f& getPosition() const { return sprite.getPosition(); }
	void setPosition(const sf::Vector2f& position);
	void translate(const sf::Vector2f& translation);
	void setScale(const sf::Vector2f& scale);
	void setRotation(float rotation);

// SIGNALS SLOTS
	public slots:
		void emitStatus() const;
		void show(); //Make visible
		void hide();
	signals:
		void layerVisible() const;
		void layerUnvisible() const;
		void layerMoved(sf::Vector2f pos) const;
		void layerScaled(sf::Vector2f size) const;
		void layerUpdated() const;
		void nameChanged(QString) const;

// MEMBERS
private:
	bool visible = true;
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
		void setImage(sf::Image& image_var, bool recreate=false);
};