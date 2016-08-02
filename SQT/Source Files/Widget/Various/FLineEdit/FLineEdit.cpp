#include "FLineEdit.h"

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