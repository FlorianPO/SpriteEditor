#include "Menu.h"

#include "Source Files/Widget/Menu/Actions/SaveAction.h"
#include "Source Files/Widget/Menu/Actions/OpenAction.h"
#include "Source Files/Widget/Menu/Actions/OpenSpriteEditor.h"

Menu* Menu::_t;

Menu::Menu(QWidget* parent) : QMenuBar(parent) {
	parent->installEventFilter(this);
	setGeometry(QRect(0, 0, 1920, w_height));

	fileMenu = addMenu("Fichier");
	windowMenu = addMenu("Fen\303\252tres");

	// FILE
	fileMenu->addAction(new SaveAction());
	fileMenu->addAction(new OpenAction());
	fileMenu->addAction(new OpenActionAsLayer());
	// WINDOW
	windowMenu->addAction(new OpenSpriteEditor());
}

void Menu::showEvent(QShowEvent* evnt) {
	QWidget::showEvent(evnt);
	emit globallyChanged();
}

void Menu::hideEvent(QHideEvent* evnt) {
	QWidget::hideEvent(evnt);
	emit globallyChanged();
}

bool Menu::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::Resize) {
        QResizeEvent* resizeEvent = static_cast<QResizeEvent*>(event);

		setGeometry(0, 0, resizeEvent->size().width(), w_height);
		emit globallyChanged();
    }
    return false;
}