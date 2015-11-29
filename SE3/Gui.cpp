#include "Gui.h"
#include "SpriteAnim.h"
#include "BoutonDisplay.h"
#include "Arg.h"
#include "Res.h"
#include "BoutonActive.h"
#include "Var.h"
#include "Input.h"
#include "Selec.h"
#include "App.h"
#include "OptionColor.h"
#include "Retour.h"
#include "Copy.h"

CGui* GUI;

bool CGui::predicat_1(fonction_type l)
{
	if (OUTIL != NULL)
		return OUTIL->numero_outil == *static_cast<COutil::outil_enum*>(l[0]);

	return false;
}

void CGui::fonction_6_shape(fonction_type l) { if (*static_cast<int*>(l[0]) != BROSSE->which_brosse) BROSSE->changeBrosse(*static_cast<int*>(l[0])); }

void CGui::fonction_8_1(fonction_type l)
{
	int nbr = 0;
	for (int i = 0; i<CALQUE_LIST.size(); i++)
		nbr += !CALQUE_LIST[i]->isDead();
	if (nbr > 1)
	{
		RETOUR_VECTOR.push_back(CALQUE);
		RETOUR->add_retour();
		CALQUE->creer_retour(NULL, CCalque::DEL);
	}
}

void CGui::fonction_8_2(fonction_type l)
{
	for (int i = CALQUE->getNumero() - 1; i >= 0; i--)
		if (!CALQUE_LIST[i]->isDead())
		{
			sf::Texture tex = CALQUE->getRenderTexture()->getTexture();
			sf::Sprite spr = *CALQUE->getSprite();
			spr.move(-CALQUE_LIST[i]->getPosition());
			spr.setTexture(tex, true);

			sf::Texture tex2 = CALQUE_LIST[i]->getRenderTexture()->getTexture();

			RES->getShader(CRes::fuse)->setParameter("source", tex);
			RES->getShader(CRes::fuse)->setParameter("background", tex2);
			RES->getShader(CRes::fuse)->setParameter("position", spr.getPosition());

			CALQUE_LIST[i]->getRenderTexture()->draw(spr, RES->getShader(CRes::fuse));
			CALQUE_LIST[i]->getRenderTexture()->display();

			RETOUR_VECTOR.push_back(CALQUE); RETOUR_VECTOR.push_back(CALQUE_LIST[i]);
			RETOUR->add_retour();

			CALQUE->creer_retour(NULL, CCalque::DEL);
			CALQUE_LIST[i]->creer_retour(&CALQUE_LIST[i]->getRenderTexture()->getTexture().copyToImage(), CCalque::ACT);

			break;
		}
}

