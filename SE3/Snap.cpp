#include "Snap.h"
#include "App.h"
#include "Calque.h"
#include "Selec.h"
#include "Var.h"
#include "Fonction.h"
#include "Input.h"
#include "Retour.h"

CSnap::CSnap()
{
	numero_outil = COutil::SNAP;
}


CSnap::~CSnap()
{
}

void CSnap::afficher()
{
	sf::Color color = sf::Color(100 * bool(rand() % 2), 100 * bool(rand() % 2), 100 * bool(rand() % 2));
	for (int i = 0; i<conf_lines.size(); i++)
	{
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre.draw(conf_lines[i].line);
	}
}


void CSnap::snap(sf::Vector2i pos_ini, sf::Vector2i pos)
{
	bit_image.create(CALQUE->getImage()->getSize().x, CALQUE->getImage()->getSize().y, SELEC->ident_color);

	sf::VertexArray l(sf::LinesStrip, 2);
	conf_lines.clear();

	rect = sf::IntRect(std::min(pos_ini. x, pos.x), std::min(pos_ini.y, pos.y), std::abs(pos_ini.x - pos.x)+1, std::abs(pos_ini.y - pos.y)+1);
	
	for (int i = rect.left; i < rect.left + rect.width; i++)
	{
		//Haut
		l[0].position = sf::Vector2f(i, rect.top);
		l[1].position = sf::Vector2f(i + 1, rect.top);
		conf_lines.push_back(COutil::creer_conf_line(l, 0, i, rect.top));
		//Bas
		l[0].position = sf::Vector2f(i, rect.top + rect.height);
		l[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
		conf_lines.push_back(COutil::creer_conf_line(l, 2, i, rect.top + rect.height));
	}
	for (int j = rect.top; j < rect.top + rect.height; j++)
	{
		//Gauche
		l[0].position = sf::Vector2f(rect.left, j);
		l[1].position = sf::Vector2f(rect.left, j + 1);
		conf_lines.push_back(COutil::creer_conf_line(l, 3, rect.left, j));
		//Droite
		l[0].position = sf::Vector2f(rect.left + rect.width, j);
		l[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
		conf_lines.push_back(COutil::creer_conf_line(l, 1, rect.left + rect.width, j));
	}
}

bool CSnap::pixelCheck(sf::Color color)
{
	return std::abs(target_color.a - color.a) <= VAR->seuil
		&& std::abs(target_color.r - color.r) <= VAR->seuil
		&& std::abs(target_color.g - color.g) <= VAR->seuil
		&& std::abs(target_color.b - color.b) <= VAR->seuil;
}

void CSnap::snapping(sf::IntRect rect, sf::Vector2i pos_click)
{
	sf::VertexArray l(sf::LinesStrip, 2);
	conf_lines.clear();

	rect.left -= CCalque::_t->getPosition_i().x;
	rect.top -= CCalque::_t->getPosition_i().y;
	if (CFonction::checkCadre(&rect, sf::IntRect(0, 0, CCalque::_t->getTexture()->getSize().x, CCalque::_t->getTexture()->getSize().y)))
		return;

	test_image = CALQUE->getImage();
	target_color = CFonction::getColor(pos_click, test_image);

	for (int i = rect.left; i <= rect.left + rect.width-1; i++)
	{
		bool var = false;
		for (int j = rect.top; j <= rect.top + rect.height-1; j++)
		{
			if (!var && !pixelCheck(test_image->getPixel(i, j)))
			{
				l[0].position = sf::Vector2f(i, j);
				l[1].position = sf::Vector2f(i + 1, j);
				conf_lines.push_back(COutil::creer_conf_line(l, 0, i, j));
				var = true;
			}
			if (var)
			{
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (j == bit_image.getSize().y - 1 || pixelCheck(test_image->getPixel(i, j + 1)) || j == rect.top + rect.height - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Bas
				{
					l[0].position = sf::Vector2f(i, j + 1);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(COutil::creer_conf_line(l, 2, i, j));
					var = false;
				}
			}
		}
	}

	for (int j = rect.top; j <= rect.top + rect.height-1; j++)
	{
		bool var = false;
		for (int i = rect.left; i <= rect.left + rect.width-1; i++)
		{
			if (!var && !pixelCheck(test_image->getPixel(i, j)))
			{
				l[0].position = sf::Vector2f(i, j);
				l[1].position = sf::Vector2f(i, j + 1);
				conf_lines.push_back(COutil::creer_conf_line(l, 3, i, j));
				var = true;
			}
			if (var)
			{
				bit_image.setPixel(i, j, SELEC->blend_color);
				if (i == bit_image.getSize().x - 1 || pixelCheck(test_image->getPixel(i + 1, j)) || i == rect.left + rect.width - 1 && bit_image.getPixel(i, j) == SELEC->blend_color) //Droite
				{
					l[0].position = sf::Vector2f(i + 1, j);
					l[1].position = sf::Vector2f(i + 1, j + 1);
					conf_lines.push_back(COutil::creer_conf_line(l, 1, i, j));
					var = false;
				}
			}
		}
	}
}

void CSnap::end_selec(int type)
{
	if (conf_lines.size() > 0)
	{
		COutil::move_line(&conf_lines, CCalque::_t->getPosition_i());

		int x_min = conf_lines[0].x, y_min = conf_lines[0].y, x_max = conf_lines[0].x, y_max = conf_lines[0].y;
		for (int i = 0; i<conf_lines.size(); i++)
		{
			if (conf_lines[i].x < x_min) { x_min = conf_lines[i].x; }
			else if (conf_lines[i].x > x_max) { x_max = conf_lines[i].x; }
			if (conf_lines[i].y < y_min) { y_min = conf_lines[i].y; }
			else if (conf_lines[i].y > y_max) { y_max = conf_lines[i].y; }
		}
		SELEC->new_selec(sf::IntRect(x_min, y_min, x_max - x_min + 1, y_max - y_min + 1), &bit_image, &conf_lines, type);
		conf_lines.clear();
	}
}

void CSnap::use()
{
	static bool active = false;
	static sf::Vector2i pos_click;
	static int key;
	sf::Vector2i center = IO->getPixel();

	if (IO->again(CInput::MLeft))
	{
		pos_click = IO->getPixel();
		active = true;
	}

	if (active)
	{
		if (IO->pressed(CInput::MLeft))
			snap(pos_click, center);
		else
		{
			RETOUR_VECTOR.push_back(IO);
			IO->creer_retour();
			
			snapping(rect, pos_click);
			if (IO->pressed(CInput::Ctrl) && IO->pressed(CInput::Maj))
				end_selec(3);
			else if (IO->pressed(CInput::Ctrl))
				end_selec(2);
			else if (IO->pressed(CInput::Maj))
				end_selec(1);
			else
				end_selec(0);
			active = false;
		}
	}
	
}