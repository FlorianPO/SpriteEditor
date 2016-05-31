#include "Source Files/Application/Tool/Tools/Aero.h"

#include "Source Files/Application/Res/Res.h"
#include "Source Files/Application/IO/Input.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Selec/Selec.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Color/ColorController.h"
#include <QtWidgets/QApplication>

CAero::CAero() {
	numero_outil = CTool::AERO;
	RES->getShader(CRes::usual)->setParameter("mode", 2);
}

void CAero::afficher() {
	BRUSH->afficher(center);
	if (IO->pressed(Qt::Key_Shift))
		displayLine();
}

void CAero::use_line(sf::Vector2f pos_ini) {
	RES->getShader(CRes::usual)->setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
	RES->getShader(CRes::usual)->setParameter("background", LAYER->getTexture());

	drawLine(pos_ini, center);
}

void CAero::use() {
	center = IO->getCenter();

	Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
	if (special & Qt::ShiftModifier)
		calculateLine();

	if (IO->pressed(Qt::LeftButton)) {
		if (special & Qt::ShiftModifier) {
			if (IO->again(Qt::LeftButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor1());
				use_line(IO->getPreviousCenterClick());
			}
		}
		else if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor1());
		else {
			BRUSH->setColor(COLOR_CONTROLLER->getColor1());
			use_line(IO->getPreviousCenter());
		}
	}
	else if (IO->pressed(Qt::RightButton)) {
		if (special & Qt::ShiftModifier) {
			if (IO->again(Qt::RightButton)) {
				BRUSH->setColor(COLOR_CONTROLLER->getColor2());
				use_line(IO->getPreviousCenterClick());
			}
		}
		else if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor2());
		else {
			BRUSH->setColor(COLOR_CONTROLLER->getColor2());
			use_line(IO->getPreviousCenter());
		}
	}
}
