#pragma once

#include "Panneau.h"
#include "stdafx.h"

class CBoutonSwitch : public CBouton
{
public:
	CBoutonSwitch(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg = CArg());
	~CBoutonSwitch(void);

	inline bool getEtat() { return etat; }

	bool gerer() override;
	bool update(bool forceTo = false, bool force_var = true) override;
	inline void draw(sf::RenderTexture* render) override { render->draw(sprite); }

private:
	sf::IntRect rect2;
	sf::Color color2 = sf::Color::White;
	int etat;
	int ex_etat = -1;
};

