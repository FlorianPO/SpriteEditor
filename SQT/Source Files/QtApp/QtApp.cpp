#include "QtApp.h"

#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Widget/SpriteEditor/SpriteEditor.h"
#include "Source Files/Widget/Gui/Gui.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Widget/Menu/Menu.h"

QtApp* QtApp::_t;

QtApp::QtApp(int& argc, char* argv[], const QString& name) : QApplication(argc, argv) {
	main_frame = new QMainWindow();
	main_frame->setWindowTitle(name);
	main_frame->show();
	main_frame->setMouseTracking(true);
}

QtApp::~QtApp() {
	delete main_frame;
}

void QtApp::init() {
	// INIT
	INIT_QUEUE_CONTROLLER
	INIT_INPUT_CONTROLLER
	INIT_SHORTCUT_CONTROLLER
	INIT_RESOURCE_CONTROLLER
	INIT_UNDO_STACK

	INIT_MENU(main_frame);
	INIT_GUI(main_frame);
	INIT_SFML(main_frame);
	INIT_SPRITE_EDITOR();
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