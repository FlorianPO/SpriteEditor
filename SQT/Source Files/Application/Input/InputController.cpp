#include "InputController.h"

#include "ShortcutController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Camera/CameraController.h"

using namespace nInt;

InputController* InputController::_t;

InputController::InputController() {
	std::vector<qkey> keys_used = {
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
		WHEEL_UP,
		WHEEL_DOWN
	};
	
	FOR_I (keys_used.size())
		hash[keys_used[i]] = Key_struct();
}

void InputController::reset() {
	QHashIterator<nInt::qkey, Key_struct> iterator(hash);
	while (iterator.hasNext()) {
		hash[iterator.key()] = Key_struct();
		iterator.next();
	}
}

void InputController::setMousePosition(sf::Vector2i screened, bool dump_ex, bool set_pointer) {
	if (set_pointer)
		sf::Mouse::setPosition(screened, APP->getWindow());

	if (!dump_ex) {
		ex_screen = screen;
		screen = screened;
		delta_screen = screen - ex_screen;

		ex_pos = pos;
		pos = screenToPos(screen);
		delta_pos = pos - ex_pos;

		ex_pixel = pixel;
		pixel = sf::Vector2i(floor(pos.x), floor(pos.y));
		delta_pixel = pixel - ex_pixel;
	}
	else {
		screen = screened;
		ex_screen = screen;
		delta_screen = sf::Vector2i();

		pos = screenToPos(screen);
		ex_pos = pos;
		delta_pos = sf::Vector2f();

		pixel = sf::Vector2i(floor(pos.x), floor(pos.y));
		ex_pixel = pixel;
		delta_pixel = sf::Vector2i();
	}

	emit posPixelXChanged(pixel.x);
	emit posPixelYChanged(pixel.y);
}

sf::Vector2f InputController::screenToPos(sf::Vector2i screen_position) {
	sf::Vector2f vector;
	vector.x = screen_position.x / CAMERA->getZoom();
	vector.y = screen_position.y / CAMERA->getZoom();
	vector += CAMERA->getPosition(nStd::UP_LEFT);

	return vector;
}

sf::Vector2i InputController::posToScreen(sf::Vector2f position) {
	sf::Vector2i vector;
	position -= CAMERA->getPosition(nStd::UP_LEFT);
	vector.x = position.x * CAMERA->getZoom();
	vector.y = position.y * CAMERA->getZoom();

	return vector;
}

bool InputController::isPressMode(nInt::qkey code, nInt::PressMode press_mode) {
	switch (press_mode) {
		case PRESSED:		return pressed(code);
		case RELEASED:		return released(code);
		case AGAIN:			return again(code);
		case LONG_TAP:		return long_tap(code);
		case DOUBLE_TAP:	return double_tap(code);
		case LOG:			return log(code);
		default:
			return false;
	}
}

bool InputController::isSpecial() {
	return pressed(Qt::Key_Control)
		|| pressed(Qt::Key_Shift)
		|| pressed(Qt::Key_Alt);
}

bool InputController::isZQSD() {
	return pressed(Qt::Key_Z)
		|| pressed(Qt::Key_Q)
		|| pressed(Qt::Key_S)
		|| pressed(Qt::Key_D);
}

nInt::press_code InputController::getPressCode(nInt::qkey code) {
	Key_struct key = hash[code];

	int return_value = 0;
	if (_pressed(key)) 
		return_value += PRESSED;
	else {
		if (_released(key))
			return_value += RELEASED;
		else
			return_value += NONE;
		return return_value;
	}
		
	if (_again(key)) {
		return_value += AGAIN; 
		return_value += LOG;

		if (_double_tap(key))
			return_value += DOUBLE_TAP;
	}
	else if (_long_tap(key)) {
		return_value += LONG_TAP; 
  		return_value += LOG;
	}

	return return_value;
}

