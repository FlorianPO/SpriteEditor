#include "BrushWidget.h"

#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Application/Resource/ResourceController.h"

BrushWidget::BrushWidget(Brush& brush, const sf::Texture& texture) {
	tool_sprite = sf::Sprite(texture);
	tool_sprite.setColor(sf::Color::Black);
	offset = sf::Vector2f(3, 3);

	this->brush = &brush;

	square.setSize(sf::Vector2f(39, 23));
	square.setFillColor(sf::Color::Transparent);
	square.setOutlineThickness(1);
	square.setOutlineColor(sf::Color::Red);

	tool_size.setFont(RES->getFont(nRer::base)); 
	tool_size.setCharacterSize(8);
	tool_size.setColor(sf::Color::Black);

	QObject::connect(this->brush, SIGNAL(selected()), this, SLOT(selected()));
	QObject::connect(this->brush, SIGNAL(unselected()), this, SLOT(unselected()));
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeXChanged(int)), this, SLOT(sizeXChanged(int)));
	QObject::connect(BRUSH_CONTROLLER, SIGNAL(sizeYChanged(int)), this, SLOT(sizeYChanged(int)));

	sizeChanged(this->brush->getSize());
}

void BrushWidget::draw(sf::RenderWindow& fenetre) {
	if (selec)
		fenetre.draw(square);
	fenetre.draw(tool_sprite);
	fenetre.draw(tool_size);
}

sf::FloatRect BrushWidget::getBounds() const {
	return sf::FloatRect(square.getPosition(), sf::Vector2f(39, 23));
}

void BrushWidget::setPosition(const sf::Vector2f& pos) {
	square.setPosition(pos);
	tool_sprite.setPosition(pos + offset);

	sf::Vector2f size_pos = pos + sf::Vector2f(22, 2);
	tool_size.setPosition(size_pos);
}

void BrushWidget::selected() {
	selec = true;
}
void BrushWidget::unselected() {
	selec = false;
}

void BrushWidget::tabSelect() {
	BRUSH_CONTROLLER->selectBrush(*brush);
}

void BrushWidget::sizeChanged(const sf::Vector2i& size) {
	tool_size.setString(std::to_string(size.x) + "\n" + std::to_string(size.y));
	this->size = size;
}
void BrushWidget::sizeXChanged(int value) {
	sizeChanged(sf::Vector2i(value, size.y));
}
void BrushWidget::sizeYChanged(int value) {
	sizeChanged(sf::Vector2i(size.x, value));
}