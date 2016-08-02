#pragma once

#include "stdenum.h"

class State2Button : public QPushButton
{
	Q_OBJECT
// CONSTRUCTOR
public:
	State2Button(QWidget* parent, QString* path_enabled, QString* path_disabled, bool active=true);
	~State2Button() {}

// SIGNALS SLOTS
	private slots:
		void buttonClicked();
	public slots:
		void enable();
		void disable();
	signals:
		void enabled();
		void disabled();

// MEMBERS
private:
	bool state;
	QIcon* iconEnabled=NULL;
	QIcon* iconDisabled=NULL;
};
