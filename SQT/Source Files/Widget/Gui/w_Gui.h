#pragma once

#include "stdafx.h"
#include <QtWidgets/QWidget>
#include "GeneratedFiles/ui_Gui.h"
#include "Source Files/Widget/Various/VerticalLayout/VerticalLayout.h"

class w_Gui : public QWidget
{
	Q_OBJECT
public:
	explicit w_Gui(QWidget *parent);
	~w_Gui() {};

protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* Qm) override;

private:
	Ui_Gui ui;
	VerticalLayout* verticalLayout;
};

