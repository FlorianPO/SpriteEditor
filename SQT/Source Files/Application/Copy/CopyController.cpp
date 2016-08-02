#include "CopyController.h"

#include "CopyUndo.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

CopyController* CopyController::_t;

CopyController::CopyController() {
	using namespace nInt;
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::CTRL + Qt::Key_C), this, SLOT(copy()));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::CTRL + Qt::Key_X), this, SLOT(cut()));
	SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::CTRL + Qt::Key_V), this, SLOT(paste()));
}

//////////
// COPY //
//////////
void CopyController::copy() {
	if (SELEC->isSelected()) {
		sf::IntRect cadre = SELEC->getCadre();

		cadre.left -= LAYER->getPosition().x;
		cadre.top -= LAYER->getPosition().y;
		if (Fonction::checkCadre(&cadre, sf::IntRect(sf::Vector2i(), VECTOR2I(LAYER->getTexture().getSize()))))
			return;

		copy_position = sf::Vector2f(cadre.left, cadre.top) + LAYER->getPosition();

		sf::Texture texture;
		texture.loadFromImage(LAYER->getTexture().copyToImage(), cadre);

		sf::RenderTexture renderTexture; renderTexture.create(cadre.width, cadre.height);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();

		sf::Texture tex = renderTexture.getTexture();
		RES->getShader(nRer::cut).setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
		RES->getShader(nRer::cut).setParameter("offset_image", sf::Vector2f(cadre.left, cadre.top));
		RES->getShader(nRer::cut).setParameter("background", tex);

		sf::Sprite spr(texture);
		renderTexture.draw(spr, RES->getRender(nRer::cut));
		renderTexture.display();

		Fonction::copy_to_clipboard(&renderTexture.getTexture().copyToImage());
	}
}

/////////
// CUT //
/////////
void CopyController::cut() {
	copy();
	SELEC->deleteLayer();
}

///////////
// PASTE //
///////////
void CopyController::paste() {
	UNDO->beginMacro();
	if (COPY != NULL)
		applyCopy();
	else if (SELEC->isSelected())
		SELEC->deleteSelection();

	sf::Image* image = Fonction::get_clipboard();
	if (image == NULL)
		return;

	createCopy(*image, copy_position);
	UNDO->endMacro();

	delete image;
}

////////////
// CREATE //
////////////
void CopyController::createCopy(const sf::Image& image, sf::Vector2f position) {
	Copy* copy = new Copy(image, position);
	copy_list.push_back(copy);

	UNDO->push(new CopyCreated(copy, position));

	_createCopy(copy);
}

void CopyController::_createCopy(Copy* copy) {
	emit copyCreated(copy);

	using namespace nInt;
	space_shortcut_id = SHORTCUT_CONTROLLER->createShortcut(QKeySequence(Qt::Key_Space), this, SLOT(applyCopy()));
	shift_core_shortcut_id = SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::Key_Shift, DOUBLE_TAP), FUNCTION(COPY_CONTROLLER->dropCopy(COPY)));

	zqsd_core_shortcut_id[0] = SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_Z, LOG), FUNCTION(COPY->keyMove(0, -1)));
	zqsd_core_shortcut_id[1] = SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_S, LOG), FUNCTION(COPY->keyMove(0, 1)));
	zqsd_core_shortcut_id[2] = SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_Q, LOG), FUNCTION(COPY->keyMove(-1, 0)));
	zqsd_core_shortcut_id[3] = SHORTCUT_CONTROLLER->createCoreShortcut(keyCombinaison(Qt::SHIFT + Qt::Key_D, LOG), FUNCTION(COPY->keyMove(1, 0)));

	current_copy = copy;
}

////////////
// DELETE //
////////////
void CopyController::deleteCopy(Copy* copy) {
	if (copy != NULL) {
		emit copyDeleted(copy);

		copy_list.erase(std::find(copy_list.begin(), copy_list.end(), copy));
		delete copy;
	}
}

void CopyController::applyCopy(Copy* copy) {
	sf::Texture tex = COPY->getTexture();
	sf::Sprite spr = COPY->getSprite();
	spr.setTexture(tex, true);

	sf::Texture tex2 = LAYER->getTexture();

	RES->getShader(nRer::fuse).setParameter("source", tex);
	RES->getShader(nRer::fuse).setParameter("background", tex2);
	RES->getShader(nRer::fuse).setParameter("position", spr.getPosition());

	LAYER->drawSprite(spr, RES->getRender(nRer::fuse));
	
	apply_position = spr.getPosition();

	UNDO->beginMacro();
	dropCopy(copy);
	LAYER->update();
	UNDO->endMacro();
}

//////////
// DROP //
//////////
void CopyController::dropCopy(Copy* copy) {
	if (copy != NULL) {
		UNDO->push(new CopyDropped(copy));
		_dropCopy(copy);
	}
}

void CopyController::_dropCopy(Copy* copy) {
	emit copyDropped(copy);

	if (current_copy == copy)
		current_copy = NULL;
	SHORTCUT_CONTROLLER->removeShortcut(space_shortcut_id);
	SHORTCUT_CONTROLLER->removeCoreShortcut(shift_core_shortcut_id);
	FOR_I (4)
		SHORTCUT_CONTROLLER->removeCoreShortcut(zqsd_core_shortcut_id[i]);
}