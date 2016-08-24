#pragma once

#include "stdenum.h"

namespace Fonction
{
	struct sl_PR {
		sf::Vector2f distance;
		int orientation;
	};

	bool mouseOnSprite(const sf::Sprite* sprite); //Test if mouse is on a given sprite
	bool mouseOnSprite(const sf::Sprite& sprite, const sf::RenderWindow& fenetre); //Test if mouse is on a given sprite on a window
	bool mouseOnRect(sf::FloatRect rect);
	bool mouseOnRect(sf::FloatRect rect, const sf::RenderWindow& fenetre);

	sl_PR selecPointRect(sf::Vector2f pos_ini, sf::Vector2f pos, int only = -1, double angle = 0, float seuil = 0);
	sf::Vector2f* selecPoint(sf::Sprite* sprite, sf::Vector2f pos, float seuil);

	bool onCalque(sf::Vector2i vect, const sf::Image& image_courant);
	bool onCalque(sf::Vector2i vect, const sf::Texture& texture_courant);
	sf::Color getColor(sf::Vector2i vect, const sf::Image& image_courant);
	sf::Color getPointedColor();

	bool checkCadre(sf::IntRect* cadre, sf::IntRect cadre_in);
	std::vector<sf::Vector2f>* getPoints(sf::Sprite* sprite);

	void fuseTexture(sf::RenderTexture& render_texture, const sf::Texture& texture_src, sf::Vector2f pos_src);

	/////////////
	// SPECIAL //
	/////////////
	int copy_to_clipboard(sf::Image *image);
	int copy_to_clipboard(std::string string);
	sf::String get_macro();
	sf::Image* get_clipboard();

	//////////
	// MATH //
	//////////
	UINT8 numDigits(int32_t x);
	template<typename T>
	T floatPart(T f) { return f - int(f); }
	template<typename T>
	T degToRad(T deg) { return deg / 180 * PI; }
	template<typename T>
	T radToDeg(T rad) { return rad * 180 / PI; }

	inline bool equal(double d1, double d2) { return std::fabs(d1 - d2) < 1e-3; }

