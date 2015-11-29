#include "BoutonSegment.h"
#include "Fonction.h"
#include "Writter.h"

CBoutonSegment::CBoutonSegment(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg) : CBouton(texture, rect, pos)
{
	for (int i = 0; i < arg.size(); i++)
	{
		if (arg.is(i) == CArg::VECTOR_I)
			interval = *static_cast<sf::Vector2i*>(arg.get(i));
		else if (arg.is(i) == CArg::FLOAT)
			addUnrefArg(*static_cast<FLOAT*>(arg.get(i)));
		else
			std::cout << "Erreur d'arguments dans CBoutonSegment pour " << this << std::endl;
	}
	render.create(rect.width, rect.height);
	sprite.setTexture(render.getTexture());
}


CBoutonSegment::~CBoutonSegment()
{
}

bool CBoutonSegment::gerer()
{
	if (onSprite())
	{
		int incr = CFonction::change_number();
		if (incr == 0)
			return false;

		if (usePredicatGroupe() && groupe == ONE_ALL)
		{
			auto list = parent->getBoutonList(this);
			for (int i = 0; i < list->size(); i++)
				static_cast<CBoutonSegment*>((*list)[i])->increment(incr);

			for (int i = 0; i < list->size(); i++)
				static_cast<CBoutonSegment*>((*list)[i])->useFonction();
		}
		else
			increment(incr);

		return true;
	}

	return false;
}

bool CBoutonSegment::update(bool forceTo, bool force_var)
{
	if (interval.y <= 255)
	{
		if (ex_arg != *static_cast<sf::Uint8*>((*arguments)[0]))
		{
			ex_arg = *static_cast<sf::Uint8*>((*arguments)[0]);
			WRITTER->ecrire(*static_cast<sf::Uint8*>((*arguments)[0]), &render);
			useFonction();
			return true;
		}
	}
	else
	{
		if (ex_arg != *static_cast<int*>((*arguments)[0]))
		{
			ex_arg = *static_cast<int*>((*arguments)[0]);
			WRITTER->ecrire(*static_cast<int*>((*arguments)[0]), &render);
			useFonction();
			return true;
		}
	}

	return false;
}

int CBoutonSegment::getValeur()
{
	if (interval.y <= 255)
		return *static_cast<sf::Uint8*>((*arguments)[0]);
	return *static_cast<int*>((*arguments)[0]);
}

bool CBoutonSegment::usePredicatGroupe()
{
	if (predicat_groupe == NULL)
		return false;
	return int((*predicat_groupe)(fonction_type()));
}

void CBoutonSegment::increment(int incr)
{
	if (interval.y <= 255)
	{
		if (*static_cast<sf::Uint8*>((*arguments)[0]) + incr > interval.y)
			*static_cast<sf::Uint8*>((*arguments)[0]) = interval.y;
		else if (*static_cast<sf::Uint8*>((*arguments)[0]) + incr < interval.x)
			*static_cast<sf::Uint8*>((*arguments)[0]) = interval.x;
		else
			*static_cast<sf::Uint8*>((*arguments)[0]) += incr;
		WRITTER->ecrire(*static_cast<sf::Uint8*>((*arguments)[0]), &render);
	}
	else
	{
		if (*static_cast<int*>((*arguments)[0]) + incr > interval.y)
			*static_cast<int*>((*arguments)[0]) = interval.y;
		else if (*static_cast<int*>((*arguments)[0]) + incr < interval.x)
			*static_cast<int*>((*arguments)[0]) = interval.x;
		else
			*static_cast<int*>((*arguments)[0]) += incr;
		WRITTER->ecrire(*static_cast<int*>((*arguments)[0]), &render);
	}
	if (groupe != ONE_ALL)
		useFonction();
}