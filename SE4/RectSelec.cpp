#include "RectSelec.h"
#include "App.h"
#include "Input.h"
#include "Gui.h"
#include "Selec.h"
#include "Retour.h"

CRectSelec::CRectSelec(void)
{
	numero_outil = COutil::RECTSELEC;

	active = false;
	int key = -1;
}

CRectSelec::~CRectSelec(void)
{
	GUI->cancelCadreReplacement();
}

void CRectSelec::afficher()
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i < conf_lines.size(); i++)
	{
		conf_lines[i].line[0].color = color;
		conf_lines[i].line[1].color = color;
		APP->fenetre.draw(conf_lines[i].line);
	}
}

void CRectSelec::selec_rect(sf::Vector2i pos_ini, sf::Vector2i pos)
{
	static sf::Vector2i ex_pos;

	if (ex_pos != pos)
	{
		sf::VertexArray line(sf::LinesStrip, 2);
		conf_lines.clear();

		rect = sf::IntRect(std::min(pos.x, pos_ini.x), std::min(pos.y, pos_ini.y), std::abs(pos.x - pos_ini.x) + 1, std::abs(pos.y - pos_ini.y) + 1);

		for (int i = rect.left; i <= rect.left + rect.width - 1; i++)
		{
			line[0].position = sf::Vector2f(i, rect.top);
			line[1].position = sf::Vector2f(i + 1, rect.top);
			conf_lines.push_back(COutil::creer_conf_line(line, 0, i, rect.top));

			line[0].position = sf::Vector2f(i, rect.top + rect.height);
			line[1].position = sf::Vector2f(i + 1, rect.top + rect.height);
			conf_lines.push_back(COutil::creer_conf_line(line, 2, i, rect.top + rect.height - 1));
		}
		for (int j = rect.top; j <= rect.top + rect.height - 1; j++)
		{
			line[0].position = sf::Vector2f(rect.left, j);
			line[1].position = sf::Vector2f(rect.left, j + 1);
			conf_lines.push_back(COutil::creer_conf_line(line, 3, rect.left, j));

			line[0].position = sf::Vector2f(rect.left + rect.width, j);
			line[1].position = sf::Vector2f(rect.left + rect.width, j + 1);
			conf_lines.push_back(COutil::creer_conf_line(line, 1, rect.left + rect.width - 1, j));
		}
		GUI->replaceCadre(&rect);

		ex_pos = pos;
	}
}
void CRectSelec::end_selec(int type)
{
	SELEC->new_selec(rect, NULL, &conf_lines, type);
	conf_lines.clear();
	GUI->cancelCadreReplacement();
}

void CRectSelec::use()
{
	sf::Vector2i center = IO->getPixel();

	if (!IO->pressed(CInput::Alt) && IO->again(CInput::MLeft))
	{
		key = CInput::MLeft;
		IO->setExClick(sf::Vector2f(center.x, center.y));
		active = true;
	}
	if (IO->pressed(CInput::Alt) && IO->again(CInput::MLeft))
	{
		key = CInput::Alt;
		ex_center = center;
		active = true;
	}

	if (active)
	{
		if (IO->pressed(CInput::MLeft))
			selec_rect(sf::Vector2i(IO->getPreviousCenterClick().x, IO->getPreviousCenterClick().y), center);
		else
		{
			//TODO
			/*if (key == CInput::MLeft)
			{
				CRetour::vector.push_back(IO);
				IO->creer_retour();
			}*/

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