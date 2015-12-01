#include "OptionColor.h"
#include "Res.h"
#include "Input.h"
#include "Fonction.h"
#include "App.h"
#include "Gui.h"
#include "Var.h"
#include "EnteredInput.h"
#include "Outil.h"

COptionColor* OPTION_COLOR;
sf::Color COptionColor::color_list[15];

void COptionColor::create_opt_Color(void* param)
{
	static bool var = true;

	if (OPTION_COLOR != NULL)
		delete OPTION_COLOR;

	if (var)
	{
		iniColor();
		var = false;
	}

	OPTION_COLOR = new COptionColor(param);
}

COptionColor::COptionColor(void* param) //VERIFIED//
{
	ADVIO->replace({CInput::A}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(0);}), this);
	ADVIO->replace({CInput::Z}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(1);}), this);
	ADVIO->replace({CInput::E}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(2);}), this);
	ADVIO->replace({CInput::R}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(3);}), this);
	ADVIO->replace({CInput::T}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(4);}), this);
	ADVIO->replace({CInput::Q}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(5);}), this);
	ADVIO->replace({CInput::S}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(6);}), this);
	ADVIO->replace({CInput::D}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(7);}), this);
	ADVIO->replace({CInput::F}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(8);}), this);
	ADVIO->replace({CInput::G}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(9);}), this);
	ADVIO->replace({CInput::W}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(10);}), this);
	ADVIO->replace({CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(11);}), this);
	ADVIO->replace({CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(12);}), this);
	ADVIO->replace({CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(13);}), this);
	ADVIO->replace({CInput::B}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->getColor(14);}), this);

	ADVIO->replace({CInput::Ctrl, CInput::A}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(0);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::Z}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(1);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::E}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(2);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::R}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(3);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::T}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(4);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::Q}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(5);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::S}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(6);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::D}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(7);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::F}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(8);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::G}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(9);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::W}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(10);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(11);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(12);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(13);}), this);
	ADVIO->replace({CInput::Ctrl, CInput::B}, CInput::AGAIN, new std::function<void(void)>([]() {OPTION_COLOR->setColor(14);}), this);
	ADVIO->replace({CInput::Space}, CInput::AGAIN, new std::function<void(void)>([]() {
		delete OPTION_COLOR;
		OPTION_COLOR = NULL;
		return;
	}), this);
	ADVIO->replace({CInput::Alt}, CInput::DOUBLE_TAP, new std::function<void(void)>([]() {iniColor(true);}), this);

	spr1.setTexture(*RES->getTexture(CRes::TEXTURE::optionColor));
	spr2.setTexture(*RES->getTexture(CRes::TEXTURE::optionColor_1));
	spr3.setTexture(*RES->getTexture(CRes::TEXTURE::optionColor_3));
	sprb.setTexture(*RES->getTexture(CRes::TEXTURE::optionColor_2));

	sf::Image img;
	img.create(86, 48, sf::Color::White);

	spr_ancien = RES->getSprite(CRes::sprite_white, sf::Vector2i(86, 48));
	spr_nouveau = spr_ancien;

	for (int i = 0; i<15; i++)
	{
		sprite_list.push_back(RES->getSprite(CRes::sprite_white, sf::Vector2i(32, 14)));
		sprite_list[i].setColor(color_list[i]);
	}

	//Keeping parameter
	parametre = static_cast<sf::Color*>(param);

	spr_ancien.setColor(*parametre);
	spr2.setColor(*parametre);
	ex_parametre = *parametre;

	CHud::addMe(this);
}

COptionColor::~COptionColor(void) //VERIFIED//
{
	ADVIO->remove(this);
	CHud::killMe(this);
}

void COptionColor::zoom(float z) //VERIFIED//
{
	for (int i = 0; i<sprite_list.size(); i++)
		sprite_list[i].setScale(z, z);

	spr_ancien.setScale(z, z);
	spr_nouveau.setScale(z, z);

	spr1.setScale(z, z);
	sprb.setScale(z, z);
	spr2.setScale(z, z);
	spr3.setScale(z, z);
}

