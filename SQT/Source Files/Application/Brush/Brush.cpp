#include "Brush.h"

#include "Source Files/Application/App.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/InputController.h"

void Brush::select() {
	emit selected();
}

void Brush::checkSize(sf::Vector2i size_to_check) {
	if (default_brush)
		if (size != size_to_check) {
			create(size_to_check);
			createLines();
		}
}

void Brush::unselect() {
	emit unselected();
}

sf::Vector2f Brush::getPointedPosition() {
	return truePosition(INPUT->getPosition());
}

sf::Vector2f Brush::getExPosition() {
	return truePosition(BRUSH_CONTROLLER->getExPosition());
}

void Brush::setColor(sf::Color color) {
	sprite.setColor(color);
}

void Brush::createPreview() {
	create(sf::Vector2i(17, 17));
	preview_texture = texture;
}

void Brush::createLines() {
	sf::VertexArray line(sf::LinesStrip, 2);

	lines.lines.clear();
	
	sf::Image image = texture.copyToImage();
	setSize(VECTOR2I(image.getSize()));
	lines.pos = sf::Vector2f(parity.x == 0 ? 0 : 0.5f, parity.y == 0 ? 0 : 0.5f);

	FOR_I (size.x)
		FOR_J (size.y)
			if (image.getPixel(i, j).a > 0) {
				int x = i - int(hsize.x);
				int y = j - int(hsize.y);
				//Gauche
				if (i - 1 >= 0) {
					if (image.getPixel(i - 1, j).a == 0) {
						line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y + 1); lines.lines.push_back(line);
					}
				}
				else {
					line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y + 1); lines.lines.push_back(line);
				}

				//Droite
				if (i + 1 < size.x) {
					if (image.getPixel(i + 1, j).a == 0) {
						line[0].position = sf::Vector2f(x + 1, y); line[1].position = sf::Vector2f(x + 1, y + 1); lines.lines.push_back(line);
					}
				}
				else {
					line[0].position = sf::Vector2f(x + 1, y); line[1].position = sf::Vector2f(x + 1, y + 1); lines.lines.push_back(line);
				}

				//Haut
				if (j - 1 >= 0) {
					if (image.getPixel(i, j - 1).a == 0) {
						line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x + 1, y); lines.lines.push_back(line);
					}
				}
				else {
					line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x + 1, y); lines.lines.push_back(line);
				}

				//Bas
				if (j + 1 < size.y) {
					if (image.getPixel(i, j + 1).a == 0) {
						line[0].position = sf::Vector2f(x, y + 1); line[1].position = sf::Vector2f(x + 1, y + 1); lines.lines.push_back(line);
					}
				}
				else {
					line[0].position = sf::Vector2f(x, y + 1); line[1].position = sf::Vector2f(x + 1, y + 1); lines.lines.push_back(line);
				}
			}
}

void Brush::setDisplayPosition(sf::Vector2f center) {
	center = truePosition(center);

	if (lines.pos != center) {
		sf::Vector2f delta_move = center - lines.pos;
		FOR_I (lines.lines.size()) {
			lines.lines[i][0].position += delta_move;
			lines.lines[i][1].position += delta_move;
		}
		
		lines.pos = center;
	}
}

void Brush::display(sf::Vector2f center) {
	setDisplayPosition(center);
	display();
}

void Brush::display() {
	setDisplayPosition(BRUSH_CONTROLLER->getDisplayPosition());

	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	FOR_I (lines.lines.size()) {
		lines.lines[i][0].color = color;
		lines.lines[i][1].color = color;

		APP->getWindow().draw(lines.lines[i]);
	}
}

void Brush::setPosition(sf::Vector2f position) {
	sprite.setPosition(position - hsize);
	RES->getShader(nRer::usual).setParameter("pos_brosse", position - hsize);
}

void Brush::move(sf::Vector2f delta_move) {
	sprite.move(delta_move);
	RES->getShader(nRer::usual).setParameter("pos_brosse", sprite.getPosition() - hsize);
}

void Brush::setSize(sf::Vector2i size_to_set) {
	size = size_to_set;
	hsize = Fonction::centerCorner(size_to_set);
	parity.x = size.x % 2;
	parity.y = size.y % 2;
}

sf::Vector2f Brush::truePosition(sf::Vector2f position) {
	if (parity.x == 0) //Taille x paire
		position.x = floor(position.x) + (std::abs(position.x - int(position.x)) >= 0.5f);
	else
		position.x = floor(position.x) + 0.5f;

	if (parity.y == 0) //Taille y paire
		position.y = floor(position.y) + (std::abs(position.y - int(position.y)) >= 0.5f);
	else
		position.y = floor(position.y) + 0.5f;

	return position;
}