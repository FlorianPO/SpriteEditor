#include "SelectionController.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "SelectionUndo.h"

////////////
// CREATE //
////////////
void SelectionController::createSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l) {
	createSelection(rect, NULL);
	setInverted(false);

	pos_lines = new nSet::positionned_lines();
	pos_lines->lines = std::vector<nSet::o_line>(conf_l);
	pos_lines->pos = getPosition();
	updateCadre();

	UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
	emit selectionCreated();
}

void SelectionController::createSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l) {
	createSelection(rect, &image);
	setInverted(false);

	pos_lines = new nSet::positionned_lines();
	pos_lines->lines = std::vector<nSet::o_line>(conf_l);
	pos_lines->pos = getPosition();
	updateCadre();

	UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
	emit selectionCreated();
}

void SelectionController::createSelection(sf::IntRect rect, const sf::Image* image) {
	renderTexture_selec.create(rect.width + 2, rect.height + 2);
	renderTexture_selec.clear(ident_color);
	sprite_selec.setPosition(rect.left - 1, rect.top - 1);

	sf::Texture texture;
	if (image == NULL) {
		sf::Image img;
		img.create(rect.width, rect.height, blend_color);
		texture.loadFromImage(img);
	}
	else {
		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - VECTOR2I(LAYER->getPosition()),
			sf::Vector2i(rect.width, rect.height)));
	}

	sf::Sprite spr(texture); spr.setPosition(1, 1);
	renderTexture_selec.draw(spr, sf::BlendNone);
	renderTexture_selec.display();
	
	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	image_selec = new sf::Image(renderTexture_selec.getTexture().copyToImage());
}

////////////
// DELETE //
////////////
void SelectionController::deleteSelection(bool force) {
	if (force || isSelected()) {
		del();

		UNDO->push(new SelecDeleted(this));
	}
}

/////////
// ADD //
/////////
void SelectionController::addSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		sumSelection(rect, NULL, true);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();
	
		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(1);
		}	
	}
	else
		createSelection(rect, conf_l);
}

void SelectionController::addSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		sumSelection(rect, &image, true);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();

		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(1);
		}
	}
	else
		createSelection(rect, image, conf_l);
}

/////////
// SUB //
/////////
void SelectionController::subSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		sumSelection(rect, NULL, false);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();

		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(2);
		}
	}
}

void SelectionController::subSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		sumSelection(rect, &image, false);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();

		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(2);
		}
	}
}

void SelectionController::sumSelection(sf::IntRect rect, const sf::Image* image, bool add) {
	float min_x = std::min(rect.left, cadre.left);
	float min_y = std::min(rect.top, cadre.top);

	sf::Texture texture = *sprite_selec.getTexture();
	sf::Sprite spr(texture);

	sprite_selec.setPosition(min_x - 1, min_y - 1);
	renderTexture_selec.create(std::max(rect.left + rect.width, cadre.left + cadre.width) - min_x + 2,
							   std::max(rect.top + rect.height, cadre.top + cadre.height) - min_y + 2);

	if (!inverted)
		renderTexture_selec.clear(ident_color);
	else
		renderTexture_selec.clear(blend_color);

	spr.setPosition(cadre.left - min_x, cadre.top - min_y);
	renderTexture_selec.draw(spr, sf::BlendNone);

	renderTexture_selec.display();

	if (image == NULL) {
		sf::Image img;
		if (add)
			img.create(rect.width, rect.height, blend_color);
		else
			img.create(rect.width, rect.height, ident_color);
		texture.loadFromImage(img);

		spr.setTexture(texture, true); spr.setPosition(rect.left - min_x + 1, rect.top - min_y + 1);
		renderTexture_selec.draw(spr, sf::BlendNone);
	}
	else {
		if (add)
			RES->getShader(nRer::update).setParameter("mode", 1); //Add
		else
			RES->getShader(nRer::update).setParameter("mode", 2); //Sub
		RES->getShader(nRer::update).setParameter("offset", sprite_selec.getPosition());
		RES->getShader(nRer::update).setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - VECTOR2I(LAYER->getPosition()),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(nRer::update).setParameter("brosse", texture);
		RES->getShader(nRer::update).setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, RES->getRender(nRer::update));
	}
	renderTexture_selec.display();

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	image_selec = new sf::Image(renderTexture_selec.getTexture().copyToImage());
}

///////////////
// INTERSECT //
///////////////
void SelectionController::intersectSelection(sf::IntRect rect, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		intersectSelection(rect, static_cast<sf::Image*>(NULL));
		setInverted(false);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		FOR_I_INV (pos_lines->lines.size())
			if (!rect.contains(pos_lines->lines[i].x, pos_lines->lines[i].y))
				pos_lines->lines.erase(pos_lines->lines.begin() + i);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();
	
		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(3);
		}
	}
	else
		createSelection(rect, conf_l);
}

void SelectionController::intersectSelection(sf::IntRect rect, const sf::Image& image, const std::vector<nSet::o_line>& conf_l) {
	if (isSelected()) {
		intersectSelection(rect, &image);
		setInverted(false);

		pos_lines = new nSet::positionned_lines(*pos_lines);
		FOR_I_INV (pos_lines->lines.size())
			if (!rect.contains(pos_lines->lines[i].x, pos_lines->lines[i].y))
				pos_lines->lines.erase(pos_lines->lines.begin() + i);
		pos_lines->lines.insert(pos_lines->lines.end(), conf_l.begin(), conf_l.end());
		pos_lines->pos = getPosition();
	
		if (!reline()) {
			UNDO->push(new SelecUpdated(this, image_selec, pos_lines->pos, pos_lines, inverted));
			emit selectionUpdated(3);
		}
	}
	else
		createSelection(rect, image, conf_l);
}

void SelectionController::intersectSelection(sf::IntRect rect, const sf::Image* image) {
	sf::Texture texture = *sprite_selec.getTexture();
	sf::Sprite spr(texture, sf::IntRect(rect.left - cadre.left + 1, rect.top - cadre.top + 1, rect.width, rect.height));

	sprite_selec.setPosition(rect.left - 1, rect.top - 1);
	renderTexture_selec.create(rect.width + 2, rect.height + 2);
	renderTexture_selec.clear(ident_color);

	if (image == NULL) {
		spr.setPosition(1, 1);
		renderTexture_selec.draw(spr, sf::BlendMultiply);
	}
	else {
		spr.setPosition(1, 1);
		renderTexture_selec.draw(spr, sf::BlendNone);

		RES->getShader(nRer::update).setParameter("mode", 3);
		RES->getShader(nRer::update).setParameter("offset", sprite_selec.getPosition());
		RES->getShader(nRer::update).setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - VECTOR2I(LAYER->getPosition()),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(nRer::update).setParameter("brosse", texture);
		RES->getShader(nRer::update).setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, RES->getRender(nRer::update));
	}

	renderTexture_selec.display();

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	image_selec = new sf::Image(renderTexture_selec.getTexture().copyToImage());
}

////////////
// INVERT //
////////////
void SelectionController::invertSelection() {
	if (isSelected())
		if (!inverted == true) {
			setInverted(true);
			invert();

			UNDO->push(new SelecInverted(this, image_selec, inverted));
			emit selectionInverted();
		}
}

void SelectionController::uninvertSelection() {
	if (isSelected())
		if (!inverted == false) {
			setInverted(false);
			invert();

			UNDO->push(new SelecInverted(this, image_selec, inverted));
			emit selectionUninverted();
		}
}