#include "Source Files/Widget/Gui/InfoPanel/InfoPanel.h"

#include "Source Files/Application/IO/Input.h"
#include "Source Files/Application/Selec/Selec.h"

InfoPanel::InfoPanel(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui.setupUi(this);
	show();

	// POSX
	PosX = new ViewLabel(this, ViewLabel::WIDE); PosX->move(QPoint(0, 24)); PosX->show(); 
	QObject::connect(IO, SIGNAL(posPixelXChanged(int)), PosX, SLOT(changeValue(int)));
	// POSY
	PosY = new ViewLabel(this, ViewLabel::WIDE); PosY->move(QPoint(64, 24)); PosY->show(); 
	QObject::connect(IO, SIGNAL(posPixelYChanged(int)), PosY, SLOT(changeValue(int)));

	// SIZEX
	SizeX = new ViewLabel(this, ViewLabel::WIDE); SizeX->move(QPoint(0, 64)); SizeX->show(); 
	QObject::connect(SELEC, SIGNAL(cadreXChanged(int)), SizeX, SLOT(changeValue(int)));
	// SIZEY
	SizeY = new ViewLabel(this, ViewLabel::WIDE); SizeY->move(QPoint(64, 64)); SizeY->show(); 
	QObject::connect(SELEC, SIGNAL(cadreYChanged(int)), SizeY, SLOT(changeValue(int)));
	// SIZEW
	SizeW = new ViewLabel(this, ViewLabel::WIDE); SizeW->move(QPoint(0, 80)); SizeW->show(); 
	QObject::connect(SELEC, SIGNAL(cadreWChanged(int)), SizeW, SLOT(changeValue(int)));
	// SIZEH
	SizeH = new ViewLabel(this, ViewLabel::WIDE); SizeH->move(QPoint(64, 80)); SizeH->show(); 
	QObject::connect(SELEC, SIGNAL(cadreHChanged(int)), SizeH, SLOT(changeValue(int)));

	QObject::connect(SELEC, SIGNAL(selectionCreated()), this, SLOT(selectionCreated()));
	QObject::connect(SELEC, SIGNAL(selectionDeleted()), this, SLOT(selectionDeleted()));
}

void InfoPanel::selectionCreated() {
	resize(QSize(size().width(), 97));
}

void InfoPanel::selectionDeleted() {
	resize(QSize(size().width(), 41));
}