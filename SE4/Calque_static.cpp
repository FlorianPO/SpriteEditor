#include "Calque.h"

void CCalque::new_calque(sf::Texture* texture_var)
{
	if (texture_var != NULL)
		calque_list.push_back(new CCalque(texture_var));
	else {
		sf::Image image; sf::Texture texture;
		image.create(calque_list.back()->getSize().x, calque_list.back()->getSize().y, sf::Color::Transparent);
		texture.loadFromImage(image);
		calque_list.push_back(new CCalque(&texture));
	}
}

int CCalque::nbrCalque(bool count_dead)
{
	if (count_dead)
		return calque_list.size();

	int nbr = 0;
	for (int i = 0; i < calque_list.size(); i++)
		if (!calque_list[i]->dead)
			nbr++;
	return nbr;
}

bool CCalque::isFirst() 
{
	for (int i = 0; i < calque_list.size(); i--)
		if (!calque_list[i]->dead)
			return calque_list[i] == _t;
	return false;
}

void CCalque::choose_calque()
{
	for (int i = _t->getNumero(); i >= 0; i--)
		if (!calque_list[i]->dead) {
			_t = calque_list[i]; 
			return;
		}
	for (int i = _t->getNumero() + 1; i < calque_list.size(); i++)
		if (!calque_list[i]->dead) {
			_t = calque_list[i];
			return;
		}
}