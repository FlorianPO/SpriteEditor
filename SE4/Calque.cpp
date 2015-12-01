#include "Calque.h"

#include "BoutonSwitch.h"
#include "Writter.h"
#include "Retour.h"
#include "Input.h"
#include "Var.h"
#include "App.h"
#include "Curseur.h"
#include "BoutonView.h"
#include "Gui.h"
#include "Fonction.h"

CCalque* CALQUE;
std::vector<CCalque*> CALQUE_LIST;

CCalque::CCalque(sf::Texture* texture_var)
{
	_t = this;

	//Nom
	nom = "Calque " + std::to_string(nbrCalque() + 1);
	renderNom.create(88, 31);
	WRITTER->ecrire(nom, &renderNom, sf::Vector2i(0, 10), sf::Color::Transparent);
	sprite_nom.setTexture(renderNom.getTexture());

	//Image
	renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
	update(texture_var);
	sprite.setTexture(renderTexture.getTexture());

	//Gui
	panneau = new CPanneau(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(1, 401, 129, hauteur_c), NULL, sf::IntRect(131, 401, 129, hauteur_c));
	vignette = new CBoutonView(sprite.getTexture(), sf::IntRect(50, 4, 43, 26));
	
	oeil = new CBoutonSwitch(RES->getTexture(CRes::TEXTURE::panneau), sf::IntRect(261, 401, 31, 31), sf::Vector2f(3, 0));
	auto fonction = new std::function<void(fonction_type)>([](fonction_type l) {static_cast<CCalque*>(l[0])->setVisible(!static_cast<CCalque*>(l[0])->isVisible()); });
	auto arguments = new fonction_type{ this };
	auto predicat = new std::function<int(fonction_type)>([](fonction_type l) {return static_cast<CCalque*>(l[0])->isVisible(); });
	oeil->setFonction(fonction);
	oeil->setPredicat(predicat);
	oeil->setArguments(arguments);

	panneau->addBouton(vignette);
	panneau->addBouton(oeil);

	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return _t == l[0]; }); panneau->setPredicatSwap(predicat);
	arguments = new fonction_type{ this }; panneau->setArguments(arguments);
	fonction = new std::function<void(fonction_type)>([](fonction_type l) {_t = static_cast<CCalque*>(l[0]); });
	panneau->setFonction(fonction);
	predicat = new std::function<int(fonction_type)>([](fonction_type l) {return !static_cast<CCalque*>(l[0])->isDead();});
	panneau->setPredicatScroll(predicat);

	panneau->group(GUI->getPanneauAboveCalque());
	if (nbrCalque() == 0)
		GUI->getPanneauBelowCalque()->group(panneau);

	//Création du ctrl-z / ctrl-y
	i_retour_type = -1;
	i_retour_image = -1;
	i_retour_pos = -1;

	RETOUR->add_retour({this});

	creer_retour(NULL, CRE);
	creer_retour(getImage(), ACT);
}