void COptionColor::position()
{
	sf::Vector2f hsize = sf::Vector2f(spr1.getTextureRect().width/APP->zoom/2.f, spr1.getTextureRect().height/APP->zoom/2.f);
	spr3.setPosition(APP->camera.getCenter()-sf::Vector2f(spr3.getTextureRect().width/APP->zoom/2.f, spr3.getTextureRect().height/APP->zoom/2.f));
	spr1.setPosition(spr3.getPosition()+sf::Vector2f(4/APP->zoom, 4/APP->zoom));
	sprb.setPosition(spr1.getPosition()+hsize-sf::Vector2f(sprb.getTextureRect().width/APP->zoom/2.f, sprb.getTextureRect().height/APP->zoom/2.f));
	spr2.setPosition(spr1.getPosition()+hsize-sf::Vector2f(spr2.getTextureRect().width/APP->zoom/2.f, spr2.getTextureRect().height/APP->zoom/2.f));

	spr_ancien.setPosition(spr3.getPosition()+sf::Vector2f(5/APP->zoom, 357/APP->zoom));
	spr_nouveau.setPosition(spr3.getPosition()+sf::Vector2f(92/APP->zoom, 357/APP->zoom));

	for (int i = 0; i<sprite_list.size(); i++)
		sprite_list[i].setPosition(spr3.getPosition()+sf::Vector2f((181+i%5*35)/APP->zoom, (357+i/5*17)/APP->zoom));
}


void COptionColor::gerer() //VERIFIED//
{
	if (IO->again(CInput::MRight))
	{
		for (int i = 0; i<sprite_list.size(); i++)
			if (CFonction::onSprite(&sprite_list[i]))
				setColor(i);

		if (CFonction::onSprite(&spr1))
			spr2.setColor(*parametre);
	}

	static bool spr1_active = false;
	static bool spr2_active = false;

	if (IO->again(CInput::MLeft))
	{
		if (!spr1_active && !spr2_active)
		{
			for (int i = 0; i<sprite_list.size(); i++)
				if (CFonction::onSprite(&sprite_list[i]))
					getColor(i);

			if (CFonction::onSprite(&spr2))
			{
				spr2_active = true;
				sf::RenderTexture render;
				render.create(spr2.getTexture()->getSize().x, spr2.getTexture()->getSize().y);

				sf::Sprite spr = sprb; spr.setScale(1, 1); spr.setPosition(-77, -77);
				render.draw(spr);
				spr = spr2; spr.setScale(1, 1); spr.setPosition(0, 0);
				render.draw(spr);

				render.display();
				image = render.getTexture().copyToImage();
			}
			else if (CFonction::onSprite(&spr1))
			{
				spr1_active = true;
				image = spr1.getTexture()->copyToImage();
			}
		}
	}
	else if (!IO->pressed(CInput::MLeft))
	{
		spr1_active = false;
		spr2_active = false;
	}

	if (spr1_active)
		gererColor(&spr1);
	else if (spr2_active)
		gererColor(&spr2);

	if (IO->pressed(CInput::Ctrl) && (spr1_active || spr2_active))
		arrondi();
	if (spr1_active) spr2.setColor(*parametre);

	if (ex_parametre != *parametre)
	{
		ex_parametre = *parametre;
		spr2.setColor(*parametre);
	}
}

void COptionColor::gererColor(sf::Sprite *sprite) //VERIFIED//
{
	sf::Vector2f pos = (IO->getPosition()-sprite->getPosition())*APP->zoom;
	sf::Vector2f center_image(image.getSize().x/2.f, image.getSize().y/2.f);

	sf::Vector2f vecteur(pos.x-center_image.x, pos.y-center_image.y);
	float angle = -std::atan2(vecteur.y, vecteur.x)*180/VAR->PI;

	if (!(pos.x>=0&&pos.y>=0&&pos.x<image.getSize().x && pos.y<image.getSize().y))
	{
		float ratio;
		if (angle<45&&angle>=-45)
			ratio = center_image.x/(pos.x-center_image.x);
		else if (angle<135&&angle>=45)
			ratio = center_image.y/(center_image.y-pos.y);
		else if (angle<-135||angle>=135)
			ratio = center_image.x/(center_image.x-pos.x);
		else
			ratio = center_image.y/(pos.y-center_image.y);

		vecteur.x *= ratio;
		vecteur.y *= ratio;

		if (center_image.x+vecteur.x==image.getSize().x) vecteur.x--;
		if (center_image.y+vecteur.y==image.getSize().y) vecteur.y--;
	}

	*parametre = CFonction::getColor(sf::Vector2i(center_image.x+vecteur.x, center_image.y+vecteur.y), &image);
	ex_parametre = *parametre;
}

