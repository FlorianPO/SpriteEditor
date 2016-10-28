#pragma once

#include "stdenum.h"

class SignalListObject : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SignalListObject();
	~SignalListObject();

// METHODS
public:
	inline bool isSelected() const { return b_selected; }
	inline bool isDropped() const { return b_dropped; }

// SIGNAL / SLOTS
	public slots:
		virtual void drop();
		virtual void undrop();
		virtual void select();
		virtual void unselect();
	signals:
		void deleted() const;
		void dropped() const;
		void undropped() const;
		void selected() const;
		void unselected() const;

// MEMBERS
protected:
	bool b_dropped;
	bool b_selected;
};
