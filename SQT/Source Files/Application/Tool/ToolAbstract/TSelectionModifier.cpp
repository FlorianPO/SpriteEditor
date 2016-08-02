#include "TSelectionModifier.h"

#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

using namespace nSet;

void TSelectionModifier::display() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	std::vector<o_line>& lines = oriented_lines.getLines();
	FOR_I (lines.size()) {
		lines[i].line[0].color = color;
		lines[i].line[1].color = color;
		APP->getWindow().draw(lines[i].line);
	}
}

void TSelectionModifier::endSelection(nSet::FuseMode fuse_mode) {
	if (oriented_lines.size() > 0) {
		switch (fuse_mode) {
			case NO_FUSION:	SELEC->createSelection(oriented_lines.getBounds(), oriented_lines.getLines());
				break;
			case ADD: SELEC->addSelection(oriented_lines.getBounds(), oriented_lines.getLines());
				break;
			case SUB: SELEC->subSelection(oriented_lines.getBounds(), oriented_lines.getLines());
				break;
			case INTERSECT: SELEC->intersectSelection(oriented_lines.getBounds(), oriented_lines.getLines());
				break;
		}
		oriented_lines.clear();
	}
}

void TSelectionModifier::endSelection(nSet::FuseMode fuse_mode, const sf::Image& bit_image) {
	if (oriented_lines.size() > 0) {
		oriented_lines.moveLines(VECTOR2I(LAYER->getPosition()));
		switch (fuse_mode) {
			case 0:	SELEC->createSelection(oriented_lines.getBounds(), bit_image, oriented_lines.getLines());
				break;
			case 1: SELEC->addSelection(oriented_lines.getBounds(), bit_image, oriented_lines.getLines());
				break;
			case 2: SELEC->subSelection(oriented_lines.getBounds(), bit_image, oriented_lines.getLines());
				break;
			case 3: SELEC->intersectSelection(oriented_lines.getBounds(), bit_image, oriented_lines.getLines());
				break;
		}
		oriented_lines.clear();
	}
}