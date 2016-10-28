#include "AnimationController.h"

#include "Animation.h"
#include "AnimationUndo.h"
#include "Source Files/Application/Camera/CameraController.h"

AnimationController* AnimationController::_t;

AnimationController::AnimationController() {
	QObject::connect(CAMERA, SIGNAL(moved(sf::Vector2f)), this, SLOT(moved(sf::Vector2f)));
	QObject::connect(CAMERA, SIGNAL(zoomed(float)), this, SLOT(zoomed(float)));
}

AnimationController::~AnimationController() {
	FOR_I (anim_list.size())
		delete anim_list[i];
}

Animation& AnimationController::createAnimation() {
	Animation* anim = new Animation(QString::fromStdString("Animation" + std::to_string(anim_list.size())));
	undo_stack.push(*new AnimationCreated(anim));
	anim_list.push_back(*anim);

	_createAnimation(*anim);
	return *anim;
}

void AnimationController::_createAnimation(Animation& anim) {
	anim.undrop();
	anim_list.selectOne(anim);
}

void AnimationController::dropSelected() {
	undo_stack.beginMacro();
	FOR_I (anim_list.size())
		if (anim_list.at(i)->isSelected()) {
			_dropAnimation(*anim_list.at<Animation*>(i));
			undo_stack.push(*new AnimationDropped(anim_list.at(i)));
		}
			
	undo_stack.endMacro();
}

void AnimationController::_dropAnimation(Animation& anim) {
	anim.drop();

	checkSelection(anim);
}

void AnimationController::display() {
	FOR_I (anim_list.size())
		anim_list.at<Animation*>(i)->gerer();
	FOR_I (anim_list.size())
		anim_list.at<Animation*>(i)->display();
}

void AnimationController::checkSelection(const Animation& anim) {
	bool at_least_one_selected = false;
	FOR_I (anim_list.size())
		if (anim_list[i]->isSelected()) {
			at_least_one_selected = true;
			break;
		}
	
	if (!at_least_one_selected) {
		FOR_I (anim_list.size())
			if (anim_list[i] == &anim) {
				bool found=false;
				FOR_J_INV (i) {
					if (!anim_list[j]->isDropped()) {
						anim_list[j]->select();
						found = true;
						break;
					}
				}
				if (!found)
					for (int j=i+1; j < anim_list.size(); j++)
						if (!anim_list[j]->isDropped()) {
							anim_list[j]->select();
							break;
						}
			}
	}
}

void AnimationController::moved(const sf::Vector2f& new_position) {
	FOR_I (anim_list.size())
		anim_list.at<Animation*>(i)->setPosition(CAMERA->getPosition(nStd::DOWN_RIGHT));
}

void AnimationController::zoomed(float new_factor) {
	FOR_I (anim_list.size())
		anim_list.at<Animation*>(i)->setScale(1.f/new_factor);
}