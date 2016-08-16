#pragma once

#include "stdenum.h"

class Menu : public QMenuBar
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Menu(QWidget* parent);
	~Menu() {}

// METHODS
private:
	void showEvent(QShowEvent* evnt) override;
	void hideEvent(QHideEvent* evnt) override;
	bool eventFilter(QObject *object, QEvent *event) override;

// SIGNALS SLOTS
	signals:
		void globallyChanged();

// MEMBERS
private:
	QMenu* fileMenu;
	QMenu* toolMenu;

	int w_height = 27;
};

