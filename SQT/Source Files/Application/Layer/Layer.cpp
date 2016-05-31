#include "Source Files/Application/Layer/Layer.h"

#include "Source Files/Retour/Retour.h"
#include "Source Files/Application/App.h"

CLayer::CLayer(sf::Texture* texture_var) {
	name = QString::fromStdString(std::to_string(LAYER_CONTROLLER->countLayer() + 1));

	//Image
	renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
	update(texture_var);
	sprite.setTexture(renderTexture.getTexture());

	//Création du setPointedColor-z / setPointedColor-y
	//RETOUR->add_retour({this});

	//creer_retour(NULL, CRE);
	//creer_retour(&getImage(), ACT);
}

sf::Image& CLayer::getImage() {
	if (refresh) {
		image_buffer = renderTexture.getTexture().copyToImage();
		refresh = false;
	}
	return image_buffer;
}

void CLayer::draw_brush(CBrush& brush, sf::Vector2f pos, sf::RenderStates* render) {
	brush.setPosition(pos - getPosition());
	draw(brush.getSprite(), render);
}

void CLayer::draw(const sf::Sprite& spr, sf::RenderStates* render, bool no_retour) {
	if (render != NULL)
		renderTexture.draw(spr, *render);
	else
		renderTexture.draw(spr);
	renderTexture.display();
	
	if (!no_retour)
		changed = true;
	refresh = true;
}

void CLayer::update(sf::Texture* texture_var) {
	if (texture_var->getSize() == renderTexture.getSize()) {
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
	}
	else {
		renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);
	}
	refresh = true;
}

void CLayer::display() {
	if (!dead && visible)
		APP->fenetre->draw(sprite);	
}

////////////////
// VISIBILITY //
////////////////
void CLayer::show() {
	visible = true;
	emit layerVisible();
}
void CLayer::hide() {
	visible = false;
	emit layerUnvisible();
}

////////////
// SELECT //
////////////
void CLayer::select() {
	emit layerSelected();
}
void CLayer::unselect() {
	emit layerUnselected();
}

/////////////
// DEELETE //
/////////////
void CLayer::drop() {
	dead = true;
}