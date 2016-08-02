#include "Gomme.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Brush/Brush.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include <Source Files/Fonction/Fonction.h>

Gomme::Gomme(void) {
	numero_outil = nTol::GOMME;
}

void Gomme::display() {
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

void Gomme::use() {
	if (INPUT->pressed(Qt::Key_Shift))
		calculateLine();

	if (INPUT->pressed(Qt::LeftButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::LeftButton)) {
				RES->getShader(nRer::usual).setParameter("mode", 0);
				drawLine(line[0].position, line[1].position);
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor1(Fonction::getPointedColor());
		else {
			RES->getShader(nRer::usual).setParameter("mode", 0);
			drawLine(BRUSH->getExPointedPosition(), BRUSH->getPointedPosition());
		}
	}
	else if (INPUT->released(Qt::LeftButton))
		checkLayerUpdate();

	if (INPUT->pressed(Qt::RightButton)) {
		if (INPUT->pressed(Qt::Key_Shift)) {
			if (INPUT->again(Qt::RightButton)) {
				RES->getShader(nRer::usual).setParameter("mode", 0.5f);
				drawLine(line[0].position, line[1].position);
			}
		}
		else if (INPUT->pressed(Qt::Key_Control))
			COLOR_CONTROLLER->setColor2(Fonction::getPointedColor());
		else {
			RES->getShader(nRer::usual).setParameter("mode", 0.5f);
			drawLine(BRUSH->getExPointedPosition(), BRUSH->getPointedPosition());
		}
	}
	else if (INPUT->released(Qt::RightButton))
		checkLayerUpdate();
}
