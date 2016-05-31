#include "Source Files/Application/Layer/LayerController.h"

#include "Source Files/Application/Layer/Layer.h"

CLayerController* CLayerController::_t;

void CLayerController::createLayer(sf::Texture* texture_var) {
	CLayer* layer;
	if (texture_var != NULL)
		layer = new CLayer(texture_var);
	else {
		sf::Image image; sf::Texture texture;
		if (layer_list.size() == 0)
			image.create(500, 500, sf::Color::Transparent);
		else
			image.create(layer_list.front()->getSize().x, layer_list.front()->getSize().y, sf::Color::Transparent);
		texture.loadFromImage(image);
		layer = new CLayer(&texture);
	}
	layer_list.push_back(layer);

	if (countLayer() == 1)
		emit onlyOneLayer();
	else
		emit moreThanOneLayer();

	emit layerCreated(layer);
	layer->show();
	selectLayer(layer);
}

void CLayerController::selectLayer(CLayer* layer) {
	CLayer* ex_layer = current_layer;
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

	if (ex_layer != current_layer) {
		if (ex_layer != NULL)
			ex_layer->unselect();
		current_layer->select();

		if (current_layer == firstLayer())
			emit firstLayerSelected(current_layer);
		else
			emit firstLayerUnselected(current_layer);
	}
}

void CLayerController::deleteLayer(CLayer* layer) {
	if (layer == NULL)
		layer = current_layer;	
	
	emit layerDeleted(layer);
	layer->drop();
	selectLayer();

	if (countLayer() == 1)
		emit onlyOneLayer();
	else
		emit moreThanOneLayer();
}

int CLayerController::countLayer(bool count_dead) {
	if (count_dead)
		return layer_list.size();

	int nbr = 0;
	for (int i=0; i < layer_list.size(); i++)
		if (!layer_list[i]->isDead())
			nbr++;
	return nbr;
}

int CLayerController::positionList(CLayer* layer) {
	for (int i=0; i < layer_list.size(); i++)
		if (layer == layer_list[i])
			return i;
	return 0;
}

CLayer* CLayerController::firstLayer() {
	for (int i=0; i < layer_list.size(); i++)
		if (!layer_list[i]->isDead())
			return layer_list[i];
	return NULL;
}

void CLayerController::fuseLayer(CLayer* layer_src, CLayer* layer_dst) {
	sf::Texture tex = layer_src->getRenderTexture()->getTexture();
	sf::Sprite spr;
	//sf::Sprite spr = layer_src->getSprite();
	//spr.move(-layer_src->getPosition());
	spr.setTexture(tex, true);

	sf::Texture tex2 = layer_dst->getRenderTexture()->getTexture();

	RES->getShader(CRes::fuse)->setParameter("source", tex);
	RES->getShader(CRes::fuse)->setParameter("background", tex2);
	RES->getShader(CRes::fuse)->setParameter("position", spr.getPosition());

	layer_dst->draw(spr, RES->getRender(RES->fuse), true);
	
	deleteLayer(layer_src);
	//RETOUR->add_retour({CALQUE_LIST[i], LAYER});
	//LAYER->creer_retour(NULL, CLayer::DEL);
	//CALQUE_LIST[i]->creer_retour(&CALQUE_LIST[i]->getRenderTexture()->getTexture().copyToImage(), CLayer::ACT);
}

void CLayerController::fuseLayer() {
	for (int i = positionList(current_layer)-1; i >= 0; i--)
		if (!layer_list[i]->isDead()) {
			fuseLayer(current_layer, layer_list[i]);
			break;
		}	
}