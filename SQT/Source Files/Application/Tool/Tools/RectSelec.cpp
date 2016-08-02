#include "RectSelec.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Selection/SelectionController.h"

using namespace nSet;

RectSelec::RectSelec() {
	numero_outil = nTol::RECTSELEC;
}

void RectSelec::selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos) {
	static sf::Vector2i ex_pos;

	if (ex_pos != pos) {
		sf::VertexArray line(sf::LinesStrip, 2);
		oriented_lines.clear();

		sf::IntRect rect = sf::IntRect(std::min(pos.x, pos_ini.x), std::min(pos.y, pos_ini.y), std::abs(pos.x - pos_ini.x) + 1, std::abs(pos.y - pos_ini.y) + 1);
		for (int i = rect.left; i <= rect.left + rect.width - 1; i++) {
			line[0].position = sf::Vector2f(i, rect.top);
			line[1].position = sf::Vector2f(i + 1, rect.top);
			oriented_lines.push_back(oLine(line, UP, i, rect.top));

			line[0].position = sf::Vector2f(i, rect.top + rect.height);
			line[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
			oriented_lines.push_back(oLine(line, DOWN, i, rect.top + rect.height - 1));
		}
		for (int j = rect.top; j <= rect.top + rect.height - 1; j++) {
			line[0].position = sf::Vector2f(rect.left, j);
			line[1].position = sf::Vector2f(rect.left, j + 1);
			oriented_lines.push_back(oLine(line, LEFT, rect.left, j));

			line[0].position = sf::Vector2f(rect.left + rect.width, j);
			line[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
			oriented_lines.push_back(oLine(line, RIGHT, rect.left + rect.width - 1, j));
		}

		ex_pos = pos;
	}
}

void RectSelec::use() {
	sf::Vector2i center = INPUT->getPixel();

	SELEC->move();

	if (INPUT->again(Qt::LeftButton))
		ex_center = center;

	if (INPUT->pressed(Qt::LeftButton))
		selec_rect(ex_center, center);
	else if (INPUT->released(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Shift) && INPUT->pressed(Qt::Key_Control))
			endSelection(INTERSECT);
		else if (INPUT->pressed(Qt::Key_Control))
			endSelection(SUB);
		else if (INPUT->pressed(Qt::Key_Shift))
			endSelection(ADD);
		else
			endSelection(NO_FUSION);
	}
}