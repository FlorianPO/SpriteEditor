#include "BoutonView.h"
#include "Res.h"


CBoutonView::CBoutonView(const sf::Texture* texture, sf::IntRect rect) : CBouton(texture, sf::IntRect(), sf::Vector2f(-1, -1))
{
	this->rect = rect;
}

CBoutonView::~CBoutonView()
{
}

bool CBoutonView::update(bool forceTo, bool force_var)
{
	compteur++;
	if (compteur >= 30 || init)
	{
		init = false;
		float min = std::max(float(rect.width) / sprite.getTextureRect().width, float(rect.height) / sprite.getTextureRect().height);
		sprite.setScale(min, min);
		if (sprite.getGlobalBounds().width > rect.width || sprite.getGlobalBounds().height > rect.height)
		{
			min = std::max(float(rect.width - 1) / sprite.getTextureRect().width, float(rect.height - 1) / sprite.getTextureRect().height);
			sprite.setScale(min, min);
		}

		compteur = 0;
		return true;
	}

	return false;
}

void CBoutonView::draw(sf::RenderTexture* render)
{
	sf::RenderTexture render_fond;
	render_fond.create(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	render_fond.clear();
	sf::Sprite fond = RES->getSprite(CRes::SPRITE::alpha_gimp);
	fond.scale(4, 4);
	render_fond.draw(fond);
	render_fond.draw(sprite);
	render_fond.display();

	sf::Sprite spr(render_fond.getTexture());
	spr.setPosition(rect.left, rect.top);
	render->draw(spr);
}

void CBoutonView::changeTexture(const sf::Texture* texture)
{
	sprite.setTexture(*texture, true);
}