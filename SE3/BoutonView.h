#pragma once

#include "Panneau.h"

class CBoutonView : public CBouton
{
public:
	CBoutonView(const sf::Texture* texture, sf::IntRect rect);
	~CBoutonView();

	void draw(sf::RenderTexture* render) override;
	bool update(bool forceTo = false, bool force_var = true) override;
	void changeTexture(const sf::Texture* texture);

private:
	int compteur = 0;
};

