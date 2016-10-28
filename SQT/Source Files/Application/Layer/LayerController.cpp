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

	FOR_I (layer_list.size()) 
		delete layer_list.at<Layer*>(i);
	layer_list.clear();
}

////////////
// CREATE //
////////////
Layer& LayerController::createLayer() {
	sf::Image* image = new sf::Image();
	if (layer_list.size() == 0)
		image->create(500, 500, sf::Color::Transparent);
	else
		image->create(static_cast<Layer&>(layer_list.front()).getSize().x, static_cast<Layer&>(layer_list.front()).getSize().y, sf::Color::Transparent);

	Layer* layer = new Layer(*image);
	UNDO->push(*new LayerCreated(layer, *image));
	layer_list.push_back(*layer);

	_createLayer(*layer);
	return *layer;
}
Layer& LayerController::createLayer(sf::Image& image) {
	Layer* layer = new Layer(image);
	UNDO->push(*new LayerCreated(layer, image));
	layer_list.push_back(*layer);

	_createLayer(*layer);
	return *layer;
}

void LayerController::_createLayer(Layer& layer) {
	layer.undrop();
	selectLayer(layer);
}

//////////
// DROP //
//////////
void LayerController::dropLayer(Layer& layer) {
	UNDO->push(*new LayerDropped(&layer));

	_dropLayer(layer);
}

void LayerController::_dropLayer(Layer& layer) {
	layer.drop();
	selectLayer();
}

////////////
// SELECT //
////////////
void LayerController::selectLayer() {
	//Select down layer
	bool found = false;
	for (int i = positionList(*current_layer); i >= 0; i--)
		if (!layer_list.at<Layer*>(i)->isDropped()) {
			current_layer = layer_list.at<Layer*>(i);
			found = true;
			break;
		}
	//Select up layer
	if (!found)
		for (int i = positionList(*current_layer) + 1; i < layer_list.size(); i++)
			if (!layer_list.at<Layer*>(i)->isDropped()) {
				current_layer = layer_list.at<Layer*>(i);
				break;
			}

	current_layer->select();
	emit layerSelected(*current_layer);
	current_layer->emitStatus();
}

void LayerController::selectLayer(Layer& layer) {
	if (current_layer == &layer)
		return;

	Layer* ex_layer = current_layer;
	current_layer = &layer;

	if (ex_layer != NULL) {
		ex_layer->unselect();
		emit layerUnselected(*ex_layer);
	}
	current_layer->select();
	emit layerSelected(*current_layer);
	current_layer->emitStatus();
}

//////////
// FUSE //
//////////
void LayerController::fuseLayer(Layer& layer_src, Layer& layer_dst) {
	sf::Texture tex = layer_src.getTexture();
	sf::Sprite spr;
	spr.setPosition(layer_src.getPosition());
	spr.setTexture(tex, true);

	sf::Texture tex2 = layer_dst.getTexture();

	RES->getShader(nRer::fuse).setParameter("source", tex);
	RES->getShader(nRer::fuse).setParameter("background", tex2);
	RES->getShader(nRer::fuse).setParameter("position", spr.getPosition() - layer_dst.getPosition());

	layer_dst.drawSprite(spr, RES->getRender(nRer::fuse));
	
	UNDO->beginMacro();
	dropLayer(layer_src);
	layer_dst.update();
	UNDO->endMacro();
}

void LayerController::fuseLayer() {
	for (int i = positionList(*current_layer) - 1; i >= 0; i--)
		if (!layer_list.at<Layer*>(i)->isDropped()) {
			fuseLayer(*current_layer, *layer_list.at<Layer*>(i));
			break;
		}
}

///////////
// OTHER //
///////////
int LayerController::countLayer(bool count_dead) const {
	if (count_dead)
		return layer_list.size();

	int nbr = 0;
	FOR_I (layer_list.size())
		if (!layer_list.at<Layer*>(i)->isDropped())
			nbr++;
	return nbr;
}

int LayerController::positionList(const Layer& layer) const {
	auto it = std::find(layer_list.begin(), layer_list.end(), &layer);
	return  it - layer_list.begin();
}

const Layer& LayerController::firstLayer() const {
	FOR_I (layer_list.size())
		if (!layer_list.at<Layer*>(i)->isDropped())
			return *layer_list.at<Layer*>(i);

	// Unreachable
	return *layer_list.at<Layer*>(-1);
}