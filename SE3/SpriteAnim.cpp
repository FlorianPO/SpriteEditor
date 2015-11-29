#include "SpriteAnim.h"
#include "Res.h"
#include "BoutonSwitch.h"
#include "BoutonDisplay.h"
#include "App.h"
#include "Calque.h"
#include "Fonction.h"
#include "Input.h"

CSpriteAnim* SPRITE_ANIM;

void CSpriteAnim::fonction_numbers(fonction_type l)
{
	for (int i = 0; i < 3; i++)
		if (SPRITE_ANIM->boutons_numero[i]->getEtat() == 0)
		{
			SPRITE_ANIM->boutons_numero[i]->update(true, true);
			SPRITE_ANIM->boutons_numero[i]->useFonction();
		}
}

bool CSpriteAnim::predicat_oeil(fonction_type l)
{
	int var = 0;
	for (int i = 0; i < 3; i++)
		var += SPRITE_ANIM->boutons_oeil[i]->getEtat();

	if (var == 3) return true;
	return false;
}


void CSpriteAnim::fonction_oeil(fonction_type l)
{
	if (SPRITE_ANIM->bouton_oeil->usePredicat())
		for (int i = 0; i < 3; i++)
			SPRITE_ANIM->boutons_oeil[i]->update(true, false);
	else
		for (int i = 0; i < 3; i++)
			SPRITE_ANIM->boutons_oeil[i]->update(true, true);
}

void CSpriteAnim::fonction_nbr(fonction_type l)
{
	if (*static_cast<int*>(l[0]) != 0)
	{
		std::function<void(fonction_type)>* fonction = new std::function<void(fonction_type)>([](fonction_type lp) {return SPRITE_ANIM->selecAnimation(*static_cast<int*>(lp[1])); });
		std::function<int(fonction_type)>* predicat = new std::function<int(fonction_type)>([](fonction_type lp) {return !bool(*static_cast<int*>(lp[0])); });
		fonction_type* arguments = new fonction_type();
		for (int i = 0; i < l.size(); i++)
			arguments->push_back(l[i]);
	}
}

bool CSpriteAnim::predicat_sync(fonction_type l)
{
	int cpt = 0;
	for (int i = 0; i < 3; i++)
		if (SPRITE_ANIM->frame_list[i].size() > 0)
			cpt++;

	return cpt > 0;
}

void CSpriteAnim::fonction_sync(fonction_type l)
{
	for (int i = 0; i < 3; i++)
		SPRITE_ANIM->tempo_list[i] = sf::Vector2i();
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

	panneau = new CPanneau(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(1, 1, 129, 102));

	all_numbers = new CBoutonDisplay(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(51, 127, 24, 24), sf::Vector2f(6, 75));
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_numbers(l); }); all_numbers->setFonction(fonction);

	bouton_oeil = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(76, 127, 24, 24), sf::Vector2f(31, 75), CArg(true));
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CSpriteAnim::predicat_oeil(l); }); bouton_oeil->setPredicat(predicat);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_oeil(l); }); bouton_oeil->setFonction(fonction);


	bouton_sync = new CBoutonActive(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(26, 127, 24, 24), sf::Vector2f(56, 75));
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return CSpriteAnim::predicat_sync(l); }); bouton_sync->setPredicat(predicat);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_sync(l); }); bouton_sync->setFonction(fonction);

	bouton_ombre = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(1, 127, 24, 24), sf::Vector2f(81, 75), CArg(true));

	bouton_chaine = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(115, 121, 13, 30), sf::Vector2f(107, 71), CArg(sf::IntRect(101, 121, 13, 30), CArg(true)));

	panneau->addBouton(all_numbers);
	panneau->addBouton(bouton_oeil);
	panneau->addBouton(bouton_sync);
	panneau->addBouton(bouton_ombre);
	panneau->addBouton(bouton_chaine);

	//Numéros
	predicat1 = new std::function<int(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->bouton_chaine->getEtat(); });
	predicat2 = new std::function<int(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->frame_list[*static_cast<int*>(l[0])].size() > 0; });
	fonction1 = new std::function<void(fonction_type)>([](fonction_type l) {return CSpriteAnim::fonction_nbr(l); });
	fonction2 = new std::function<void(fonction_type)>([](fonction_type l) {return SPRITE_ANIM->frame_list[*static_cast<int*>(l[0])].clear(); });

	for (int i = 0; i < 3; i++)
	{
		boutons_numero[i] = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(1 + i * 23, 104, 22, 22), sf::Vector2f(5, 2 + i * 23), CArg(false));
		boutons_numero[i]->setFonction(fonction1);
		boutons_numero[i]->addUnrefArg(i);
		boutons_frame[i] = new CBoutonSegment(RES->getTexture(CRes::TEXTURE::none), sf::IntRect(0, 0, 32, 14), sf::Vector2f(31, 6 + i * 23), CArg(sf::Vector2i(1, 999), CArg(float(5))));
		boutons_frame[i]->setPredicatGroupe(predicat1);

		boutons_chrono[i] = new CBoutonDisplay(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(70, 104, 14, 14), sf::Vector2f(65, 6 + i * 23));
		boutons_rect[i] = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(85, 104, 14, 14), sf::Vector2f(80, 6 + i * 23), CArg(true));
		boutons_oeil[i] = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(100, 104, 14, 14), sf::Vector2f(95, 6 + i * 23), CArg(true));
		boutons_del[i] = new CBoutonActive(RES->getTexture(CRes::TEXTURE::anim), sf::IntRect(115, 104, 14, 14), sf::Vector2f(110, 6 + i * 23));
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

	sf::RectangleShape rectangle; rectangle.setOutlineThickness(2); rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color(255, 0, 0, 128)); recteur_list[0] = rectangle;
	rectangle.setOutlineColor(sf::Color(0, 255, 0, 128)); recteur_list[1] = rectangle;
	rectangle.setOutlineColor(sf::Color(0, 0, 255, 128)); recteur_list[2] = rectangle;

}

