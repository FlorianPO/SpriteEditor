#include "SaveAction.h"

#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Fonction/Fonction.h"

SaveAction::SaveAction() : QAction("Enregistrer", NULL) {
	QObject::connect(this, SIGNAL(triggered()), this, SLOT(save()));

	setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
}

void SaveAction::save() {
	sf::IntRect total_rect;
	bool inited = false;
	FOR_I (LAYER_LIST.size())
		if (!inited) {
			total_rect = LAYER_LIST.at<Layer*>(i)->getGlobalBounds();
			inited = true;
		}
		else if (LAYER_LIST.at<Layer*>(i)->isVisible() && !LAYER_LIST.at<Layer*>(i)->isDropped())
			total_rect = Fonction::unionRect(total_rect, LAYER_LIST.at<Layer*>(i)->getGlobalBounds());
	
	sf::RenderTexture render_texture = sf::RenderTexture();
	render_texture.create(ARG_SIZE(total_rect));
	render_texture.clear(sf::Color::Transparent);

	FOR_I (LAYER_LIST.size())
		if (LAYER_LIST.at<Layer*>(i)->isVisible() && !LAYER_LIST.at<Layer*>(i)->isDropped()) {
			sf::Texture tmp = LAYER_LIST.at<Layer*>(i)->getTexture(); // This is mandatory
			Fonction::fuseTexture(render_texture, tmp, LAYER_LIST.at<Layer*>(i)->getPosition() - POS_RECT(total_rect));
		}
	
	render_texture.getTexture().copyToImage().saveToFile("test.png");
}