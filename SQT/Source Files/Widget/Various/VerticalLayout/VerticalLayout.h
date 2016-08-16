#pragma once

#include "stdenum.h"

class VerticalLayout : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	VerticalLayout(QPoint topLeft=QPoint(), bool up_to_down=true, bool dragable=false, QWidget* parent=NULL);
	~VerticalLayout() {}

// METHODS
public:
	void addWidget(QWidget* widget, bool filter=true);
	void addWidgetAfter(QWidget* widget_to_add, QWidget* after, bool filter=true);
	void addWidgetBefore(QWidget* widget_to_add, QWidget* before, bool filter=true);
	void removeWidget(QWidget* widget, bool del=true);
	void setSpacing(int spacing);
	void setLocalSpacing(int spacing);

	bool isUptoDown() { return up_to_down; }
	const std::deque<QWidget*>& getList() { return widget_list; }

	// For multiple call optimisation 
	void _fillBegin() { _cstr = true; }
	void _fillEnd() { _cstr = false; refresh(); }

private:
	void refresh();
	bool eventFilter(QObject *object, QEvent *evnt) override;
	QWidget* posOn(const QPoint& pos, QWidget* ignore_me=NULL); // returns the widget where pos is located

// SIGNALS SLOTS
	public slots:
		void moveElement(int src, int dst); // Doesn't emit elementMoved(...)
	signals:
		void elementMoved(int src, int dst);
		void reordered();

// MEMBERS
private:
	QPoint topLeftPos;
	std::deque<QWidget*> widget_list;
	std::deque<int> spacing_list;
	bool up_to_down;
	int spacing = 0;
	bool _cstr = false;

	//Drag
	QWidget* parent;
	QWidget* ex_widget_pointed;
	bool dragable;
	bool clicked;
	bool dragging;
	QPoint click_pos;
	QWidget* widget_dragged;
	QFrame* line;
};

