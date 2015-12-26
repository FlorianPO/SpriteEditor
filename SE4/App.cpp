#include "App.h"

#include "EnteredInput.h"
#include "Res.h"
#include "Calque.h"
#include "Retour.h"
#include "Selec.h"
#include "Copy.h"
#include "Input.h"
#include "Var.h"

CApp* APP;

CApp::CApp(void)
{
	fenetre.create(sf::VideoMode(800, 600, 32), "Sprite Editor");
	fenetre.setVerticalSyncEnabled(true);
	//fenetre.setFramerateLimit(10);
}

CApp::~CApp(void)
{
	fenetre.close();
}

void CApp::charger(std::string str)
{
	filename = str;

	//Loading image
	sf::Texture texture_var;
	if (!texture_var.loadFromFile(RES->directory + str))
		std::cout << "Unable to load file at " + RES->directory.toAnsiString() + str << std::endl;

	init_work(&texture_var);
}

void CApp::init_work(sf::Texture* text)
{
	free_work();

	//Init some stuff
	CCalque::new_calque(text);
	SELEC->initialiser();

	//Init patron
	patron = sf::IntRect(0, 0, text->getSize().x, text->getSize().y);
	lines_bord = sf::VertexArray(sf::LinesStrip, 5);
	lines_bord[0].position = sf::Vector2f(0, 0);
	lines_bord[1].position = sf::Vector2f(patron.width, 0);
	lines_bord[2].position = sf::Vector2f(patron.width, patron.height);
	lines_bord[3].position = sf::Vector2f(0, patron.height);
	lines_bord[4].position = sf::Vector2f(0, 0);

	init_camera(); //Explicit
}

void CApp::free_work()
{
	//Free all pointers
	for (int i = 0; i < CALQUE_LIST.size(); i++)
		delete CALQUE_LIST[i];
	for (int i = 0; i < COPY_LIST.size(); i++)
		delete COPY_LIST[i];

	CALQUE_LIST.clear();
	COPY_LIST.clear();
	RETOUR->free();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CApp::init_camera()
{
	//Centrage de la caméra au milieu du calque
	camera.setCenter(sf::Vector2f(CCalque::_t->getSize().x/2, CCalque::_t->getSize().y/2));
	camera.setSize(sf::Vector2f(fenetre.getSize().x, fenetre.getSize().y));

	zoom = 1.f;
}

void CApp::zoomer(float z, bool s)
{
	if (zoom/z >= 128 || zoom/z <= 0.0625) {return;}

	if (s)
	{
		sf::Vector2f pos_mouse = IO->getPosition();
		if (z <= 1.f)
		{
			camera.setCenter((pos_mouse.x + camera.getCenter().x)/2.f, (pos_mouse.y + camera.getCenter().y)/2.f);
			camera.zoom(z); zoom = zoom / z;
		}
		else
		{
			float x = camera.getCenter().x - pos_mouse.x;
			float y = camera.getCenter().y - pos_mouse.y;
			camera.zoom(z); zoom = zoom / z;
			camera.move(x, y);
		}
	}
	else
	{
		camera.zoom(z); zoom = zoom / z;
	}
}

void CApp::follow(sf::Vector2f pos)
{
	camera.setCenter(pos);
	sf::Vector2i vect = sf::Vector2i(fenetre.getSize().x/2, fenetre.getSize().y/2);
	sf::Mouse::setPosition(vect, fenetre);
	IO->ini_pos(vect);
}

void CApp::follow()
{
	//Centrer la caméra sur la souris
	camera.setCenter(IO->getPosition());
	sf::Vector2i vect = sf::Vector2i(fenetre.getSize().x/2, fenetre.getSize().y/2);
	sf::Mouse::setPosition(vect, fenetre);
	IO->ini_pos(vect);
}

sf::Vector2f CApp::getPositionCamera(int coin) //VERIFIED//
{
	switch (coin)
	{
		case 0:		return camera.getCenter();
		case 1:		return sf::Vector2f(camera.getCenter().x - camera.getSize().x / 2.f, camera.getCenter().y - camera.getSize().y / 2.f);
		case 2:		return sf::Vector2f(camera.getCenter().x + camera.getSize().x / 2.f, camera.getCenter().y - camera.getSize().y / 2.f);
		case 3:		return sf::Vector2f(camera.getCenter().x + camera.getSize().x / 2.f, camera.getCenter().y + camera.getSize().y / 2.f);
		case 4:		return sf::Vector2f(camera.getCenter().x - camera.getSize().x / 2.f, camera.getCenter().y + camera.getSize().y / 2.f);
		default:	return camera.getCenter();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CApp::gererFond()
{
	static bool ini = false;
	if (!ini)
	{
		ini = true;
		sprite_transparency = RES->getSprite(CRes::SPRITE::alpha_gimp);

		cache_fond[0] = sf::VertexArray(sf::Quads, 4);
		cache_fond[1] = sf::VertexArray(sf::Quads, 4);
		cache_fond[2] = sf::VertexArray(sf::Quads, 4);
		cache_fond[3] = sf::VertexArray(sf::Quads, 4);
	}

	sf::Vector2f pos(camera.getCenter() - sf::Vector2f(camera.getSize().x / 2.f, camera.getSize().y / 2.f));
	sprite_transparency.setPosition(pos);
	sprite_transparency.setScale(10 / zoom, 10 / zoom);

	sf::FloatRect rect = CALQUE->getSprite()->getGlobalBounds();

	cache_fond[0][0] = sf::Vertex(pos, VAR->color_fond);
	cache_fond[0][1] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, pos.y), VAR->color_fond);
	cache_fond[0][2] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, rect.top), VAR->color_fond);
	cache_fond[0][3] = sf::Vertex(sf::Vector2f(pos.x, rect.top), VAR->color_fond);
	//
	cache_fond[1][0] = sf::Vertex(sf::Vector2f(pos.x, rect.top), VAR->color_fond);
	cache_fond[1][1] = sf::Vertex(sf::Vector2f(rect.left, rect.top), VAR->color_fond);
	cache_fond[1][2] = sf::Vertex(sf::Vector2f(rect.left, rect.top + rect.height), VAR->color_fond);
	cache_fond[1][3] = sf::Vertex(sf::Vector2f(pos.x, rect.top + rect.height), VAR->color_fond);
	//
	cache_fond[2][0] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top), VAR->color_fond);
	cache_fond[2][1] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, rect.top), VAR->color_fond);
	cache_fond[2][2] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, rect.top + rect.height), VAR->color_fond);
	cache_fond[2][3] = sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top + rect.height), VAR->color_fond);
	//
	cache_fond[3][0] = sf::Vertex(sf::Vector2f(pos.x, rect.top + rect.height), VAR->color_fond);
	cache_fond[3][1] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, rect.top + rect.height), VAR->color_fond);
	cache_fond[3][2] = sf::Vertex(sf::Vector2f(pos.x + camera.getSize().x, pos.y + camera.getSize().y), VAR->color_fond);
	cache_fond[3][3] = sf::Vertex(sf::Vector2f(pos.x, pos.y + camera.getSize().y), VAR->color_fond);
}

