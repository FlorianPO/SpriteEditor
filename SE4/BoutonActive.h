#pragma once
#include "Panneau.h"

class CBoutonActive : public CBouton
{
public:
	CBoutonActive(const sf::Texture* texture, sf::IntRect rect, sf::Vector2f pos, CArg arg = CArg());
	~CBoutonActive();

	bool gerer() override;
	inline void draw(sf::RenderTexture* render) override { render->draw(sprite); }
	bool update(bool forceTo = false, bool force_var = true) override;

	inline void setPredicatActive(std::function<int(fonction_type)>* p) { predicat2 = p; }

	int usePredicat2();

private:
	int etat;
	int ex_etat = -1;

	int etat2;
	int ex_etat2 = -1;

	std::function<int(fonction_type)>* predicat2 = NULL;
	sf::IntRect rect2;
	sf::Color color2 = sf::Color::White;
};