CSpriteAnim::~CSpriteAnim()
{
	delete panneau;
}

void CSpriteAnim::selecAnimation(int i)
{
	static unsigned ex_frame = 0;

	if (APP->whichFrame() != ex_frame)
	{
		ex_frame = APP->whichFrame();
		img = CALQUE->getTexture()->copyToImage();
		result = searchAnimation(&img, IO->getPixel() - CALQUE->getPosition_i());
	}

	recteur_list[i].setSize(sf::Vector2f(result.rect.width, result.rect.height));

	frame_list[i].clear();
	tempo_list[i] = sf::Vector2i();
	view_sprites[i].setTexture(*CALQUE->getTexture(), true);

	sf::IntRect r_tmp = result.rect;
	for (int j = 0; j < result.nbr_anim; j++)
	{
		frame_list[i].push_back(r_tmp); //Rectangle de la frame
		r_tmp.left += r_tmp.width + 1;
	}
}

void CSpriteAnim::afficher() {}

CSpriteAnim::type_anim CSpriteAnim::searchAnimation(sf::Image* i_src, sf::Vector2i p_ini)
{
	if (!CFonction::onCalque(p_ini, i_src))
		return type_anim{ sf::IntRect(), 0 };

	sf::Vector2i p_tmp;
	int var1, var2 = 0;
	int taille_xl = 0, taille_xr = 0, taille_yl = 0, taille_yr = 0;

	p_tmp = p_ini; //LEFT
	while (true)
		if (i_src->getPixel(p_tmp.x, p_tmp.y) != sf::Color::Magenta)
		{
			if (p_tmp.x <= 0) break;
			p_tmp.x -= 1;
			taille_xl++;
		}
		else break;

	var1 = p_tmp.x;
	p_tmp = p_ini; //RIGHT
	int cpt = 0;
	while (true)
		if (i_src->getPixel(p_tmp.x, p_tmp.y) != sf::Color::Magenta)
		{
			if (p_tmp.x >= i_src->getSize().x - 1) break;
			p_tmp.x += 1;
			if (var2 == 0)
				taille_xr++;
			else
			{
				cpt++;
				if (cpt > taille_xr + taille_xl)
					break;
			}
		}
		else
		{
			p_tmp.x += 1;
			var2++;
			cpt = 0;
		}

	p_tmp = p_ini; //DOWN
	while (true)
		if (i_src->getPixel(p_tmp.x, p_tmp.y) != sf::Color::Magenta)
		{
			if (p_tmp.y >= i_src->getSize().y - 1) break;
			p_tmp.y += 1;
			taille_yr++;
		}
		else break;

	p_tmp = p_ini; //UP
	while (true)
		if (i_src->getPixel(p_tmp.x, p_tmp.y) != sf::Color::Magenta)
		{
			if (p_tmp.y <= 0) break;
			p_tmp.y -= 1;
			taille_yl++;
		}
		else break;

	return type_anim{ sf::IntRect(var1 + 1, p_tmp.y + 1, taille_xl + taille_xr - 1, taille_yl + taille_yr - 1), var2 };
}