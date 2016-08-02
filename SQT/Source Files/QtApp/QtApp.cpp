#include "QtApp.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/Resource/ResourceController.h"

QtApp* QtApp::_t;

QtApp::QtApp(int& argc, char* argv[], const QString& name) : QApplication(argc, argv) {
	MainFrame = new QMainWindow();
	MainFrame->setWindowTitle(name);
	MainFrame->show();
	MainFrame->setMouseTracking(true);

	INIT_INPUT_CONTROLLER
	INIT_SHORTCUT_CONTROLLER
	INIT_RESOURCE_CONTROLLER
}

bool QtApp::notify(QObject* object, QEvent* event) {
	if (strcmp(object->metaObject()->className(), "QWidgetWindow") == 0)
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent* Qk = static_cast<QKeyEvent*>(event);
			if (!Qk->isAutoRepeat())
				INPUT->registerPressed(Qk->key());
		}
		else if (event->type() == QEvent::KeyRelease) {
			QKeyEvent* Qk = static_cast<QKeyEvent*>(event);
			if (!Qk->isAutoRepeat())
				INPUT->registerReleased(Qk->key());
		}

		return QApplication::notify(object, event);
}