CGui::CGui(void)
{
	sf::IntRect rect; sf::Vector2f pos;
	std::function<int(fonction_type)>* predicat;
	std::function<void(fonction_type)>* fonction;
	std::function<void(fonction_type)>* fonction1;
	std::function<void(fonction_type)>* fonction2;
	fonction_type* arguments;

	//Part 1 // OUTILS
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CGui::predicat_1(l); });
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return COutil::chooseOutil(*static_cast<COutil::outil_enum*>(l[0])); });
	panneau_1 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 1, 129, 78));
	for (int i = 0; i < 15; i++)
	{
		if (i < 5)
		{
			rect = sf::IntRect(1 + i * 24, 301, 23, 23);
			pos = sf::Vector2f(5 + i * 24, 5);
		}
		else if (i < 10)
		{
			rect = sf::IntRect(1 + (i - 5) * 24, 325, 23, 23);
			pos = sf::Vector2f(5 + (i - 5) * 24, 29);
		}
		else
		{
			rect = sf::IntRect(1 + (i - 10) * 24, 349, 23, 23);
			pos = sf::Vector2f(5 + (i - 10) * 24, 53);
		}

		boutons_1[i] = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), rect, pos);

		boutons_1[i]->setPredicat(predicat);
		boutons_1[i]->setFonction(fonction);
		boutons_1[i]->addUnrefArg(i);

		if (i > 0) panneau_1->addBouton(boutons_1[i], boutons_1[i - 1]);
		else panneau_1->addBouton(boutons_1[i]);
	}

	//Part2 // ANIM_SELEC
	panneau_2 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 80, 129, 21), panneau_1);

	bouton_2_sprite = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 102, 69, 18), sf::Vector2f(5, 1), CArg(false));
	bouton_2_tile = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 121, 48, 18), sf::Vector2f(76, 1), CArg(false));

	panneau_2->addBouton(bouton_2_sprite);
	panneau_2->addBouton(bouton_2_tile, bouton_2_sprite);

	//Part3 // ANIM
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return GUI->bouton_2_sprite->getEtat(); });
	SPRITE_ANIM->getPanneau()->group(panneau_2);
	SPRITE_ANIM->getPanneau()->setPredicatScroll(predicat);

	//Part 4 // COLOR
	panneau_4 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(131, 1, 129, 165), SPRITE_ANIM->getPanneau());

	bouton_4_color_1[4] = new CBoutonDisplay(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 59, 59), sf::Vector2f(4, 1));
	bouton_4_color_2[4] = new CBoutonDisplay(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 59, 59), sf::Vector2f(66, 65));

	fonction1 = new std::function<void(fonction_type)>([](fonction_type l) {return GUI->bouton_4_color_1[4]->setColor(VAR->color1);});
	fonction2 = new std::function<void(fonction_type)>([](fonction_type l) {return GUI->bouton_4_color_2[4]->setColor(VAR->color2);});
	for (int i = 0; i < 4; i++)
	{
		bouton_4_color_1[i] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 49, 14), sf::Vector2f(64, 1 + 15 * i));
		bouton_4_color_2[i] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 49, 14), sf::Vector2f(16, 65 + 15 * i));

		if (i == 0)
		{
			panneau_4->addBouton(bouton_4_color_1[i]);
			panneau_4->addBouton(bouton_4_color_2[i]);
		}
		else
		{
			panneau_4->addBouton(bouton_4_color_1[i], bouton_4_color_1[i - 1]);
			panneau_4->addBouton(bouton_4_color_2[i], bouton_4_color_2[i - 1]);
		}

		bouton_4_color_1[i]->setFonction(fonction1);
		bouton_4_color_2[i]->setFonction(fonction2);

		arguments = new fonction_type();
		if (i == 0) arguments->push_back(&VAR->color1.r);
		else if (i == 1) arguments->push_back(&VAR->color1.g);
		else if (i == 2) arguments->push_back(&VAR->color1.b);
		else arguments->push_back(&VAR->color1.a);

		bouton_4_color_1[i]->setArguments(arguments);

		arguments = new fonction_type();
		if (i == 0) arguments->push_back(&VAR->color2.r);
		else if (i == 1) arguments->push_back(&VAR->color2.g);
		else if (i == 2) arguments->push_back(&VAR->color2.b);
		else arguments->push_back(&VAR->color2.a);

		bouton_4_color_2[i]->setArguments(arguments);
	}
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return COptionColor::create_opt_Color(&VAR->color1); }); 
	bouton_4_color_1[4]->setFonction(fonction);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return COptionColor::create_opt_Color(&VAR->color2); });
	bouton_4_color_2[4]->setFonction(fonction);
	panneau_4->addBouton(bouton_4_color_1[4]);
	panneau_4->addBouton(bouton_4_color_2[4]);

	bouton_4_opacite = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(5, 129), CArg(sf::Vector2i(1, 255)));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return BROSSE->changeOpacity(); }); bouton_4_opacite->setFonction(fonction);

	bouton_4_seuil = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(5, 148), CArg(sf::Vector2i(1, 255)));
	panneau_4->addBouton(bouton_4_opacite);
	panneau_4->addBouton(bouton_4_seuil);
	arguments = new fonction_type{ &VAR->opacity }; bouton_4_opacite->setArguments(arguments);
	arguments = new fonction_type{ &VAR->seuil }; bouton_4_seuil->setArguments(arguments);

	//Part 6 // OUITL_SIZE
	panneau_6 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 1, 129, 75), panneau_4);

	bouton_6_x = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(5, 2), CArg(sf::Vector2i(1, 999)));
	bouton_6_y = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(38, 2), CArg(sf::Vector2i(1, 999)));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return BROSSE->changeBrosse(BROSSE->which_brosse); });
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return GUI->bouton_6_chaine->getEtat(); });
	bouton_6_x->setPredicatGroupe(predicat); bouton_6_y->setPredicatGroupe(predicat);
	bouton_6_x->setFonction(fonction);
	bouton_6_y->setFonction(fonction);
	arguments = new fonction_type{ &BROSSE->size.x }; bouton_6_x->setArguments(arguments);
	arguments = new fonction_type{ &BROSSE->size.y }; bouton_6_y->setArguments(arguments);

	panneau_6->addBouton(bouton_6_x);
	panneau_6->addBouton(bouton_6_y, bouton_6_x, CBouton::GROUP::ONE_ALL);

	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CGui::fonction_6_shape(l); });
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return BROSSE->which_brosse == *static_cast<int*>(l[0]); });

	for (int i = 0; i<5; i++)
	{
		boutons_6_shape[i] = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1 + i * 24, 277, 23, 23), sf::Vector2f(5 + i * 24, 17), CArg(sf::Color::Red));

		boutons_6_shape[i]->setFonction(fonction);
		boutons_6_shape[i]->setPredicat(predicat);
		boutons_6_shape[i]->addUnrefArg(i);

		if (i == 0) panneau_6->addBouton(boutons_6_shape[i]);
		else panneau_6->addBouton(boutons_6_shape[i], boutons_6_shape[i - 1]);
	}

	bouton_6_chaine = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(121, 383, 30, 13), sf::Vector2f(83, 2), CArg(sf::IntRect(152, 383, 30, 13), CArg(true)));
	panneau_6->addBouton(bouton_6_chaine);

	bouton_6_posx = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(5, 58), CArg(sf::Vector2i(INT_MIN, INT_MAX)));
	bouton_6_posy = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 49, 14), sf::Vector2f(65, 58), CArg(sf::Vector2i(INT_MIN, INT_MAX)));

	arguments = new fonction_type{ IO->getRefPos_x() }; bouton_6_posx->setArguments(arguments);
	arguments = new fonction_type{ IO->getRefPos_y() }; bouton_6_posy->setArguments(arguments);

	panneau_6->addBouton(bouton_6_posx);
	panneau_6->addBouton(bouton_6_posy);

	//Part 7 // POSITION
	panneau_7 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 77, 129, 47), panneau_6);

	boutons_7[0] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(5, 15), CArg(sf::Vector2i(INT_MIN, INT_MAX)));
	arguments = new fonction_type{ SELEC->getRefLeft() }; boutons_7[0]->setArguments(arguments);
	boutons_7[1] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(65, 15), CArg(sf::Vector2i(INT_MIN, INT_MAX)));
	arguments = new fonction_type{ SELEC->getRefTop() }; boutons_7[1]->setArguments(arguments);
	boutons_7[2] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(5, 30), CArg(sf::Vector2i(0, INT_MAX)));
	arguments = new fonction_type{ SELEC->getRefWidth() }; boutons_7[2]->setArguments(arguments);
	boutons_7[3] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(65, 30), CArg(sf::Vector2i(0, INT_MAX)));
	arguments = new fonction_type{ SELEC->getRefHeight() }; boutons_7[3]->setArguments(arguments);

	for (int i = 0; i < 4; i++)
		panneau_7->addBouton(boutons_7[i]);

	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return SELEC->isSelected() || GUI->isReplacing(); });
	panneau_7->setPredicatScroll(predicat);

	//Part COPY

	panneau_copy = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(391, 84, 129, 47), panneau_7);
	boutons_copy[0] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(5, 15), CArg(sf::Vector2i(INT_MIN, INT_MAX)));
	arguments = new fonction_type{ COPY->getRefLeft() }; boutons_copy[0]->setArguments(arguments);
	boutons_copy[1] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(65, 15), CArg(sf::Vector2i(INT_MIN, INT_MAX)));
	arguments = new fonction_type{ COPY->getRefTop() }; boutons_copy[1]->setArguments(arguments);
	boutons_copy[2] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(5, 30), CArg(sf::Vector2i(0, INT_MAX)));
	arguments = new fonction_type{ COPY->getRefWidth() }; boutons_copy[2]->setArguments(arguments);
	boutons_copy[3] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 57, 14), sf::Vector2f(65, 30), CArg(sf::Vector2i(0, INT_MAX)));
	arguments = new fonction_type{ COPY->getRefHeight() }; boutons_copy[3]->setArguments(arguments);

	for (int i = 0; i < 4; i++)
		panneau_copy->addBouton(boutons_copy[i]);

	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return COPY != NULL; });
	panneau_copy->setPredicatScroll(predicat);

	//Part 8 // FONCTIONS
	panneau_8 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 125, 129, 28), panneau_copy);
	CBouton* boutons_8_fonction[5];

	boutons_8_fonction[0] = new CBoutonDisplay(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 373, 23, 23), sf::Vector2f(5, 1));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CCalque::new_calque(NULL); }); boutons_8_fonction[0]->setFonction(fonction);

	boutons_8_fonction[1] = new CBoutonActive(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1 + 1 * 24, 373, 23, 23), sf::Vector2f(5 + 1 * 24, 1));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return fonction_8_1(l); }); boutons_8_fonction[1]->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CCalque::nbrCalque() > 1; }); boutons_8_fonction[1]->setPredicat(predicat);

	boutons_8_fonction[2] = new CBoutonActive(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1 + 2 * 24, 373, 23, 23), sf::Vector2f(5 + 2 * 24, 1));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return fonction_8_2(l); }); boutons_8_fonction[2]->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return !CCalque::isFirst(); }); boutons_8_fonction[2]->setPredicat(predicat);

	boutons_8_fonction[3] = new CBoutonActive(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1 + 3 * 24, 373, 23, 23), sf::Vector2f(5 + 3 * 24, 1), CArg(sf::IntRect(121, 359, 23, 23)));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return SELEC->inverser_selec(); }); boutons_8_fonction[3]->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return SELEC->isSelected(); }); boutons_8_fonction[3]->setPredicat(predicat);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return SELEC->isInverted(); }); static_cast<CBoutonActive*>(boutons_8_fonction[3])->setPredicatActive(predicat);

	boutons_8_fonction[4] = new CBoutonActive(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1 + 4 * 24, 373, 23, 23), sf::Vector2f(5 + 4 * 24, 1));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return SELEC->delete_selec(); }); boutons_8_fonction[4]->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return SELEC->isSelected(); }); boutons_8_fonction[4]->setPredicat(predicat);

	for (int i = 0; i<5; i++)
		panneau_8->addBouton(boutons_8_fonction[i]);

	panneau_9 = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(25, 397, 129, 3));

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// HUD
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	CHud::addMe(this);

	f_afficher = new std::function<void(void)>([]() {
		GUI->panneau_1->afficher();
		GUI->panneau_2->afficher();
		SPRITE_ANIM->getPanneau()->afficher();
		GUI->panneau_4->afficher();
		GUI->panneau_6->afficher();
		GUI->panneau_7->afficher();
		GUI->panneau_copy->afficher();
		GUI->panneau_8->afficher();
		GUI->panneau_9->afficher();

		for (int i = 0; i < CALQUE_LIST.size(); i++)
			CALQUE_LIST[i]->getPanneau()->afficher();
	});

	f_position = new std::function<void(void)>([]() {
		GUI->panneau_1->setPosition(APP->getPositionCamera(2) - sf::Vector2f(GUI->panneau_1->getSprite()->getGlobalBounds().width, 0));
	});
}

