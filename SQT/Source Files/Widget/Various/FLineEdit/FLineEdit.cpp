#include "FLineEdit.h"

#include "Source Files/Application/Input/ShortcutController.h"

FLineEdit::FLineEdit(QWidget* parent) : QLineEdit(parent) {
	QObject::connect(this, SIGNAL(focussed()), SHORTCUT_CONTROLLER, SLOT(disableCoreShortcut()));
	QObject::connect(this, SIGNAL(unFocussed()), SHORTCUT_CONTROLLER, SLOT(enableCoreShortcut()));

	setStyleSheet("background-color:white;");
}

void FLineEdit::focusInEvent(QFocusEvent *Qf) {
	QLineEdit::focusInEvent(Qf);
	emit focussed();
}

void FLineEdit::focusOutEvent(QFocusEvent *Qf) {
	QLineEdit::focusOutEvent(Qf);
	emit unFocussed();
}

void FLineEdit::keyPressEvent(QKeyEvent *Qk) {
	int key = Qk->key();
	if (key == Qt::Key_Return || key == Qt::Key_Enter || key == Qt::Key_Escape)
		clearFocus();
	QLineEdit::keyPressEvent(Qk);
	Qk->accept();
}