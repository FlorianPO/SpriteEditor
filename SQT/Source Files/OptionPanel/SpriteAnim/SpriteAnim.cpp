/*

#include "SpriteAnim.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "BoutonSwitch.h"
#include "BoutonDisplay.h"
#include "Source Files/Application/INPUT/InputController.h"

CSpriteAnim* SPRITE_ANIM;

bool CSpriteAnim::predicat_oeil(fonction_type l)
{
	int var = 0;
	for (int i = 0; i < 3; i++)
		var += SPRITE_ANIM->boutons_oeil[i]->getEtat();

	if (var == 3)
		return true;
	return false;
}

bool CSpriteAnim::predicat_sync(fonction_type l)
{
	int cpt = 0;
	for (int i = 0; i < 3; i++)
		if (SPRITE_ANIM->frame_list[i].size() > 0)
			cpt++;

	return cpt > 0;
}


CSpriteAnim::CSpriteAnim()
{
	std::function<int(fonction_type)>* predicat;
	std::function<int(fonction_type)>* predicat1;
	std::function<int(fonction_type)>* predicat2;
	std::function<void(fonction_type)>* fonction;
	std::function<void(fonction_type)>* fonction1;
	std::function<void(fonction_type)>* fonction2;
	fonction_type* arguments;

	panneau = new CPanneau(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(1, 1, 129, 102));

	all_numbers = new CBoutonDisplay(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(51, 127, 24, 24), sf::Vector2f(6, 75));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_numbers(l); }); all_numbers->setFonction(fonction);

	bouton_oeil = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(76, 127, 24, 24), sf::Vector2f(31, 75), CArg(true));
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CSpriteAnim::predicat_oeil(l); }); bouton_oeil->setPredicat(predicat);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_oeil(l); }); bouton_oeil->setFonction(fonction);

	bouton_sync = new CBoutonActive(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(26, 127, 24, 24), sf::Vector2f(56, 75));
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CSpriteAnim::predicat_sync(l); }); bouton_sync->setPredicat(predicat);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_sync(l); }); bouton_sync->setFonction(fonction);

	bouton_ombre = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(1, 127, 24, 24), sf::Vector2f(81, 75), CArg(true));

	bouton_chaine = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(115, 121, 13, 30), sf::Vector2f(107, 71), CArg(sf::IntRect(101, 121, 13, 30), CArg(true)));

	panneau->addBouton(all_numbers);
	panneau->addBouton(bouton_oeil);
	panneau->addBouton(bouton_sync);
	panneau->addBouton(bouton_ombre);
	panneau->addBouton(bouton_chaine);

	//Numéros
	predicat1 = new std::function<int(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->bouton_chaine->getEtat(); });
	predicat2 = new std::function<int(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->frame_list[*static_cast<int*>(l[0])].size() > 0; });
	fonction2 = new std::function<void(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->frame_list[*static_cast<int*>(l[0])].clear(); });

	for (int i = 0; i < 3; i++)
	{
		boutons_numero[i] = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(1 + i * 23, 104, 22, 22), sf::Vector2f(5, 2 + i * 23), CArg(false));
		boutons_numero[i]->addUnrefArg(i);
		boutons_frame[i] = new CBoutonSegment(RES->getTexture(ResourceController::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(31, 6 + i * 23), CArg(sf::Vector2i(1, 999), CArg(float(5))));
		boutons_frame[i]->setPredicatGroupe(predicat1);

		boutons_chrono[i] = new CBoutonDisplay(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(70, 104, 14, 14), sf::Vector2f(65, 6 + i * 23));
		boutons_rect[i] = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(85, 104, 14, 14), sf::Vector2f(80, 6 + i * 23), CArg(true));
		boutons_oeil[i] = new CBoutonSwitch(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(100, 104, 14, 14), sf::Vector2f(95, 6 + i * 23), CArg(true));
		boutons_del[i] = new CBoutonActive(RES->getTexture(ResourceController::TEXTURE::anim), sf::IntRect(115, 104, 14, 14), sf::Vector2f(110, 6 + i * 23));
		boutons_del[i]->addUnrefArg(i); boutons_del[i]->setPredicat(predicat2);
		boutons_del[i]->setFonction(fonction2);

		if (i == 0)
		{
			panneau->addBouton(boutons_numero[i]);
			panneau->addBouton(boutons_frame[i]);
			panneau->addBouton(boutons_chrono[i]);
			panneau->addBouton(boutons_rect[i]);
			panneau->addBouton(boutons_oeil[i]);
			panneau->addBouton(boutons_del[i]);
		}
		else
		{
			panneau->addBouton(boutons_rect[i], boutons_rect[i - 1]);
			panneau->addBouton(boutons_chrono[i], boutons_chrono[i - 1]);
			panneau->addBouton(boutons_numero[i], boutons_numero[i - 1], CBouton::GROUP::ONE_ALL);
			panneau->addBouton(boutons_frame[i], boutons_frame[i - 1], CBouton::GROUP::ONE_ALL);
			panneau->addBouton(boutons_oeil[i], boutons_oeil[i - 1]);
			panneau->addBouton(boutons_del[i], boutons_del[i - 1]);
		}
	}

	for (int i=0; i < 3; i++)
	{
		recteur_list[i].setOutlineThickness(1);
		recteur_list[i].setFillColor(sf::Color::Transparent);
	}

	recteur_list[0].setOutlineColor(sf::Color(255, 0, 0, 128));
	recteur_list[1].setOutlineColor(sf::Color(0, 255, 0, 128));
	recteur_list[2].setOutlineColor(sf::Color(0, 0, 255, 128));
				
	CHud::addMe(this);

	for (int i=0; i < 3; i++)
	{
		offset_list[i] = sf::Vector2f();
		zoom_list[i] = sf::Vector2f(1, 1);
	}
}

CSpriteAnim::~CSpriteAnim()
{
	delete panneau;
}

*/