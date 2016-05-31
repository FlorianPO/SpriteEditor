#include "Source Files/Application/Tool/ToolAbstract/ToolLiner.h"

#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Var/Var.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/App.h"
#include <QtWidgets/QApplication>

void ToolLiner::calculateLine() {
	sf::Vector2f cl = IO->getPreviousCenterClick();
	line[0].position = cl;

	Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
	if (special & Qt::ControlModifier) {
		float d_x = center.x - cl.x;
		float d_y = center.y - cl.y;

		float cos = d_x / CFonction::hypothenus(d_x, d_y);
		float sin = -d_y / CFonction::hypothenus(d_x, d_y);

		float hyp = floor(CFonction::hypothenus(d_x, d_y) / std::sqrt(2.f));

		if (cos >= std::cos(VAR->PIH))
			center.y = cl.y;
		else if (cos <= std::cos(7 * VAR->PIH))
			center.y = cl.y;
		else if (sin >= std::sin(3 * VAR->PIH))
			center.x = cl.x;
		else if (sin <= std::sin(-3 * VAR->PIH))
			center.x = cl.x;
		else if (cos >= 0) {
			if (sin >= 0)
				center = sf::Vector2f(cl.x + hyp, cl.y - hyp);
			else
				center = sf::Vector2f(cl.x + hyp, cl.y + hyp);
		}
		else {
			if (sin >= 0)
				center = sf::Vector2f(cl.x - hyp, cl.y - hyp);
			else
				center = sf::Vector2f(cl.x - hyp, cl.y + hyp);
		}
	}
	line[1].position = center;
}

void ToolLiner::drawLine(sf::Vector2f pos_ini, sf::Vector2f pos_fin) {
	float x1, x2, y1, y2;

	x1 = pos_ini.x; x2 = pos_fin.x;
	y1 = pos_ini.y; y2 = pos_fin.y;

	int delta_x = x2 - x1;
	signed char const ix = (delta_x > 0) - (delta_x < 0);
	delta_x = std::abs(delta_x) << 1;
	int delta_y = y2 - y1;
	signed char const iy = (delta_y > 0) - (delta_y < 0);
	delta_y = std::abs(delta_y) << 1;

	pos_fin = sf::Vector2f(x1, y1); LAYER->draw_brush(*BRUSH, pos_fin);
	if (delta_x >= delta_y) {
		int error(delta_y - (delta_x >> 1));
		while (x1 != x2) {
			if (error >= 0 && (error || ix > 0))
				{error -= delta_x; y1 += iy;}
			error += delta_y; x1 += ix;
			pos_fin = sf::Vector2f(x1, y1); LAYER->draw_brush(*BRUSH, pos_fin);
		}
	}
	else {
		int error(delta_x - (delta_y >> 1));
		while (y1 != y2) {
			if (error >= 0 && (error || iy > 0))
				{error -= delta_y; x1 += ix;}
			error += delta_x; y1 += iy;
			pos_fin = sf::Vector2f(x1, y1); LAYER->draw_brush(*BRUSH, pos_fin);
		}
	}
	IO->setExClick(pos_fin);
}

void ToolLiner::displayLine() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	line[0].color = color;
	line[1].color = color;
	APP->fenetre->draw(line, 2, sf::Lines);
}