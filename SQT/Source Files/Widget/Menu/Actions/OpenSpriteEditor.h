#pragma once

#include "stdenum.h"

class OpenSpriteEditor : public QAction
{
	Q_OBJECT
public:
	OpenSpriteEditor();
	~OpenSpriteEditor() {}

	private slots:
		void start();
};

