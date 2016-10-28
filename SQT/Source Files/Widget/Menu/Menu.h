#pragma once

#include "stdenum.h"

#define INIT_MENU Menu::createInstance
#define MENU Menu::getInstance()

class Menu : public QMenuBar
{
// INSTANCE
private:	static Menu* _t; 
public:		inline static void createInstance(QWidget* parent) { _t = new Menu(parent); }
			inline static Menu* getInstance() { return _t; }
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
		void globallyChanged() const;

// MEMBERS
private:
	QMenu* fileMenu;
	QMenu* windowMenu;

	int w_height = 27;
};

