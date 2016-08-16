#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_ColorPanel.h"
class ClickLabel; // Forward declaration
class SignalColor; // Forward declaration

class ColorPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	ColorPanel(QWidget *parent, const QPoint& position=QPoint());
	~ColorPanel() {}

// SIGNALS SLOTS
	public slots:
		void color1Changed();
		void color2Changed();

// MEMBERS
private:
	Ui_ColorPanel ui;

	ClickLabel *r1, *g1, *b1, *a1;
	ClickLabel *r2, *g2, *b2, *a2;

	SignalColor* C1;
	SignalColor* C2;
};

