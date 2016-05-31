#pragma once

#include "stdafx.h"

#define QTWINDOW MainQt::_t->MainFrame
#define QTCREATE MainQt::_t = new MainQt

class MainQt : public QWidget
{
	Q_OBJECT
// INSTANCE
public:
	static MainQt* _t;
// CONSTRUCTOR
public:
	MainQt(QString name);
	~MainQt() {}

// MEMBERS
public:
	QMainWindow* MainFrame;
};

