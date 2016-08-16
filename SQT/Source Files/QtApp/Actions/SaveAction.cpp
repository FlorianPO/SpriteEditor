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
			total_rect = LAYER_LIST[i]->getGlobalBounds();
			inited = true;
		}
		else if (LAYER_LIST[i]->isVisible() && !LAYER_LIST[i]->isDead())
			total_rect = Fonction::unionRect(total_rect, LAYER_LIST[i]->getGlobalBounds());
	
	sf::RenderTexture render_texture = sf::RenderTexture();
	render_texture.create(ARG_SIZE(total_rect));
	render_texture.clear(sf::Color::Transparent);

	FOR_I (LAYER_LIST.size())
		if (LAYER_LIST[i]->isVisible() && !LAYER_LIST[i]->isDead()) {
			sf::Texture tmp = LAYER_LIST[i]->getTexture(); // This is mandatory
			Fonction::fuseTexture(render_texture, tmp, LAYER_LIST[i]->getPosition() - POS_RECT(total_rect));
		}
	
	render_texture.getTexture().copyToImage().saveToFile("test.png");
}