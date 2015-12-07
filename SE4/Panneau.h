#pragma once

#include "stdafx.h"
#include "Hud.h"

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
	void updateGroup();

	CBouton(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos);
	virtual ~CBouton(void) = 0;

	bool onSprite();
	void group(CBouton* with, GROUP grp);

	virtual bool gerer() {return false;}
	virtual bool update(bool forceTo = false, bool force_var = true) {return false;}
	virtual void draw(sf::RenderTexture* render) = 0;
	
	void useFonction();
	int usePredicat();

	inline void setParent(CPanneau* p) { parent = p; }
	inline void setColor(sf::Color c) { sprite.setColor(c); }

	void addUnrefArg(int arg);
	inline void setPredicat(std::function<int(fonction_type)>* p) { predicat = p; }
	inline void setFonction(std::function<void(fonction_type)>* f) { fonction = f; }
	inline void setArguments(fonction_type* a) { arguments = a; }

	void replaceArgument(fonction_type* a);
	void cancelArgumentReplacement();

	inline std::function<int(fonction_type)>* getPredicat() { return predicat; }
	inline std::function<void(fonction_type)>* getFonction() { return fonction; }
	inline fonction_type* getArguments(fonction_type* a) { return arguments; }

protected:
	CPanneau* parent;

	sf::Sprite sprite;
	sf::Color color = sf::Color::White;
	sf::IntRect rect;
	GROUP groupe;

	std::function<int(fonction_type)>* predicat = NULL;
	std::function<void(fonction_type)>* fonction = NULL;
	fonction_type* arguments = NULL;
	fonction_type* ex_arguments = NULL;
	std::vector<int> unreferenced_arguments;

	bool init = true;
	
};

class CPanneau : public CHud
{
public:
	void zoom(float z) override;
	void afficher() override;
	bool test() override;
	void gerer() override;
	void update() override;

	bool testButtons();

	static bool testPanneau();
	static void gererPanneau();
	static void afficherPanneau();
private:
	static std::vector<std::vector<CPanneau*>> panneau_list;
public:
	CPanneau(const sf::Texture* texture, sf::IntRect rect, CPanneau* with = NULL, sf::IntRect swap = sf::IntRect());
	~CPanneau(void);

	inline float getZoom() { return sprite.getScale().x; }

	void group(CPanneau* with);
	void unGroup();

	void addBouton(CBouton* b, CBouton* with = NULL, CBouton::GROUP groupe = CBouton::NONE);
	void draw();

	void setPosition(sf::Vector2f pos);

	inline sf::Vector2f getPosition() { return sprite.getPosition(); }
	inline const sf::Sprite* getSprite() { return &sprite; }

	std::vector<CBouton*>* getBoutonList(CBouton* bouton);
	void setPredicatScroll(std::function<int(fonction_type)>* p);
	inline void setPredicatSwap(std::function<int(fonction_type)>* p) { predicatSwap = p; }
	inline void setArguments(fonction_type* a) { arguments = a; }
	inline void setFonction(std::function<void(fonction_type)>* f) { fonction = f; }

	inline void setMoveGroup(CPanneau* panneau) { move_group = panneau->move_group; }
	void affectMoveGroup();

private:
	void scrollMe();

	std::vector<std::vector<CBouton*>> bouton_list;
	sf::RenderTexture render;

	sf::Sprite sprite_fond;
	sf::Sprite sprite;

private:
	bool ini = true;
	float offset = 0;
	sf::Vector2i size_ini;
	int which_group;

	std::function<int(fonction_type)>* predicatScroll = NULL;
	bool scrolledDown = true;
	bool scrolling = false;
	bool scrollgoal;

	int move_group = 0;

	fonction_type* arguments = NULL;

	sf::IntRect rect; //Primal rect of the pannel

	//SWAP//
	sf::IntRect swap; //For a 2 stated pannel
	bool swap_etat = false; //Swaped or not
	std::function<int(fonction_type)>* predicatSwap = NULL;

	std::function<void(fonction_type)>* fonction = NULL;
};
