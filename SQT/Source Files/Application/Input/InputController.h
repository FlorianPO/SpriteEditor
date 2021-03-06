#pragma once

#include "stdenum.h"
#include "LineSmoother.h"

#define INIT_INPUT_CONTROLLER InputController::createInstance();
#define INPUT_CONTROLLER InputController::getInstance()
#define INPUT INPUT_CONTROLLER

#define FUNC_PRESSED(key)		(key.frame_pressed > key.frame_released)
#define FUNC_RELEASED(key)		(current_frame - 1 == key.frame_released)
#define FUNC_LOG(key)			(_again(key) || _long_tap(key))
#define FUNC_AGAIN(key)			(current_frame - 1 == key.frame_pressed)
#define FUNC_DOUBLE(key)		(_again(key) && key.frame_pressed - key.ex_frame_pressed < tempo_d)
#define FUNC_LONG(key)			(_pressed(key) && current_frame - 1 - key.frame_pressed > tempo)

class InputController : public QObject
{
	Q_OBJECT
// INSTANCE
private:	static InputController* _t; 
public:		inline static void createInstance() { _t = new InputController(); }
			inline static InputController* getInstance() { return _t; }

// CONSTRUCTOR
public:
	InputController();
	~InputController() {}
	void reset();

private:
	struct Key_struct {
		int ex_frame_pressed=-60;
		int frame_pressed=0;
		int ex_frame_released=-60;
		int frame_released=0;
	};

// SIGNALS SLOTS
	signals:
		void posPixelXChanged(int) const;
		void posPixelYChanged(int) const;
		void combinaisonPressed(const nInt::key_combinaison&) const;

// METHODS
public:
	void registerPressed(nInt::qkey code);
	void registerReleased(nInt::qkey code);
	void registerWheelUp();
	void registerWheelDown();

	bool gerer();

private:
	inline bool _pressed(const Key_struct& key) const		{ return FUNC_PRESSED(key); }
	inline bool _released(const Key_struct& key) const		{ return FUNC_RELEASED(key); }
	inline bool _log(const Key_struct& key) const			{ return FUNC_LOG(key); }
	inline bool _again(const Key_struct& key) const			{ return FUNC_AGAIN(key); }
	inline bool _double_tap(const Key_struct& key) const	{ return FUNC_DOUBLE(key); }
	inline bool _long_tap(const Key_struct& key) const		{ return FUNC_LONG(key); }
public:
	inline bool pressed(nInt::qkey code) const		{ return _pressed(hash[code]); }
	inline bool released(nInt::qkey code) const		{ return _released(hash[code]); }
	inline bool log(nInt::qkey code) const			{ return _log(hash[code]); }
	inline bool again(nInt::qkey code) const		{ return _again(hash[code]); }
	inline bool double_tap(nInt::qkey code) const	{ return _double_tap(hash[code]); }
	inline bool long_tap(nInt::qkey code) const		{ return _long_tap(hash[code]); }
	bool isPressMode(nInt::qkey code, nInt::PressMode press_mode) const;

	bool isSpecial() const;
	bool isZQSD() const;

	nInt::press_code getPressCode(nInt::qkey code) const;

	void setMousePosition(const sf::Vector2i& screened, bool dump_ex=false, bool set_pointer=true);

	inline const std::vector<sf::Vector2f>& getSmoothList() const { return pos_smoothed; }
	inline sf::Vector2f getPosition() const { return pos; }
	inline sf::Vector2f getExPosition() const { return ex_pos; }
	inline sf::Vector2i getDeltaPos() const { return delta_pixel; }
	inline sf::Vector2f getPositionClick() const { return pos_click; }

	inline sf::Vector2i getPixel() const { return pixel; }
	inline sf::Vector2i getExPixel() const { return ex_pixel; }
	inline sf::Vector2i getDeltaPixel() const { return delta_pixel; }
	inline sf::Vector2i getPixelClick() const { return pixel_click; }

	inline sf::Vector2i getScreenPosition() const { return screen; }
	inline sf::Vector2i getExScreenPosition() const { return ex_screen; }
	inline sf::Vector2i getDeltaScreen() const { return delta_screen; }
	inline sf::Vector2i getScreenClick() const { return screen_click; }

	sf::Vector2f screenToPos(const sf::Vector2i& screen_position) const;
	sf::Vector2i posToScreen(sf::Vector2f position) const;

private:
	void bindZQSD();

// MEMBERS
private:
	uint current_frame = 1; //Starts at 1
	QHash<nInt::qkey, Key_struct> hash;

	// Shortcut feature
	std::vector<nInt::qkey> key_pressed;
	std::vector<int> key_to_release;

	LineSmoother lsmooth;
	std::vector<sf::Vector2f> pos_smoothed;
	bool clear_smoothed = false;

	sf::Vector2f pos,		ex_pos,		pos_click,		delta_pos;
	sf::Vector2i pixel,		ex_pixel,	pixel_click,	delta_pixel;
	sf::Vector2i screen,	ex_screen,	screen_click,	delta_screen;

	int tempo = 10;
	int tempo_d = 20;
};
