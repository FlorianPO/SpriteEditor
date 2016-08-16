#include "QtApp.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "SQT/SFMLView.h"

QtApp* QtApp::_t;

QtApp::QtApp(int& argc, char* argv[], const QString& name) : QApplication(argc, argv) {
	main_frame = new QMainWindow();
	main_frame->setWindowTitle(name);
	main_frame->show();
	main_frame->setMouseTracking(true);

	menu = new Menu(main_frame);
	menu->show();

	// INIT
	INIT_QUEUE_CONTROLLER
	INIT_INPUT_CONTROLLER
	INIT_SHORTCUT_CONTROLLER
	INIT_RESOURCE_CONTROLLER
	INIT_UNDO_STACK
}

bool QtApp::notify(QObject* object, QEvent* event) {
	if (strcmp(object->metaObject()->className(), "QWidgetWindow") == 0)
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent* Qk = static_cast<QKeyEvent*>(event);
			if (!Qk->isAutoRepeat()) {
				INPUT->registerPressed(Qk->key());
				if (Qk->key() == Qt::Key_Tab && SFML->QWidget::hasFocus()) // No tab while drawing
					return false;
			}
		}
		else if (event->type() == QEvent::KeyRelease) {
			QKeyEvent* Qk = static_cast<QKeyEvent*>(event);
			if (!Qk->isAutoRepeat())
				INPUT->registerReleased(Qk->key());
		}
		
	return QApplication::notify(object, event);
}