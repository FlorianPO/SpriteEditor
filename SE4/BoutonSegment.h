#pragma once

#include "Panneau.h"
#include "stdafx.h"

class CArg;
class CBoutonSegment : public CBouton
{
public:
	CBoutonSegment(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg = CArg());
	~CBoutonSegment();

	bool gerer() override;
	bool update(bool forceTo = false, bool force_var = true) override; 
	inline void draw(sf::RenderTexture* render) override { render->draw(sprite); }
	int getValeur();

	inline void setPredicatGroupe(std::function<int(fonction_type)>* p) { predicat_groupe = p; }
	bool usePredicatGroupe();

private:
	void increment(int incr);
	std::function<int(fonction_type)>* predicat_groupe = NULL;
	sf::Vector2i interval = sf::Vector2i(0, 255);
	int ex_arg = -1;

	sf::String string;
	sf::RenderTexture render;
};

