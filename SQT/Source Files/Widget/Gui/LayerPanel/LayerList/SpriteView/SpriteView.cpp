#include "SpriteView.h"

#include "Source Files/Fonction/Fonction.h"

SpriteView::SpriteView(QWidget* parent, const sf::Texture& texture, sf::Vector2u size) : SQT(parent, QSize(texture.getSize().x, texture.getSize().y)) {
	this->size = size;
	changeTexture(texture);
}

void SpriteView::changeTexture(const sf::Texture& texture) {
	sprite.setTexture(texture, true);
	sprite.setOrigin(Fonction::centerCorner(texture));
	resize();
}

void SpriteView::resize() {
	float min = std::min(float(size.x) / sprite.getTextureRect().width, float(size.y) / sprite.getTextureRect().height);
	sprite.setScale(min, min);
	sprite.setPosition(Fonction::centerCorner(size));
}

void SpriteView::selected() {
	background_color = sf::Color(200, 200, 200);
}

void SpriteView::unselected() {
	background_color = sf::Color(240, 240, 240);
}

void SpriteView::OnUpdate() {
	clear(background_color);
	draw(sprite);
}