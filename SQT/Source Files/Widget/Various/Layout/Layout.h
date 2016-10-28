#pragma once

#include "stdenum.h"

class Layout : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	Layout(bool up_to_down, const QPoint& topLeft);
	~Layout() {}

// METHODS
	void addWidget(QWidget* widget);
	void removeWidget(QWidget* widget, bool del=true);
	void setSpacing(int spacing);
	void setLocalSpacing(int spacing);

	inline bool isUptoDown() const { return up_to_down; }
	inline const std::deque<QWidget*>& getList() const { return widget_list; }

	// For multiple call optimisation 
	void _fillBegin() { _cstr = true; }
	void _fillEnd() { _cstr = false; refresh(); }

private:
	virtual void refresh()=0;
	bool eventFilter(QObject *object, QEvent *evnt) override;

// MEMBERS
protected:
	QPoint topLeftPos;
	std::deque<QWidget*> widget_list;
	std::deque<int> spacing_list;
	bool up_to_down;
	int spacing = 0;
	bool _cstr = false;
};

