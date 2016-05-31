#pragma once

#include "stdafx.h"

#include "Source Files/Widget/Various/TabSFML/TabObject.h"

class CBrush;

class ToolWidget : public TabObject
{
	Q_OBJECT
// CONSTRUCTORS
public:
	ToolWidget(CBrush& brush, const sf::Sprite& sprite);
	~ToolWidget() {}

// METHODS
	void draw(sf::RenderWindow* fenetre) override;
	sf::FloatRect getBounds() override;
	void setPosition(sf::Vector2f pos) override;

// SIGNALS SLOTS
	private slots:
		void sizeChanged(sf::Vector2i);
	public slots:
		void sizeXChanged(int);
		void sizeYChanged(int);
		void selected();
		void unselected();
		void tabSelect() override;

// MEMBERS
private:
	CBrush* brush;

	sf::Sprite tool_sprite;
	sf::Text tool_size;
	sf::Vector2i size;
	sf::RectangleShape square;
	sf::Vector2f offset;
	bool selec = false;
};

