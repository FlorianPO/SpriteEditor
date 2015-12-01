#include "Panneau.h"

#include "Fonction.h"
#include "BoutonSwitch.h"


CBouton::CBouton(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos)
{
	sprite.setTexture(*texture);

	if (rect.width != 0) sprite.setTextureRect(rect);
	if (pos.x != -1) sprite.setPosition(pos);

	this->rect = rect;
}


CBouton::~CBouton(void)
{
	if ((*parent->getBoutonList(this))[0] == this)
	{
		if (fonction != NULL)
			delete fonction;
		if (predicat != NULL)
			delete predicat;
	}
	if (arguments != NULL)
		delete arguments;
}

bool CBouton::onSprite()
{
	sf::Sprite spr = sprite;
	spr.setPosition(spr.getPosition().x * parent->getZoom(), spr.getPosition().y * parent->getZoom());
	spr.move(parent->getPosition());
	spr.setScale(parent->getZoom() * spr.getScale().x, parent->getZoom() * spr.getScale().y);

	return CFonction::onSprite(&spr);
}

void CBouton::group(CBouton* with, GROUP grp)
{
	std::vector<CBouton*>* bouton_list = parent->getBoutonList(with);
	for (int i = 0; i < bouton_list->size(); i++)
		if (with == (*bouton_list)[i])
		{
			bouton_list->insert(bouton_list->begin() + i + 1, this);
			groupe = grp;
			with->groupe = grp;
			return;
		}
}

void CBouton::addUnrefArg(int arg)
{
	unreferenced_arguments.push_back(arg);

	if (arguments == NULL)
		arguments = new fonction_type();
	arguments->push_back(&unreferenced_arguments.back());
}

void CBouton::replaceArgument(fonction_type* a)
{
	if (ex_arguments == NULL)
	{
		ex_arguments = arguments;
		arguments = a;
	}
}

void CBouton::cancelArgumentReplacement()
{
	if (ex_arguments != NULL)
	{
		delete arguments;
		arguments = ex_arguments;
		ex_arguments = NULL;
	}
}

void CBouton::useFonction()
{
	if (fonction != NULL)
		if (arguments != NULL)
			(*fonction)(*arguments);
		else
			(*fonction)(fonction_type());
}

int CBouton::usePredicat()
{
	if (predicat != NULL)
	{
		if (arguments != NULL)
			return int((*predicat)(*arguments));
		return int((*predicat)(fonction_type()));
	}

	return 0;
}

void CBouton::updateGroup()
{
	if (groupe == ONE)
	{
		auto list = parent->getBoutonList(this);
		for (int i = 0; i < list->size(); i++)
			if ((*list)[i] != this)
				(*list)[i]->update(true, false);
	}
	else if (groupe == ONE_ALL)
	{
		int cpt = 0;
		auto list = parent->getBoutonList(this);
		for (int i = 0; i < list->size(); i++)
			cpt += static_cast<CBoutonSwitch*>((*list)[i])->getEtat();

		if (cpt != 3)
		{
			for (int i = 0; i < list->size(); i++)
				if ((*list)[i] != this)
					(*list)[i]->update(true, false);
		}
	}
}