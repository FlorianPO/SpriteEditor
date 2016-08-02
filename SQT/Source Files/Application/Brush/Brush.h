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
	void setDisplayPosition(sf::Vector2f center, bool force=false);
	void display(sf::Vector2f center);
	void display(); //Display brush lines
	
	void setPosition(sf::Vector2f position); //Set brush's position
	void move(sf::Vector2f delta_move);

	inline sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::Vector2f getPointedPosition();
	sf::Vector2f getExPointedPosition();

	void setExPosition(sf::Vector2f position);
	inline sf::Vector2f getExPosition() { return truePosition(ex_position); }

	void setColor(sf::Color color);

	inline sf::Vector2i	getSize() { return size; }
	inline QSize getQSize() { return QSize(size.x, size.y); }
	inline const sf::Sprite& getSprite() { return sprite; }
	inline const sf::Texture& getPreviewTexture() { return preview_texture; }

	inline nBrh::brush_enum getEnum() { return numero_brush; }
	inline int getId() { return static_cast<int>(numero_brush); }

protected:
	void setSize(sf::Vector2i size_to_set);
private:
	sf::Vector2f truePosition(sf::Vector2f position);

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

	static sf::Vector2f	ex_position;
	static sf::Vector2f display_position;

	sf::Vector2i	size;
	sf::Vector2f	hsize;
	sf::Vector2i	parity;

	sf::Texture		texture;
	sf::Sprite		sprite;
	sf::Texture		preview_texture;

	std::vector<sf::VertexArray> lines;
	std::vector<sf::VertexArray> lines_init;
};