	// Geometry
	template<typename T>
	double norme(sf::Vector2<T> direction) { return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2)); }
	double hypothenus(double cote1, double cote2);
	template<typename T>
	sf::Vector2<T> rotationGlobal(sf::Vector2<T> toRot, sf::Vector2<T> center, double angle, nStd::Angle angle_type=nStd::DEG) {
		if (angle_type == nStd::DEG)
			angle = degToRad(angle);
	
		double x = toRot.x;
		double y = toRot.y;
		double x_temp;

		x -= center.x;
		y -= center.y;
		x_temp = x;
		x = x*std::cos(angle) - y*std::sin(angle);
		y = y*std::cos(angle) + x_temp*std::sin(angle);
		x += center.x;
		y += center.y;

		return sf::Vector2<T>(x, y);
	}
	template<typename T>
	sf::Vector2<T> rotationLocal(sf::Vector2<T> toRot, double angle, nStd::Angle angle_type=nStd::DEG) {
		if (angle_type == nStd::DEG)
		angle = degToRad(angle);

		double x = toRot.x;
		double y = toRot.y;
		double x_temp = x;

		x = x*std::cos(angle) - y*std::sin(angle);
		y = y*std::cos(angle) + x_temp*std::sin(angle);

		return sf::Vector2<T>(x, y);
	}

	// Sprite transformations
	void moveLocaly(sf::Sprite& sprite, sf::Vector2f translation);
	void setGlobalPosition(sf::Sprite& sprite, sf::Vector2f position);
	void setOriginLocally(sf::Sprite& sprite, sf::Vector2f origin);
	void setOriginGlobally(sf::Sprite& sprite, sf::Vector2f origin);
	void flipVertically(sf::Sprite& sprite);
	void flipHorizontally(sf::Sprite& sprite);
	template<typename T>
	sf::Rect<T> unionRect(sf::Rect<T> r1, sf::Rect<T> r2) {
		T left = std::min(r1.left, r2.left);
		T top = std::min(r1.top, r2.top);
		T width = std::max(r1.left + r1.width, r2.left + r2.width) - left;
		T height = std::max(r1.top + r1.height, r2.top + r2.height) - top;
		return sf::Rect<T>(left, top, width, height);
	}

	////////////
	// VECTOR //
	////////////
	struct vector;
	bool parallel(const vector& d1, const vector& d2);
	Vector2d intersect(const vector& d1, const vector& d2);
	double scalar(const vector& d1, const vector& d2);
	double vetoriel(const vector& d1, const vector& d2);
	double angle(const vector& d1, const vector& d2, nStd::Angle angle_type=nStd::DEG);

	struct vector { // Both a line and a vector
		Vector2d p1;
		Vector2d p2;
		Vector2d size;

		vector() {}

		template<typename T>
		vector(sf::Vector2<T> p1, sf::Vector2<T> p2) {
			this->p1 = VECTOR2D(p1);
			this->p2 = VECTOR2D(p2);
			this->size = this->p2 - this->p1;
		}

		Vector2d middle(double pourcent=50) const {
			double p_2 = pourcent/100;
			double p_1 = 1-p_2;
			return Vector2d(p1.x*p_1 + p2.x*p_2, p1.y*p_1 + p2.y*p_2);
		}
		vector opposite() const { return vector(p1, Fonction::rotationGlobal(p2, p1, 180, nStd::DEG)); }
		bool infinite() const { return size.x == 0; }
		double norme() const { return std::sqrt(std::pow(size.x, 2) + std::pow(size.y, 2)); }
		double direction() const {
			Fonction::vector base = Fonction::vector(Vector2d(0, 0), Vector2d(1, 0));

			double cos_angle = scalar(*this, base) / (norme()*base.norme());
			double sin_angle = vetoriel(*this, base) / (norme()*base.norme());

			double angle = atan2(sin_angle, cos_angle);
			return Fonction::radToDeg(angle);
		}
		double pente() const { return  size.y / size.x; }
		double origin() const { return  p1.y - pente() * p1.x; }
		void rotateAroundP1(double angle, nStd::Angle angle_type=nStd::DEG) {
			p2 = Fonction::rotationGlobal(p2, p1, angle, angle_type);
			size = p2 - p1;
		}
		void rotateAroundP2(double angle, nStd::Angle angle_type=nStd::DEG) {
			p1 = Fonction::rotationGlobal(p1, p2, angle, angle_type);
			size = p2 - p1;
		}
		template<typename T>
		void setAtP1(sf::Vector2<T> position) { 
			Vector2d delta = VECTOR2D(position) - p1;
			p1 += delta;
			p2 += delta;
		}
		template<typename T>
		void setAtP2(sf::Vector2<T> position) { 
			Vector2d delta = VECTOR2D(position) - p2;
			p1 += delta;
			p2 += delta;
		}
	};

	//////////////
	// POSITION //
	//////////////
	// CENTER
	sf::Vector2f centerCorner(const sf::Sprite& sprite);
	sf::Vector2f centerCorner(const sf::Texture& texture);
	sf::Vector2f centerCorner(const sf::Image& image);
	sf::Vector2f centerCorner(sf::Vector2i size);
	sf::Vector2f centerCorner(sf::Vector2u size);
	sf::Vector2f centerCorner(sf::Vector2f size);
	sf::Vector2f centerCorner(sf::FloatRect rect);
	sf::Vector2f centerCorner(sf::IntRect rect);
	// TOP LEFT
	sf::Vector2f topLeftCorner(const sf::Sprite& sprite);
	sf::Vector2f topLeftCorner(const sf::Texture& texture);
	sf::Vector2f topLeftCorner(const sf::Image& image);
	sf::Vector2f topLeftCorner(sf::Vector2i size);
	sf::Vector2f topLeftCorner(sf::Vector2u size);
	sf::Vector2f topLeftCorner(sf::Vector2f size);
	sf::Vector2f topLeftCorner(sf::FloatRect rect);
	sf::Vector2f topLeftCorner(sf::IntRect rect);
	// TOP RIGHT
	sf::Vector2f topRightCorner(const sf::Sprite& sprite);
	sf::Vector2f topRightCorner(const sf::Texture& texture);
	sf::Vector2f topRightCorner(const sf::Image& image);
	sf::Vector2f topRightCorner(sf::Vector2i size);
	sf::Vector2f topRightCorner(sf::Vector2u size);
	sf::Vector2f topRightCorner(sf::Vector2f size);
	sf::Vector2f topRightCorner(sf::FloatRect rect);
	sf::Vector2f topRightCorner(sf::IntRect rect);
	// BOTTOM RIGHT
	sf::Vector2f bottomRightCorner(const sf::Sprite& sprite);
	sf::Vector2f bottomRightCorner(const sf::Texture& texture);
	sf::Vector2f bottomRightCorner(const sf::Image& image);
	sf::Vector2f bottomRightCorner(sf::Vector2i size);
	sf::Vector2f bottomRightCorner(sf::Vector2u size);
	sf::Vector2f bottomRightCorner(sf::Vector2f size);
	sf::Vector2f bottomRightCorner(sf::FloatRect rect);
	sf::Vector2f bottomRightCorner(sf::IntRect rect);
	// BOTTOM LEFT
	sf::Vector2f bottomLeftCorner(const sf::Sprite& sprite);
	sf::Vector2f bottomLeftCorner(const sf::Texture& texture);
	sf::Vector2f bottomLeftCorner(const sf::Image& image);
	sf::Vector2f bottomLeftCorner(sf::Vector2i size);
	sf::Vector2f bottomLeftCorner(sf::Vector2u size);
	sf::Vector2f bottomLeftCorner(sf::Vector2f size);
	sf::Vector2f bottomLeftCorner(sf::FloatRect rect);
	sf::Vector2f bottomLeftCorner(sf::IntRect rect);
};

