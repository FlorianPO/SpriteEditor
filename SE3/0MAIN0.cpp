/*
Here is where all begins. The compilation order is natively set up alphabeticaly, that's why this file
is named with a number, try to keep it first while compiling.

Dependencies such as SFML, vector, queue etc... are grouped in the "stdafx.h" file.
Largely used types are also placed there, keep it simple.

This code is rigorously written. Check "stdafx.cpp" to know the bases of the application.
*/

#include "stdafx.h"

#include "App.h"
#include "Input.h"
#include "Res.h"
#include "Var.h"
#include "Writter.h"
#include "Gui.h"
#include "SpriteAnim.h"
#include "EnteredInput.h"
#include "Selec.h"
#include "Curseur.h"
#include "OptionColor.h"
#include "Retour.h"
#include "Copy.h"

/*
Create here your objects. Every objects used are dynamic, static declarations could work, 
but it is incompatible with the use of macro (I tried though).
Since macros provide tons of readability (especially with an IDE which provides colored highlighting), 
this task is worth it. Plus it gives you total control on the application and a dedicated place to init 
your static variables.
*/
void init()
{
	APP = new CApp();
	VAR = new CVar();
	RES = new CRes();
	RETOUR = new CRetour();
	WRITTER = new CWritter();
	IO = new CInput();
	BROSSE = new CBrosse();
	CURSEUR = new CCurseur();
	SELEC = new CSelec();
	SPRITE_ANIM = new CSpriteAnim();
	GUI = new CGui();
	ADVIO = new CEnteredInput();

	//CDegrade::mode = 0;
	//CDegrade::transp = false;

	OUTIL = NULL;
	CALQUE = NULL;
	COPY = NULL;
	OPTION_COLOR = NULL;
}

/*
Proper way to program.
*/
void free()
{
	if (OUTIL != NULL) delete OUTIL;
	if (CALQUE != NULL) delete CALQUE;
	if (COPY != NULL) delete COPY;
	if (OPTION_COLOR != NULL) delete OPTION_COLOR;

	delete BROSSE;
	delete CURSEUR;
	delete SELEC;
	delete SPRITE_ANIM;
	delete GUI;

	delete APP;
	delete VAR;
	delete RES;
	delete RETOUR;
	delete WRITTER;
	delete IO;
	delete ADVIO;
}

/*
Here is the main loop of the application:
 - Check keyboard and mouse envents (IO->gerer())
 - APP proceeds due to these events (APP->gerer())
 - APP is displayed (APP->afficher())

This three steps correspond to one frame.
APP is set up to run at 60 FPS (check its constructor).
Pressing Escape key will close the application.
*/
void main()
{
	init();

	APP->charger("test.png");

	sf::Clock horloge; //A clock for couting FPS
	while (true)
	{
		if (IO->gerer()) //True if Escape button pressed or else
		{
			APP->fenetre.close();
			break; //Quit application
		}
		if (APP->fenetre.hasFocus())
		{
			APP->gerer(); //Proceeding
			APP->afficher(); //Displaying
		}
		//Print FPS
		//std::cout << int(1/horloge.restart().asSeconds()) << std::endl;
	}

	free();
}