#include "Crayon.h"

#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/QtApp/SQT/SFMLView.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/UndoStack/UndoStack.h"

Crayon::Crayon() {
	numero_outil = nTol::CRAYON;
	RES->getShader(nRer::usual).setParameter("mode", 1);
}

void Crayon::display() {
	if (INPUT->pressed(Qt::Key_Shift)) {
		displayLine();
		if (SFML->QWidget::hasFocus())
			BRUSH_CONTROLLER->setDisplayPosition(line[1].position);
		BRUSH->display();
	}
	else {
		if (SFML->QWidget::hasFocus())
			BRUSH_CONTROLLER->setDisplayPosition(BRUSH->getPointedPosition());
		BRUSH->display();
	}
}

#define UPDATE(pos) UNDO->beginMacro(); BRUSH_CONTROLLER->setExPosition(pos); checkLayerUpdate(); UNDO->endMacro();
void Crayon::use() {
	if (INPUT->pressed(Qt::Key_Shift))
		calculateLine();
	
	if (INPUT->pressed(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::LeftButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor1());
				drawLine(line[0].position, line[1].position);
				UPDATE(line[1].position)
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor1(Fonction::getPointedColor());
		else if (hasSmoothLine()) {
			BRUSH->setColor(COLOR_CONTROLLER->getColor1());
			drawSmoothLine();
		}
	}
	else if (INPUT->released(Qt::LeftButton)) {
		if (!INPUT->pressed(Qt::Key_Shift) && !INPUT->pressed(Qt::Key_Control) && hasSmoothLine()) {
			BRUSH->setColor(COLOR_CONTROLLER->getColor1());
			drawSmoothLine();
			UPDATE(LAST(INPUT->getSmoothList()))
		}
	}

	if (INPUT->pressed(Qt::RightButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::RightButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor2());
				drawLine(line[0].position, line[1].position);
				UPDATE(line[1].position)
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor2(Fonction::getPointedColor());
		else if (hasSmoothLine()) {
			BRUSH->setColor(COLOR_CONTROLLER->getColor2());
			drawSmoothLine();
		}
	}
	else if (INPUT->released(Qt::RightButton)) {
		if (!INPUT->pressed(Qt::Key_Shift) && !INPUT->pressed(Qt::Key_Control) && hasSmoothLine()) {
			BRUSH->setColor(COLOR_CONTROLLER->getColor2());
			drawSmoothLine();
			UPDATE(LAST(INPUT->getSmoothList()))
		}
	}
}