void CApp::afficher_lines_bord()
{
	static sf::Uint8 var = 0;
	static bool change = false;

	sf::Color color = sf::Color(255, 255, var);

	for (int i=0; i<lines_bord.getVertexCount(); i++)
		lines_bord[i].color = color;
	fenetre.draw(lines_bord);
	
	if (!change)
	{
		if (var + 10 > 255)
		{var = 255; change = true;}
		else {var += 10;}
	}
	else
	{
		if (var - 10 < 0)
		{var = 0; change = false;}
		else {var -= 10;}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CApp::gerer()
{
	ADVIO->gerer();

	//Enregistrer les nouvelles images pour ctrl-z / ctrl-y
	if (COPY == NULL && !IO->pressed(CInput::MLeft) && !IO->pressed(CInput::MRight))
	{
		for (int i=0; i < CALQUE_LIST.size(); i++)
			if (CALQUE_LIST[i]->changed)
			{
				CALQUE_LIST[i]->changed = false;

				RETOUR->add_retour({CALQUE_LIST[i], IO});
				CALQUE_LIST[i]->creer_retour(&CALQUE_LIST[i]->getTexture()->copyToImage(), CCalque::ACT);
				IO->creer_retour();
			}
	}

	if (!CHud::onHud() && !CHud::isBusy())
	{
		//Utiliser l'outil
		if (OUTIL != NULL && COPY == NULL || COPY != NULL && COutil::isTransform())
			OUTIL->use();
		//Copie
		if (!COutil::isTransform() && !COutil::isMove() && COPY != NULL)
			COPY->move();
	}
	SELEC->move();
}

void CApp::afficher()
{
	static sf::Vector2u size_window = fenetre.getSize();
	if (size_window != fenetre.getSize())
	{
		size_window = fenetre.getSize();
		init_camera();
	}

	static bool fullscreen = false;
	if (IO->again(CInput::F11))
	{
		if (!fullscreen)
			fenetre.create(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 32), "Sprite Editor", sf::Style::Fullscreen);
		else
			fenetre.create(sf::VideoMode(800, 600, 32), "Sprite Editor");
		fenetre.setVerticalSyncEnabled(true);

		fullscreen = !fullscreen;
	}

	//CPanneau::gererPanneau();
	CHud::gererHud(1.f/zoom);

	//Nettoyer fenêtre
	fenetre.setView(camera);
	fenetre.clear(VAR->color_fond);

	gererFond();
	fenetre.draw(sprite_transparency);
	for (int i = 0; i < 4; i++)
		fenetre.draw(cache_fond[i]);
	//fenetre.clear(sf::Color(255*bool(rand()%2), 255*bool(rand()%2), 255*bool(rand()%2)));

	//Afficher les calques / la sélection
	for (int i=0; i<CCalque::calque_list.size(); i++)
	{
		//if (CCalque::_t == CCalque::calque_list[i])
		//	SPRITE_ANIM->.afficher_ombre();
		CCalque::calque_list[i]->afficher();
		
		if (COPY != NULL && CALQUE == CALQUE_LIST[i])
			COPY->afficher();
	}

	afficher_lines_bord();
	//SPRITE_ANIM->.afficher();

	if (COPY != NULL)
		COPY->afficher_lines();
	
	//Afficher les lignes de la séléction
	SELEC->afficher_lines();

	//Afficher les objets relatifs à l'outil
	if (!CHud::onHud() && OUTIL != NULL || COutil::isTransform())
		OUTIL->afficher();

	CHud::afficherHud();

	//Rafraichir fenêtre
	fenetre.display();

	frame++;
}

