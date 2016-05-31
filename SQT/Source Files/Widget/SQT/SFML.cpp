#include "Source Files/Widget/SQT/SFML.h"

#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/Var/Var.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Copy/Copy.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Tool/ToolController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/IO/Input.h"

SFML::SFML(QWidget* Parent, const QPoint& Position, const QSize& Size) : SQT(Parent, Position, Size)
{
	INIT_APP(this);

	INIT_VAR
	INIT_RES

	INIT_COLOR_CONTROLLER
	INIT_TOOL_CONTROLLER
	INIT_LAYER_CONTROLLER
	INIT_BRUSH_CONTROLLER
	INIT_COPY_CONTROLLER
		
	INIT_IO
	INIT_CURSEUR
	INIT_SELEC
}

void SFML::OnInit() {
	//RETOUR = new CRetour();
	//WRITTER = new CWritter();
	//BROSSE = new CBrosse();
		
		
	//SPRITE_ANIM = new CSpriteAnim();
	//GUI = new CGui();
	//ADVIO = new CEnteredInput();

	//CDegrade::mode = 0;
	//CDegrade::transp = false;

	//TOOL = NULL;
	//COPY = NULL;
	//OPTION_COLOR = NULL;
	APP->loadFromPath("test.png");
	//CTool::chooseOutil(CTool::CRAYON);
}

void SFML::OnUpdate() {
	//clear(sf::Color(0, 128, 0));
	if (IO->gerer()) //True if Escape button pressed or else
	{
		//APP->fenetre->close();
		//break; //Quit application
	}

	//std::cout << IO->getPosition().x << "  " << IO->getPosition().y << std::endl;
	//if (APP->fenetre->hasFocus())
	//{
	APP->run(); //Proceeding
	APP->display(); //Displaying

	//static sf::Clock horloge;
	//std::cout << int(1/horloge.restart().asSeconds()) << std::endl;
	//}
	/*
		//std::cout << "lol" << std::endl;
        // On efface l'écran
        clear(sf::Color(150, 128, 150));

        // Une petite rotation du sprite
        //mySprite.rotate(GetFrameTime() * 100.f);

        // Et on l'affiche
        // draw(mySprite);
		*/
	update();
}

void SFML::keyPressEvent(QKeyEvent* Qk) {
	IO->registerPressed(Qk->key());
}

void SFML::keyReleaseEvent(QKeyEvent* Qk) {
	IO->registerReleased(Qk->key());
}
void SFML::mousePressEvent(QMouseEvent* Qm) {
	IO->registerPressed(Qm->button());
}

void SFML::mouseReleaseEvent(QMouseEvent* Qm)  {
	IO->registerReleased(Qm->button());
}