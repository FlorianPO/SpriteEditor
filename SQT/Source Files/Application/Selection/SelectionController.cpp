#include "SelectionController.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

#include "Source Files/Application/App.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Application/Queue/QueueController.h"

using namespace nSet;

SelectionController* SelectionController::_t;

SelectionController::SelectionController() {
	RES->getShader(nRer::cut).setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(nRer::invert).setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(nRer::update).setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(nRer::usual).setParameter("texture", renderTexture_selec.getTexture());
	RES->getShader(nRer::pot).setParameter("texture", renderTexture_selec.getTexture());

	using namespace nInt;
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_Z, LOG), [this](){keyMove(sf::Vector2f(0, -1));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_S, LOG), [this](){keyMove(sf::Vector2f(0, 1));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_Q, LOG), [this](){keyMove(sf::Vector2f(-1, 0));});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_D, LOG), [this](){keyMove(sf::Vector2f(1, 0));});

	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Shift, DOUBLE_TAP), [this](){deleteSelection();});
	SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Delete, AGAIN), [this](){deleteLayer();});
}

//////////
// FREE //
//////////
void SelectionController::freeWork() {
	UNDO->beginFirst();
	deleteSelection(true);
	UNDO->endFirst();
}

bool SelectionController::reline() {
	if (isSelected()) {
		sf::Vector2f pos = sprite_selec.getPosition();

		FOR_I_INV (pos_lines->lines.size())
			switch (pos_lines->lines[i].orient) {
				case UP:
					if (image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y - 1 - pos.y).a == image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y - pos.y).a)
						pos_lines->lines.erase(pos_lines->lines.begin() + i);
					break;
				case RIGHT:
					if (image_selec->getPixel(pos_lines->lines[i].x + 1 - pos.x, pos_lines->lines[i].y - pos.y).a == image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y - pos.y).a)
						pos_lines->lines.erase(pos_lines->lines.begin() + i);
					break;
				case DOWN:
					if (image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y + 1 - pos.y).a == image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y - pos.y).a)
						pos_lines->lines.erase(pos_lines->lines.begin() + i);
					break;
				case LEFT:
					if (image_selec->getPixel(pos_lines->lines[i].x - 1 - pos.x, pos_lines->lines[i].y - pos.y).a == image_selec->getPixel(pos_lines->lines[i].x - pos.x, pos_lines->lines[i].y - pos.y).a)
						pos_lines->lines.erase(pos_lines->lines.begin() + i);
					break;
		}

		if (pos_lines->lines.size() > 0)
			updateCadre();
		else {
			delete pos_lines;
			deleteSelection(true);
			return true;
		}
	}
	return false;
}

void SelectionController::del() {
	pos_lines = NULL;

	setInverted(false);

	renderTexture_selec.create(1, 1);
	renderTexture_selec.clear(blend_color);
	renderTexture_selec.display();

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	image_selec = NULL;

	emit selectionDeleted();
}

void SelectionController::updateCadre() {
	cadre = sf::IntRect(sprite_selec.getPosition().x + 1, sprite_selec.getPosition().y + 1, sprite_selec.getTextureRect().width - 2, sprite_selec.getTextureRect().height - 2);

	emit selectionMoved(POS_RECT(cadre));
	emit selectionScaled(SIZE_RECT(cadre));
}

void SelectionController::invert() {
	sf::Texture texture = renderTexture_selec.getTexture();
	renderTexture_selec.draw(sf::Sprite(texture), RES->getRender(nRer::invert));
	renderTexture_selec.display();

	sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
	image_selec = new sf::Image(renderTexture_selec.getTexture().copyToImage());
}

void SelectionController::deleteLayer() {
	if (isSelected()) {
		RES->getShader(nRer::pot).setParameter("offset", getPosition() - LAYER->getPosition());
		RES->getShader(nRer::pot).setParameter("background", LAYER->getTexture());
		RES->getShader(nRer::pot).setParameter("couleur", sf::Color::Transparent);
		RES->getShader(nRer::pot).setParameter("mode", 1.f);

		sf::Texture texture = LAYER->getTexture();
		sf::Sprite sprite = sf::Sprite(texture);
		LAYER->drawSpriteLocaly(sprite, sf::Vector2f(0, 0), RES->getRender(nRer::pot));
		LAYER->update();
	}
}

void SelectionController::updateLines() {
	if (isSelected() && pos_lines->pos != getPosition()) {
		sf::Vector2f delta_move = getPosition() - pos_lines->pos;
		FOR_I (pos_lines->lines.size()) {
			pos_lines->lines[i].line[0].position.x += delta_move.x;
			pos_lines->lines[i].line[1].position.x += delta_move.x;
			pos_lines->lines[i].line[0].position.y += delta_move.y;
			pos_lines->lines[i].line[1].position.y += delta_move.y;

			pos_lines->lines[i].x += delta_move.x;
			pos_lines->lines[i].y += delta_move.y;
		}
		pos_lines->pos += delta_move;
	}
}

void SelectionController::setSelection(sf::Image* image, sf::Vector2f position, nSet::positionned_olines* plines, bool invert) {
	if (image != NULL) {
		sprite_selec.setPosition(position);
		setImage(image);
		setInverted(invert);
		setLines(plines);

		updateCadre();	
	}
	else
		del();
}

void SelectionController::setImage(sf::Image* image) {
	if (image_selec != image) {	
		sf::Texture texture = sf::Texture();
		texture.loadFromImage(*image);

		if (texture.getSize() == renderTexture_selec.getSize()) {
			renderTexture_selec.draw(sf::Sprite(texture), sf::BlendNone);
			renderTexture_selec.display();
			sprite_selec.setTexture(renderTexture_selec.getTexture());
		}
		else {
			renderTexture_selec.create(texture.getSize().x, texture.getSize().y);
			renderTexture_selec.draw(sf::Sprite(texture), sf::BlendNone);
			renderTexture_selec.display();
			sprite_selec.setTexture(renderTexture_selec.getTexture(), true);
		}
		image_selec = image;
	}
}

void SelectionController::setLines(nSet::positionned_olines* plines) {
	if (pos_lines != plines) {
		if (pos_lines == NULL)
			emit selectionCreated();

		pos_lines = plines;
		QUEUE->beforeDisplay(this, "updateLines");
	}
}

void SelectionController::setInverted(bool inverted) {
	if (inverted != this->inverted) {
		this->inverted = inverted;
		if (inverted)
			emit selectionInverted();
		else
			emit selectionUninverted();
	}
}

void SelectionController::translate(const sf::Vector2f& translation) {
	sprite_selec.move(translation);
	updateCadre();
	QUEUE->beforeDisplay(this, "updateLines");
}

void SelectionController::setPosition(const sf::Vector2f& pos) {
	sprite_selec.setPosition(pos);
	updateCadre();
	QUEUE->beforeDisplay(this, "updateLines");
}

void SelectionController::setRealPosition(const sf::Vector2f& real_pos) {
	setPosition(sf::Vector2f(real_pos.x-1, real_pos.y-1));
}

sf::Vector2f SelectionController::getRealPosition() const {
	sf::Vector2f pos = sprite_selec.getPosition();
	return sf::Vector2f(pos.x+1, pos.y+1);
}

void SelectionController::displayLines() {
	if (isSelected()) {
		sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
		FOR_I (pos_lines->lines.size()) {
			pos_lines->lines[i].line[0].color = color;
			pos_lines->lines[i].line[1].color = color;
			APP->getWindow().draw(pos_lines->lines[i].line);
		}
	}
}