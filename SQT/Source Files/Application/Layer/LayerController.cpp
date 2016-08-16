#include "LayerController.h"

#include "stdenum.h"
#include "Layer.h"
#include "LayerUndo.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

LayerController* LayerController::_t;

//////////
// FREE //
//////////
void LayerController::freeWork() {
	if (current_layer != NULL)
		current_layer = NULL;

	FOR_I (layer_list.size()) {
		emit layerDeleted(layer_list[i]);
		delete layer_list[i];
	}
	layer_list.clear();
}

////////////
// CREATE //
////////////
void LayerController::createLayer(sf::Image* image) {
	Layer* layer;
	if (image == NULL) {
		image = new sf::Image();
		if (layer_list.size() == 0)
			image->create(500, 500, sf::Color::Transparent);
		else
			image->create(layer_list.front()->getSize().x, layer_list.front()->getSize().y, sf::Color::Transparent);
	}
	layer = new Layer(image);

	UNDO->push(new LayerCreated(layer, image));

	layer_list.push_back(layer);
	emit layerCreated(layer);

	_createLayer(layer);
}

void LayerController::_createLayer(Layer* layer) {
	layer->undrop();
	selectLayer(layer);

	if (countLayer() == 1)
		emit onlyOneLayer();
	else
		emit moreThanOneLayer();
}

////////////
// DELETE //
////////////
void LayerController::deleteLayer(Layer* layer) {
	emit layerDeleted(layer);

	layer_list.erase(std::find(layer_list.begin(), layer_list.end(), layer));
	delete layer;

	if (countLayer() == 1)
		emit onlyOneLayer();
	else
		emit moreThanOneLayer();
}

//////////
// DROP //
//////////
void LayerController::dropLayer(Layer* layer) {
	UNDO->push(new LayerDropped(layer));

	_dropLayer(layer);
}

void LayerController::_dropLayer(Layer* layer) {
	layer->drop();
	selectLayer();

	if (countLayer() == 1)
		emit onlyOneLayer();
	else
		emit moreThanOneLayer();
}

////////////
// SELECT //
////////////
void LayerController::selectLayer(Layer* layer) {
	if (current_layer == layer)
		return;

	Layer* ex_layer = current_layer;
	if (layer == NULL) {
		//Select down layer
		bool found = false;
		for (int i = positionList(current_layer); i >= 0; i--)
			if (!layer_list[i]->isDead()) {
				current_layer = layer_list[i];
				found = true;
				break;
			}
		//Select up layer
		if (!found)
			for (int i = positionList(current_layer) + 1; i < layer_list.size(); i++)
				if (!layer_list[i]->isDead()) {
					current_layer = layer_list[i];
					break;
				}
	}
	else
		current_layer = layer;

	if (ex_layer != NULL) {
		ex_layer->unselect();
		emit layerUnselected(ex_layer);
	}
	current_layer->select();
	emit layerSelected(current_layer);
	current_layer->emitStatus();

	if (current_layer == firstLayer())
		emit firstLayerSelected(current_layer);
	else
		emit firstLayerUnselected(current_layer);
}

//////////
// FUSE //
//////////
void LayerController::fuseLayer(Layer* layer_src, Layer* layer_dst) {
	sf::Texture tex = layer_src->getTexture();
	sf::Sprite spr;
	spr.setPosition(layer_src->getPosition());
	spr.setTexture(tex, true);

	sf::Texture tex2 = layer_dst->getTexture();

	RES->getShader(nRer::fuse).setParameter("source", tex);
	RES->getShader(nRer::fuse).setParameter("background", tex2);
	RES->getShader(nRer::fuse).setParameter("position", spr.getPosition() - layer_dst->getPosition());

	layer_dst->drawSprite(spr, RES->getRender(nRer::fuse));
	
	UNDO->beginMacro();
	dropLayer(layer_src);
	layer_dst->update();
	UNDO->endMacro();
}

void LayerController::fuseLayer() {
	for (int i = positionList(current_layer) - 1; i >= 0; i--)
		if (!layer_list[i]->isDead()) {
			fuseLayer(current_layer, layer_list[i]);
			break;
		}
}

///////////
// OTHER //
///////////
int LayerController::countLayer(bool count_dead) {
	if (count_dead)
		return layer_list.size();

	int nbr = 0;
	FOR_I (layer_list.size())
		if (!layer_list[i]->isDead())
			nbr++;
	return nbr;
}

int LayerController::positionList(Layer* layer) {
	std::vector<Layer*>::iterator it = std::find(layer_list.begin(), layer_list.end(), layer);
	return  it-layer_list.begin();
}

Layer* LayerController::firstLayer() {
	FOR_I (layer_list.size())
		if (!layer_list[i]->isDead())
			return layer_list[i];
	return NULL;
}

///////////
// ORDER //
///////////
void LayerController::orderLayer(int src, int dst) {
	UNDO->push(new LayerOrdered(src, dst));

	Layer* layer_src = layer_list[src];
	layer_list.erase(layer_list.begin() + src);
	layer_list.insert(layer_list.begin() + dst, layer_src);

	if (current_layer == firstLayer())
		emit firstLayerSelected(current_layer);
	else
		emit firstLayerUnselected(current_layer);
}

void LayerController::_orderLayer(int src, int dst) {
	Layer* layer_src = layer_list[src];
	layer_list.erase(layer_list.begin() + src);
	layer_list.insert(layer_list.begin() + dst, layer_src);

	emit layerOrdered(src, dst);

	if (current_layer == firstLayer())
		emit firstLayerSelected(current_layer);
	else
		emit firstLayerUnselected(current_layer);
}