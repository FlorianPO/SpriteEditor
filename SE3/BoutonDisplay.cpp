#include "BoutonDisplay.h"
#include "Input.h"

CBoutonDisplay::CBoutonDisplay(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos) : CBouton(texture, rect, pos)
{
}

CBoutonDisplay::~CBoutonDisplay()
{
}

bool CBoutonDisplay::gerer()
{
	if (IO->again(CInput::MLeft))
		if (onSprite())
		{
			useFonction();
			return true;
		}

	return false;
}