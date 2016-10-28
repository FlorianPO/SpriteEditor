#pragma once

#include "stdenum.h"
#include "GeneratedFiles/ui_Gui.h"
class VerticalLayout; // Forward declaration

#define INIT_GUI Gui::createInstance
#define GUI Gui::getInstance()

class Gui : public QWidget
{
// INSTANCE
private:	static Gui* _t; 
public:		inline static void createInstance(QWidget* parent) { _t = new Gui(parent); }
			inline static Gui* getInstance() { return _t; }
	Q_OBJECT
// CONSTRUCTOR
public:
	Gui(QWidget *parent);
	~Gui() {}

// METHODS
private:
	void showEvent(QShowEvent* evnt) override;
	void hideEvent(QHideEvent* evnt) override;

// SIGNALS SLOTS
	public slots:
		void findSpace();
	signals:
		void globallyChanged() const;

// MEMBERS
private:
	Ui_Gui ui;
	VerticalLayout* verticalLayout;
};