CGui::~CGui(void)
{
	delete panneau_1;
	delete panneau_2;
	delete panneau_4;
	delete panneau_6;
	delete panneau_7;
	delete panneau_copy;
	delete panneau_8;
	delete panneau_9;

	CHud::killMe(this);
}

void CGui::zoom(float z)
{
	panneau_1->zoom(z);
	panneau_2->zoom(z);
	SPRITE_ANIM->getPanneau()->zoom(z);
	panneau_4->zoom(z);
	panneau_6->zoom(z);
	panneau_7->zoom(z);
	panneau_8->zoom(z);
	panneau_copy->zoom(z);
	panneau_9->zoom(z);

	for (int i = 0; i < CALQUE_LIST.size(); i++)
		CALQUE_LIST[i]->getPanneau()->zoom(z);
}

void CGui::gerer()
{
	panneau_1->gerer();
	panneau_2->gerer();
	SPRITE_ANIM->getPanneau()->gerer();
	panneau_4->gerer();
	panneau_6->gerer();
	panneau_7->gerer();
	panneau_copy->gerer();
	panneau_8->gerer();
	panneau_9->gerer();

	for (int i = 0; i < CALQUE_LIST.size(); i++)
		CALQUE_LIST[i]->getPanneau()->gerer();
}

bool CGui::test()
{
	if (GUI->panneau_1->test() || GUI->panneau_2->test() || SPRITE_ANIM->getPanneau()->test() || GUI->panneau_4->test()
		|| GUI->panneau_6->test() || GUI->panneau_7->test() || panneau_copy->test() || GUI->panneau_8->test()
		|| GUI->panneau_9->test())
		return true;
	for (int i = 0; i < CALQUE_LIST.size(); i++)
		if (CALQUE_LIST[i]->getPanneau()->test())
			return true;

	return false;
}

void CGui::update()
{
	panneau_1->update();
	panneau_2->update();
	SPRITE_ANIM->getPanneau()->update();
	panneau_4->update();
	panneau_6->update();
	panneau_7->update();
	panneau_copy->update();
	panneau_8->update();
	panneau_9->update();

	for (int i = 0; i < CALQUE_LIST.size(); i++)
		CALQUE_LIST[i]->getPanneau()->update();
}

void CGui::replaceCadre(sf::IntRect* cadre)
{
	replacing = true;
	boutons_7[0]->replaceArgument(new fonction_type{ &cadre->left });
	boutons_7[1]->replaceArgument(new fonction_type{ &cadre->top });
	boutons_7[2]->replaceArgument(new fonction_type{ &cadre->width });
	boutons_7[3]->replaceArgument(new fonction_type{ &cadre->height });
}

void CGui::cancelCadreReplacement()
{
	replacing = false;
	boutons_7[0]->cancelArgumentReplacement();
	boutons_7[1]->cancelArgumentReplacement();
	boutons_7[2]->cancelArgumentReplacement();
	boutons_7[3]->cancelArgumentReplacement();
}