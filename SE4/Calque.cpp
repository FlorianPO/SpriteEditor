#include "Calque.h"

#include "BoutonSwitch.h"
#include "Writter.h"
#include "Retour.h"
#include "Input.h"
#include "Var.h"
#include "App.h"
#include "Curseur.h"
#include "BoutonView.h"
#include "Gui.h"
#include "Fonction.h"

CCalque* CALQUE;
std::vector<CCalque*> CALQUE_LIST;

CCalque::CCalque(sf::Texture* texture_var)
{
	_t = this;

	//Nom
	nom = "Calque " + std::to_string(nbrCalque() + 1);
	renderNom.create(88, 31);
	WRITTER->ecrire(nom, &renderNom, sf::Vector2i(0, 10), sf::Color::Transparent);
	sprite_nom.setTexture(renderNom.getTexture());

	//Image
	renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
	update(texture_var);
	sprite.setTexture(renderTexture.getTexture());

	//Gui
	GuiConstructor();
		
	//Création du ctrl-z / ctrl-y
	RETOUR->add_retour({this});

	creer_retour(NULL, CRE);
	creer_retour(getImage(), ACT);
}

CCalque::~CCalque(void)
{
	delete panneau;
}

int CCalque::getNumero()
{
	for (int i = 0; i < calque_list.size(); i++)
		if (this == calque_list[i])
			return i;
	return 0;
}

sf::Image* CCalque::getImage()
{
	if (refresh)
	{
		image_buffer = renderTexture.getTexture().copyToImage();
		refresh = false;
	}
	return &image_buffer;
}

void CCalque::draw_brosse(sf::Vector2f pos, sf::RenderStates* render)
{
	BROSSE->setPosition(pos - CCalque::_t->getPosition());
	draw(BROSSE->getSprite(), render);
}

void CCalque::draw(sf::Sprite* spr, sf::RenderStates* render, bool no_retour)
{
	if (render != NULL)
		renderTexture.draw(*spr, *render);
	else
		renderTexture.draw(*spr);
	renderTexture.display();

	if (!no_retour)
		changed = true;
	refresh = true;
}

void CCalque::update(sf::Texture* texture_var)
{
	if (texture_var->getSize() == renderTexture.getSize())
	{
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
	}
	else
	{
		renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);
	}
	refresh = true;
}

void CCalque::afficher()
{
	if (!dead && visible)
		APP->fenetre.draw(sprite);	
}