bool InputController::gerer() {
	current_frame++;

	setMousePosition(sf::Mouse::getPosition(APP->getWindow()), false, false);

	if (clear_smoothed) {
		pos_smoothed.clear();
		clear_smoothed = false;
	}
	else if (pos_smoothed.size() > 0)
		pos_smoothed = { LAST(pos_smoothed) };

	if (again(Qt::LeftButton) || again(Qt::RightButton)) {
		screen_click = screen;
		pos_click = pos;
		pixel_click = pixel;

		pos_smoothed = { pos, pos };
	}
	
	if (pressed(Qt::LeftButton) || pressed(Qt::RightButton))
		lsmooth.addPoint(pos);
	if (released(Qt::LeftButton) || released(Qt::RightButton)) {
		lsmooth.addPoint(pos);
		lsmooth.endPoint();
		clear_smoothed = true;
	}

	auto list = lsmooth.getAvailable();
	FOR_I (list.size())
		pos_smoothed.push_back(list[i]);

	bindZQSD();
	
	if (SHORTCUT_CONTROLLER->coreShortcutEnabled() && key_pressed.size() > 0) {
		qkey modifier=0;
		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ControlModifier)
			modifier += Qt::CTRL;
		if (special & Qt::ShiftModifier)
			modifier += Qt::SHIFT;
		if (special & Qt::AltModifier)
			modifier += Qt::ALT;

		FOR_I (key_pressed.size()) {
			if (key_pressed[i] < 0x01000020 || key_pressed[i] > 0x01000023) {
				emit combinaisonPressed(&nInt::keyCombinaison(key_pressed[i]+modifier, getPressCode(key_pressed[i])));
				if (key_pressed[i] == WHEEL_UP || key_pressed[i] == WHEEL_DOWN) { // WHEEL_UP WHEEL_DOWN
					key_pressed.erase(key_pressed.begin() + i);
					i--;
				}
			}
			else // Qt::Key_Control Qt::Key_Shift Qt::Key_Alt 
				emit combinaisonPressed(&nInt::keyCombinaison(key_pressed[i], getPressCode(key_pressed[i])));
		}
	}

	std::sort(key_to_release.begin(), key_to_release.end(), std::greater<int>()); // 6 4 2 0
	FOR_I (key_to_release.size())
		key_pressed.erase(key_pressed.begin() + key_to_release[i]);
	key_to_release.clear();
	
	return false;
}

void InputController::registerPressed(nInt::qkey code) {
	Key_struct& key = hash[code];
	key.ex_frame_pressed = key.frame_pressed;
	key.frame_pressed = this->current_frame;
	
	key_pressed.push_back(code);
}

void InputController::registerReleased(nInt::qkey code) {
	Key_struct& key = hash[code];
	key.ex_frame_released = key.frame_released;
	key.frame_released = this->current_frame;

	std::vector<qkey>::iterator it = std::find(key_pressed.begin(), key_pressed.end(), code);
	if (it != key_pressed.end())
		key_to_release.push_back(it - key_pressed.begin());
}

void InputController::registerWheelUp() {
	Key_struct& key = hash[WHEEL_UP];
	key.frame_released = this->current_frame-1;
	key.frame_pressed = this->current_frame;

	key_pressed.push_back(WHEEL_UP);
}

void InputController::registerWheelDown() {
	Key_struct& key = hash[WHEEL_DOWN];
	key.frame_released = this->current_frame-1;
	key.frame_pressed = this->current_frame;

	key_pressed.push_back(WHEEL_DOWN);
}

void InputController::bindZQSD() {
	std::vector<Key_struct*> keys;
	FOR_I (key_pressed.size()) {
		switch (key_pressed[i]) {
			case Qt::Key_Z: keys.push_back(&hash[Qt::Key_Z]); break;
			case Qt::Key_Q: keys.push_back(&hash[Qt::Key_Q]); break;
			case Qt::Key_S: keys.push_back(&hash[Qt::Key_S]); break;
			case Qt::Key_D: keys.push_back(&hash[Qt::Key_D]); break;
			default: break;
		}
	}

	if (keys.size() >= 2) {
		bool log = false;
		FOR_I (keys.size()) {
			Key_struct* key = keys[i];
			if (FUNC_LONG((*key))) {
				log = true;
				break;
			}
		}
		if (log)
			FOR_I (keys.size()) {
				Key_struct* key = keys[i];
				if (!FUNC_LONG((*key))) {
					key->frame_pressed = current_frame - tempo - 1;
					key->frame_released = key->frame_pressed - 1;
					key->ex_frame_pressed = key->frame_pressed - (tempo*2);
					key->frame_released = key->ex_frame_pressed - 1;
				}
			}
	}
}