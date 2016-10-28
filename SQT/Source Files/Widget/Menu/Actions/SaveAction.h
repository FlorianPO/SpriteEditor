#pragma once

#include "stdenum.h"

class SaveAction : public QAction
{
	Q_OBJECT
public:
	SaveAction();
	~SaveAction() {}

	private slots:
		void save();
};

