#include "Source Files/Application/Tool/Tools/Gomme.h"

#include "Source Files/Application/IO/Input.h"
#include "Source Files/Fonction/Fonction.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/Selec/Selec.h"
#include <QtWidgets/QApplication>

CGomme::CGomme(void) {
	numero_outil = CTool::GOMME;
}

void CGomme::afficher() {
	BRUSH->afficher(center);
	if (IO->pressed(Qt::Key_Shift))
		displayLine();
}

void CGomme::use_line(sf::Vector2f pos_ini) {
	RES->getShader(CRes::usual)->setParameter("offset", SELEC->getPosition() - LAYER->getPosition());
	RES->getShader(CRes::usual)->setParameter("background", LAYER->getTexture());

	drawLine(pos_ini, center);
}

void CGomme::use() {
	center = IO->getCenter();
	sf::Vector2f center_prec = IO->getPreviousCenter();

	Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
	if (special & Qt::ShiftModifier)
		calculateLine();

	if (IO->pressed(Qt::LeftButton)) {
		if (special & Qt::ShiftModifier) {
			if (IO->again(Qt::LeftButton)) {
				RES->getShader(CRes::usual)->setParameter("mode", 0);
				use_line(IO->getPreviousCenterClick());
			}
		}
		else if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor1());
		else {
			RES->getShader(CRes::usual)->setParameter("mode", 0);
			use_line(center_prec);
		}
	}
	else if (IO->pressed(Qt::RightButton)) {
		if (special & Qt::ShiftModifier) {
			if (IO->again(Qt::RightButton)) {
				RES->getShader(CRes::usual)->setParameter("mode", 0.5f);
				use_line(IO->getPreviousCenterClick());
			}
		}
		else if (special & Qt::ControlModifier)
			setPointedColor(COLOR_CONTROLLER->getSColor2());
		else {
			RES->getShader(CRes::usual)->setParameter("mode", 0.5f);
			use_line(center_prec);
		}
	}
}
