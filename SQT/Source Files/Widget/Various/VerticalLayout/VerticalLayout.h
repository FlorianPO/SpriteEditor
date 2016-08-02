#pragma once

#include "stdenum.h"

class VerticalLayout : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	VerticalLayout(QPoint topLeft=QPoint(), bool upToDown=true, bool dragable=false, QWidget* parent=NULL);
	~VerticalLayout() {}

// METHODS
public:
	void addWidget(QWidget* widget, bool filter=true);
	void addWidgetAfter(QWidget* widget_to_add, QWidget* after, bool filter=true);
	void addWidgetBefore(QWidget* widget_to_add, QWidget* before, bool filter=true);
	void removeWidget(QWidget* widget, bool del=true);
	void setSpacing(int spacing);
	void setLocalSpacing(int spacing);
	void refresh();

	// For multiple call optimisation 
	void _fillBegin() { _cstr = true; }
	void _fillEnd() { _cstr = false; refresh(); }

private:
	bool eventFilter(QObject *object, QEvent *evnt) override;
	QWidget* posOn(const QPoint& pos, QWidget* ignore_me=NULL); // returns the widget where pos is located

// SIGNALS SLOTS
	public slots:
		void moveElement(int src, int dst); // Doesn't emit elementMoved(...)
	signals:
		void elementMoved(int src, int dst);

// MEMBERS
private:
	QPoint topLeftPos;
	std::deque<QWidget*> widget_list;
	std::deque<int> spacing_list;
	bool upToDown;
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

