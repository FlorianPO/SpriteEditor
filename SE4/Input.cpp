#include "Input.h"
#include "App.h"
#include "Fonction.h"
#include "Brosse.h"

CInput* IO;

CInput::CInput(void)
{
	for (int i = 0; i<LASTMOUSE; i++)
	{
		t[i] = 0;
		t_double[i] = 0;
		t_double_start_frame[i] = 0;
	}

	io_to_sfml[Ctrl] = sf::Keyboard::LControl;
	io_to_sfml[Maj] = sf::Keyboard::LShift;
	io_to_sfml[Alt] = sf::Keyboard::LAlt;
	io_to_sfml[AltGr] = sf::Keyboard::RAlt;
	io_to_sfml[Tab] = sf::Keyboard::Tab;
	io_to_sfml[Up] = sf::Keyboard::Up;
	io_to_sfml[Right] = sf::Keyboard::Right;
	io_to_sfml[Down] = sf::Keyboard::Down;
	io_to_sfml[Left] = sf::Keyboard::Left;
	io_to_sfml[Add] = sf::Keyboard::Add;
	io_to_sfml[Sub] = sf::Keyboard::Subtract;
	io_to_sfml[Space] = sf::Keyboard::Space;
	io_to_sfml[A] = sf::Keyboard::A;
	io_to_sfml[Z] = sf::Keyboard::Z ;
	io_to_sfml[E] = sf::Keyboard::E;
	io_to_sfml[R] = sf::Keyboard::R;
	io_to_sfml[T] = sf::Keyboard::T;
	io_to_sfml[Y] = sf::Keyboard::Y;
	io_to_sfml[U] = sf::Keyboard::U;
	io_to_sfml[I] = sf::Keyboard::I;
	io_to_sfml[O] = sf::Keyboard::O;
	io_to_sfml[P] = sf::Keyboard::P;
	io_to_sfml[Q] = sf::Keyboard::Q;
	io_to_sfml[S] = sf::Keyboard::S;
	io_to_sfml[D] = sf::Keyboard::D;
	io_to_sfml[F] = sf::Keyboard::F;
	io_to_sfml[G] = sf::Keyboard::G;
	io_to_sfml[H] = sf::Keyboard::H;
	io_to_sfml[J] = sf::Keyboard::J;
	io_to_sfml[K] = sf::Keyboard::K;
	io_to_sfml[L] = sf::Keyboard::L;
	io_to_sfml[M] = sf::Keyboard::M;
	io_to_sfml[W] = sf::Keyboard::W;
	io_to_sfml[X] = sf::Keyboard::X;
	io_to_sfml[C] = sf::Keyboard::C;
	io_to_sfml[V] = sf::Keyboard::V;
	io_to_sfml[B] = sf::Keyboard::B;
	io_to_sfml[N] = sf::Keyboard::N;
	io_to_sfml[Enter] = sf::Keyboard::Return;
	io_to_sfml[Supr] = sf::Keyboard::Delete;
	io_to_sfml[F11] = sf::Keyboard::F11;

	ini_pos(sf::Mouse::getPosition(APP->fenetre));
	creer_retour();
}

CInput::~CInput(void) {}

void CInput::ini_pos(sf::Vector2i var_pos)
{
	pos_m = var_pos;
	pos_prec_m = var_pos;
}

bool CInput::pressed(Key key) {return t[key];}

bool CInput::log(Key key) {return t[key] == 1 || t[key] > tempo;}

bool CInput::again(Key key) {return t[key] == 1;}

bool CInput::double_tap(Key key)
{
	if (t[key] && t_double[key] > 0)
	{
		if (t_double_start_frame[key] == 0)
		{
			t_double_start_frame[key] = t_double[key];
			return true;
		}
		return t_double[key] == t_double_start_frame[key];
	}
	return false;
}

bool CInput::isPressMode(Key key, PressMode press_mode)
{
	if (t[key] == 0 && press_mode == NONE) return true;
	if (double_tap(key) && press_mode == DOUBLE_TAP || press_mode == PRESSED) return true;
	if (t[key] == 1 && press_mode == PRESSED || press_mode == AGAIN) return true;
	if (t[key] > tempo && press_mode == PRESSED || press_mode == LONG_TAP) return true;
	if (press_mode == PRESSED) return true;
	return false;
}

int CInput::getPressMode(Key key)
{
	if (t[key] == 0) return  1 << NONE;
	
	int return_value = 1 << PRESSED;
	if (double_tap(key)) return_value += 1 << DOUBLE_TAP;
	if (t[key] == 1) {return_value += 1 << AGAIN; return_value += 1 << LOG;}
	else if (t[key] > tempo) {return_value += 1 << LONG_TAP; return_value += 1 << LOG;}

	return return_value;
}

int CInput::getPressMode(PressMode press_mode)
{
	return 1 << press_mode;
}

bool CInput::long_tap(Key key) {return t[key] > tempo;}

bool CInput::isCMA() {return t[Ctrl] || t[Maj] || t[Alt];}

bool CInput::isZQSD() {return t[Z] || t[Q] || t[S] || t[D];}

