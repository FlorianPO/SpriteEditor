#include "Source Files/Application/Tool/Tools/RectSelec.h"

#include "Source Files/Application/App.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Retour/Retour.h"
#include <QtWidgets/QApplication>

CRectSelec::CRectSelec(void) {
	numero_outil = CTool::RECTSELEC;

	active = false;
}

void CRectSelec::afficher() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i < conf_lines.size(); i++) {
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre->draw(conf_lines[i].line);
	}
}

void CRectSelec::selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos) {
	static sf::Vector2i ex_pos;

	if (ex_pos != pos) {
		sf::VertexArray line(sf::LinesStrip, 2);
		conf_lines.clear();

		rect = sf::IntRect(std::min(pos.x, pos_ini.x), std::min(pos.y, pos_ini.y), std::abs(pos.x - pos_ini.x) + 1, std::abs(pos.y - pos_ini.y) + 1);

		for (int i = rect.left; i <= rect.left + rect.width - 1; i++) {
			line[0].position = sf::Vector2f(i, rect.top);
			line[1].position = sf::Vector2f(i + 1, rect.top);
			conf_lines.push_back(CTool::creer_conf_line(line, 0, i, rect.top));

			line[0].position = sf::Vector2f(i, rect.top + rect.height);
			line[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
			conf_lines.push_back(CTool::creer_conf_line(line, 2, i, rect.top + rect.height - 1));
		}
		for (int j = rect.top; j <= rect.top + rect.height - 1; j++) {
			line[0].position = sf::Vector2f(rect.left, j);
			line[1].position = sf::Vector2f(rect.left, j + 1);
			conf_lines.push_back(CTool::creer_conf_line(line, 3, rect.left, j));

			line[0].position = sf::Vector2f(rect.left + rect.width, j);
			line[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
			conf_lines.push_back(CTool::creer_conf_line(line, 1, rect.left + rect.width - 1, j));
		}

		ex_pos = pos;
	}
}
void CRectSelec::end_selec(int type) {
	switch (type) {
		case 0:	SELEC->createSelection(rect, conf_lines);
			break;
		case 1: SELEC->addSelection(rect, conf_lines);
			break;
		case 2: SELEC->subSelection(rect, conf_lines);
			break;
		case 3: SELEC->intersectSelection(rect, conf_lines);
			break;
	}
	conf_lines.clear();
}

void CRectSelec::use() {
	sf::Vector2i center = IO->getPixel();

	if (IO->again(Qt::LeftButton)) {
		ex_center = center;
		active = true;
	}

	if (active) {
		if (IO->pressed(Qt::LeftButton))
			selec_rect(ex_center, center);
		else {
			Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
			if (special & Qt::ShiftModifier && special & Qt::ControlModifier)
				end_selec(3);
			else if (special & Qt::ControlModifier)
				end_selec(2);
			else if (special & Qt::ShiftModifier)
				end_selec(1);
			else
				end_selec(0);
			active = false;
		}
	}
}