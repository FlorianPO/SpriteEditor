#include "Source Files/Application/Tool/ToolAbstract/ToolColorModifier.h"

#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

void CToolColorModifier::setPointedColor(SignalColor* color) {
	color->setColor(CFonction::getColor(IO->getPixel() - LAYER->getPosition_i(), LAYER->getImage()));
}

void CToolColorModifier::setPointedColor(sf::Color* color) {
	*color = CFonction::getColor(IO->getPixel() - LAYER->getPosition_i(), LAYER->getImage());
}