#pragma once

#include "stdenum.h"

class OpenAction : public QAction
{
	Q_OBJECT
public:
	OpenAction();
	~OpenAction() {}

	private slots:
		void open();
};

class OpenActionAsLayer : public QAction
{
	Q_OBJECT
public:
	OpenActionAsLayer();
	~OpenActionAsLayer() {}

	private slots:
		void open_as_layer();
};