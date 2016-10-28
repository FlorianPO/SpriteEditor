#pragma once

#include "stdafx.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Fonction/Fonction.h"

class LineSmoother
{
// CONSTRUCTOR
public:
	LineSmoother() {}
	~LineSmoother() {}

// METHODS
public:
	template<typename T>
	void addPoint(const sf::Vector2<T>& point);
	void endPoint() { endSmooth(); }
	std::vector<sf::Vector2f> getAvailable();
private:
	void beginSmooth();
	void smooth();
	void endSmooth();
	void getReady(int from, int to);

	std::vector<Vector2d> smooth_laplacian(const Vector2d& begin, const Vector2d& middle, const Vector2d& end);
	std::vector<Vector2d> _smooth_laplacian(const Vector2d& begin, const Vector2d& middle, const Vector2d& end);

// MEMBERS
private:
	bool b_once = false;
	int next_index;

	std::vector<Vector2d> array;
	std::vector<sf::Vector2f> ready_to_get;
};

template <typename T>
void LineSmoother::addPoint(const sf::Vector2<T>& point) {
	if (array.size() > 0 && fabs(Fonction::norme(BRUSH->truePosition(VECTOR2F(point)) - BRUSH->truePosition(VECTOR2F(LAST(array))))) < 1) {
		if (!b_once) {
			endSmooth();
			array.push_back(VECTOR2D(point));
			b_once = true;
		}
		return;
	}
		
	b_once = false;
	array.push_back(VECTOR2D(point));

	if (array.size() == 3)
		beginSmooth();
	else if (array.size() > 3)
		smooth();
}