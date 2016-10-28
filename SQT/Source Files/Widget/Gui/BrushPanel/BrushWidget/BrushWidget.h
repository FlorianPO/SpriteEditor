#pragma once

#include "stdenum.h"
#include "Source Files/Widget/Various/TabSFML/TabObject.h"
class Brush; // Forward declaration

class BrushWidget : public TabObject
{
	Q_OBJECT
// CONSTRUCTORS
public:
	BrushWidget(Brush& brush, const sf::Texture& texture);
	~BrushWidget() {}

// METHODS
public:
	void draw(sf::RenderWindow& fenetre) override;
	sf::FloatRect getBounds() const override;
	void setPosition(const sf::Vector2f& pos) override;

// SIGNALS SLOTS
	private slots:
		void sizeChanged(const sf::Vector2i&);
	public slots:
		void sizeXChanged(int);
		void sizeYChanged(int);
		void selected();
		void unselected();
		void tabSelect() override;

// MEMBERS
private:
	Brush* brush;

	sf::Sprite tool_sprite;
	sf::Text tool_size;
	sf::Vector2i size;
	sf::RectangleShape square;
	sf::Vector2f offset;
	bool selec = false;
};

