#pragma once

#include "stdenum.h"

class Brush : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Brush() {}
	virtual ~Brush() {}

// METHODS
public:
	virtual void create(sf::Vector2i) = 0;

	void createLines();
	void createPreview();

	void checkSize(sf::Vector2i size_to_check);
	void display(sf::Vector2f center);
	void display(); //Display brush lines
	
	void setPosition(sf::Vector2f position); //Set brush's position
	void move(sf::Vector2f delta_move);

	inline sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::Vector2f getPointedPosition();
	sf::Vector2f getExPosition();
	sf::Vector2f truePosition(sf::Vector2f position);

	void setColor(sf::Color color);

	inline sf::Vector2i	getSize() { return size; }
	inline QSize getQSize() { return QSize(size.x, size.y); }
	inline const sf::Sprite& getSprite() { return sprite; }
	inline const sf::Texture& getPreviewTexture() { return preview_texture; }

	inline nBrh::brush_enum getEnum() { return numero_brush; }
	inline int getId() { return static_cast<int>(numero_brush); }

protected:
	void setSize(sf::Vector2i size_to_set);
	void setDisplayPosition(sf::Vector2f center);

// SIGNALS SLOTS
	public slots:
		void select();
		void unselect();
	signals:
		void selected();
		void unselected();

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

