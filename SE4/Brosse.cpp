#include "Brosse.h"
#include "Res.h"
#include "Var.h"
#include "Selec.h"
#include "App.h"

CBrosse* BROSSE;

CBrosse::CBrosse(void)
{
	size = sf::Vector2i(5, 5);
	changeBrosse(1);
}

CBrosse::~CBrosse(void)
{
}

void CBrosse::changeBrosse(int x)
{
	static int ex_x = -1;
	if (x > 4) x = 0;
	if (x < 0) x = 4;

	static sf::Vector2i ex_size = size;
	if (ex_size != size)
	{
		if (size.x < 1) size.x = 1;
		else if (size.x > 999) size.x = 999;
		if (size.y < 1) size.y = 1;
		else if (size.y > 999) size.y = 999;
	}

	which_brosse = x;

	if (ex_x != x || ex_size != size)
	{
		sf::Image image;
		if (x == 0) //Pixel
		{
			image.create(1, 1, sf::Color::White);
			b_texture.loadFromImage(image);
			b_sprite.setTexture(b_texture, true);
		}
		else if (x == 1) //Cercle plein
		{
			image.create(size.x, size.y, sf::Color::Transparent);
			cercle(size.x / 2, size.y / 2, &image);
			b_texture.loadFromImage(image);
			b_sprite.setTexture(b_texture, true);
		}
		else if (x == 2) //Carre plein
		{
			image.create(size.x, size.y, sf::Color::Transparent);
			carre(size.x / 2, size.y / 2, &image);
			b_texture.loadFromImage(image);
			b_sprite.setTexture(b_texture, true);
		}
		else if (x == 3) //Cercle vide
		{
			image.create(size.x, size.y, sf::Color::Transparent);
			cercle(size.x / 2, size.y / 2, &image, false);
			b_texture.loadFromImage(image);
			b_sprite.setTexture(b_texture, true);
		}
		else if (x == 4) //Carre vide
		{
			image.create(size.x, size.y, sf::Color::Transparent);
			carre(size.x / 2, size.y / 2, &image, false);
			b_texture.loadFromImage(image);
			b_sprite.setTexture(b_texture, true);
		}
		create_from(&image);
	}
	ex_x = x;
	ex_size = size;
}

int CBrosse::alpha_carre(sf::Vector2f pos, sf::Vector2f center)
{
	float ax = std::abs((pos.x - center.x) / (center.x + 1));
	float ay = std::abs((pos.y - center.y) / (center.y + 1));
	return 255 - std::max(ax, ay) * 254;
}

void CBrosse::carre(float rx, float ry, sf::Image* image, bool plein)
{
	sf::Vector2f center = sf::Vector2f(image->getSize().x / 2, image->getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image->getSize().x % 2 == 0)*0.5f, (image->getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	if (plein)
	{
		for (int i = 0; i < image->getSize().x; i++)
		{
			pos = sf::Vector2f(i + delta.x, delta.y);
			image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
		}
		for (int j = 1; j < image->getSize().y - 1; j++)
			for (int i = 0; i < image->getSize().x; i++)
			{
				pos = sf::Vector2f(i + delta.x, j + delta.y);
				image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
			}
		for (int i = 0; i < image->getSize().x; i++)
		{
			pos = sf::Vector2f(i + delta.x, image->getSize().y - 1 + delta.y);
			image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_carre(pos, center)));
		}
	}
	else
	{
		for (int i = 0; i < image->getSize().x; i++)
			image->setPixel(i, 0, sf::Color::White);
		for (int j = 1; j < image->getSize().y - 1; j++)
		{
			image->setPixel(0, j, sf::Color::White);
			image->setPixel(image->getSize().x - 1, j, sf::Color::White);
		}
		for (int i = 0; i < image->getSize().x; i++)
			image->setPixel(i, image->getSize().y - 1, sf::Color::White);
	}
}

int CBrosse::alpha_cercle(sf::Vector2f pos, sf::Vector2f center)
{
	return 255 - std::sqrt(std::pow((pos.x - center.x) / (center.x + 1), 2) + std::pow((pos.y - center.y) / (center.y + 1), 2)) * 255;
}

