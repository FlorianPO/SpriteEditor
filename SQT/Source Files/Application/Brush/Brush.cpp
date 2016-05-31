#include "Source Files/Application/Brush/Brush.h"

#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Fonction/Fonction.h"

sf::Vector2f CBrush::centerOf(sf::Vector2f center) {
	if (parity.x == 0) //Taille x paire
		center.x = floor(center.x) + (std::abs(center.x - int(center.x)) >= 0.5f);
	else
		center.x = floor(center.x) + 0.5f;

	if (parity.y == 0) //Taille y paire
		center.y = floor(center.y) + (std::abs(center.y - int(center.y)) >= 0.5f);
	else
		center.y = floor(center.y) + 0.5f;

	return center;
}

bool CBrush::onCadre() {
	sf::IntRect cadre_selec = SELEC->getCadre();

	if (sprite.getPosition().x + 2 * hsize.x < cadre_selec.left)
		return false;
	if (sprite.getPosition().x >= cadre_selec.left + cadre_selec.width)
		return false;
	if (sprite.getPosition().y + 2 * hsize.y < cadre_selec.top)
		return false;
	if (sprite.getPosition().y >= cadre_selec.top + cadre_selec.height)
		return false;

	return true;
}

void CBrush::select() {
	checkSize(BRUSH_CONTROLLER->getDefaultSize());
	emit selected();
}

void CBrush::checkSize(sf::Vector2i size_to_check) {
	if (default_brush)
		if (size != size_to_check) {
			create(size_to_check);
			createLines();
		}
}

void CBrush::unselect() {
	emit unselected();
}

void CBrush::setPosition(sf::Vector2f center) {
	sprite.setPosition(center - hsize);
	RES->getShader(CRes::usual)->setParameter("pos_brosse", center - hsize);
}

void CBrush::setColor(sf::Color color) {
	sprite.setColor(color);
}

void CBrush::createPreview() {
	create(sf::Vector2i(17, 17));
	preview_texture = texture;
}

void CBrush::createLines() {
	sf::VertexArray line(sf::LinesStrip, 2);

	lines.clear();
	sf::Image image = texture.copyToImage();
	setSize(sf::Vector2i(image.getSize().x, image.getSize().y));

	for (int i=0; i < size.x; i++)
		for (int j=0; j < size.y; j++)
			if (image.getPixel(i, j).a > 0)
			{
				int x = i - int(hsize.x); 
				int y = j - int(hsize.y);
				//Gauche
				if (i-1 >= 0) {
					if (image.getPixel(i-1, j).a == 0) 
					{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y+1); lines.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y+1); lines.push_back(line);}
				
				//Droite
				if (i+1 < size.x) {
					if (image.getPixel(i+1, j).a == 0)
					{line[0].position = sf::Vector2f(x+1, y); line[1].position = sf::Vector2f(x+1, y+1); lines.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x+1, y); line[1].position = sf::Vector2f(x+1, y+1); lines.push_back(line);}
				
				//Haut
				if (j-1 >= 0) {
					if (image.getPixel(i, j-1).a == 0)
					{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x+1, y); lines.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x+1, y); lines.push_back(line);}

				//Bas
				if (j+1 < size.y) {
					if (image.getPixel(i, j+1).a == 0)
					{line[0].position = sf::Vector2f(x, y+1); line[1].position = sf::Vector2f(x+1, y+1); lines.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y+1); line[1].position = sf::Vector2f(x+1, y+1); lines.push_back(line);}
			}

	lines_init = lines;
}

void CBrush::afficher(sf::Vector2f center) {
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i][0].position.x = floor(center.x + lines_init[i][0].position.x);
		lines[i][0].position.y = floor(center.y + lines_init[i][0].position.y);

		lines[i][1].position.x = floor(center.x + lines_init[i][1].position.x);
		lines[i][1].position.y = floor(center.y + lines_init[i][1].position.y);

		lines[i][0].color = color;
		lines[i][1].color = color;
		APP->fenetre->draw(lines[i]);
	}
}

void CBrush::setSize(sf::Vector2i size_to_set) {
	size = size_to_set;
	hsize = CFonction::centerCorner(size_to_set);
	parity.x = size.x % 2;
	parity.y = size.y % 2;
}