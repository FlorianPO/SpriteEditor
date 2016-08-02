#include "Fonction.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

bool Fonction::mouseOnSprite(const sf::Sprite* sprite) {
	sf::FloatRect rect = sprite->getGlobalBounds();
	return rect.contains(INPUT->getPosition());
}

bool Fonction::mouseOnSprite(const sf::Sprite& sprite, const sf::RenderWindow& fenetre) {
	sf::FloatRect rect = sprite.getGlobalBounds();
	sf::Vector2i pos = sf::Mouse::getPosition(fenetre);
	return rect.contains(ARG_VECTOR(pos));
}

bool Fonction::mouseOnRect(sf::FloatRect rect) {
	return rect.contains(INPUT->getPosition());
}

bool Fonction::mouseOnRect(sf::FloatRect rect, const sf::RenderWindow& fenetre) {
	sf::Vector2i pos = sf::Mouse::getPosition(fenetre);
	return rect.contains(ARG_VECTOR(pos));
}

Fonction::sl_PR Fonction::selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos, int only, double angle, float seuil) {
	if (pos == pos_ini)
		return {sf::Vector2f(), -1};
	float a = Fonction::norme(pos_ini - pos);

	if (only == -1) {
		sf::Vector2f points[8];
		points[0] = sf::Vector2f(pos_ini.x - a / std::sqrt(2), pos_ini.y - a / std::sqrt(2));
		points[1] = sf::Vector2f(pos_ini.x, pos_ini.y - a);
		points[2] = sf::Vector2f(pos_ini.x + a / std::sqrt(2), pos_ini.y - a / std::sqrt(2));
		points[3] = sf::Vector2f(pos_ini.x + a, pos_ini.y);
		points[4] = sf::Vector2f(pos_ini.x + a / std::sqrt(2), pos_ini.y + a / std::sqrt(2));
		points[5] = sf::Vector2f(pos_ini.x, pos_ini.y + a);
		points[6] = sf::Vector2f(pos_ini.x - a / std::sqrt(2), pos_ini.y + a / std::sqrt(2));
		points[7] = sf::Vector2f(pos_ini.x - a, pos_ini.y);

		if (angle != 0)
			FOR_I (8)
				points[i] = rotationGlobal(points[i], pos_ini, angle);

		float distance[8];
		FOR_I (8)
			distance[i] = std::sqrt(std::pow(points[i].x - pos.x, 2) + std::pow(points[i].y - pos.y, 2));

		int j = 0;
		FOR_I (8)
			if (distance[i] < distance[j])
				j = i;
		if (Fonction::norme(points[j] - pos_ini) < seuil)
			return {sf::Vector2f(), -1};
		return {points[j] - pos_ini, j};
	}
	switch (only) {
		case 0:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a / std::sqrt(2), pos_ini.y - a / std::sqrt(2)), pos_ini, angle) - pos_ini, 0};
		case 1:	return {rotationGlobal(sf::Vector2f(pos_ini.x, pos_ini.y - a), pos_ini, angle) - pos_ini, 1};
		case 2:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a / std::sqrt(2), pos_ini.y - a / std::sqrt(2)), pos_ini, angle) - pos_ini, 2};
		case 3:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a, pos_ini.y), pos_ini, angle) - pos_ini, 3};
		case 4:	return {rotationGlobal(sf::Vector2f(pos_ini.x + a / std::sqrt(2), pos_ini.y + a / std::sqrt(2)), pos_ini, angle) - pos_ini, 4};
		case 5:	return {rotationGlobal(sf::Vector2f(pos_ini.x, pos_ini.y + a), pos_ini, angle) - pos_ini, 5};
		case 6:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a / std::sqrt(2), pos_ini.y + a / std::sqrt(2)), pos_ini, angle) - pos_ini, 6};
		case 7:	return {rotationGlobal(sf::Vector2f(pos_ini.x - a, pos_ini.y), pos_ini, angle) - pos_ini, 7};
	}
	return {sf::Vector2f(), -1};
}

