#include "InfoPanel_copy.h"

#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Application/Copy/Copy.h"

InfoPanel_copy::InfoPanel_copy(QWidget *parent) : QWidget(parent) {
	ui_copy.setupUi(this);
	hide();

	QObject::connect(COPY_CONTROLLER, SIGNAL(copyCreated(Copy&)), this, SLOT(bind(Copy&)));
	QObject::connect(COPY_CONTROLLER, SIGNAL(copyDropped(Copy&)), this, SLOT(unbind()));

	SizeX = new ClickLabel(this, sf::Vector2i(INT_MIN, INT_MAX), ViewLabel::WIDE, true); SizeX->move(QPoint(0, 24)); SizeX->show(); 
	SizeY = new ClickLabel(this, sf::Vector2i(INT_MIN, INT_MAX), ViewLabel::WIDE, true); SizeY->move(QPoint(64, 24)); SizeY->show(); 
	SizeW = new ViewLabel(this, ViewLabel::WIDE); SizeW->move(QPoint(0, 40)); SizeW->show(); 
	SizeH = new ViewLabel(this, ViewLabel::WIDE); SizeH->move(QPoint(64, 40)); SizeH->show(); 
}

void InfoPanel_copy::bind(Copy& copy) {
	// SIZEX
	lambdas.push_back(QObject::connect(&copy, &Copy::copyMoved, [this](sf::Vector2f pos) {SizeX->changeValue(pos.x);}));
	lambdas.push_back(QObject::connect(SizeX, &ClickLabel::valueChanged, [&](int x) {copy.setGlobalPosition(sf::Vector2f(x, copy.getGlobalPosition().y));}));
	// SIZEY
	lambdas.push_back(QObject::connect(&copy, &Copy::copyMoved, [this](sf::Vector2f pos) {SizeY->changeValue(pos.y);}));
	lambdas.push_back(QObject::connect(SizeY, &ClickLabel::valueChanged, [&](int y) {copy.setGlobalPosition(sf::Vector2f(copy.getGlobalPosition().x, y));}));
	// SIZEW
	lambdas.push_back(QObject::connect(&copy, &Copy::copyScaled, [this](sf::Vector2f size) {SizeW->changeValue(size.x);}));
	// SIZEH
	lambdas.push_back(QObject::connect(&copy, &Copy::copyScaled, [this](sf::Vector2f size) {SizeH->changeValue(size.y);}));

	QUEUE->beforeDisplay(this, "show", "hide");
}

void InfoPanel_copy::unbind() {
	FOR_I (lambdas.size())
		QObject::disconnect(lambdas[i]);
	lambdas.clear();

	QUEUE->beforeDisplay(this, "hide", "show");
}