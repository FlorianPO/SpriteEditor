#pragma once

#include "stdafx.h"

class CBrush : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit CBrush() {}
	virtual ~CBrush() {}

	enum brush_enum
	{
		PIXEL = 0,
		CIRCLE,
		CIRCLE_OUTLINE,
		SQUARE,
		SQUARE_OUTLINE
	};

	inline brush_enum getEnum() { return numero_brush; }
	inline int getId() { return static_cast<int>(numero_brush); }

// METHODS
public:
	virtual void create(sf::Vector2i) = 0;

	void createLines();
	void createPreview();

	void checkSize(sf::Vector2i size_to_check);
	void afficher(sf::Vector2f center);			//Display brush lines
	void setPosition(sf::Vector2f center);		//Set brush's position
	void setColor(sf::Color color);

	inline sf::Vector2i	getSize() { return size; }
	inline QSize getQSize() { return QSize(size.x, size.y); }
	inline const sf::Sprite& getSprite() { return sprite; }
	inline const sf::Texture& getPreviewTexture() { return preview_texture; }
	
	sf::Vector2f centerOf(sf::Vector2f center);
	bool onCadre();

// SIGNALS SLOTS
	public slots:
		void select();
		void unselect();
	signals:
		void selected();
		void unselected();

// MEMBERS
protected:
	void setSize(sf::Vector2i size_to_set);

	bool default_brush = true;
	brush_enum numero_brush;

	sf::Vector2i	size;
	sf::Vector2f	hsize;
	sf::Vector2i	parity;

	sf::Texture		texture;
	sf::Sprite		sprite;
	sf::Texture		preview_texture;

	std::vector<sf::VertexArray> lines;
	std::vector<sf::VertexArray> lines_init;
};

