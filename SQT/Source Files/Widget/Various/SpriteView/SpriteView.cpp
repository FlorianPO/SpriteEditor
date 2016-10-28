#include "SpriteView.h"

#include "Source Files/Fonction/Fonction.h"

SpriteView::SpriteView(QWidget* parent, QMainWindow* window) : SQT(parent, false) {
	this->parent = parent;
	if (window != NULL)
		window->installEventFilter(this);
	parent->installEventFilter(this);
}

SpriteView::SpriteView(QWidget* parent, const sf::Texture& texture, QMainWindow* window) : SpriteView(parent, window) {
	sprite.setTexture(texture, true);
	sprite.setOrigin(Fonction::centerCorner(texture));
}

SpriteView::SpriteView(QWidget* parent, const sf::Texture& texture, const sf::IntRect& rect, QMainWindow* window) : SpriteView(parent, window) {
	sprite.setTexture(texture, true);
	texture_rect_defined = true;
	texture_rect = rect;
	sprite.setTextureRect(rect);
	sprite.setOrigin(Fonction::centerCorner(SIZE_RECT(rect)));
}

bool SpriteView::eventFilter(QObject* object, QEvent* evnt) {
	if (object == parent) {
		if (evnt->type() == QEvent::Move || evnt->type() == QEvent::Resize)
			refreshOnce();
	}
	else if (evnt->type() == QEvent::Resize)
		refreshOnce();

	return false;
}

void SpriteView::resizeEvent(QResizeEvent* qr) {
	SQT::resizeEvent(qr);
	resize();
}

void SpriteView::setTexture(const sf::Texture& texture) {
	sprite.setTexture(texture, true);
	if (texture_rect_defined)
		setTextureRect(texture_rect);
	else {
		sprite.setOrigin(Fonction::centerCorner(texture));
		resize();
	}
}

void SpriteView::setTextureRect(const sf::IntRect& rect) {
	texture_rect_defined = true;
	texture_rect = rect;
	sprite.setTextureRect(rect);
	sprite.setOrigin(Fonction::centerCorner(SIZE_RECT(rect)));
	resize();
}

void SpriteView::setOutLine(int pixel) {
	this->pixel = pixel;
	resize();
}

void SpriteView::resize() {
	sf::Vector2f _size = sf::Vector2f(size().width(), size().height());

	float min = std::min(float(_size.x-2*pixel) / sprite.getTextureRect().width, float(_size.y-2*pixel) / sprite.getTextureRect().height);
	sprite.setScale(min, min);
	sprite.setPosition(Fonction::centerCorner(_size));
	refreshOnce();
}

void SpriteView::select() {
	if (!selected) {
		selected = true;
		background_color = sf::Color(200, 200, 200);
		refreshOnce();
	}
}

void SpriteView::unselect() {
	if (selected) {
		selected = false;
		background_color = sf::Color(240, 240, 240);
		refreshOnce();
	}			
}

void SpriteView::OnUpdate() {
	clear(background_color);
	draw(sprite);	
}