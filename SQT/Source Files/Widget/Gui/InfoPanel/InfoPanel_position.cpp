#include "InfoPanel_position.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"

InfoPanel_position::InfoPanel_position(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui_pos.setupUi(this);
	hide();

	// POSX
	PosX = new ViewLabel(this, ViewLabel::WIDE); PosX->move(QPoint(0, 24)); PosX->show(); 
	QObject::connect(INPUT, SIGNAL(posPixelXChanged(int)), PosX, SLOT(changeValue(int)));
	// POSY
	PosY = new ViewLabel(this, ViewLabel::WIDE); PosY->move(QPoint(64, 24)); PosY->show(); 
	QObject::connect(INPUT, SIGNAL(posPixelYChanged(int)), PosY, SLOT(changeValue(int)));
}