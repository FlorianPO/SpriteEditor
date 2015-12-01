#pragma once

#include "Panneau.h"
#include "stdafx.h"

class CBoutonDisplay : public CBouton
{
public:
	CBoutonDisplay(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos);
	~CBoutonDisplay(void);

	bool gerer() override;
	inline void draw(sf::RenderTexture* render) override { render->draw(sprite); }
};
