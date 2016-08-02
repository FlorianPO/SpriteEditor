#include "Aero.h"

#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include <Source Files/Fonction/Fonction.h>

Aero::Aero() {
	numero_outil = nTol::AERO;
	RES->getShader(nRer::usual).setParameter("mode", 2);
}

void Aero::display() {
	if (INPUT->pressed(Qt::Key_Shift)) {
		displayLine();
		if (SFML->QWidget::hasFocus())
			BRUSH->setDisplayPosition(line[1].position);
		BRUSH->display();
	}
	else {
		if (SFML->QWidget::hasFocus())
			BRUSH->setDisplayPosition(BRUSH->getPointedPosition());
		BRUSH->display();
	}
}

void Aero::use() {
	if (INPUT->pressed(Qt::Key_Shift))
		calculateLine();

	if (INPUT->pressed(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::LeftButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor1());
				drawLine(line[0].position, line[1].position);
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor1(Fonction::getPointedColor());
		else {
			BRUSH->setColor(COLOR_CONTROLLER->getColor1());
			drawLine(BRUSH->getExPointedPosition(), BRUSH->getPointedPosition());
		}
	}
	else if (INPUT->released(Qt::LeftButton))
		checkLayerUpdate();

	if (INPUT->pressed(Qt::RightButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::RightButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor2());
				drawLine(line[0].position, line[1].position);
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor2(Fonction::getPointedColor());
		else {
			BRUSH->setColor(COLOR_CONTROLLER->getColor2());
			drawLine(BRUSH->getExPointedPosition(), BRUSH->getPointedPosition());
		}
	}
	else if (INPUT->released(Qt::RightButton))
		checkLayerUpdate();
}
