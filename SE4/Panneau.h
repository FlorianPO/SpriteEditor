#pragma once

#include "stdafx.h"
#include "Hud.h"
#include "Retourable.h"
#include "PanneauControler.h" 

class CPanneau;

class CBouton
{
public:
	enum GROUP
	{
		NONE = 0,
		ONE,
		ONE_ALL
	};
	
	CBouton(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos);
	virtual ~CBouton(void) = 0;

	virtual bool gerer() {return false;}
	virtual bool update(bool forceTo = false, bool force_var = true) {return false;}
	virtual void draw(sf::RenderTexture* render) = 0;

	//Group
	public:		void group(CBouton* with, GROUP grp);	
				void updateGroup();
												protected:	GROUP groupe;
	
	//Sprite
	public:		bool onSprite();		
				inline void setColor(sf::Color c) { sprite.setColor(c); }
				
												protected:	sf::Sprite sprite;
															sf::Color color = sf::Color::White;
															sf::IntRect rect;

	public:		inline void setParent(CPanneau* p) { parent = p; }		
				inline CPanneau* getParent() { return parent; }

												protected:	CPanneau* parent;

	//Core members
	public:		inline void setPredicat(std::function<int(fonction_type)>* p) { predicat = p; }	
				inline std::function<int(fonction_type)>* getPredicat() { return predicat; }
				int usePredicat();
	public:		inline void setFonction(std::function<void(fonction_type)>* f) { fonction = f; }
				inline std::function<void(fonction_type)>* getFonction() { return fonction; }
				void useFonction();
	public:		inline void setArguments(fonction_type* a) { arguments = a; }
				inline fonction_type* getArguments(fonction_type* a) { return arguments; }
				void addUnrefArg(int arg);
												protected:	std::function<int(fonction_type)>* predicat = NULL;
															std::function<void(fonction_type)>* fonction = NULL;
															fonction_type* arguments = NULL;
															std::vector<int> unreferenced_arguments;

	//Replace the argument until wish
	public:		void replaceArgument(fonction_type* a);	
				void cancelArgumentReplacement();

												protected:	fonction_type* ex_arguments = NULL;
	
protected:
	bool init = true;
};











#define PANEL_LIST CPanneau::panneau_list
class CPanneau : public CHud, public CRetourable
{
public:
//STATIC//
	static std::vector<std::vector<CPanneau*>> panneau_list;

	static bool testPanneau();
	static void gererPanneau();
	static void afficherPanneau();
	static int whichPosition(CPanneau* panneau);
//

	CPanneau(const sf::Texture* texture, sf::IntRect rect, CPanneau* with = NULL, sf::IntRect swap = sf::IntRect());
	~CPanneau(void);

	void zoom(float z) override;
	inline float getZoom() { return sprite.getScale().x; }

	void afficher() override;
	bool test() override;
	void gerer() override;
	void update() override;
	void draw();

	//Sprite
	public:		inline const sf::Sprite* getSprite() { return &sprite; }
	public:		inline sf::Vector2f getPosition() { return sprite.getPosition(); }
				void setPosition(sf::Vector2f pos);

												private:	sf::Sprite sprite;
															sf::Vector2i size_ini;		//Size of the sprite's texture
															sf::Sprite sprite_fond;
															sf::IntRect rect;
															sf::RenderTexture render;
	//Core
	public:		void setPredicatScroll(std::function<int(fonction_type)>* p);
				inline void setPredicatSwap(std::function<int(fonction_type)>* p) { predicatSwap = p; }
				inline void setFonction(std::function<void(fonction_type)>* f) { fonction = f; }
				inline void setArguments(fonction_type* a) { arguments = a; }

												private:	std::function<int(fonction_type)>* predicatScroll = NULL;
																void scrollMe();
																	bool scrolledDown = true;
																	bool scrolling = false;
																	bool scrollgoal;
																	float offset = 0;
															std::function<int(fonction_type)>* predicatSwap = NULL;
																sf::IntRect swap; //For a 2 stated pannel
																bool swap_etat = false; //Swaped or not
															std::function<void(fonction_type)>* fonction = NULL;
															fonction_type* arguments = NULL;
	//Group
	public:		void group(CPanneau* with);
				void unGroup();
				int getGroup() { return which_group; }

												private:	int which_group;
	//Move group
	public:		inline void setMoveGroup(CPanneau* panneau) { move_group = panneau->move_group; }
				void affectMoveGroup(std::function<void(int, int)>* function = NULL);
				int getMoveGroup() { return move_group; }

												private:	int move_group = 0;
	//Buttons
	public:		void addBouton(CBouton* b, CBouton* with = NULL, CBouton::GROUP groupe = CBouton::NONE);
				std::vector<CBouton*>* getBoutonList(CBouton* bouton);
	public:		bool testButtons();
												private:		std::vector<std::vector<CBouton*>> bouton_list;
private:
	bool ini = true;
};
