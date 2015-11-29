#include "Gomme.h"
#include "App.h"
#include "Brosse.h"
#include "Input.h"
#include "Fonction.h"
#include "Calque.h"
#include "Selec.h"
#include "Var.h"

CGomme::CGomme(void)
{
	numero_outil = COutil::GOMME;
}

CGomme::~CGomme(void) {}

void CGomme::afficher()
{
	BROSSE->afficher(center);
	if (IO->pressed(CInput::Maj))
	{
		sf::Color color = sf::Color(255 * bool(rand() % 2), 255 * bool(rand() % 2), 255 * bool(rand() % 2));
		line[0].color = color;
		line[1].color = color;
		APP->fenetre.draw(line, 2, sf::Lines);
	}
}

void CGomme::ctrl(sf::Color* color)
{
	*color = CFonction::getColor(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getImage());
}

void CGomme::use_line(sf::Vector2f pos_ini)
{
	RES->getShader(CRes::usual)->setParameter("offset", SELEC->getPosition() - CALQUE->getPosition());
	RES->getShader(CRes::usual)->setParameter("background", *CALQUE->getTexture());

	CFonction::line(pos_ini, center, CALQUE);
}

void CGomme::use()
{
	center = IO->getCenter();
	sf::Vector2f center_prec = IO->getPreviousCenter();

	if (IO->pressed(CInput::Maj))
		CFonction::maj(&center, &line[0]);

	if (IO->pressed(CInput::MLeft))
	{
		if (!IO->pressed(CInput::Maj) && IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color1);
		else if (IO->pressed(CInput::Maj) && IO->again(CInput::MLeft))
		{
			RES->getShader(CRes::usual)->setParameter("mode", 0);
			use_line(IO->getPreviousCenterClick());
		}
		else if (!IO->pressed(CInput::Maj))
		{
			RES->getShader(CRes::usual)->setParameter("mode", 0);
			use_line(center_prec);
		}
	}
	else if (IO->pressed(CInput::MRight))
	{
		if (!IO->pressed(CInput::Maj) && IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color2);
		else if (IO->pressed(CInput::Maj) && IO->again(CInput::MRight))
		{
			RES->getShader(CRes::usual)->setParameter("mode", 0.5f);
			use_line(IO->getPreviousCenterClick());
		}
		else if (!IO->pressed(CInput::Maj))
		{
			RES->getShader(CRes::usual)->setParameter("mode", 0.5f);
			use_line(center_prec);
		}
	}
}
