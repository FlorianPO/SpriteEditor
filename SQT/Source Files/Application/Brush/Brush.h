#pragma once

#include "stdenum.h"

class Brush : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Brush() {}
	~Brush() {}

// METHODS
public:
	virtual void create(const sf::Vector2i&) = 0;

	void createLines();
	void createPreview();

	void checkSize(const sf::Vector2i& size_to_check);
	void display(const sf::Vector2f& center);
	void display(); //Display brush lines
	
	void setPosition(const sf::Vector2f& position); //Set brush's position
	void move(const sf::Vector2f& delta_move);

	inline const sf::Vector2f& getPosition() const { return sprite.getPosition(); }
	sf::Vector2f getPointedPosition() const;
	sf::Vector2f getExPosition() const;
	sf::Vector2f truePosition(sf::Vector2f position) const;

	void setColor(const sf::Color& color);

	inline const sf::Vector2i& getSize() const { return size; }
	inline QSize getQSize() const { return QSize(ARG_VECTOR(size)); }
	inline const sf::Sprite& getSprite() const { return sprite; }
	inline const sf::Texture& getPreviewTexture() const { return preview_texture; }

	inline nBrh::brush_enum getEnum() const { return numero_brush; }
	inline int getId() const { return static_cast<int>(numero_brush); }

protected:
	void setSize(const sf::Vector2i& size_to_set);
	void setDisplayPosition(sf::Vector2f center);

// SIGNALS SLOTS
	public slots:
		void select();
		void unselect();
	signals:
		void selected() const;
		void unselected() const;

// MEMBERS
protected:
	bool default_brush = true;
	nBrh::brush_enum numero_brush;

	sf::Vector2i	size;
	sf::Vector2f	hsize;
	sf::Vector2i	parity;

	sf::Texture		texture;
	sf::Sprite		sprite;
	sf::Texture		preview_texture;

	nSet::positionned_lines lines;
};