void CBrosse::cercle(float rx, float ry, sf::Image* image, bool plein)
{
	sf::Vector2f center = sf::Vector2f(image->getSize().x / 2, image->getSize().y / 2);
	sf::Vector2f delta = sf::Vector2f((image->getSize().x % 2 == 0)*0.5f, (image->getSize().y % 2 == 0)*0.5f);
	sf::Vector2f pos;

	float rxSq = rx*rx;
	float rySq = ry*ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq*y;

	if (plein)
		for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++)
		{
			pos = sf::Vector2f(center.x + (x - delta.x), i);
			image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			pos = sf::Vector2f(center.x - (x - delta.x), i);
			image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
		}
	else
	{
		image->setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
		image->setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image->setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
		image->setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);
	}

	//Region 1
	p = rySq - (rxSq*ry) + (0.25*rxSq);
	while (px < py)
	{
		x++;
		px = px + 2 * rySq;
		if (p < 0)
			p = p + rySq + px;
		else
		{
			y--;
			py = py - 2 * rxSq;
			p = p + rySq + px - py;
		}
		if (plein)
			for (float i = center.y - (y - delta.y); i <= center.y + (y - delta.y); i++)
			{
				pos = sf::Vector2f(center.x + (x - delta.x), i);
				image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
				pos = sf::Vector2f(center.x - (x - delta.x), i);
				image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			}
		else
		{
			image->setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
			image->setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
			image->setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
			image->setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);
		}
	}
	//Region 2
	p = rySq*(x + 0.5)*(x + 0.5) + rxSq*(y - 1)*(y - 1) - rxSq*rySq;
	while (y > 0)
	{
		y--;
		py = py - 2 * rxSq;
		if (p > 0)
			p = p + rxSq - py;
		else
		{
			x++;
			px = px + 2 * rySq;
			p = p + rxSq - py + px;
		}
		if (plein)
			for (float i = center.x - (x - delta.x); i <= center.x + (x - delta.x); i++)
			{
				pos = sf::Vector2f(i, center.y + (y - delta.y));
				image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
				pos = sf::Vector2f(i, center.y - (y - delta.y));
				image->setPixel(pos.x, pos.y, sf::Color(255, 255, 255, alpha_cercle(pos, center)));
			}
		else
		{
			image->setPixel(center.x + (x - delta.x), center.y - (y - delta.y), sf::Color::White);
			image->setPixel(center.x + (x - delta.x), center.y + (y - delta.y), sf::Color::White);
			image->setPixel(center.x - (x - delta.x), center.y + (y - delta.y), sf::Color::White);
			image->setPixel(center.x - (x - delta.x), center.y - (y - delta.y), sf::Color::White);
		}
	}
}

void CBrosse::create_from(sf::Image* image)
{
	sf::VertexArray line(sf::LinesStrip, 2);

	l.clear();
	parite = sf::Vector2i(int(image->getSize().x)%2, int(image->getSize().y)%2);
	hsize = sf::Vector2f(image->getSize().x/2.f, image->getSize().y/2.f);

	//Interieur
	for (int i=0; i<image->getSize().x; i++)
	{
		for (int j=0; j<image->getSize().y; j++)
		{
			if (image->getPixel(i, j).a > 0)
			{
				int x = i - int(hsize.x); 
				int y = j - int(hsize.y);
				//Gauche
				if (i-1 >= 0)
				{
					if (image->getPixel(i-1, j).a == 0) 
					{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y+1); l.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x, y+1); l.push_back(line);}
				
				//Droite
				if (i+1 < image->getSize().x)
				{
					if (image->getPixel(i+1, j).a == 0)
					{line[0].position = sf::Vector2f(x+1, y); line[1].position = sf::Vector2f(x+1, y+1); l.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x+1, y); line[1].position = sf::Vector2f(x+1, y+1); l.push_back(line);}
				
				//Haut
				if (j-1 >= 0)
				{
					if (image->getPixel(i, j-1).a == 0)
					{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x+1, y); l.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y); line[1].position = sf::Vector2f(x+1, y); l.push_back(line);}

				//Bas
				if (j+1 < image->getSize().y)
				{
					if (image->getPixel(i, j+1).a == 0)
					{line[0].position = sf::Vector2f(x, y+1); line[1].position = sf::Vector2f(x+1, y+1); l.push_back(line);}
				}
				else
				{line[0].position = sf::Vector2f(x, y+1); line[1].position = sf::Vector2f(x+1, y+1); l.push_back(line);}
	}	}	}

	l_ini = l;
}

sf::Vector2f CBrosse::centerOf(sf::Vector2f center)
{
	if (parite.x == 0) //Taille x paire
		center.x = floor(center.x) + (std::abs(center.x - int(center.x)) >= 0.5f);
	else
		center.x = floor(center.x) + 0.5f;

	if (parite.y == 0) //Taille y paire
		center.y = floor(center.y) + (std::abs(center.y - int(center.y)) >= 0.5f);
	else
		center.y = floor(center.y) + 0.5f;

	return center;
}

void CBrosse::setColor(sf::Color* color)
{
	b_sprite.setColor(*color);
}

void CBrosse::changeOpacity()
{
	RES->getShader(CRes::usual)->setParameter("opacity", VAR->opacity);
}

void CBrosse::setPosition(sf::Vector2f center)
{
	b_sprite.setPosition(center - hsize);
	RES->getShader(CRes::usual)->setParameter("pos_brosse", center - hsize);
}

bool CBrosse::onCadre()
{
	sf::IntRect cadre_selec = SELEC->getCadre();

	if (b_sprite.getPosition().x + 2 * hsize.x < cadre_selec.left)
		return false;
	if (b_sprite.getPosition().x >= cadre_selec.left + cadre_selec.width)
		return false;
	if (b_sprite.getPosition().y + 2 * hsize.y < cadre_selec.top)
		return false;
	if (b_sprite.getPosition().y >= cadre_selec.top + cadre_selec.height)
		return false;

	return true;
}

void CBrosse::afficher(sf::Vector2f center)
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i<l.size(); i++)
	{
		l[i][0].position.x = floor(center.x + l_ini[i][0].position.x);
		l[i][0].position.y = floor(center.y + l_ini[i][0].position.y);

		l[i][1].position.x = floor(center.x + l_ini[i][1].position.x);
		l[i][1].position.y = floor(center.y + l_ini[i][1].position.y);

		l[i][0].color = color;
		l[i][1].color = color;
		APP->fenetre.draw(l[i]);
	}
}