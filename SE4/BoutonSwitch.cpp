#include "BoutonSwitch.h"
#include "Input.h"

CBoutonSwitch::CBoutonSwitch(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg) : CBouton(texture, rect, pos)
{
	for (int i = 0; i < arg.size(); i++)
	{
		if (arg.is(i) == CArg::INTRECT)
			rect2 = *static_cast<sf::IntRect*>(arg.get(i));
		else if (arg.is(i) == CArg::COLOR)
			color2 = *static_cast<sf::Color*>(arg.get(i));
		else if (arg.is(i) == CArg::INT)
		{
			etat = *static_cast<int*>(arg.get(i));
			predicat = new std::function<int(fonction_type)>([](fonction_type l) {return *static_cast<int*>(l[0]) > 0; });
			arguments = new fonction_type();
			arguments->push_back(&etat);
		}
		else
			std::cout << "Erreur d'arguments dans CBoutonSwitch pour " << this << std::endl;

	}
}

CBoutonSwitch::~CBoutonSwitch(void)
{
}

bool CBoutonSwitch::gerer()
{
	if (IO->again(CInput::MLeft))
		if (onSprite())
		{
			etat = !bool(etat);
			useFonction();

			return true;
		}

	return false;
}

bool CBoutonSwitch::update(bool forceTo, bool force_var)
{
	if (predicat != NULL)
		etat = usePredicat();
	
	if (forceTo)
		etat = force_var;

	if (etat != ex_etat)
	{
		if (rect2 != sf::IntRect())
		{
			if (etat == 1) sprite.setTextureRect(rect2);
			else  sprite.setTextureRect(rect);
		}
		else
		{
			if (etat == 1) sprite.setColor(sf::Color(color2.r, color2.g, color2.b, 255));
			else sprite.setColor(sf::Color(color.r, color.g, color.b, 128));
		}

		ex_etat = etat;
		return true;
	}

	return false;
}