CInput::type_advio CInput::key_from(std::vector<CInput::Key> key_list)
{
	type_advio key = {false, false, false, false, static_cast<CInput::Key>(LASTKEY)};

	for (int i=0; i < key_list.size(); i++)
	{
		if (key_list[i] == CInput::Ctrl)
			key.CTRL = true;
		else if (key_list[i] == CInput::Maj)
			key.MAJ = true;
		else if (key_list[i] == CInput::Alt) 
			key.ALT = true;
		else if (key_list[i] == CInput::Space) 
			key.SPACE = true;
		
		key.KEY = key_list[i];
	}

	return key;
}

int CInput::id_of(type_advio key_comb)
{
	return key_comb.CTRL + (key_comb.MAJ << 1) + (key_comb.ALT << 2) + (key_comb.ALT << 3) + (key_comb.KEY << 4) + (key_comb.press_mode << 4 + int(std::ceil(std::log2(float(LASTMOUSE)))));
}

//MAIN FONCTION
bool CInput::gerer()
{
	Key key_pressed[2] = {LASTKEY, LASTKEY};
	int i_kp = 0;

	if (APP->fenetre.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			return true;
		if (event.type == sf::Event::MouseWheelMoved)
		{
			if (event.mouseWheel.delta > 0) { t[MWAdd]++;  key_pressed[i_kp] = MWAdd; i_kp++;}
			else { t[MWAdd] = 0; }
			if (event.mouseWheel.delta < 0) { t[MWSub]++;  key_pressed[i_kp] = MWSub; i_kp++;}
			else { t[MWSub] = 0; }
			event.mouseWheel.delta = 0;
		}
		else
			{t[MWAdd] = 0; t[MWSub] = 0;}
	}
	else
		{t[MWAdd] = 0; t[MWSub] = 0;}

	if (!APP->fenetre.hasFocus())
		return false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return true; } //Quitter

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { t[MLeft]++; key_pressed[i_kp] = MLeft; i_kp++;}
	else { if (t[MLeft]) { t_double[MLeft] = tempo_d; } t[MLeft] = 0; t_double_start_frame[MLeft] = 0; }
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) { t[MRight]++; key_pressed[i_kp] = MRight; i_kp++;}
	else { if (t[MRight]) { t_double[MRight] = tempo_d; } t[MRight] = 0; t_double_start_frame[MRight] = 0; }
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { t[MMiddle]++; key_pressed[i_kp] = MMiddle; i_kp++;}
	else { if (t[MMiddle]) { t_double[MMiddle] = tempo_d; } t[MMiddle] = 0; t_double_start_frame[MMiddle] = 0; }
	
	for (int i=0; i < LASTKEY; i++)
		if (sf::Keyboard::isKeyPressed(io_to_sfml[i]))
		{
			t[i]++;
			if (static_cast<Key>(i) != Ctrl && static_cast<Key>(i) != Maj && static_cast<Key>(i) != Alt || key_pressed[i_kp] == LASTKEY)
			{
				key_pressed[i_kp] = static_cast<Key>(i); 
				i_kp++;
			}
		}
		else 
		{
			if (t[i])
				t_double[i] = tempo_d;
			t[i] = 0;
			t_double_start_frame[i] = 0;
		}

	pos_prec_m = pos_m;
	pos_m = sf::Mouse::getPosition(APP->fenetre);
	delta_m = pos_prec_m - pos_m;

	pos_prec = pos;
	pos = CFonction::pointed(pos_m);
	delta_p = pixel_prec - pixel;

	center_prec = center;
	center = pos;
	 
	pixel_prec = pixel;
	pixel = sf::Vector2i(floor(pos.x), floor(pos.y));

	key_combinaison[0] = {t[Ctrl], t[Maj], t[Alt], t[Space], key_pressed[0], getPressMode(key_pressed[0])};
	key_combinaison[1] = {t[Ctrl], t[Maj], t[Alt], t[Space], key_pressed[1], getPressMode(key_pressed[1])};

	for (int i = 0; i < LASTKEY; i++)
		if (t_double[i] > 0)
			t_double[i]--;
	for (int i = LASTKEY+1; i < LASTMOUSE; i++)
		if (t_double[i] > 0)
			t_double[i]--;

	return false;
}

//------------------------------------------------------//

void CInput::creer_retour()
{
	i_retour_click++;
	retour_click.push_back(ex_click);
}

void CInput::ctrl_z()
{
	i_retour_click--;
	ex_click = retour_click[i_retour_click];
}

void CInput::ctrl_y()
{
	i_retour_click++;
	ex_click = retour_click[i_retour_click];
}

void CInput::delete_retour()
{
	retour_click.erase(retour_click.begin() + i_retour_click + 1, retour_click.end());
}

void CInput::checkCenter(sf::Vector2f* ptr_vect)
{
	if (BROSSE->getSize().x % 2 == 0 && int(ptr_vect->x) != ptr_vect->x)
		ptr_vect->x = int(ptr_vect->x);
	else if (BROSSE->getSize().x % 2 != 0 && int(ptr_vect->x) == ptr_vect->x)
		ptr_vect->x += 0.5f;

	if (BROSSE->getSize().y % 2 == 0 && int(ptr_vect->y) != ptr_vect->y)
		ptr_vect->y = int(ptr_vect->y);
	else if (BROSSE->getSize().y % 2 != 0 && int(ptr_vect->y) == ptr_vect->y)
		ptr_vect->y += 0.5f;
}