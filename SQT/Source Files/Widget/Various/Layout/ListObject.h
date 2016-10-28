#pragma once

#include "stdenum.h"
class SignalListObject;

class ListObject : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	ListObject(QWidget* parent, SignalListObject* binded_object=NULL);
	~ListObject();

// SIGNAL / SLOTS
	public slots:
		void drop();
		void undrop();
		void select();
		void unselect();
		void inverseSelection();
	private slots:
		void _drop();
		void _undrop();
		void _select();
		void _unselect();
	signals:
		void deleted() const;
		void dropped() const;
		void undropped() const;
		void selected() const;
		void unselected() const;
		void leftClicked() const;
		void rightClicked() const;
		void moved() const;

// METHODS
public:
	inline bool isSelected() const { return b_selected; }
	inline bool isDropped() const { return b_dropped; }
	template <typename T=SignalListObject*>
	inline T getBindedObject() const { return static_cast<T>(binded_object); }
private:
	void mousePressEvent(QMouseEvent* Qm) override;
	void moveEvent(QMoveEvent* Qm) override;

// MEMBERS
private:
	bool b_selected;
	bool b_dropped;

	SignalListObject* binded_object;
};

