#include "SpriteEditor.h"

SpriteEditor::SpriteEditor() : QAction("\303\211diteur de sprites", NULL) {
	QObject::connect(this, SIGNAL(triggered()), this, SLOT(start()));

	setShortcut(QKeySequence(Qt::Key_F1));
}

void SpriteEditor::start() {
	
}