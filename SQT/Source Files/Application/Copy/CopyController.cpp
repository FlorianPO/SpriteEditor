#include "CopyController.h"
#include "Source Files/Application/Copy/Copy.h"

CopyController* CopyController::_t;

void CopyController::new_copy(const sf::Image& image) {
	current_copy = new CCopy(image, last_pos_copy);
	
	_copyCreated(current_copy);
	QObject::connect(current_copy, SIGNAL(copyApplied), this, SLOT(_copyApplied));
	QObject::connect(current_copy, SIGNAL(copyTransformed), this, SLOT(_copyTransformed));

	copy_list.push_back(current_copy);
}

void CopyController::_copyCreated(CCopy* copy) {
	emit copyCreated(copy);
}

void CopyController::_copyApplied(CCopy* copy) {
	emit copyApplied(copy);
}

void CopyController::_copyTransformed(CCopy* copy) {
	emit copyTransformed(copy);
}