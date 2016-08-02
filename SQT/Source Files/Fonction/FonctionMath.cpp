#include "Fonction.h"

UINT8 Fonction::numDigits(int32_t x) {
	if (x == INT_MIN) return 10 + 1;
	if (x < 0) return numDigits(-x) + 1;

	if (x >= 10000) {
		if (x >= 10000000) {
			if (x >= 100000000) {
				if (x >= 1000000000)
					return 10;
				return 9;
			}
			return 8;
		}
		if (x >= 100000) {
			if (x >= 1000000)
				return 7;
			return 6;
		}
		return 5;
	}
	if (x >= 100) {
		if (x >= 1000)
			return 4;
		return 3;
	}
	if (x >= 10)
		return 2;
	return 1;
}

float Fonction::degToRad(float deg) {
	return deg / 180 * PI;
}

float Fonction::radToDeg(float rad) {
	return rad * 180 / PI;
}

float Fonction::hypothenus(double cote1, double cote2) {
	double hyp = cote1*cote1 + cote2*cote2;
	return std::sqrt(hyp);
}

float Fonction::norme(sf::Vector2f direction) {
	return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
}

float Fonction::norme(sf::Vector2i direction) {
	return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
}

sf::Vector2f Fonction::rotationGlobal(sf::Vector2f toRot, sf::Vector2f center, double angle, nStd::Angle angle_type) {
	if (angle_type == nStd::DEG)
		angle = degToRad(angle);
	
	double x = toRot.x;
	double y = toRot.y;
	double x_temp = x;

	x -= center.x;
	y -= center.y;
	x = x*std::cos(angle) - y*std::sin(angle);
	y = y*std::cos(angle) + x_temp*std::sin(angle);
	x += center.x;
	y += center.y;

	return sf::Vector2f(x, y);
}

sf::Vector2f Fonction::rotationLocal(sf::Vector2f toRot, double angle, nStd::Angle angle_type) {
	if (angle_type == nStd::DEG)
		angle = degToRad(angle);

	double x = toRot.x;
	double y = toRot.y;
	double x_temp = x;

	x = x*std::cos(angle) - y*std::sin(angle);
	y = y*std::cos(angle) + x_temp*std::sin(angle);

	return sf::Vector2f(x, y);
}

void Fonction::moveLocaly(sf::Sprite& sprite, sf::Vector2f translation) {
	translation = Fonction::rotationLocal(translation, sprite.getRotation());
	sprite.move(translation);
}

void Fonction::setGlobalPosition(sf::Sprite& sprite, sf::Vector2f position) {
	sf::Vector2f pos_sprite = topLeftCorner(sprite.getGlobalBounds());

	sprite.move(position - pos_sprite);
}

void Fonction::setOriginLocally(sf::Sprite& sprite, sf::Vector2f origin) {
	sf::Vector2f delta = origin - sprite.getOrigin();
	delta.x *= sprite.getScale().x;
	delta.y *= sprite.getScale().y;

	sprite.setOrigin(origin);
	moveLocaly(sprite, delta);
}

void Fonction::setOriginGlobally(sf::Sprite& sprite, sf::Vector2f origin) {
	sf::Vector2f pos_center = centerCorner(sprite.getGlobalBounds());

	pos_center = rotationLocal(pos_center - origin, -sprite.getRotation());
	pos_center.x /= sprite.getScale().x;
	pos_center.y /= sprite.getScale().y;

	sprite.setOrigin(centerCorner(sprite.getTextureRect()) - pos_center);
	sprite.setPosition(origin);
}

void Fonction::flipVertically(sf::Sprite& sprite) {
	sf::Vector2f scale = sprite.getScale();
	scale.y = -scale.y;
	sprite.setScale(scale);

	sf::Vector2f origin = sprite.getOrigin();
	sf::Vector2f center = centerCorner(sprite.getTextureRect());
	moveLocaly(sprite, sf::Vector2f(0, scale.y*(origin.y - center.y)*2.f));
}

void Fonction::flipHorizontally(sf::Sprite& sprite) {
	sf::Vector2f scale = sprite.getScale();
	scale.x = -scale.x;
	sprite.setScale(scale);
	
	sf::Vector2f origin = sprite.getOrigin();
	sf::Vector2f center = centerCorner(sprite.getTextureRect());
	moveLocaly(sprite, sf::Vector2f(scale.x*(origin.x - center.x)*2.f, 0));
}