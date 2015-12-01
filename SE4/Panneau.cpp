#include "Panneau.h"

#include "Input.h"
#include "App.h"
#include "Fonction.h"

std::vector<std::vector<CPanneau*>> CPanneau::panneau_list;

class CBouton;

void CPanneau::zoom(float z) {sprite.setScale(z, z);}

bool CPanneau::test() {return CFonction::onSprite(&sprite);}

void CPanneau::afficher() {APP->fenetre.draw(sprite);}

void CPanneau::gerer()
{
	//Test buttons if totally scrolled down
	if (scrolledDown == true)
		for (int i = 0; i < bouton_list.size(); i++)
			for (int j = 0; j < bouton_list[i].size(); j++)
				if (bouton_list[i][j]->gerer())
				{
					for (int k = j + 1; k < bouton_list[i].size(); k++)
						bouton_list[i][k]->gerer();
					bouton_list[i][j]->updateGroup();
					break;
				}

	//Fonction if pannel clicked on
	if (fonction != NULL)
		if (!testButtons() && IO->again(CInput::MLeft) && CFonction::onSprite(&sprite))
			(*fonction)(*arguments);

	update();
}

void CPanneau::update()
{
	bool var = false;
	//Test swap mode
	if (predicatSwap != NULL)
		if ((*predicatSwap)(*arguments) != int(swap_etat))
		{
			swap_etat = (*predicatSwap)(*arguments);

			if (!swap_etat)
				sprite_fond.setTextureRect(rect);
			else
				sprite_fond.setTextureRect(swap);
			var = true;
		}
	//Test scrolling
	if (predicatScroll != NULL)
		if (scrolling == false)
		{
			if (arguments == NULL)
			{
				if ((*predicatScroll)(fonction_type()) != int(scrolledDown))
				{
					scrollgoal = (*predicatScroll)(fonction_type());
					scrolling = true;
				}
			}
			else if ((*predicatScroll)(*arguments) != int(scrolledDown))
			{
				scrollgoal = (*predicatScroll)(*arguments);
				scrolling = true;
			}
		}
		else
			scrollMe();

	if (scrollgoal || scrolledDown && !scrolling)
		for (int i = 0; i < bouton_list.size(); i++)
			for (int j = 0; j < bouton_list[i].size(); j++)
				if (bouton_list[i][j]->update())
					var = true;
				
	//Render panel
	if (var || ini) draw();
	ini = false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CPanneau::testPanneau()
{
	for (int i = 0; i < panneau_list.size(); i++)
		for (int j = 0; j < panneau_list[i].size(); j++)
			if (panneau_list[i][j]->test())
				return true;
	return false;
}

void CPanneau::gererPanneau()
{
	static int ex_size = panneau_list.size();
	for (int i = 0; i < panneau_list.size(); i++)
	{
		static int ex_size_1 = panneau_list[i].size();
		for (int j = 0; j < panneau_list[i].size(); j++)
		{
			panneau_list[i][j]->gerer();

			if (panneau_list.size() < ex_size)
			{
				i -= ex_size - panneau_list.size();
				ex_size = panneau_list.size();
				j = 0;
			}
			else if (panneau_list[i].size() < ex_size_1)
			{
				j -= ex_size_1 - panneau_list[i].size();
				ex_size_1 = panneau_list[i].size();
			}
		}
	}
}

void CPanneau::afficherPanneau()
{
	for (int i = 0; i < panneau_list.size(); i++)
		for (int j = 0; j < panneau_list[i].size(); j++)
			panneau_list[i][j]->afficher();
}

bool CPanneau::testButtons()
{
	for (int i = 0; i < bouton_list.size(); i++)
		for (int j = 0; j < bouton_list[i].size(); j++)
			if (bouton_list[i][j]->onSprite())
				return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CPanneau::CPanneau(const sf::Texture* texture, sf::IntRect rect, CPanneau* with, sf::IntRect swap)
{
	this->swap = swap;
	this->rect = rect;

	sprite_fond = sf::Sprite(*texture);
	sprite_fond.setTextureRect(rect);

	render.create(rect.width, rect.height);
	sprite.setTexture(render.getTexture());

	size_ini = sf::Vector2i(rect.width, rect.height);

	if (with != NULL)
		group(with);
	else
	{
		panneau_list.push_back(std::vector <CPanneau*> {this});
		which_group = panneau_list.size() - 1;
	}
}

CPanneau::~CPanneau(void)
{
	for (int i = 0; i < bouton_list.size(); i++)
		for (int j = 0; j < bouton_list[i].size(); j++)
			delete bouton_list[i][j];

	for (int j = 0; j < panneau_list[which_group].size(); j++)
		if (panneau_list[which_group][j] == this)
		{
			panneau_list[which_group].erase(panneau_list[which_group].begin() + j);
			if (panneau_list[which_group].size() == 0)
				panneau_list.erase(panneau_list.begin() + which_group);
			return;
		}

	if (arguments != NULL)
		delete arguments;
	if (fonction != NULL)
		delete fonction;
	if (predicatScroll != NULL)
		delete predicatScroll;
	if (predicatSwap != NULL)
		delete predicatSwap;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CPanneau::addBouton(CBouton* b, CBouton* with, CBouton::GROUP groupe)
{
	b->setParent(this);

	if (with != NULL)
		b->group(with, groupe);
	else
		bouton_list.push_back(std::vector<CBouton*> {b});
}



void CPanneau::draw()
{
	if (render.getSize().y == 0)
		return;

	render.clear(sf::Color::Transparent);
	render.draw(sprite_fond);

	for (int i = 0; i < bouton_list.size(); i++)
		for (int j = 0; j < bouton_list[i].size(); j++)
			bouton_list[i][j]->draw(&render);

	render.display();
}

void CPanneau::group(CPanneau* with)
{
	for (int i = 0; i < panneau_list.size(); i++)
		for (int j = 0; j < panneau_list[i].size(); j++)
			if (with == panneau_list[i][j])
			{
				if (which_group != i && which_group < panneau_list.size())
					for (int k = 0; k < panneau_list[which_group].size(); k++)
						if (this == panneau_list[which_group][k])
						{
							panneau_list[which_group].erase(panneau_list[which_group].begin() + k);
							break;
						}
				for (int k = 0; k < panneau_list[i].size(); k++)
					if (this == panneau_list[i][k])
					{
						panneau_list[i].erase(panneau_list[i].begin() + k);
						break;
					}

				which_group = i;
				panneau_list[i][j]->which_group = i;
				panneau_list[i].insert(panneau_list[i].begin() + j + 1, this);

				return;
			}
}

void CPanneau::unGroup()
{
	for (int j = 0; j < panneau_list[which_group].size(); j++)
		if (this == panneau_list[which_group][j])
		{
			panneau_list[which_group].erase(panneau_list[which_group].begin() + j);
			if (panneau_list[which_group].size() == 0)
				panneau_list.erase(panneau_list.begin() + which_group);
			panneau_list.push_back(std::vector<CPanneau*> {this});
			which_group = panneau_list.size() - 1;
			return;
		}
}

void CPanneau::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
	if (which_group != -1)
	{
		for (int j = 0; j < panneau_list[which_group].size(); j++)
			if (this == panneau_list[which_group][j])
			{
				if (j + 1 < panneau_list[which_group].size())
					panneau_list[which_group][j + 1]->setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height));
				return;
			}
	}
}

std::vector<CBouton*>* CPanneau::getBoutonList(CBouton* bouton)
{
	for (int i = 0; i < bouton_list.size(); i++)
		for (int j = 0; j < bouton_list[i].size(); j++)
			if (bouton_list[i][j] == bouton)
				return &bouton_list[i];
	return NULL;
}

void CPanneau::setPredicatScroll(std::function<int(fonction_type)>* p)
{
	predicatScroll = p;
	offset = 0;
	scrolledDown = false;
	sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTextureRect().width, offset));
}

void CPanneau::scrollMe()
{
	if (scrollgoal == true)
	{
		offset += size_ini.y / 8.f;
		if (offset >= size_ini.y)
		{
			offset = size_ini.y;
			scrolling = false;
			scrolledDown = true;
		}
	}
	else
	{
		offset -= size_ini.y / 8.f;
		if (offset <= 0)
		{
			offset = 0;
			scrolling = false;
			scrolledDown = false;
		}
	}
	sprite.setTextureRect(sf::IntRect(0, 0, sprite.getTextureRect().width, offset));
}