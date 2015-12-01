#include "Curseur.h"
#include "App.h"
#include "Input.h"
#include "Var.h"
#include "Fonction.h"

CCurseur* CURSEUR;

CCurseur::CCurseur(void)
{
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

	position = sf::Vector2f();
}

CCurseur::~CCurseur(void) {}

void CCurseur::afficher()
{
	sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i][0].color = color;
		lines[i][1].color = color;
		APP->fenetre.draw(lines[i]);
	}
}

void CCurseur::setPosition(sf::Vector2f pos)
{
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i][0].position -= position - pos;
		lines[i][1].position -= position - pos;
	}
	position = pos;
}

void CCurseur::gerer(sf::Sprite* sprite)
{
	if (!IO->pressed(CInput::Maj))
	{
		if (IO->pressed(CInput::MRight))
			setPosition(IO->getPosition());
	}
	else
		if (IO->again(CInput::MRight))
		{
			sf::Vector2f* tmp = CFonction::selecPoint(sprite, IO->getPosition(), static_cast<unsigned int>(-1));
			if (tmp != NULL)
			{
				setPosition(*tmp);
				delete tmp;
			}	
		}
}

void CCurseur::ini(sf::Sprite* sprite)
{
	sf::FloatRect rect_glob = sprite->getGlobalBounds();
	sf::Vector2f pos_center(rect_glob.left + rect_glob.width / 2.f, rect_glob.top + rect_glob.height / 2.f);

	float angle = sprite->getRotation() / 180 * VAR->PI;
	sf::Vector2f temp = pos_center - position;
	pos_center.x = temp.x*std::cos(angle) + temp.y*std::sin(angle);
	pos_center.y = temp.y*std::cos(angle) - temp.x*std::sin(angle);
	pos_center.x /= sprite->getScale().x;
	pos_center.y /= sprite->getScale().y;

	sprite->setOrigin(sf::Vector2f(sprite->getTextureRect().width / 2.f, sprite->getTextureRect().height / 2.f) - pos_center);
	sprite->setPosition(position);
}