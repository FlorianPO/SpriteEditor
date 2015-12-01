#include "stdafx.h"

/*
Application's architecture:
	A lot of objects are independant, they provide functionnality which can be used by other objects.
	
	Here are the main components of the application:



	- APP
		APP is the main object of the application. It contains the camera (camera) and the window (fenetre) of
		the application. Displaying an object will be performed by using draw(...) function of the APP's window.
		All the application will be managed by its gerer() and afficher() functions, these sections are changeable.
	- IO
		IO provides information on keyboard and mouse events. For example, pressed(CInput::A) will return true if A key
		is pressed. You can get here the mouse's position and more.
	- ADVIO
		ADVIO is an extension of IO. It provides a simple way to assign instructions to a key combinaison. It's worth a look.
	- RES
		It contains all the ressources needed by the application, such as textures (which MUST be centralized due to performance reasons),
		pre-built sprites which could be commonly used, and shaders.
	- VAR
		It contains global variables concerning the application wich could be often used, such as opacity of all the tools and even PI.



	- CALQUE
		CALQUE is the selected layer of the application, they are the main objects of it. All layers are contained in a vector called CALQUE_LIST
	- COutil tools
		All tools used in the application inherit of COutil. They allow drawing on the layers.
	- RETOUR
		RETOUR is the one who manages CTRL+Z / CTRL+Y combinaisons. You can inherit CRetour if you want to use this functionnality.
	- COPY
		COPY is the selected pasted selection (with CTRL+C / CTRL+V). All copy are contained in a vector called COPY_LIST.
	- BROSSE
		Brush functionnality used by different tools.
	- SELEC
		Allows selecting areas with dedicated tools to manipulate images. A mask with black and white pixels performs this.
		Done with OpenGl, these functionnalities are certainly the most powerfull of the application. Worth a look.
		Major optimisations are also planned, even if current performances are quite impressive (need to learn more OpenGL).
	- GUI
		GUI is the panel on the right side. It uses the Menu framework which is a big advancement of the project.



	- Menu framework
		Here is why I restarted this project for the third time. Performances were good, but programming was awful when dealing
		with menus. Now, you can declare a panel with buttons.
		You declare their position relatively to the panel, their functions when they are clicked on and other parameters, and ...
		that's all. CHud class will provide other functionnality such as priority on panel and constant size.
		All is perform with anonym functions and it's very modular and simple, you can use old-style programming whitout problem, it is meant
		to last overtime. Plus, performances were not overlooked. Now this project is powerful and modular. Worth a look too.



	- CFonction
		It provides tons of functions such as checking if the mouse cursor is on a sprite or not and many others.



Common programming style:
	If you quickly look at the code, you will notice a lot of similar function names in the different classes.
	The most used are:
		- init() or initialiser()
			Init functions, nothing more to say.
		- gerer()
			These kinds of functions should be the proceeding functions. To use a tool for example, you will call
			this function of the tool. They perform the main changes of the application. A boolean can be returned.
		- afficher()
			These are the displaying functions (SFML displaying functions) which are called at the end of a frame.
	
	gerer() function can also update graphic components. If you want to distinguish these actions, use an update()
	function as in CBoutons classes.
	Function names are meant to be explicit, it is a mix between english and french (sorry).

	I don't really mind if you use:

		void function() {
			...
		}

	Instead of:

		void function() 
		{
				...
		}

	I'm fine with both. But NEVER put '{' and '}' if a bloc has only 1 instruction in your final code.
	Generally I tend to make it minimal and clear. Check out COutil::chooseOutil(...) function in "Outil.cpp".
	There is not one way to program, only clever ways. Visibility is important to maintain a clean code.
	Get rid of useless parenthesis in conditions and keep it visible too:

		if (a + b == (1 + c)*4)

	Since the application is rendered in real-time, you will probably have to save previous frame's variables.
	"ex_variable" is a commonly used term to do so.
	Every single instance of a class such as IO class or APP class is named "_t" and can be accessed with:

		CMyclass::_t

	Macros are used to avoid this painful naming usage. "CInput::_t->gerer()" is shorten as "IO->gerer()".
*/