#include "TLiner.h"

#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

bool TLiner::hasSmoothLine() {
	return INPUT->getSmoothList().size() > 0;
}

void TLiner::calculateLine() {
	sf::Vector2f cl = BRUSH->getExPosition();
	line[0].position = cl;

	sf::Vector2f pos = BRUSH->getPointedPosition();
	if (INPUT->pressed(Qt::Key_Control)) {
		float d_x = pos.x - cl.x;
		float d_y = pos.y - cl.y;

		float cos = d_x / Fonction::hypothenus(d_x, d_y);
		float sin = -d_y / Fonction::hypothenus(d_x, d_y);

		float hyp = floor(Fonction::hypothenus(d_x, d_y) / std::sqrt(2.f));

		if (cos >= std::cos(PIH))
			pos.y = cl.y;
		else if (cos <= std::cos(7 * PIH))
			pos.y = cl.y;
		else if (sin >= std::sin(3 * PIH))
			pos.x = cl.x;
		else if (sin <= std::sin(-3 * PIH))
			pos.x = cl.x;
		else if (cos >= 0) {
			if (sin >= 0)
				pos = sf::Vector2f(cl.x + hyp, cl.y - hyp);
			else
				pos = sf::Vector2f(cl.x + hyp, cl.y + hyp);
		}
		else {
			if (sin >= 0)
				pos = sf::Vector2f(cl.x - hyp, cl.y - hyp);
			else
				pos = sf::Vector2f(cl.x - hyp, cl.y + hyp);
		}
	}
	line[1].position = pos;
}

void TLiner::drawLine(sf::Vector2f pos_from, sf::Vector2f pos_to) {
	_drawLine(pos_from, pos_to);

	setLayerChanged();
}

void TLiner::_drawLine(sf::Vector2f pos_from, sf::Vector2f pos_to) {
	using namespace nRer;
	RES->getShader(usual).setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
	RES->getShader(usual).setParameter("background", LAYER->getTexture());

	if (pos_from != pos_to) {
		float x1, x2, y1, y2;
		x1 = pos_from.x; x2 = pos_to.x;
		y1 = pos_from.y; y2 = pos_to.y;

		int delta_x = x2 - x1;
		signed char const ix = (delta_x > 0) - (delta_x < 0);
		delta_x = std::abs(delta_x) << 1;
		int delta_y = y2 - y1;
		signed char const iy = (delta_y > 0) - (delta_y < 0);
		delta_y = std::abs(delta_y) << 1;

		if (delta_x >= delta_y) {
			int error(delta_y - (delta_x >> 1));
			while (x1 != x2) {
				if (error >= 0 && (error || ix > 0)) {
					error -= delta_x; 
					y1 += iy;
				}
				error += delta_y; x1 += ix;
				LAYER->drawBrush(*BRUSH, sf::Vector2f(x1, y1), RES->getRender(usual));
			}
		}
		else {
			int error(delta_x - (delta_y >> 1));
			while (y1 != y2) {
				if (error >= 0 && (error || iy > 0)) {
					error -= delta_y; 
					x1 += ix;
				}
				error += delta_x; y1 += iy;
				LAYER->drawBrush(*BRUSH, sf::Vector2f(x1, y1), RES->getRender(usual));
			}
		}
	}
	else
		LAYER->drawBrush(*BRUSH, pos_to, RES->getRender(usual));
}

void TLiner::drawSmoothLine() {
	if (hasSmoothLine()) {
		auto list = INPUT->getSmoothList();
		for (int i = 1; i < list.size(); i++)
			_drawLine(BRUSH->truePosition(list[i - 1]), BRUSH->truePosition(list[i]));
		setLayerChanged();
	}
}

void TLiner::displayLine() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	line[0].color = color;
	line[1].color = color;
	APP->getWindow().draw(line, 2, sf::Lines);
}