#pragma once

#include "stdafx.h"
#include <QtCore/QObject>
#include <QtCore/qpoint.h>

class VerticalLayout : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	explicit VerticalLayout(QPoint topLeft=QPoint(), bool upToDown=true);
	~VerticalLayout() {}

// METHODS
public:
	void addWidget(QWidget* widget);
	void removeWidget(QWidget* widget);
	void setSpacing(int spacing);
	void setLocalSpacing(int spacing);

	// For multiple call optimisation 
	void _fillBegin() { _cstr = true; }
	void _fillEnd() { _cstr = false; refresh(); }
private:
	bool eventFilter(QObject *object, QEvent *evnt) override;

// SIGNALS SLOTS
	public slots:
		void refresh();

// MEMBERS
private:
	QPoint topLeftPos;
	std::deque<QWidget*> widget_list;
	std::deque<int> spacing_list;
	bool upToDown;
	int spacing = 0;
	bool _cstr = false;
};

