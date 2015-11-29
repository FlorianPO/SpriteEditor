#include "BoutonActive.h"
#include "Input.h"

CBoutonActive::CBoutonActive(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg) : CBouton(texture, rect, pos)
{
	for (int i = 0; i < arg.size(); i++)
	{
		if (arg.is(i) == CArg::INTRECT)
			rect2 = *static_cast<sf::IntRect*>(arg.get(i));
		else if (arg.is(i) == CArg::COLOR)
			color2 = *static_cast<sf::Color*>(arg.get(i));
		else
			std::cout << "Erreur d'arguments dans CBoutonActive pour " << this << std::endl;
	}
}

CBoutonActive::~CBoutonActive()
{
}

bool CBoutonActive::gerer()
{
	if (IO->again(CInput::MLeft))
		if (onSprite())
			if (etat)
			{
				useFonction();
				return true;
			}

	return false;
}

bool CBoutonActive::update(bool forceTo, bool force_var)
{
	if (predicat != NULL)
		etat = usePredicat();

	if (forceTo)
			etat = force_var;
	
	if (etat != ex_etat)
	{
		if (etat == 1) sprite.setColor(sf::Color(color2.r, color2.g, color2.b, 255));
		else sprite.setColor(sf::Color(color.r, color.g, color.b, 128));

		if (rect2 != sf::IntRect())
		{
			if (usePredicat2()) sprite.setTextureRect(rect2);
			else sprite.setTextureRect(rect);
		}

		ex_etat = etat;
		return true;
	}

	return false;
}

int CBoutonActive::usePredicat2()
{
	if (predicat2 != NULL)
	{
		if (arguments != NULL)
			return int((*predicat2)(*arguments));
		return int((*predicat2)(fonction_type()));
	}

	return etat;
}