#include "OpenSpriteEditor.h"

#include "Source Files/Widget/SpriteEditor/SpriteEditor.h"

OpenSpriteEditor::OpenSpriteEditor() : QAction("\303\211diteur de sprites", NULL) {
	QObject::connect(this, SIGNAL(triggered()), this, SLOT(start()));

	setShortcut(QKeySequence(Qt::Key_F1));
}

void OpenSpriteEditor::start() {
	if (!SPRITE_EDITOR->isVisible())
		SPRITE_EDITOR->show();
	if (!SPRITE_EDITOR->isActiveWindow())
		SPRITE_EDITOR->activateWindow();
}