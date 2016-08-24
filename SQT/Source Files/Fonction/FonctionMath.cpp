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

double Fonction::hypothenus(double cote1, double cote2) {
	double hyp = cote1*cote1 + cote2*cote2;
	return std::sqrt(hyp);
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

////////////
// DROITE //
////////////
Vector2d Fonction::intersect(const vector& d1, const vector& d2) {
	if (d1.infinite())
		return Vector2d(d1.p1.x, d2.pente() * d1.p1.x + d2.origin());
	if (d2.infinite())
		return Vector2d(d2.p1.x, d1.pente() * d2.p1.x + d1.origin());

	Vector2d final;
	final.x = (d2.origin() - d1.origin())/(d1.pente() - d2.pente());
	final.y = d1.pente() * final.x  + d1.origin();

	return final;
}

bool Fonction::parallel(const vector& d1, const vector& d2) {
	if (d1.infinite() && d2.infinite())
		return true;
	if (d1.infinite() || d2.infinite())
		return false;

	return Fonction::equal(fabs(d1.pente()), fabs(d2.pente()));
}

double Fonction::scalar(const vector& d1, const vector& d2) {
	return d1.size.x*d2.size.x + d1.size.y*d2.size.y;
}

double Fonction::vetoriel(const vector& d1, const vector& d2) {
	return d1.size.x*d2.size.y - d1.size.y*d2.size.x;
}

double Fonction::angle(const vector& d1, const vector& d2, nStd::Angle angle_type) {
	double cos_angle = scalar(d1, d2) / (d1.norme()*d2.norme());
	double sin_angle = vetoriel(d1, d2) / (d1.norme()*d2.norme());

	double angle = atan2(sin_angle, cos_angle);

	if (angle_type == nStd::RAD)
		return angle;
	else
		return radToDeg(angle);
}