#include "Source Files/Application/Layer/Layer.h"

#include "Source Files/Application/Layer/LayerController.h"
/*
void CLayer::creer_retour(sf::Image* image, type_retour t)
{
	i_retour_type++;
	retour_type.push_back(t);

	if (t == ACT)
	{
		i_retour_image++;
		retour_image.push_back(*image);
	}
	else if (t == DEL)
	{
		dead = true;
		LAYER_CONTROLLER->selectLayer();
	}
	else if (t == MOV || t == CRE)
	{
		i_retour_pos++;
		retour_pos.push_back(sprite.getPosition());
	}
}

void CLayer::ctrl_z()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type--;
	type_retour t = retour_type[i_retour_type];


	if (t == CRE) // c <- a
	{
		dead = true;
		LAYER_CONTROLLER->selectLayer();
	}
	else if (ex_t == DEL) // a <- d
		dead = false;
	else if (ex_t == ACT) // a <- a
	{
		i_retour_image--;
		sf::Texture texture; texture.loadFromImage(retour_image[i_retour_image]);
		update(&texture);
	}
	else if (ex_t == MOV) // m <- m
	{
		i_retour_pos--;
		sprite.setPosition(retour_pos[i_retour_pos]);
	}
}

void CLayer::ctrl_y()
{
	type_retour ex_t = retour_type[i_retour_type];
	i_retour_type++;
	type_retour t = retour_type[i_retour_type];

	if (ex_t == CRE) // c -> a
		dead = false;
	else if (t == DEL) // a -> d
	{
		dead = true;
		LAYER_CONTROLLER->selectLayer();
	}
	else if (t == ACT) // a -> a
	{
		i_retour_image++;
		sf::Texture texture; texture.loadFromImage(retour_image[i_retour_image]);
		update(&texture);
	}
	else if (t == MOV) // m -> m
	{
		i_retour_pos++;
		sprite.setPosition(retour_pos[i_retour_pos]);
	}
}

void CLayer::delete_retour()
{
	retour_type.erase(retour_type.begin() + i_retour_type + 1, retour_type.end());
	retour_image.erase(retour_image.begin() + i_retour_image + 1, retour_image.end());
	retour_pos.erase(retour_pos.begin() + i_retour_pos + 1, retour_pos.end());
}
*/