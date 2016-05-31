/*

#pragma once

#define ADVIO CEnteredInput::_t
#include "Source Files/Application/IO/Input.h"


class CEnteredInput
{
public:
	static CEnteredInput* _t;
public:
	CEnteredInput(void);
	~CEnteredInput(void);

	struct type_functionnal_advio
	{
		CInput::type_advio advio;
		std::function<void(void)>* fonction;
		void* user;
	};

	struct type_replace_advio
	{
		type_functionnal_advio advio;
		void* new_user;
	};

	//void add(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void(void)>* fonction, void* user = NULL);
	//void replaceDefinitively(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void(void)>* fonction, void* user = NULL);
	//void replace(std::vector<CInput::Key> key_list, CInput::PressMode press_mode, std::function<void(void)>* fonction, void* user = NULL);
	//void cancelReplacement(std::vector<CInput::Key> key_list, CInput::PressMode press_mode);

	//void remove(void* user);
	//void remove(std::vector<CInput::Key> key_list, CInput::PressMode press_mode);

	void gerer(); //Test keys combinasions

private:
	//std::unordered_map<int, type_functionnal_advio, HashFn, EqualFn> combinaison_map;
	//std::unordered_map<int, type_replace_advio, HashFn, EqualFn> replacement_map;
};

*/
