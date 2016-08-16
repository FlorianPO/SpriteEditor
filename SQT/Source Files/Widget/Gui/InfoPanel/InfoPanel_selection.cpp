#include "InfoPanel_selection.h"

#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"

InfoPanel_selection::InfoPanel_selection(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui_selec.setupUi(this);
	hide();

	SizeX = new ClickLabel(this, sf::Vector2i(INT_MIN, INT_MAX), ViewLabel::WIDE, true); SizeX->move(QPoint(0, 24)); SizeX->show(); 
	SizeY = new ClickLabel(this, sf::Vector2i(INT_MIN, INT_MAX), ViewLabel::WIDE, true); SizeY->move(QPoint(64, 24)); SizeY->show(); 
	SizeW = new ViewLabel(this, ViewLabel::WIDE); SizeW->move(QPoint(0, 40)); SizeW->show(); 
	SizeH = new ViewLabel(this, ViewLabel::WIDE); SizeH->move(QPoint(64, 40)); SizeH->show(); 

	QObject::connect(SELEC, SIGNAL(selectionCreated()), this, SLOT(show()));
	QObject::connect(SELEC, SIGNAL(selectionDeleted()), this, SLOT(hide()));

	bind();
}

void InfoPanel_selection::bind() {
	// SIZEX
	lambdas.push_back(QObject::connect(SELEC, &SelectionController::selectionMoved, [this](sf::Vector2f pos) {SizeX->changeValue(pos.x);}));
	lambdas.push_back(QObject::connect(SizeX, &ClickLabel::valueChanged, [](int x) {SELEC->setRealPosition(sf::Vector2f(x, SELEC->getRealPosition().y));}));
	// SIZEY
	lambdas.push_back(QObject::connect(SELEC, &SelectionController::selectionMoved, [this](sf::Vector2f pos) {SizeY->changeValue(pos.y);}));
	lambdas.push_back(QObject::connect(SizeY, &ClickLabel::valueChanged, [](int y) {SELEC->setRealPosition(sf::Vector2f(SELEC->getRealPosition().x, y));}));
	// SIZEW
	lambdas.push_back(QObject::connect(SELEC, &SelectionController::selectionScaled, [this](sf::Vector2f size) {SizeW->changeValue(size.x);}));
	// SIZEH
	lambdas.push_back(QObject::connect(SELEC, &SelectionController::selectionScaled, [this](sf::Vector2f size) {SizeH->changeValue(size.y);}));
}