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
	panneau = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 401, 129, hauteur_c), NULL, sf::IntRect(131, 401, 129, hauteur_c));
	b_vignette = new CBoutonView(sprite.getTexture(), sf::IntRect(50, 4, 43, 26));
	
	b_oeil = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 401, 31, 31), sf::Vector2f(3, 0));
	auto fonction = new std::function<void(fonction_type)>([](fonction_type l) {static_cast<CCalque*>(l[0])->setVisible(!static_cast<CCalque*>(l[0])->isVisible()); });
	auto arguments = new fonction_type{ this };
	auto predicat = new std::function<int(fonction_type)>([](fonction_type l) {return static_cast<CCalque*>(l[0])->isVisible(); });
	b_oeil->setFonction(fonction);
	b_oeil->setPredicat(predicat);
	b_oeil->setArguments(arguments);

	panneau->addBouton(b_vignette);
	panneau->addBouton(b_oeil);

	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return _t == l[0]; }); panneau->setPredicatSwap(predicat);
	arguments = new fonction_type{ this }; panneau->setArguments(arguments);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {_t = static_cast<CCalque*>(l[0]); });
	panneau->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return !static_cast<CCalque*>(l[0])->isDead();});
	panneau->setPredicatScroll(predicat);

	panneau->group(GUI->getPanneauAboveCalque());
	if (nbrCalque() == 0)
	{
		GUI->getPanneauBelowCalque()->group(panneau);
		panneau->affectMoveGroup(new std::function<void(int, int)>([](int i_src, int i_dst)
		{
			i_src = CALQUE_LIST.size() - (i_src - CPanneau::whichPosition(GUI->getPanneauAboveCalque()));
			i_dst = CALQUE_LIST.size() - (i_dst - CPanneau::whichPosition(GUI->getPanneauAboveCalque()));
			CCalque* tmp = CALQUE_LIST[i_src];
			CALQUE_LIST.erase(CALQUE_LIST.begin() + i_src);
			CALQUE_LIST.insert(CALQUE_LIST.begin() + i_dst, tmp);
		}));
	}
	else
		panneau->setMoveGroup(calque_list[0]->panneau);
		
	//Création du ctrl-z / ctrl-y
	i_retour_type = -1;
	i_retour_image = -1;
	i_retour_pos = -1;

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