#pragma once

#include "stdenum.h"
#include "Source Files/QtApp/SQT/SQT.h"

class SpriteView : public SQT
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SpriteView(QWidget* parent, const sf::Texture& texture, sf::Vector2u size);
	~SpriteView() {}

// METHODS
public:
	void changeTexture(const sf::Texture& texture);
	void resize();
private:
	virtual void OnUpdate() override;

// SIGNALS SLOTS
	public slots:
		void selected();
		void unselected();

// MEMBERS
private:
	sf::Sprite sprite;
	sf::Vector2u size;
	sf::Color background_color = sf::Color(240, 240, 240);
	bool select = false;

	bool init = false;
};