void COptionColor::arrondi() //VERIFIED//
{
	const int nbr = 7; int points[nbr+1];
	for (int i = 0; i<nbr+1; i++)
		points[i] = i*255/nbr;

	int distance[nbr+1];
	int j;

	for (int i = 0; i<nbr+1; i++) distance[i] = std::abs(points[i]-parametre->r);
	j = 0; for (int i = 1; i<nbr+1; i++) if (distance[i]<distance[j]) j = i;
	parametre->r = points[j];

	for (int i = 0; i<nbr+1; i++) distance[i] = std::abs(points[i]-parametre->g);
	j = 0; for (int i = 1; i<nbr+1; i++) if (distance[i]<distance[j]) j = i;
	parametre->g = points[j];

	for (int i = 0; i<nbr+1; i++) distance[i] = std::abs(points[i]-parametre->b);
	j = 0; for (int i = 1; i<nbr+1; i++) if (distance[i]<distance[j]) j = i;
	parametre->b = points[j];

	ex_parametre = *parametre;
}

void COptionColor::getColor(int i) //VERIFIED//
{
	*parametre = color_list[i];
	ex_parametre = *parametre;
	spr2.setColor(*parametre);
}

void COptionColor::setColor(int i) //VERIFIED//
{
	color_list[i] = *parametre;
	sprite_list[i].setColor(*parametre);
}

void COptionColor::iniColor(bool display) //VERIFIED//
{
	color_list[0] = sf::Color::White;
	color_list[1] = sf::Color::White;
	color_list[2] = sf::Color::Black;
	color_list[3] = sf::Color(128, 128, 128);
	color_list[4] = sf::Color::White;
	color_list[5] = sf::Color::White;
	color_list[6] = sf::Color::White;
	color_list[7] = sf::Color::Magenta;
	color_list[8] = sf::Color::Yellow;
	color_list[9] = sf::Color(0, 255, 255);
	color_list[10] = sf::Color::White;
	color_list[11] = sf::Color::White;
	color_list[12] = sf::Color::Red;
	color_list[13] = sf::Color::Green;
	color_list[14] = sf::Color::Blue;

	if (display)
		for (int i = 0; i<15; i++)
			OPTION_COLOR->sprite_list[i].setColor(color_list[i]);
}

void COptionColor::afficher() //VERIFIED//
{
	spr_nouveau.setColor(*parametre);

	APP->fenetre.draw(spr3);
	APP->fenetre.draw(spr1);
	APP->fenetre.draw(sprb);
	APP->fenetre.draw(spr2);

	APP->fenetre.draw(spr_ancien);
	APP->fenetre.draw(spr_nouveau);

	for (int i = 0; i<sprite_list.size(); i++)
		APP->fenetre.draw(sprite_list[i]);
}

bool COptionColor::test()
{
	return CFonction::onSprite(&spr3);
}

/*
void COptionColor::createCircle()
{
	const int nbr = 90;
	sf::VertexArray quad(sf::TrianglesFan, nbr+2);
	sf::Color color_list[nbr+2];
	color_list[0] = sf::Color::Transparent;

	for (int i = 0; i<nbr/6; i++)
		color_list[1+i] = sf::Color(255, 0, i * 255.f/(nbr/6.f));
	for (int i = 0; i<nbr/6; i++)
		color_list[1+nbr/6+i] = sf::Color(255-i * 255.f/(nbr/6.f), 0, 255);

	for (int i = 0; i<nbr/6; i++)
		color_list[1+2*nbr/6+i] = sf::Color(0, i * 255.f/(nbr/6.f), 255);
	for (int i = 0; i<nbr/6; i++)
		color_list[1+3*nbr/6+i] = sf::Color(0, 255, 255-i * 255.f/(nbr/6.f));

	for (int i = 0; i<nbr/6; i++)
		color_list[1+4*nbr/6+i] = sf::Color(i * 255.f/(nbr/6.f), 255, 0);
	for (int i = 0; i<nbr/6; i++)
		color_list[1+5*nbr/6+i] = sf::Color(255, 255-i * 255.f/(nbr/6.f), 0);

	color_list[nbr+1] = color_list[1];

	quad[0] = sf::Vertex(sf::Vector2f(0, 0), color_list[0]);
	float angle = VAR->PI, a = 500;
	for (int i = 1; i<nbr+2; i++)
	{
		quad[i] = sf::Vertex(sf::Vector2f(a*std::cos(angle), a*std::sin(angle))+quad[0].position, color_list[i]);
		angle += VAR->PI/nbr * 2.f;
	}

	for (int i = 0; i<nbr+2; i++)
		quad[i].position += sf::Vector2f(a, a);

	sf::RenderTexture render;
	render.create(a*2, a*2);
	render.clear(sf::Color::Transparent);
	render.draw(quad);
	render.display();

	CFonction::copy_to_clipboard(&tex1.copyToImage());
}
*/