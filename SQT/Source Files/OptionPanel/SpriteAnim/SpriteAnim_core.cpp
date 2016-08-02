/*

#include "SpriteAnim.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/INPUT/InputController.h"
#include "Source Files/Fonction/Fonction.h"


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
	view_sprites[i].setTexture(*LAYER->getTexture(), true);

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
	if (!Fonction::onCalque(p_ini, i_src))
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
		{
			view_sprites[i].setScale(z, z);
			view_sprites[i].scale(zoom_list[i]);
		}
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
	if (!CHud::onHud(this))
		if (busy()) //SELECTION
		{
			if (INPUT->again(Qt::LeftButton))
			{
				result = searchAnimation(LAYER->getImage(), INPUT->getPixel() - VECTOR2I(LAYER->getPosition()));
				if (result.nbr_anim > 0)
					for (int i=0; i < 3; i++)
						if (boutons_numero[i]->getEtat())
							selecAnimation(i);
			}
			else if (INPUT->released(Qt::LeftButton))
			{
				for (int i = 0; i < 3; i++)
					if (boutons_numero[i]->getEtat() == 1)
						boutons_numero[i]->update(true, false);
				panneau->draw();
			}
		}
		else
		{
			if (!INPUT->pressed(Qt::RightButton))
				moving = 0;
			if (moving > 0)
				offset_list[moving-1] -= sf::Vector2f(INPUT->getDeltaScreen().x, INPUT->getDeltaScreen().y);
			
			if (!INPUT->pressed(Qt::LeftButton))
				scaling = 0;
			if (scaling > 0)
				zoom_me(scaling-1);
		}
}

void CSpriteAnim::zoom_me(int i)
{
	sf::Vector2f temp = Fonction::selecPointRect(view_sprites[i].getPosition(), sf::Vector2f(INPUT->getPosition().x, INPUT->getPosition().y), 2).distance;
	sf::Vector2f dist_ini = posm_click - view_sprites[i].getPosition();
	sf::Vector2f scale = sf::Vector2f(temp.x/dist_ini.x, temp.y/dist_ini.y);

	zoom_list[i] = sf::Vector2f(scale.x * scal_click.x, scale.y * scal_click.y);
	view_sprites[i].scale(zoom_list[i]);
}

void CSpriteAnim::gerer()
{
	if (!CHud::onHud(this))
		if (moving == 0 && scaling == 0)
			for (int i=0; i < 3; i++)
				if (frame_list[i].size() > 0 && boutons_oeil[i]->getEtat())
					if (Fonction::mouseOnSprite(&view_sprites[i]))
						if (INPUT->pressed(Qt::RightButton))
						{
							moving = i+1;
							break;
						}
						else if (INPUT->pressed(Qt::LeftButton))
						{
							scaling = i+1;
							posm_click = Fonction::selecPointRect(view_sprites[i].getPosition(), sf::Vector2f(INPUT->getPosition().x, INPUT->getPosition().y), 2).distance;
							scal_click = zoom_list[i];
							break;
						}
						
}

bool CSpriteAnim::test()
{
	for (int i=0; i < 3; i++)
		if (frame_list[i].size() > 0 && boutons_oeil[i]->getEtat())
			if (Fonction::mouseOnSprite(&view_sprites[i]))
				return true;
	return moving > 0 || scaling > 0;
}

void CSpriteAnim::position()
{
	for (int i=2; i >=0; i--)
		if (frame_list[i].size() > 0)
		{
			view_sprites[i].setPosition(APP->getPositionCamera(4) + sf::Vector2f(offset_list[i].x / APP->zoom, offset_list[i].y / APP->zoom));
			recteur_list[i].setPosition(frame_list[i][cpt_list[i].x].left-1, frame_list[i][cpt_list[i].x].top-1);
		}
			
}

void CSpriteAnim::display()
{
	for (int i=2; i >=0; i--)
		if (frame_list[i].size() > 0)
		{
			if (boutons_oeil[i]->getEtat())
				APP->getWindow().draw(view_sprites[i]);
			if (boutons_rect[i]->getEtat())
				APP->getWindow().draw(recteur_list[i]);
		}
			
}
*/