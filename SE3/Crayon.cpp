#include "Crayon.h"
#include "Res.h"
#include "Brosse.h"
#include "Input.h"
#include "Fonction.h"
#include "Calque.h"
#include "App.h"
#include "Var.h"
#include "Selec.h"

CCrayon::CCrayon(void)
{
	numero_outil = COutil::CRAYON;
	RES->getShader(CRes::usual)->setParameter("mode", 1);
}

CCrayon::~CCrayon(void) {}

void CCrayon::afficher()
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

void CCrayon::ctrl(sf::Color* color)
{
	*color = CFonction::getColor(IO->getPixel() - CALQUE->getPosition_i(), CALQUE->getImage());
}

void CCrayon::use_line(sf::Vector2f pos_ini)
{
	RES->getShader(CRes::usual)->setParameter("offset", SELEC->getPosition() - CALQUE->getPosition());
	RES->getShader(CRes::usual)->setParameter("background", *CALQUE->getTexture());

	CFonction::line(pos_ini, center, CALQUE);
}

void CCrayon::use()
{
	center = IO->getCenter();

	if (IO->pressed(CInput::Maj))
		CFonction::maj(&center, &line[0]);

	if (IO->pressed(CInput::MLeft))
	{
		if (!IO->pressed(CInput::Maj) && IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color1);
		else if (IO->pressed(CInput::Maj) && IO->again(CInput::MLeft))
		{
			BROSSE->setColor(&VAR->color1);
			use_line(IO->getPreviousCenterClick());
		}
		else if (!IO->pressed(CInput::Maj))
		{
			BROSSE->setColor(&VAR->color1);
			use_line(IO->getPreviousCenter());
		}
	}
	else if (IO->pressed(CInput::MRight))
	{
		if (!IO->pressed(CInput::Maj) && IO->pressed(CInput::Ctrl))
			ctrl(&VAR->color2);
		else if (IO->pressed(CInput::Maj) && IO->again(CInput::MRight))
		{
			BROSSE->setColor(&VAR->color2);
			use_line(IO->getPreviousCenterClick());
		}
		else if (!IO->pressed(CInput::Maj))
		{
			BROSSE->setColor(&VAR->color2);
			use_line(IO->getPreviousCenter());
		}
	}
}