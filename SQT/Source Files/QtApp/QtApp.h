#pragma once

#include "stdenum.h"
#include "Source Files/QtApp/Menu/Menu.h"

#define QTAPP_CREATE QtApp::createInstance
#define QTAPP QtApp::getInstance()
#define QTWINDOW QtApp::getInstance()->getMainWindow()
#define QTMENU QtApp::getInstance()->getMenu()

class QtApp : public QApplication
{
	Q_OBJECT
// INSTANCE
private:	static QtApp* _t; 
public:		inline static void createInstance(int& argc, char* argv[], const QString& name) { _t = new QtApp(argc, argv, name); }
			inline static QtApp* getInstance() { return _t; }

// CONSTRUCTOR
public:
	QtApp(int& argc ,char* argv[], const QString& name);
	~QtApp() {}

// METHODS
public:
	inline QMainWindow* getMainWindow() { return main_frame; }
	inline Menu* getMenu() { return menu; }
private:
	bool notify(QObject* object, QEvent* event) override;

// MEMBERS
private:
	QMainWindow* main_frame;
	Menu* menu;

	QString name;
	QSize size;
};