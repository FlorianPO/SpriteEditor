#include "RectList.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Layer/Layer.h"

void RectList::use() {
	if (INPUT->again(Qt::LeftButton)) {
		sf::IntRect rect = findRect(INPUT->getPixel() - VECTOR2I(LAYER->getPosition()), LAYER->getImage());
		if (rect.width > 0) {
			layer = LAYER;
			findRectList(rect, LAYER->getImage());
		}	
	}
}

sf::IntRect RectList::findRect(const sf::Vector2i& pixel_pointed, const sf::Image& image) {
	sf::IntRect rect;
	sf::Vector2i p_tmp;
	bool bound_found;

	//LEFT
	bound_found = false;
	p_tmp = pixel_pointed;
	while (true)
		if (image.getPixel(ARG_VECTOR(p_tmp)) != sf::Color::Magenta) {
			rect.width++;
			p_tmp.x -= 1;
			if (p_tmp.x < 0)
				break;
		}
		else {
			bound_found = true;
			rect.left = p_tmp.x+1;
			break;
		}
		
	if (!bound_found)
		return sf::IntRect();

	//RIGHT
	bound_found = false;
	p_tmp = sf::Vector2i(pixel_pointed.x+1, pixel_pointed.y); 
	while (true)
		if (image.getPixel(ARG_VECTOR(p_tmp)) != sf::Color::Magenta) {
			rect.width++;
			p_tmp.x += 1;
			if (p_tmp.x > image.getSize().x-1)
				break;
		}
		else {
			bound_found = true;
			break;
		}

	if (!bound_found)
		return sf::IntRect();

	//UP
	bound_found = false;
	p_tmp = pixel_pointed;
	while (true)
		if (image.getPixel(ARG_VECTOR(p_tmp)) != sf::Color::Magenta) {
			rect.height++;
			p_tmp.y -= 1;
			if (p_tmp.y < 0)
				break;
		}
		else {
			bound_found = true;
			rect.top = p_tmp.y+1;
			break;
		}
		
	if (!bound_found)
		return sf::IntRect();

	//DOWN
	bound_found = false;
	p_tmp = sf::Vector2i(pixel_pointed.x, pixel_pointed.y+1);
	while (true)
		if (image.getPixel(ARG_VECTOR(p_tmp)) != sf::Color::Magenta) {
			rect.height++;
			p_tmp.y += 1;
			if (p_tmp.y > image.getSize().y-1)
				break;
		}
		else {
			bound_found = true;
			break;
		}

	if (!bound_found)
		return sf::IntRect();

	return rect;
}

void RectList::findRectList(sf::IntRect rect, const sf::Image& image) {
	sf::Vector2i p_tmp;
	rect_list = std::vector<sf::IntRect>({ rect });

	while (rect.left + rect.width + 1 < image.getSize().x)
		if (image.getPixel(rect.left + rect.width + 1, rect.top - 1) == sf::Color::Magenta) {
			rect.left = rect.left + rect.width + 1;
			rect_list.push_back(rect);
		}
		else
			break;

	emit ended();
}