CCalque::~CCalque(void)
{
	delete panneau;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CCalque::new_calque(sf::Texture* texture_var)
{
	if (texture_var != NULL)
		calque_list.push_back(new CCalque(texture_var));
	else
	{
		sf::Image image; sf::Texture texture;
		image.create(calque_list.back()->getSize().x, calque_list.back()->getSize().y, sf::Color::Transparent);
		texture.loadFromImage(image);
		calque_list.push_back(new CCalque(&texture));
	}
}

int CCalque::nbrCalque(bool count_dead)
{
	if (count_dead)
		return calque_list.size();

	int nbr = 0;
	for (int i = 0; i < calque_list.size(); i++)
		if (!calque_list[i]->dead)
			nbr++;
	return nbr;
}

bool CCalque::isFirst()
{
	for (int i = 0; i < calque_list.size(); i--)
		if (!calque_list[i]->dead)
			return calque_list[i] == _t;
	return false;
}

void CCalque::choose_calque()
{
	for (int i = _t->getNumero(); i >= 0; i--)
		if (!calque_list[i]->dead)
		{
			_t = calque_list[i]; 
			return;
		}
	for (int i = _t->getNumero() + 1; i < calque_list.size(); i++)
		if (!calque_list[i]->dead)
		{
			_t = calque_list[i];
			return;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CCalque::getNumero()
{
	for (int i = 0; i < calque_list.size(); i++)
		if (this == calque_list[i])
			return i;
	return 0;
}

sf::Image* CCalque::getImage()
{
	if (refresh)
	{
		image_buffer = renderTexture.getTexture().copyToImage();
		refresh = false;
	}
	return &image_buffer;
}

void CCalque::draw_brosse(sf::Vector2f pos, sf::RenderStates* render)
{
	BROSSE->setPosition(pos - CCalque::_t->getPosition());
	draw(BROSSE->getSprite(), render);
}

void CCalque::draw(sf::Sprite* spr, sf::RenderStates* render, bool no_retour)
{
	if (render != NULL)
		renderTexture.draw(*spr, *render);
	else
		renderTexture.draw(*spr);
	renderTexture.display();

	if (!no_retour)
		changed = true;
	refresh = true;
}

void CCalque::update(sf::Texture* texture_var)
{
	if (texture_var->getSize() == renderTexture.getSize())
	{
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
	}
	else
	{
		renderTexture.create(texture_var->getSize().x, texture_var->getSize().y);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(sf::Sprite(*texture_var), sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);
	}
	refresh = true;
}

void CCalque::afficher()
{
	if (!dead && visible)
		APP->fenetre.draw(sprite);	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CCalque::move()
{
	if (IO->pressed(CInput::MRight) || IO->isZQSD() && !IO->isCMA())
	{
		if (!clicked)
		{
			posi = IO->getPixel();
			posf = sprite.getPosition();
			clicked = true;
		}

		sf::Vector2f move;
		if (!IO->isZQSD())
		{
			if (IO->pressed(CInput::Ctrl))
			{
				sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(posi.x, posi.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
				pos_mouse.x = floor(pos_mouse.x);
				pos_mouse.y = floor(pos_mouse.y);
				move.x = pos_mouse.x + posf.x;
				move.y = pos_mouse.y + posf.y;
				sprite.setPosition(move);
			}
			else
				sprite.move(-IO->getDeltaPixel().x, -IO->getDeltaPixel().y);
		}
		else
		{
			if (IO->log(CInput::Z)) move.y = -1;
			if (IO->log(CInput::D)) move.x = 1;
			if (IO->log(CInput::S)) move.y = 1;
			if (IO->log(CInput::Q)) move.x = -1;
			sprite.move(move);
		}
	}
	else if (clicked)
	{
		RETOUR->add_retour({this});
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::grand()
{
	CURSEUR->gerer(&sprite);

	if (IO->pressed(CInput::MLeft))
	{
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite);
			posf.x = IO->getPixel().x;
			posf.y = IO->getPixel().y;
		}
		if (IO->pressed(CInput::Ctrl))
		{
			int max_size = std::max(sprite.getTextureRect().width, sprite.getTextureRect().height);
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sf::Vector2f(posf.x, posf.y), sf::Vector2f(IO->getPixel().x, IO->getPixel().y));
			sprite.setScale(1.f + pos_mouse.x / max_size, 1.f + pos_mouse.y / max_size);
		}
		else
			sprite.setScale(1.f + (IO->getPixel().x - posf.x) / _t->getSize().x, 1.f + (IO->getPixel().y - posf.y) / _t->getSize().y);
	}
	else if (clicked)
	{
		sf::Vector2f scale = sprite.getScale();
		sf::Texture text = renderTexture.getTexture();
		sf::Sprite spr(text);

		renderTexture.create(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		renderTexture.clear(sf::Color::Transparent);

		spr.setPosition(sprite.getPosition().x - sprite.getGlobalBounds().left, sprite.getPosition().y - sprite.getGlobalBounds().top);
		spr.setScale(scale);
		spr.setOrigin(sprite.getOrigin());

		renderTexture.draw(spr, sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);

		sprite.setScale(1, 1);
		refresh = true;

		RETOUR->add_retour({this, this});
		creer_retour(getImage(), ACT);
		sprite.setPosition(0, 0);
		sprite.setOrigin(0, 0);
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::rotation()
{
	CURSEUR->gerer(&sprite);

	if (IO->pressed(CInput::MLeft))
	{
		float angle;
		if (!clicked)
		{
			clicked = true;
			CURSEUR->ini(&sprite);
			angle_ini = atan2(IO->getPosition().y - sprite.getPosition().y, IO->getPosition().x - sprite.getPosition().x);
		}
		if (IO->pressed(CInput::Ctrl))
		{
			sf::Vector2f pos_mouse = CFonction::selecPointRect(sprite.getPosition(), IO->getPosition());
			angle = atan2(pos_mouse.y, pos_mouse.x);
			sprite.setRotation(-angle * 180 / VAR->PI);
		}
		else
		{
			angle = atan2(IO->getPosition().y - sprite.getPosition().y, IO->getPosition().x - sprite.getPosition().x);
			sprite.setRotation((angle - angle_ini) * 180 / VAR->PI);
		}
	}
	else if (clicked)
	{
		float angle = sprite.getRotation();

		sf::Texture text = renderTexture.getTexture();
		sf::Sprite spr(text);
		spr.setOrigin(sprite.getOrigin());
		spr.setRotation(angle);
		spr.setPosition(sprite.getPosition().x - sprite.getGlobalBounds().left, sprite.getPosition().y - sprite.getGlobalBounds().top);

		renderTexture.create(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		renderTexture.clear(sf::Color::Transparent);
		renderTexture.draw(spr, sf::BlendNone);
		renderTexture.display();
		sprite.setTexture(renderTexture.getTexture(), true);
		refresh = true;

		RETOUR->add_retour({this, this});
		creer_retour(getImage(), ACT);
		sprite.setOrigin(0, 0);
		sprite.setPosition(0, 0);
		sprite.setRotation(0);
		creer_retour(NULL, MOV);

		clicked = false;
	}
}

void CCalque::flip()
{
	if (IO->again(CInput::MLeft) || IO->again(CInput::MRight))
	{
		sf::Image image = renderTexture.getTexture().copyToImage();
		if (IO->again(CInput::MLeft))
			image.flipHorizontally();
		else
			image.flipVertically();

		sf::Texture texture;
		texture.loadFromImage(image);

		renderTexture.draw(sf::Sprite(texture), sf::BlendNone);
		renderTexture.display();
		refresh = true;
		RETOUR->add_retour({this});
		creer_retour(getImage(), ACT);
	}
}

///##################################################################################################################################################
///##################################################################################################################################################
///##################################################################################################################################################

void CCalque::creer_retour(sf::Image* image, type_retour t)
{
	i_retour_type++;
	retour_type.push_back(t);

	if (t == ACT)
	{
		i_retour_image++;
		retour_image.push_back(*image);
	}
	else if (t == DEL)
	{
		dead = true;
		CCalque::choose_calque();
	}
	else if (t == MOV || t == CRE)
	{
		i_retour_pos++;
		retour_pos.push_back(sprite.getPosition());
	}
}

void CCalque::ctrl_z()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type--;
	type_retour t = retour_type[i_retour_type];


	if (t == CRE) // c <- a
	{
		dead = true;
		CCalque::choose_calque();
	}
	else if (ex_t == DEL) // a <- d
		dead = false;
	else if (ex_t == ACT) // a <- a
	{
		i_retour_image--;
		sf::Texture texture; texture.loadFromImage(retour_image[i_retour_image]);
		update(&texture);
	}
	else if (ex_t == MOV) // m <- m
	{
		i_retour_pos--;
		sprite.setPosition(retour_pos[i_retour_pos]);
	}
}

void CCalque::ctrl_y()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type++;
	type_retour t = retour_type[i_retour_type];

	if (ex_t == CRE) // c -> a
		dead = false;
	else if (t == DEL) // a -> d
	{
		dead = true;
		CCalque::choose_calque();
	}
	else if (t == ACT) // a -> a
	{
		i_retour_image++;
		sf::Texture texture; texture.loadFromImage(retour_image[i_retour_image]);
		update(&texture);
	}
	else if (t == MOV) // m -> m
	{
		i_retour_pos++;
		sprite.setPosition(retour_pos[i_retour_pos]);
	}
}

void CCalque::delete_retour()
{
	retour_type.erase(retour_type.begin() + i_retour_type + 1, retour_type.end());
	retour_image.erase(retour_image.begin() + i_retour_image + 1, retour_image.end());
	retour_pos.erase(retour_pos.begin() + i_retour_pos + 1, retour_pos.end());
}