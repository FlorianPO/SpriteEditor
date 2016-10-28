#include "Curseur.h"

#include "Source Files/Application/App.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "CurseurUndo.h"

Curseur* Curseur::_t;

Curseur::Curseur() {
	///// Cursor construction
	sf::VertexArray line = sf::VertexArray(sf::LinesStrip, 2);
	float a = 3;

	line[0].position.x = -a; line[0].position.y = -a;
	line[1].position.x = a; line[1].position.y = a;
	lines.push_back(line);
	line[0].position.x = -a; line[0].position.y = a;
	line[1].position.x = a; line[1].position.y = -a;
	lines.push_back(line);

	line[0].position.x = -a * std::sqrt(2.f); line[0].position.y = 0;
	line[1].position.x = a * std::sqrt(2.f); line[1].position.y = 0;
	lines.push_back(line);
	line[0].position.x = 0; line[0].position.y = a * std::sqrt(2.f);
	line[1].position.x = 0; line[1].position.y = -a * std::sqrt(2.f);
	lines.push_back(line);
	//
}

void Curseur::display() {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	FOR_I (lines.size()) {
		lines[i][0].color = color;
		lines[i][1].color = color;
		APP->getWindow().draw(lines[i]);
	}
}

void Curseur::setPosition(const sf::Vector2f& pos) {
	FOR_I (lines.size()) {
		lines[i][0].position -= position - pos;
		lines[i][1].position -= position - pos;
	}
	position = pos;
}

void Curseur::gerer(const sf::Sprite& sprite) {
	if (!INPUT->pressed(Qt::Key_Shift)) {
		if (INPUT->again(Qt::RightButton))
			start_pos = position;	

		if (INPUT->pressed(Qt::RightButton))
			setPosition(INPUT->getPosition());
		else if (INPUT->released(Qt::RightButton))
			UNDO->push(*new CurseurUndo(position, start_pos));
	}
	else
		if (INPUT->again(Qt::RightButton)) {
			auto tmp = Fonction::selecPoint(sprite, INPUT->getPosition(), static_cast<unsigned int>(-1));
			if (tmp != NULL) {
				start_pos = position;
				setPosition(*tmp);
				UNDO->push(*new CurseurUndo(position, start_pos));
			}
		}
}

void Curseur::init(sf::Sprite& sprite) {
	Fonction::setOriginGlobally(sprite, position);
}