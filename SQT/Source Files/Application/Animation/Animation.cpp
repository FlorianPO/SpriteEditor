#include "Animation.h"

#include "Source Files/Application/Camera/CameraController.h"
#include "Source Files/Application/App.h"
#include "AnimationRect/AnimationRectUndo.h"
#include "AnimationRect/AnimationRect.h"
#include "AnimationController.h"

Animation::Animation(const QString name) {
	this->name = name;	
}

void Animation::gerer() {
	if (!b_dropped && visible && anim_rect_list.size() > 0) {
		if (cpt >= anim_rect_list.at<AnimationRect*>(i_anim)->getFrame() + 1) {
			cpt = 0;

			i_anim = (i_anim+1) % anim_rect_list.size();
			int indice = i_anim;
			bool no_visible = false;
			while (!anim_rect_list.at<AnimationRect*>(i_anim)->isVisible() || anim_rect_list.at<AnimationRect*>(i_anim)->isDropped()) {
				i_anim = (i_anim+1) % anim_rect_list.size();
				if (i_anim == indice) {
					no_visible = true;
					break;
				}
			}
			
			if (!no_visible) 
				sprite.setTextureRect(anim_rect_list.at<AnimationRect*>(i_anim)->getRect());	
			else
				sprite.setTextureRect(sf::IntRect());
		}
		else
			cpt++;
	}
}

void Animation::display() {
	if (!b_dropped && visible)
		APP->getWindow().draw(sprite);
}

void Animation::hide() {
	if (visible) {
		visible = false;
		emit animationUnvisible();	
	}
}

void Animation::show() {
	if (!visible) {
		selectFistAnimation();
		visible = true;
		emit animationVisible();
	}
}

void Animation::selectFistAnimation() {
	cpt = 0;
	FOR_I (anim_rect_list.size())
		if (anim_rect_list.at<AnimationRect*>(i)->isVisible()) {
			i_anim = i;
			sprite.setTextureRect(anim_rect_list.at<AnimationRect*>(i_anim)->getRect());
			break;
		}
}

void Animation::createAnimationRect(const sf::IntRect& rect) {
	AnimationRect* anim_rect = new AnimationRect(rect, 7, ANIM_STACK);

	QObject::connect(anim_rect, &SignalListObject::dropped, [=](){ emit animationChanged(); });
	QObject::connect(anim_rect, &SignalListObject::undropped, [=](){ emit animationChanged(); });
	QObject::connect(anim_rect, &AnimationRect::rectChanged, [=](){ emit animationChanged(); });
	QObject::connect(anim_rect, &AnimationRect::frameChanged, [=](){ emit animationChanged(); });

	anim_rect_list.push_back(*anim_rect);

	if (!origin_resolved) {
		origin_resolved = true;
		sprite.setTextureRect(rect);
		sprite.setOrigin(SIZE_RECT(rect));
		setPosition(CAMERA->getPosition(nStd::DOWN_RIGHT));
		//setScale(CAMERA->getPosition(nStd::DOWN_RIGHT));
	}
}

void Animation::dropSelected() {
	ANIM_STACK.beginMacro();
	FOR_I (anim_rect_list.size())
		if (anim_rect_list.at(i)->isSelected()) {
			anim_rect_list.at(i)->drop();
			ANIM_STACK.push(*new AnimationRectDropped(anim_rect_list.at(i)));
		}
			
	ANIM_STACK.endMacro();
}

void Animation::setLayer(const Layer& layer) {
	sprite.setTexture(layer.getTexture(), true);
	emit layerChanged(layer);
}

void Animation::setName(const QString& name) {
	this->name = name;
	emit nameChanged(name);
}

void Animation::setPosition(const sf::Vector2f& position) {
	this->position = position;
	sprite.setPosition(position + offset_position);
}

void Animation::setOffsetPosition(const sf::Vector2f& position) {
	offset_position = position - this->position;
	setPosition(this->position);
}

void Animation::setOffsetScale(float scale) {
	DEBUGN("set_offset : " << scale)
	offset_scale = scale;
	setScale(this->scale);
}

void Animation::setScale(float factor) {
	scale = factor;
	sprite.setScale(factor * offset_scale, factor * offset_scale);

	DEBUGN("offset : " << scale)
	DEBUGN("scale : " << sprite.getScale().x)
}