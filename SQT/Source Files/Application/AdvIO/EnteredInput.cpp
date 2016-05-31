/*

#include "EnteredInput.h"
#include "Source Files/Application/Tool/Tool.h"
#include "Source Files/Retour/Retour.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Var/Var.h"
#include "SpriteAnim.h"

CEnteredInput* ADVIO;

CEnteredInput::CEnteredInput(void)
{
	
	add({CInput::A}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::CRAYON);}));
	add({Qt::Key_Z}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::GOMME);}));
	add({CInput::E}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::AERO);}));
	add({CInput::R}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::POT);}));
	add({Qt::Key_Q}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::RECTSELEC);}));
	add({Qt::Key_S}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::BAGUETTE);}));
	add({Qt::Key_D}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::SELECCOLOR);}));
	add({CInput::F}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::SNAP);}));
	add({CInput::W}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::MOVE);}));
	add({CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::GRAND);}));
	add({CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::ROTATION);}));
	add({CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {CTool::chooseOutil(CTool::FLIP);}));

	add({Qt::Key_Control, Qt::Key_Z}, CInput::LOG, new std::function<void(void)>([]() {RETOUR->ctrl_z();}));
	add({Qt::Key_Control, CInput::Y}, CInput::LOG, new std::function<void(void)>([]() {RETOUR->ctrl_y();}));
	add({Qt::Key_Control, CInput::C}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::copy();}));			
	add({Qt::Key_Control, CInput::V}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::paste();}));			
	add({Qt::Key_Control, CInput::X}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::copy(); SELEC->supr();}));

	//add({CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {APP->zoomer(0.5f, true);}));	
	//add({CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {APP->zoomer(2.0f, true);}));	
	add({Qt::Key_Shift, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->seuil, 1, sf::Vector2i(1, 255));}));	
	add({Qt::Key_Shift, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->seuil, -1, sf::Vector2i(1, 255));}));	
	add({Qt::Key_Control, Qt::Key_Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {BRUSH->changeBrosse(BRUSH->which_brosse + 1);}));	
	add({Qt::Key_Control, Qt::Key_Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {BRUSH->changeBrosse(BRUSH->which_brosse - 1);}));

	add({Qt::Key_Shift}, Qt::Key_DOUBLE_TAP, new std::function<void(void)>([]() {SELEC->delete_selec();}));	
	add({Qt::Key_Shift, Qt::Key_Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->opacity, 1, sf::Vector2i(1, 255));}));	
	add({Qt::Key_Shift, Qt::Key_Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {CFonction::increment(&VAR->opacity, -1, sf::Vector2i(1, 255));}));
	add({Qt::Key_Supr}, CInput::AGAIN, new std::function<void(void)>([]() {SELEC->supr();}));

	add({Qt::Key_Alt}, Qt::Key_DOUBLE_TAP, new std::function<void(void)>([]() {APP->init_camera();}));
	add({Qt::Key_Alt, Qt::Key_Z}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(0, -10 / APP->zoom);}));
	add({Qt::Key_Alt, Qt::Key_D}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(10 / APP->zoom, 0);}));
	add({Qt::Key_Alt, Qt::Key_S}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(0, 10 / APP->zoom);}));
	add({Qt::Key_Alt, Qt::Key_Q}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(-10 / APP->zoom, 0);}));

	add({Qt::Key_Alt, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]()
	{
		CFonction::increment(&BRUSH->size.x, 1, sf::Vector2i(1, 999));
		CFonction::increment(&BRUSH->size.y, 1, sf::Vector2i(1, 999));
	}));
	add({Qt::Key_Alt, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]()
	{
		CFonction::increment(&BRUSH->size.x, -1, sf::Vector2i(1, 999));
		CFonction::increment(&BRUSH->size.y, -1, sf::Vector2i(1, 999));
	}));

	add({CInput::Add}, CInput::LOG, new std::function<void(void)>([]() {APP->zoomer(0.5f, false);}));
	add({Qt::Key_Sub}, CInput::LOG, new std::function<void(void)>([]() {APP->zoomer(2.0f, false);}));
	add({Qt::Key_Control, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->zoomer(0.5f, true);}));
	add({Qt::Key_Control, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->zoomer(2.0f, true);}));

	add({CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->camera.move(0, -VAR->scroll_speed / APP->zoom);}));
	add({CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->camera.move(0, VAR->scroll_speed / APP->zoom);}));
	
	add({Qt::Key_Shift, CInput::MWAdd}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->camera.move(VAR->scroll_speed / APP->zoom, 0);}));
	add({Qt::Key_Shift, CInput::MWSub}, CInput::AGAIN, new std::function<void(void)>([]() {if (!CHud::onHud(SPRITE_ANIM)) APP->camera.move(-VAR->scroll_speed / APP->zoom, 0);}));

	add({CInput::MMiddle}, CInput::PRESSED, new std::function<void(void)>([]() {APP->camera.move(IO->getDeltaMouse().x / APP->zoom, IO->getDeltaMouse().y / APP->zoom);}));
	add({CInput::MMiddle}, Qt::Key_DOUBLE_TAP, new std::function<void(void)>([]() {APP->follow();}));
	
}

CEnteredInput::~CEnteredInput(void)
{
	//for (auto x : combinaison_map)
	//	delete x.second.fonction;
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
*/