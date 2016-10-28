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
			DEBUGN(list.size())
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

std::vector<Vector2d> LineSmoother::smooth_laplacian(const Vector2d& begin, const Vector2d& middle, const Vector2d& end) {
	std::vector<Vector2d> m1_center_m2 = _smooth_laplacian(begin, middle, end);

	if (m1_center_m2.size() < 3)
		return m1_center_m2;

	std::vector<Vector2d> left = _smooth_laplacian(begin, m1_center_m2[0], m1_center_m2[1]);
	std::vector<Vector2d> right = _smooth_laplacian(m1_center_m2[1], m1_center_m2[2], end);
	std::vector<Vector2d> final_list;
	
	FOR_I (left.size())
		final_list.push_back(left[i]);
	final_list.push_back(m1_center_m2[1]);
	FOR_I (right.size())
		final_list.push_back(right[i]);

	FOR_I (final_list.size()) {
		if (i > 0 && i < final_list.size()-1)
			final_list[i] = Vector2d((final_list[i-1].x + final_list[i].x + final_list[i+1].x)/3.0, 
									 (final_list[i-1].y + final_list[i].y + final_list[i+1].y)/3.0);
	}

	return final_list;
}

std::vector<Vector2d> LineSmoother::_smooth_laplacian(const Vector2d& begin, const Vector2d& middle, const Vector2d& end) {
	Fonction::vector d1(begin, middle);
	Fonction::vector d2(end, middle);

	if (Fonction::norme(end - begin) < 10)
		return {};

	Vector2d m1 = d1.middle(33);
	Vector2d m2 = d2.middle(33);
	
	double norme_m1 = d1.norme();
	double norme_m2 = d2.norme();
	double norme_middle = d1.norme()/2 + d2.norme()/2;

	Vector2d center_triangle = Vector2d((m1.x*norme_m1 + m2.x*norme_m2 + middle.x*norme_middle)/(norme_m1 + norme_m2 + norme_middle), 
										(m1.y*norme_m1 + m2.y*norme_m2 + middle.y*norme_middle)/(norme_m1 + norme_m2 + norme_middle));

	if (Fonction::equal(d1.norme(), 0) || Fonction::equal(d2.norme(), 0))
		return {center_triangle};
	
	return {m1, center_triangle, m2};
}