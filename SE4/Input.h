#pragma once

#include "stdafx.h"
#include "Retourable.h"
#include <bitset>

#define IO CInput::_t
class CInput : public CRetourable
{
public:
	static CInput* _t;
public:
	CInput(void);
	~CInput(void);
	
public:
	enum Key
	{
		AltGr,
		Tab,
		Up,
		Right,
		Down,
		Left,
		Add,
		Sub,
		A, Z, E, R, T, Y, U, I, O, P, Q, S, D, F, G, H, J, K, L, M, W, X, C, V, B, N,
		Enter,
		Supr,
		F11,
		Ctrl,
		Maj,
		Alt,
		Space,
		LASTKEY, //Do not use
		MLeft,
		MRight,
		MMiddle,
		MWAdd,
		MWSub,
		LASTMOUSE
	};

	enum PressMode
	{
		PRESSED = 0,
		AGAIN,
		LONG_TAP,
		DOUBLE_TAP,
		LOG,
		NONE,
		LASTPRESSMODE
	};

	struct type_advio
	{
		bool CTRL;
		bool MAJ;
		bool ALT;
		bool SPACE;

		Key KEY;
		uint8_t press_mode;
	};

	static type_advio key_from(std::vector<Key> key_list);
	static int id_of(type_advio key_comb);

	bool gerer();

	//Touche
	bool pressed(Key key);
	bool log(Key key);
	bool again(Key key);
	bool double_tap(Key key);
	bool long_tap(Key key);
	
	bool isPressMode(Key key, PressMode press_mode);
	int getPressMode(Key key);
	static int getPressMode(PressMode press_mode);

	inline type_advio* getCombinaison() {return key_combinaison;}

	void ini_pos(sf::Vector2i var_pos);

	inline sf::Vector2f getPosition() { return pos; }
	inline sf::Vector2f getPreviousPosition() { return pos_prec; }

	inline int* getRefPos_x() { return &pixel.x; }
	inline int* getRefPos_y() { return &pixel.y; }
	inline sf::Vector2i getPixel() { return pixel; }
	inline sf::Vector2i getPreviousPixel() { return pixel_prec; }

	inline sf::Vector2i getDeltaMouse() { return delta_m; }
	inline sf::Vector2i getDeltaPixel() { return delta_p; }

	sf::Vector2f getCenter() { checkCenter(&center); return center; }
	sf::Vector2f getPreviousCenter() { checkCenter(&center_prec); return center_prec; }
	sf::Vector2f getPreviousCenterClick() { checkCenter(&ex_click); return ex_click; }
	void checkCenter(sf::Vector2f* ptr_vect);
	
	inline void setExClick(sf::Vector2f position) { ex_click = position; }

	bool isCMA();
	bool isZQSD();

private:
	//Attributs
	sf::Event event;

	int t[LASTMOUSE];
	int t_double[LASTMOUSE];
	int t_double_start_frame[LASTMOUSE];

	sf::Vector2f center, center_prec;
	sf::Vector2f pos, pos_prec;
	sf::Vector2i pixel, pixel_prec, delta_p;
	sf::Vector2i pos_m, pos_prec_m, delta_m;

	int tempo = 20;
	int tempo_d = 10;

private:
	type_advio key_combinaison[2];
	sf::Keyboard::Key io_to_sfml[LASTKEY];

//RETOUR
private:
	int i_retour_click = -1;
	std::vector<sf::Vector2f> retour_click;
	sf::Vector2f ex_click;

public:
	void creer_retour();

	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
};

class EqualFn
{
public:
	bool operator()(const int& t1, const int& t2) const
	{
		int mask = (1 << int(std::ceil(std::log2(float(CInput::LASTMOUSE)))) + 4) - 1;

		if (int(t1 & mask) != int(t2 & mask))
			return false;	

		mask = (1 << int(std::ceil(std::log2(float(CInput::LASTMOUSE)))) + int(CInput::LASTPRESSMODE) + 4) - 1 - mask;
		return int(t1 & t2 & mask) > 0;
	}
};

class HashFn
{
public:
	size_t operator()(const int& t1) const {return t1;}
};
