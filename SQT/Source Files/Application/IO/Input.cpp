#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/App.h"
#include "Source Files/Fonction/Fonction.h"

CInput* CInput::_t;

CInput::CInput(void)
{
	std::vector<int> keys_used = {
		Qt::Key_Up, Qt::Key_Right, Qt::Key_Down, Qt::Key_Left,
		Qt::Key_Plus, Qt::Key_Minus,
		Qt::Key_A, Qt::Key_Z, Qt::Key_E, Qt::Key_R, Qt::Key_T, Qt::Key_Y, Qt::Key_U, Qt::Key_I, Qt::Key_O, Qt::Key_P, 
		Qt::Key_Q, Qt::Key_S, Qt::Key_D, Qt::Key_F, Qt::Key_G, Qt::Key_H, Qt::Key_J, Qt::Key_K, Qt::Key_L, Qt::Key_M, 
		Qt::Key_W, Qt::Key_X, Qt::Key_C, Qt::Key_V, Qt::Key_B, Qt::Key_N,
		Qt::Key_Enter,
		Qt::Key_Delete,
		Qt::Key_F11,
		Qt::Key_Control, Qt::Key_Shift, Qt::Key_Alt, Qt::Key_Tab, Qt::Key_AltGr,
		Qt::Key_Space,
		Qt::LeftButton,
		Qt::RightButton,
		Qt::MiddleButton,
	};

	for (int i=0; i < keys_used.size(); i++) 
		hash[keys_used[i]] = Key_struct();

	/*
		MLeft,
		MRight,
		MMiddle,
		MWAdd,
		MWSub,
	*/

	ini_pos(sf::Mouse::getPosition(*APP->fenetre));
	//creer_retour();
}

void CInput::ini_pos(sf::Vector2i var_pos)
{
	pos_m = var_pos;
	pos_prec_m = var_pos;
}

void CInput::setMousePosition(sf::Vector2i screened)
{
	sf::Mouse::setPosition(screened, *APP->fenetre);
	pos_prec_m = pos_m;
	pos_m = sf::Mouse::getPosition(*APP->fenetre);
	delta_m = sf::Vector2i();

	pos_prec = pos;
	pos = CFonction::pointed(pos_m);
	delta_p = sf::Vector2i();

	center_prec = center;
	center = pos;
	 
	pixel_prec = pixel;
	pixel = sf::Vector2i(floor(pos.x), floor(pos.y));
}

bool CInput::pressed(int code) {
	return hash[code].frame_pressed > hash[code].frame_released;
}

bool CInput::released(int code) {
	return (this->current_frame-1) == hash[code].frame_released;
}

bool CInput::log(int code) {
	return again(code) || long_tap(code);
}

bool CInput::again(int code) {
	return (this->current_frame-1) == hash[code].frame_pressed;
}

bool CInput::long_tap(int code) {
	return pressed(code) && (this->current_frame-1) - hash[code].frame_pressed > tempo;
}

bool CInput::double_tap(int code) {
	return again(code) && hash[code].frame_pressed - hash[code].frame_released < tempo_d;
}

bool CInput::isCMA() {
	return pressed(Qt::Key_Control) 
		|| pressed(Qt::Key_Shift) 
		|| pressed(Qt::Key_Alt);
}

bool CInput::isZQSD() {
	return pressed(Qt::Key_Z) 
		|| pressed(Qt::Key_Q) 
		|| pressed(Qt::Key_S) 
		|| pressed(Qt::Key_D);
}

/*
bool CInput::isPressMode(Qt::Key code, PressMode press_mode)
{
	if (t[code] == 0 && press_mode == NONE) return true;
	if (double_tap(code) && press_mode == DOUBLE_TAP || press_mode == PRESSED) return true;
	if (t[code] == 1 && press_mode == PRESSED || press_mode == AGAIN) return true;
	if (t[code] > tempo && press_mode == PRESSED || press_mode == LONG_TAP) return true;
	if (press_mode == PRESSED) return true;
	return false;
}
*/

/*
int CInput::getPressMode(Qt::Key code)
{
	if (t[code] == 0) return  1 << NONE;
	
	int return_value = 1 << PRESSED;
	if (double_tap(code)) return_value += 1 << DOUBLE_TAP;
	if (t[code] == 1) {return_value += 1 << AGAIN; return_value += 1 << LOG;}
	else if (t[code] > tempo) {return_value += 1 << LONG_TAP; return_value += 1 << LOG;}

	return return_value;
}
*/

/*
int CInput::getPressMode(PressMode press_mode)
{
	return 1 << press_mode;
}
*/

/*
CInput::type_advio CInput::key_from(std::vector<CInput::Key> key_list)
{
	type_advio code = {false, false, false, false, static_cast<CInput::Key>(LASTKEY)};

	for (int i=0; i < key_list.size(); i++)
	{
		if (key_list[i] == Qt::Key_Control)
			code.CTRL = true;
		else if (key_list[i] == Qt::Key_Shift)
			code.MAJ = true;
		else if (key_list[i] == Qt::Key_Alt) 
			code.ALT = true;
		else if (key_list[i] == Qt::Key_Space) 
			code.SPACE = true;
		
		code.KEY = key_list[i];
	}

	return code;
}
*/

/*
int CInput::id_of(type_advio key_comb)
{
	return key_comb.CTRL + (key_comb.MAJ << 1) + (key_comb.ALT << 2) + (key_comb.ALT << 3) + (key_comb.KEY << 4) + (key_comb.press_mode << 4 + int(std::ceil(std::log2(float(LASTMOUSE)))));
}
*/

bool CInput::gerer()
{
	current_frame++;

	if (pressed(Qt::Key_Escape)) //Quit program
		return true;

	pos_prec_m = pos_m;
	pos_m = sf::Mouse::getPosition(*APP->fenetre);
	delta_m = pos_prec_m - pos_m;

	pos_prec = pos;
	pos = CFonction::pointed(pos_m);
	delta_p = pixel_prec - pixel;

	center_prec = center;
	center = pos;
	 
	pixel_prec = pixel;
	pixel = sf::Vector2i(floor(pos.x), floor(pos.y));

	emit posPixelXChanged(pixel.x);
	emit posPixelYChanged(pixel.y);

	//key_combinaison[0] = {t[Ctrl], t[Maj], t[Alt], t[Space], key_pressed[0], getPressMode(key_pressed[0])};
	//key_combinaison[1] = {t[Ctrl], t[Maj], t[Alt], t[Space], key_pressed[1], getPressMode(key_pressed[1])};

	return false;
}

void CInput::registerPressed(int code) {
	hash[code].frame_pressed = this->current_frame;
}

void CInput::registerReleased(int code) {
	hash[code].frame_released = this->current_frame;
}

//------------------------------------------------------//
/*
void CInput::creer_retour() {
	i_retour_click++;
	retour_click.push_back(ex_click);
}

void CInput::ctrl_z() {
	i_retour_click--;
	ex_click = retour_click[i_retour_click];
}

void CInput::ctrl_y() {
	i_retour_click++;
	ex_click = retour_click[i_retour_click];
}

void CInput::delete_retour() {
	retour_click.erase(retour_click.begin() + i_retour_click + 1, retour_click.end());
}
*/