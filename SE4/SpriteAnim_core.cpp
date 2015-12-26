#include "SpriteAnim.h"
#include "App.h"
#include "Calque.h"
#include "Input.h"
#include "Fonction.h"

void CSpriteAnim::fonction_numbers(fonction_type l)
{
	bool var = false;
	for (int i = 0; i < 3; i++)
		if (SPRITE_ANIM->boutons_numero[i]->getEtat() == 0)
		{
			var = true;
			SPRITE_ANIM->boutons_numero[i]->update(true, true);
		}
	if (var)
		SPRITE_ANIM->getPanneau()->draw();
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

void CSpriteAnim::fonction_sync(fonction_type l)
{
	for (int i = 0; i < 3; i++)
		if (SPRITE_ANIM->frame_list[i].size() > 0)
		{
			SPRITE_ANIM->view_sprites[i].setTextureRect(SPRITE_ANIM->frame_list[i][0]);
			SPRITE_ANIM->cpt_list[i] = sf::Vector2i();
		}	
}

bool CSpriteAnim::busy()
{
	for (int i=0; i < 3; i++)
		if (boutons_numero[i]->getEtat())
			return true;

	return false;
}

void CSpriteAnim::selecAnimation(int i)
{
	recteur_list[i].setSize(sf::Vector2f(result.rect.width, result.rect.height));

	frame_list[i].clear();
	cpt_list[i] = sf::Vector2i();
	view_sprites[i].setTexture(*CALQUE->getTexture(), true);

	sf::IntRect r_tmp = result.rect;
	for (int j = 0; j < result.nbr_anim; j++)
	{
		frame_list[i].push_back(r_tmp); //Rectangle de la frame
		r_tmp.left += r_tmp.width + 1;
	}

	view_sprites[i].setTextureRect(frame_list[i][0]);
	view_sprites[i].setOrigin(0, view_sprites[i].getTextureRect().height);
	recteur_list[i].setSize(sf::Vector2f(frame_list[i][0].width+2, frame_list[i][0].height+2));
}

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

void CSpriteAnim::zoom(float z)
{
	for (int i=0; i < 3; i++)
		if (frame_list[i].size() > 0)
			view_sprites[i].setScale(z, z);
}

void CSpriteAnim::update()
{
	for (int i=0; i < 3; i++)
		if (frame_list[i].size() > 0)
		{
			cpt_list[i].y++;
			if (cpt_list[i].y >= boutons_frame[i]->getValeur())
			{
				cpt_list[i].y = 0;
				cpt_list[i].x++;
				if (cpt_list[i].x >= frame_list[i].size())
					cpt_list[i].x = 0;

				view_sprites[i].setTextureRect(frame_list[i][cpt_list[i].x]);
				recteur_list[i].setSize(sf::Vector2f(frame_list[i][cpt_list[i].x].width+2, frame_list[i][cpt_list[i].x].height+2));
			}
		}

	if (busy() && !CHud::onHud()) //SELECTION
	{
		if (IO->again(CInput::MLeft))
		{
			result = searchAnimation(CALQUE->getImage(), IO->getPixel() - CALQUE->getPosition_i());
			if (result.nbr_anim > 0)
				for (int i=0; i < 3; i++)
					if (boutons_numero[i]->getEtat())
						selecAnimation(i);
		}
		else if (IO->released(CInput::MLeft))
		{
			for (int i = 0; i < 3; i++)
				if (boutons_numero[i]->getEtat() == 1)
					boutons_numero[i]->update(true, false);
			panneau->draw();
		}
	}
}

void CSpriteAnim::gerer()
{
}

bool CSpriteAnim::test()
{
	for (int i=0; i < 3; i++)
		if (frame_list[i].size() > 0)
			if (CFonction::onSprite(&view_sprites[i]))
				return true;
	return false;
}

void CSpriteAnim::position()
{
	for (int i=2; i >=0; i--)
		if (frame_list[i].size() > 0)
		{
			view_sprites[i].setPosition(APP->getPositionCamera(4) + offset_list[i]);
			recteur_list[i].setPosition(frame_list[i][cpt_list[i].x].left-1, frame_list[i][cpt_list[i].x].top-1);
		}
			
}

void CSpriteAnim::afficher()
{
	for (int i=2; i >=0; i--)
		if (frame_list[i].size() > 0)
		{
			if (boutons_oeil[i]->getEtat())
				APP->fenetre.draw(view_sprites[i]);
			if (boutons_rect[i]->getEtat())
				APP->fenetre.draw(recteur_list[i]);
		}
			
}