#include "LineSmoother.h"

#include "Source Files/Fonction/Fonction.h"

std::vector<sf::Vector2f> LineSmoother::getAvailable() {
	auto list = ready_to_get;
	ready_to_get.clear();
	return list;
}

void LineSmoother::beginSmooth() {
	Fonction::vector d1 = Fonction::vector(array[0], array[1]);
	Fonction::vector d2 = Fonction::vector(array[2], array[1]);

	double angle = -Fonction::angle(d1, d2.opposite());
	if (Fonction::equal(angle, 0) || Fonction::equal(fabs(angle), 180)) {
		next_index = 1;
		return;
	}

	d2.setAtP1(d1.p2);
	d2.rotateAroundP1(angle/2);
	d1.rotateAroundP1(angle/6);

	auto list = smooth_laplacian(d1.p1, Fonction::intersect(d1, d2), d2.p1);
	array.insert(array.begin()+1, list.begin(), list.end());

	next_index = list.size()+1;
	getReady(0, next_index);
}

void LineSmoother::smooth() {
	int indice = next_index;
	Fonction::vector d1 = Fonction::vector(array[indice-1], array[indice]);
	d1.setAtP1(array[indice]);
	Fonction::vector d2 = Fonction::vector(array[indice+2], array[indice+1]);
	d2.setAtP1(array[indice+1]);
	Fonction::vector d2_base = Fonction::vector(array[indice+1], array[indice]);

	double angle = Fonction::angle(d2, d2_base);
	d2.rotateAroundP1(angle/2);

	if (parallel(d1, d2)) {
		next_index = indice + 1;
		getReady(indice, next_index);
		return;
	}
	
	Vector2d inter = Fonction::intersect(d1, d2);
	Fonction::vector p1_middle = Fonction::vector(d1.p1, inter);
	Fonction::vector p2_middle = Fonction::vector(d2.p1, inter);

	if (Fonction::equal(p1_middle.norme(), 0) || Fonction::equal(p2_middle.norme(), 0)) {
		next_index = indice + 1;
		getReady(indice, next_index);
		return;
	}

	bool test = Fonction::equal(p1_middle.direction(), d1.direction()) && Fonction::equal(p2_middle.direction(), d2.direction());

	if (test) {
		auto list = smooth_laplacian(d1.p1, inter, d2.p1);
		array.insert(array.begin() + indice+1, list.begin(), list.end());

		next_index = list.size() + indice+1;
		getReady(indice, next_index);
	}
	else {		
		double angle_d1 = Fonction::angle(d1, d2_base.opposite());

		Fonction::vector middle = Fonction::vector(d2_base.middle(), array[indice]);
		middle.rotateAroundP1(angle_d1/4);

		std::vector<Vector2d> list;
		std::vector<Vector2d> list2;
		if (!parallel(d1, middle)) {
			list = smooth_laplacian(d1.p1, Fonction::intersect(d1, middle), middle.p1);
			list.push_back(middle.p1);
			array.insert(array.begin() + indice+1, list.begin(), list.end());
		}
		middle = middle.opposite();
		if (!parallel(middle, d2)) {
			list2 = smooth_laplacian(middle.p1, Fonction::intersect(middle, d2), d2.p1);
			array.insert(array.begin() + list.size() + indice+1, list2.begin(), list2.end());
		}

		next_index = list.size() + list2.size() + indice+1;
		getReady(indice, next_index);
	}
}

void LineSmoother::endSmooth() {
	if (array.size() >= 3) {
		int indice = array.size() - 2;

		Fonction::vector d1 = Fonction::vector(array[indice - 1], array[indice]);
		Fonction::vector d2 = Fonction::vector(array[indice + 1], array[indice]);

		double angle = Fonction::angle(d1, d2.opposite());
		bool no_smooth = false;
		if (Fonction::equal(angle, 0) || Fonction::equal(fabs(angle), 180))
			no_smooth = true;

		if (!no_smooth) {
			d1.setAtP1(array[indice]);
			d2.rotateAroundP1(angle / 6);
			d1.rotateAroundP1(angle / 2);

			auto list = smooth_laplacian(d1.p1, Fonction::intersect(d1, d2), d2.p1);
			array.insert(array.begin() + indice + 1, list.begin(), list.end());
		}
		getReady(indice, array.size()-1);
	}
	else 
		getReady(0, array.size()-1);

	array.clear();
}

void LineSmoother::getReady(int from, int to) {
	ready_to_get.clear();

	Vector2d* previous = NULL;
	for (int i=from+1; i <= to; i++) {
		if (previous == NULL || fabs(Fonction::norme(array[i] - *previous)) >= 1)
			ready_to_get.push_back(VECTOR2F(array[i]));
		previous = &array[i];
	}
}

std::vector<Vector2d> LineSmoother::smooth_laplacian(Vector2d begin, Vector2d middle, Vector2d end) {
	Fonction::vector d1(begin, middle);
	Fonction::vector d2(end, middle);

	Vector2d m1 = d1.middle(50);
	Vector2d m2 = d2.middle(50);
	Vector2d center_triangle = Vector2d((m1.x*2 + m2.x*2 + middle.x)/5.f, (m1.y*2 + m2.y*2 + middle.y)/5.f);

	if (Fonction::equal(d1.norme(), 0) || Fonction::equal(d2.norme(), 0))
		return {center_triangle};

	return {m1, center_triangle, m2};
}