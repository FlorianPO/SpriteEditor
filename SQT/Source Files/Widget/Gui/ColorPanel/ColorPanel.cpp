#include "ColorPanel.h"

#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/SignalType/SignalColor.h"

ColorPanel::ColorPanel(QWidget *parent, const QPoint& position) : QWidget(parent) {
	move(position);
	ui.setupUi(this);
	show();

	// COLOR1
	SignalColor* C1 = COLOR_CONTROLLER->getSColor1();
	ui.Color1->setAutoFillBackground(true);
	QObject::connect(C1, SIGNAL(colorChanged(SignalColor*)), this, SLOT(color1Changed(SignalColor*)));

	// R
	r1 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); r1->move(QPoint(64, 0)); r1->show(); 
	r1->setPrefixe("R  "); r1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); r1->setIndent(5);
	QObject::connect(C1, SIGNAL(RChanged(int)), r1, SLOT(changeValue(int)));
	QObject::connect(r1, SIGNAL(valueChanged(int)), C1, SLOT(setR(int)));
	// G
	g1 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); g1->move(QPoint(64, 16)); g1->show(); 
	g1->setPrefixe("G  "); g1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); g1->setIndent(5);
	QObject::connect(C1, SIGNAL(GChanged(int)), g1, SLOT(changeValue(int)));
	QObject::connect(g1, SIGNAL(valueChanged(int)), C1, SLOT(setG(int)));
	// B
	b1 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); b1->move(QPoint(64, 32)); b1->show(); 
	b1->setPrefixe("B  "); b1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); b1->setIndent(5);
	QObject::connect(C1, SIGNAL(BChanged(int)), b1, SLOT(changeValue(int)));
	QObject::connect(b1, SIGNAL(valueChanged(int)), C1, SLOT(setB(int)));
	// A
	a1 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); a1->move(QPoint(64, 48)); a1->show(); 
	a1->setPrefixe("A  "); a1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); a1->setIndent(5);
	QObject::connect(C1, SIGNAL(AChanged(int)), a1, SLOT(changeValue(int)));
	QObject::connect(a1, SIGNAL(valueChanged(int)), C1, SLOT(setA(int)));

	// COLOR2
	SignalColor* C2 = COLOR_CONTROLLER->getSColor2();
	ui.Color2->setAutoFillBackground(true);
	QObject::connect(C2, SIGNAL(colorChanged(SignalColor*)), this, SLOT(color2Changed(SignalColor*)));

	// R
	r2 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); r2->move(QPoint(8, 72)); r2->show(); 
	r2->setPrefixe("R  "); r2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); r2->setIndent(5);
	QObject::connect(C2, SIGNAL(RChanged(int)), r2, SLOT(changeValue(int)));
	QObject::connect(r2, SIGNAL(valueChanged(int)), C2, SLOT(setR(int)));
	// G
	g2 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); g2->move(QPoint(8, 88)); g2->show(); 
	g2->setPrefixe("G  "); g2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); g2->setIndent(5);
	QObject::connect(C2, SIGNAL(GChanged(int)), g2, SLOT(changeValue(int)));
	QObject::connect(g2, SIGNAL(valueChanged(int)), C2, SLOT(setG(int)));
	// B
	b2 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); b2->move(QPoint(8, 104)); b2->show(); 
	b2->setPrefixe("B  "); b2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); b2->setIndent(5);
	QObject::connect(C2, SIGNAL(BChanged(int)), b2, SLOT(changeValue(int)));
	QObject::connect(b2, SIGNAL(valueChanged(int)), C2, SLOT(setB(int)));
	// A
	a2 = new ClickLabel(this, sf::Vector2i(0, 255), ClickLabel::EXTENDED, true); a2->move(QPoint(8, 120)); a2->show(); 
	a2->setPrefixe("A  "); a2->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); a2->setIndent(5);
	QObject::connect(C2, SIGNAL(AChanged(int)), a2, SLOT(changeValue(int)));
	QObject::connect(a2, SIGNAL(valueChanged(int)), C2, SLOT(setA(int)));
}

void ColorPanel::color1Changed(SignalColor* color) {
	ui.Color1->setStyleSheet(QString::fromStdString("background-color: rgba(" +
							 std::to_string(color->getR()) + "," + 
							 std::to_string(color->getG()) + "," +
							 std::to_string(color->getB()) + "," +
							 std::to_string(color->getA()) + ");"));
}

void ColorPanel::color2Changed(SignalColor* color) {
	ui.Color2->setStyleSheet(QString::fromStdString("background-color: rgba(" +
							 std::to_string(color->getR()) + "," + 
							 std::to_string(color->getG()) + "," +
							 std::to_string(color->getB()) + "," +
							 std::to_string(color->getA()) + ");"));
}