sf::Vector2f* Fonction::selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil) {
	sf::FloatRect rect = sprite->getGlobalBounds();
	sf::Vector2f points[9];
	points[0] = topLeftCorner(rect);
	points[1] = topRightCorner(rect);
	points[2] = bottomRightCorner(rect);
	points[3] = bottomLeftCorner(rect);
	points[4] = centerCorner(rect);

	sf::FloatRect rect2 = sf::FloatRect(0, 0, sprite->getTextureRect().width * sprite->getScale().x, sprite->getTextureRect().height * sprite->getScale().y);
	points[5] = sf::Vector2f(0, 0);
	points[6] = sf::Vector2f(rect2.width, 0);
	points[7] = sf::Vector2f(0, rect2.height);
	points[8] = sf::Vector2f(rect2.width, rect2.height);

	float angle = -sprite->getRotation() / 180 * PI;
	for (int i = 5; i < 9; i++) {
		sf::Vector2f temp = points[i] - sf::Vector2f(sprite->getOrigin().x * sprite->getScale().x, sprite->getOrigin().y * sprite->getScale().y);
		points[i].x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
		points[i].y = temp.y*std::cos(angle) - temp.x*std::sin(angle);

		points[i] += sprite->getPosition();
	}

	float distance[9];
	FOR_I (9)
		distance[i] = std::sqrt(std::pow(points[i].x - pos.x, 2) + std::pow(points[i].y - pos.y, 2));

	int j = 0;
	for (int i = 1; i < 9; i++)
		if (distance[i] < distance[j])
			j = i;
	if (distance[j] < seuil)
		return new sf::Vector2f(points[j]);
	return NULL;
}

bool Fonction::onCalque(sf::Vector2i vect, const sf::Image& image_courant) {
	return vect.x >= 0 && vect.x < image_courant.getSize().x && vect.y >= 0 && vect.y < image_courant.getSize().y;
}

bool Fonction::onCalque(sf::Vector2i vect, const sf::Texture& texture_courant) {
	return vect.x >= 0 && vect.x < texture_courant.getSize().x && vect.y >= 0 && vect.y < texture_courant.getSize().y;
}

sf::Color Fonction::getColor(sf::Vector2i vect, const sf::Image& image_courant) {
	if (onCalque(vect, image_courant))
		return image_courant.getPixel(ARG_VECTOR(vect));

	return sf::Color::Black;
}

sf::Color Fonction::getPointedColor() {
	return Fonction::getColor(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), *LAYER->getImage());
}

sf::IntRect Fonction::FloatRectToIntRect(sf::FloatRect rect) {
	return sf::IntRect(rect.left, rect.top, rect.width, rect.height);
}

std::vector<sf::Vector2f>* Fonction::getPoints(sf::Sprite* sprite) {
	std::vector<sf::Vector2f>* points = new std::vector<sf::Vector2f>();

	sf::FloatRect rect = sprite->getGlobalBounds();
	points->push_back(Fonction::topLeftCorner(rect));
	points->push_back(Fonction::topRightCorner(rect));
	points->push_back(Fonction::bottomLeftCorner(rect));
	points->push_back(Fonction::bottomRightCorner(rect));
	points->push_back(Fonction::centerCorner(rect));

	points->push_back(sf::Vector2f(rect.left + rect.width / 2.f, rect.top));
	points->push_back(sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height));
	points->push_back(sf::Vector2f(rect.left, rect.top + rect.height / 2.f));
	points->push_back(sf::Vector2f(rect.left + rect.width, rect.top + rect.height / 2.f));

	return points;
}

bool Fonction::checkCadre(sf::IntRect* cadre, sf::IntRect cadre_in) {
	if (cadre->left < cadre_in.left) {
		cadre->width += cadre->left;
		if (cadre->width <= 0)
			return true;
		cadre->left = cadre_in.left;
	}
	if (cadre->top < cadre_in.top) {
		cadre->height += cadre->top;
		if (cadre->height <= 0)
			return true;
		cadre->top = cadre_in.top;
	}
	if (cadre->left + cadre->width >= cadre_in.left + cadre_in.width) {
		cadre->width = cadre_in.left + cadre_in.width - cadre->left;
		if (cadre->width <= 0)
			return true;
	}
	if (cadre->top + cadre->height >= cadre_in.top + cadre_in.height) {
		cadre->height = cadre_in.top + cadre_in.height - cadre->top;
		if (cadre->height <= 0)
			return true;
	}
	return false;
}