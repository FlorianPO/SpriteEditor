#pragma once

#include "stdenum.h"

class SpriteEditor : public QAction
{
	Q_OBJECT
public:
	SpriteEditor();
	~SpriteEditor() {}

	private slots:
		void start();
};

