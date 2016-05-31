#pragma once

#include "stdafx.h"
#include "Source Files/Retour/Retourable.h"
#include "Source Files/Application/Brush/BrushController.h"

#define INIT_IO CInput::createInstance();
#define IO CInput::getInstance()

class CInput : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static CInput* _t; 
public:		inline static void createInstance() { _t = new CInput(); }
			inline static CInput* getInstance() { return _t; }

// CONSTRUCTOR
	CInput(void);
	~CInput(void) {}

// SIGNALS SLOTS
	signals:
		void posPixelXChanged(int);
		void posPixelYChanged(int);

// METHODS
public:
	void registerPressed(int code);
	void registerReleased(int code);
	//static type_advio key_from(std::vector<Key> key_list);
	//static int id_of(type_advio key_comb);

	bool gerer();

	//Keys and mouse
	bool pressed(int code);
	bool released(int code);
	bool log(int code);
	bool again(int code);
	bool double_tap(int code);
	bool long_tap(int code);

	bool isCMA();
	bool isZQSD();

	//Mouse Wheel
	bool scroll_up() {return false;}
	bool scroll_down() {return false;}
	
	//bool isPressMode(Qt::Key key, PressMode press_mode);
	//int getPressMode(Qt::Key key);
	//static int getPressMode(PressMode press_mode);

	//inline type_advio* getCombinaison() {return key_combinaison;}

	void ini_pos(sf::Vector2i var_pos);
	void setMousePosition(sf::Vector2i screened);

	inline sf::Vector2f getPosition() { return pos; }
	inline sf::Vector2f getPreviousPosition() { return pos_prec; }

	inline sf::Vector2i getScreenPosition() { return pos_m; }
	inline sf::Vector2i getPreviousScreenPosition() { return pos_prec_m; }

	inline int* getRefPos_x() { return &pixel.x; }
	inline int* getRefPos_y() { return &pixel.y; }
	inline sf::Vector2i getPixel() { return pixel; }
	inline sf::Vector2i getPreviousPixel() { return pixel_prec; }

	inline sf::Vector2i getDeltaMouse() { return delta_m; }
	inline sf::Vector2i getDeltaPixel() { return delta_p; }

	sf::Vector2f getCenter() { return BRUSH->centerOf(center); }
	sf::Vector2f getPreviousCenter() { return BRUSH->centerOf(center_prec); }
	sf::Vector2f getPreviousCenterClick() { return BRUSH->centerOf(ex_click); }
	
	inline void setExClick(sf::Vector2f position) { ex_click = position; }
	
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

	struct Key_struct
	{
		uint frame_pressed;
		uint frame_released;
	};

	struct type_advio
	{
		// Special keys: used for combinaisons
		bool CTRL;
		bool MAJ;
		bool ALT;
		bool SPACE;

		Qt::Key KEY;
		PressMode press_mode;
	};

// MEMBERS
private:
	//Attributs
	uint current_frame = 1; //Starts at 1
	QHash<int, Key_struct> hash;

	sf::Vector2f center, center_prec;
	sf::Vector2f pos, pos_prec;
	sf::Vector2i pixel, pixel_prec, delta_p;
	sf::Vector2i pos_m, pos_prec_m, delta_m;
	sf::Vector2f ex_click;

	int tempo = 20;
	int tempo_d = 10;
/*
//RETOUR
private:
	int i_retour_click = -1;
	std::vector<sf::Vector2f> retour_click;

public:
	void creer_retour();

	virtual void ctrl_z() override;
	virtual void ctrl_y() override;
	virtual void delete_retour() override;
*/
};

/*
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
*/
