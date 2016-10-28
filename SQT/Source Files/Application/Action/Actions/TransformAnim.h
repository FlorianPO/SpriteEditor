#pragma once

#include "stdenum.h"
#include "Source Files/Application/Action/Action.h"
class Animation;

class TransformAnim : public Action
{
	Q_OBJECT
// CONSTRUCTOR
public:
	TransformAnim(Animation& anim);
	~TransformAnim() {}

// METHODS
public:
	void use() override;
	void move();
	void grand();

// MEMBERS
private:
	Animation* anim;
	sf::Vector2f posf, posf2, posf3, pos_init;
};