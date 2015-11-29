#include "EnteredInput.h"
#include "Outil.h"
#include "Retour.h"
#include "Fonction.h"
#include "Selec.h"
#include "App.h"
#include "Var.h"

CEnteredInput* ADVIO;

CEnteredInput::CEnteredInput(void)
{
	add({CInput::A}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::CRAYON);}));
	add({CInput::Z}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::GOMME);}));
	add({CInput::E}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::AERO);}));
	add({CInput::R}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::POT);}));
	add({CInput::Q}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::RECTSELEC);}));
	add({CInput::S}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::BAGUETTE);}));
	add({CInput::D}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::SELECCOLOR);}));
	add({CInput::F}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::SNAP);}));
	add({CInput::W}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::MOVE);}));
	add({CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::GRAND);}));
	add({CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::ROTATION);}));
	add({CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {COutil::chooseOutil(COutil::FLIP);}));

	add({CInput::Ctrl, CInput::Z}, CInput::LOG, new std::function<void(void)>([]() {RETOUR->ctrl_z();}));
	add({CInput::Ctrl, CInput::Y}, CInput::LOG, new std::function<void(void)>([]() {RETOUR->ctrl_y();}));
	add({CInput::Ctrl, CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::copy();}));			
	add({CInput::Ctrl, CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::paste();}));			
	add({CInput::Ctrl, CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::copy(); SELEC->supr();}));

	add({CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {APP->zoomer(0.5f, true);}));	
	add({CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {APP->zoomer(2.0f, true);}));	
	add({CInput::Maj, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->seuil, 1, sf::Vector2i(1, 255));}));	
	add({CInput::Maj, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->seuil, -1, sf::Vector2i(1, 255));}));	
	add({CInput::Ctrl, CInput::Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {BROSSE->changeBrosse(BROSSE->which_brosse + 1);}));	
	add({CInput::Ctrl, CInput::Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {BROSSE->changeBrosse(BROSSE->which_brosse - 1);}));

	add({CInput::Maj}, CInput::DOUBLE_TAP, new std::function<void(void)>([]() {SELEC->delete_selec();}));	
	add({CInput::Maj, CInput::Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->opacity, 1, sf::Vector2i(1, 255));}));	
	add({CInput::Maj, CInput::Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->opacity, -1, sf::Vector2i(1, 255));}));
	add({CInput::Supr}, CInput::AGAIN, new std::function<void(void)>([]() {SELEC->supr();}));

	add({CInput::Alt}, CInput::DOUBLE_TAP, new std::function<void(void)>([]() {APP->init_camera();}));
	add({CInput::Alt, CInput::Z}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(0, -10 / APP->zoom);}));
	add({CInput::Alt, CInput::D}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(10 / APP->zoom, 0);}));
	add({CInput::Alt, CInput::S}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(0, 10 / APP->zoom);}));
	add({CInput::Alt, CInput::Q}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(-10 / APP->zoom, 0);}));

	add({CInput::Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]()
	{
		CFonction::increment(&BROSSE->size.x, 1, sf::Vector2i(1, 999));
		CFonction::increment(&BROSSE->size.y, 1, sf::Vector2i(1, 999));
	}));
	add({CInput::Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]()
	{
		CFonction::increment(&BROSSE->size.x, -1, sf::Vector2i(1, 999));
		CFonction::increment(&BROSSE->size.y, -1, sf::Vector2i(1, 999));
	}));

	add({CInput::Add}, CInput::LOG, new std::function<void(void)>([]() {APP->zoomer(0.5f, false);}));
	add({CInput::Sub}, CInput::LOG, new std::function<void(void)>([]() {APP->zoomer(2.0f, false);}));
	add({CInput::Ctrl, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud()) APP->zoomer(0.5f, false);}));
	add({CInput::Ctrl, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud()) APP->zoomer(2.0f, false);}));

	add({CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud()) APP->camera.move(0, -VAR->scroll_speed / APP->zoom);}));
	add({CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud())APP->camera.move(0, VAR->scroll_speed / APP->zoom);}));
	
	add({CInput::MMiddle}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(IO->getDeltaMouse().x / APP->zoom, IO->getDeltaMouse().y / APP->zoom);}));
	add({CInput::MMiddle}, CInput::DOUBLE_TAP, new std::function<void(void)>([]() {APP->follow();}));
}

CEnteredInput::~CEnteredInput(void)
{
		for (auto x : combinaison_map)
			delete x.second.fonction;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CEnteredInput::add(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void(void)>* fonction, void* user)
{
	CInput::type_advio key = CInput::key_from(key_list);
	key.press_mode = CInput::getPressMode(press_mode);
	combinaison_map[CInput::id_of(key)] = type_functionnal_advio{key, fonction, user};
}

void CEnteredInput::replaceDefinitively(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void()>* fonction, void* user)
{
	CInput::type_advio key = CInput::key_from(key_list);
	key.press_mode = CInput::getPressMode(press_mode);

	auto it = combinaison_map.find(CInput::id_of(key));
	if (it != combinaison_map.end())
		remove(key_list, press_mode);

	combinaison_map[CInput::id_of(key)] = type_functionnal_advio{key, fonction, user};
}

void CEnteredInput::replace(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void()>* fonction, void* user)
{
	CInput::type_advio key = CInput::key_from(key_list);
	key.press_mode = CInput::getPressMode(press_mode);

	auto it = combinaison_map.find(CInput::id_of(key));
	if (it != combinaison_map.end())
	{
		replacement_map[CInput::id_of(key)] = type_replace_advio {(*it).second, user};
		combinaison_map.erase(it);
	}
	combinaison_map[CInput::id_of(key)] = type_functionnal_advio{key, fonction, user};
}

void CEnteredInput::cancelReplacement(std::vector<CInput::Key> key_list, CInput::PressMode press_mode)
{
	CInput::type_advio key = CInput::key_from(key_list);
	key.press_mode = CInput::getPressMode(press_mode);

	auto it = replacement_map.find(CInput::id_of(key));
	if (it != replacement_map.end())
	{
		remove(key_list, press_mode);
		combinaison_map[CInput::id_of(key)] = type_functionnal_advio((*it).second.advio);
		replacement_map.erase(CInput::id_of(key));
	}
	else
		combinaison_map.erase(CInput::id_of(key));
}

void CEnteredInput::remove(void* user)
{
	auto it = combinaison_map.begin();
	for (; it != combinaison_map.end(); it++)
		if ((*it).second.user == user)
			combinaison_map.erase(CInput::id_of((*it).second.advio));
	
	auto it2 = replacement_map.begin();
	for (; it2 != replacement_map.end(); it2++)
		if ((*it2).second.new_user == user)
		{
			type_functionnal_advio tfa = (*it2).second.advio;

			combinaison_map.erase(CInput::id_of(tfa.advio));
			combinaison_map[CInput::id_of(tfa.advio)] = tfa;
			replacement_map.erase(CInput::id_of(tfa.advio));
		}	
}

void CEnteredInput::remove(std::vector<CInput::Key> key_list, CInput::PressMode press_mode)
{
	CInput::type_advio key = CInput::key_from(key_list);
	key.press_mode = CInput::getPressMode(press_mode);
	combinaison_map.erase(CInput::id_of(key));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CEnteredInput::gerer()
{
	auto it = combinaison_map.find(CInput::id_of(IO->getCombinaison()[0]));
	if (it != combinaison_map.end())
		(*(*it).second.fonction)();

	it = combinaison_map.find(CInput::id_of(IO->getCombinaison()[1]));
	if (it != combinaison_map.end())
		(*(*it).second.fonction)();
}