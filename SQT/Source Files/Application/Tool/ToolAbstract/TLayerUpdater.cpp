#include "TLayerUpdater.h"

#include "Source Files\Application\Input\InputController.h"
#include "Source Files\Application\Layer\LayerController.h"
#include "Source Files\Application\Layer\Layer.h"

bool TLayerUpdater::layer_changed;

void TLayerUpdater::checkLayerUpdate(bool force) {
	if (layer_changed || force) {
		LAYER->update();
		layer_changed = false;
	}
}