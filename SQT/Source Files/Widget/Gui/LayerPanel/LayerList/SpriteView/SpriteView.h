#pragma once

#include "stdafx.h"
#include "Source Files/Widget/SQT/SQT.h"

class SpriteView : public SQT
{
	Q_OBJECT
public:
	explicit SpriteView(QWidget* parent, const sf::Texture& texture, sf::Vector2u size);
	~SpriteView() {}

	void changeTexture(const sf::Texture& texture);
	void resize();

	public slots:
		void selected();
		void unselected();

private:
	virtual void OnUpdate() override;
	
	sf::Sprite sprite;
	sf::Vector2u size;
	sf::Color background_color = sf::Color(240, 240, 240);
	bool select = false;
};
