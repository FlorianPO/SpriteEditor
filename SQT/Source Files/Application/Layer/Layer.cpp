#include "Layer.h"

#include "LayerController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Application/App.h"

#include "Source Files/Application/UndoStack/UndoStack.h"
#include "LayerUndo.h"

Layer::Layer(sf::Image* image_init) {
	name = QString::fromStdString(std::to_string(LAYER_CONTROLLER->countLayer() + 1));

	setImage(image_init, true);
}

void Layer::emitStatus() {
	sf::FloatRect bounds = sprite.getGlobalBounds();
	emit layerMoved(POS_RECT(bounds));
	emit layerScaled(SIZE_RECT(bounds));
}

void Layer::update() {
	image = new sf::Image(renderTexture.getTexture().copyToImage());
	UNDO->push(new LayerDrawn(this, image));
	emit layerUpdated();
}

void Layer::setImage(sf::Image* image_var, bool recreate) {
	if (image != image_var) {
		image = image_var;
		sf::Texture texture_var = sf::Texture();
		texture_var.loadFromImage(*image_var);

		if (recreate || texture_var.getSize() != renderTexture.getSize()) {
			renderTexture.create(texture_var.getSize().x, texture_var.getSize().y);
			renderTexture.draw(sf::Sprite(texture_var), sf::BlendNone);
			renderTexture.display();
			sprite.setTexture(renderTexture.getTexture(), true);
		}
		else {
			renderTexture.draw(sf::Sprite(texture_var), sf::BlendNone);
			renderTexture.display();
			sprite.setTexture(renderTexture.getTexture());
		}
	}
}

void Layer::display() {
	if (!dead && visible)
		APP->getWindow().draw(sprite);	
}

////////////////
// BRUSH DRAW //
////////////////
void Layer::drawBrushLocally(Brush& brush, sf::Vector2f position, const sf::RenderStates& render) {
	brush.setPosition(position);
	renderTexture.draw(brush.getSprite(), render);
	renderTexture.display();
}

void Layer::drawBrushLocally(Brush& brush, const sf::RenderStates& render) {
	renderTexture.draw(brush.getSprite(), render);
	renderTexture.display();
}

void Layer::drawBrush(Brush& brush, const sf::RenderStates& render) {
	brush.move(-getPosition());
	renderTexture.draw(brush.getSprite(), render);
	renderTexture.display();
	brush.move(getPosition());
}

void Layer::drawBrush(Brush& brush, sf::Vector2f position, const sf::RenderStates& render) {
	brush.setPosition(position - getPosition());
	renderTexture.draw(brush.getSprite(), render);
	renderTexture.display();
}

/////////////////
// SPRITE DRAW //
/////////////////
void Layer::drawSpriteLocaly(sf::Sprite& spr, sf::Vector2f position, const sf::RenderStates& render) {
	spr.setPosition(position);
	renderTexture.draw(spr, render);
	renderTexture.display();
}

void Layer::drawSpriteLocaly(const sf::Sprite& spr, const sf::RenderStates& render) {
	renderTexture.draw(spr, render);
	renderTexture.display();
}

void Layer::drawSprite(sf::Sprite& spr, const sf::RenderStates& render) {
	spr.move(-getPosition());
	renderTexture.draw(spr, render);
	renderTexture.display();
	spr.move(getPosition());
}

void Layer::drawSprite(sf::Sprite& spr, sf::Vector2f position, const sf::RenderStates& render) {
	spr.setPosition(position - getPosition());
	renderTexture.draw(spr, render);
	renderTexture.display();
}

////////////////
// VISIBILITY //
////////////////
void Layer::show() {
	visible = true;
	emit layerVisible();
}
void Layer::hide() {
	visible = false;
	emit layerUnvisible();
}

////////////
// SELECT //
////////////
void Layer::select() {
	emit layerSelected();
}
void Layer::unselect() {
	emit layerUnselected();
}

//////////
// DROP //
//////////
void Layer::drop() {
	dead = true;
	emit layerDropped();
}

void Layer::undrop() {
	dead = false;
	emit layerUndropped();
}

////////////////////
// TRANSFORMATION //
////////////////////
void Layer::setPosition(sf::Vector2f position) {
	sprite.setPosition(position);

	emit layerMoved(position);
}

void Layer::translate(sf::Vector2f translation) {
	sprite.move(translation);

	emit layerMoved(sprite.getPosition());
}

void Layer::setScale(sf::Vector2f scale) {
	sprite.setScale(scale.x, scale.y);

	sf::FloatRect bounds = sprite.getGlobalBounds();
	emit layerMoved(POS_RECT(bounds));
	emit layerScaled(SIZE_RECT(bounds));
}

void Layer::setRotation(float rotation) {
	sprite.setRotation(rotation);

	sf::FloatRect bounds = sprite.getGlobalBounds();
	emit layerMoved(POS_RECT(bounds));
	emit layerScaled(SIZE_RECT(bounds));
}