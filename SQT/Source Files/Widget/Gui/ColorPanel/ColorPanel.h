#pragma once

#include "stdafx.h"

#include "GeneratedFiles/ui_ColorPanel.h"
#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include "Source Files/SignalType/SignalColor.h"

class ColorPanel : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit ColorPanel(QWidget *parent, const QPoint& position=QPoint());
	~ColorPanel() {};

// SIGNALS SLOTS
	public slots:
		void color1Changed(SignalColor* color);
		void color2Changed(SignalColor*	color);

// MEMBERS
private:
	Ui_ColorPanel ui;

	ClickLabel *r1, *g1, *b1, *a1;
	ClickLabel *r2, *g2, *b2, *a2;
};

