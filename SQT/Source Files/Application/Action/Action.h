#pragma once

#include "stdenum.h"

class Action : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Action() {}
	~Action() {}

// METHODS
public:
	virtual void use() = 0;

// SIGNALS SLOTS
	signals:
		void ended() const;
};

