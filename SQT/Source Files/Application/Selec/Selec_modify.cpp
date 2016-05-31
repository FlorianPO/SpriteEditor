#include "Source Files/Application/Selec/Selec.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Res/Res.h"

///////////
// SLOTS //
///////////

void CSelec::createSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l) {
	createSelection(rect, NULL);
	conf_lines = conf_l;
	update_cadre();

	emit selectionCreated();
}

void CSelec::createSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l) {
	createSelection(rect, &image);
	conf_lines = conf_l;
	update_cadre();

	emit selectionCreated();
}

void CSelec::createSelection(sf::IntRect rect, const sf::Image* image) {
	renderTexture_selec.create(rect.width + 2, rect.height + 2);
	renderTexture_selec.clear(ident_color);
	sprite_selec.setPosition(rect.left - 1, rect.top - 1);

	sf::Texture texture;
	if (image == NULL) {
		sf::Image img; img.create(rect.width, rect.height, blend_color);
		texture.loadFromImage(img);
	}
	else {
		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - LAYER->getPosition_i(),
			sf::Vector2i(rect.width, rect.height)));
	}

	sf::Sprite spr(texture); spr.setPosition(1, 1);
	renderTexture_selec.draw(spr, sf::BlendNone);
	renderTexture_selec.display();
	refresh = true;
	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::deleteSelection() {
	if (isSelected()) {
		if (inverted == true)
			emit selectionUninverted();
		del();
		emit selectionDeleted();
	}
}

void CSelec::addSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l) {
	sumSelection(rect, NULL, true);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(1);
}

void CSelec::addSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l) {
	sumSelection(rect, &image, true);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(1);
}

void CSelec::subSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l) {
	sumSelection(rect, NULL, false);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(2);
}

void CSelec::subSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l) {
	sumSelection(rect, &image, false);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(2);
}

void CSelec::sumSelection(sf::IntRect rect, const sf::Image* image, bool add) {
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
			RES->getShader(CRes::update)->setParameter("mode", 1); //Add
		else
			RES->getShader(CRes::update)->setParameter("mode", 2); //Sub
		RES->getShader(CRes::update)->setParameter("offset", sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - LAYER->getPosition_i(),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("brosse", texture);
		RES->getShader(CRes::update)->setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, *RES->getRender(CRes::update));
	}
	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}

void CSelec::intersectSelection(sf::IntRect rect, const std::vector<CTool::line_conf>& conf_l) {
	intersectSelection(rect, NULL);

	for (int i = conf_lines.size() - 1; i >= 0; i--)
		if (!rect.contains(conf_lines[i].x, conf_lines[i].y))
			conf_lines.erase(conf_lines.begin() + i);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(3);
}

void CSelec::intersectSelection(sf::IntRect rect, const sf::Image& image, const std::vector<CTool::line_conf>& conf_l) {
	intersectSelection(rect, &image);

	for (int i = conf_lines.size() - 1; i >= 0; i--)
		if (!rect.contains(conf_lines[i].x, conf_lines[i].y))
			conf_lines.erase(conf_lines.begin() + i);

	conf_lines.insert(conf_lines.end(), conf_l.begin(), conf_l.end());
	reline();
	update_cadre();

	emit selectionUpdated(3);
}

void CSelec::invertSelection() {
	if (!inverted == true)
		if (isSelected()) {
			inverted = true;
			invert();

			emit selectionInverted();
		}
}

void CSelec::uninvertSelection() {
	if (!inverted == false)
		if (isSelected()) {
			inverted = false;
			invert();

			emit selectionUninverted();
		}
}

void CSelec::intersectSelection(sf::IntRect rect, const sf::Image* image) {
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

		RES->getShader(CRes::update)->setParameter("mode", 3);
		RES->getShader(CRes::update)->setParameter("offset", sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("texture", renderTexture_selec.getTexture());

		texture.loadFromImage(*image, sf::IntRect(sf::Vector2i(rect.left, rect.top) - LAYER->getPosition_i(),
			sf::Vector2i(rect.width, rect.height)));

		sf::Vector2f vect = sf::Vector2f(rect.left, rect.top);
		spr.setTexture(texture, true); spr.setPosition(vect - sprite_selec.getPosition());
		RES->getShader(CRes::update)->setParameter("brosse", texture);
		RES->getShader(CRes::update)->setParameter("pos_brosse", vect);

		renderTexture_selec.draw(spr, *RES->getRender(CRes::update));
	}

	renderTexture_selec.display();
	refresh = true;

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
}