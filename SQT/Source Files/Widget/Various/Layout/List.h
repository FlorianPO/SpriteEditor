#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalList.h"
class ListObject;
class UndoStack;

class List : public QObject
{
	Q_OBJECT
public:
	struct param {
		bool up_to_down;
		bool dragable;
		bool selectable;
		bool multi_selection;
		bool ensure_undo;
		bool ensure_drag;
	};

// CONSTRUCTOR
public:
	List(QWidget* parent, const param& parameters, const QPoint& topLeftpos=QPoint(), UndoStack* undo_stack=NULL, SignalList* binded_list=NULL);
	~List() {}

// METHODS
public:
	void addWidget(ListObject& widget);
	void removeWidget(ListObject& widget);
	void setSpacing(int spacing);
	void setLocalSpacing(int spacing);

	void selectOne(ListObject& widget);

	inline const param& getParameters() const { return parameters; }
	inline const std::deque<ListObject*>& getList() const { return widget_list; }
	inline UndoStack& getUndoStack() const { return *undo_stack; }
	inline bool size() const { return widget_list.size(); }

	// For multiple call optimisation 
	void _fillBegin();
	void _fillEnd();

	// For multiple call optimisation 
	void _selectBegin() { _slct = true; }
	void _selectEnd() { _slct = false; refreshSelection(); }

protected:
	void addWidgetAt(ListObject& widget_to_add, int index);
	void setLineAfter(const ListObject& widget);
	void setLineBefore(const ListObject& widget);
	
	ListObject& getFirstObject() const;
	ListObject& getFirstObjectSelected() const;

	int count(bool count_dropped=false) const;
	int countSelected() const;

	virtual void refresh() = 0;
	virtual void setLineSize(const QSize& size) = 0;
	void refreshSelection();

	bool eventFilter(QObject* object, QEvent *evnt) override;
	int posOn(const QPoint& pos) const; // returns the widget where pos is located
	int indexOf(const ListObject& widget) const;

	void mousePressed(QObject* object, QMouseEvent* event);
	void mouseReleased(QObject* object, QMouseEvent* event);
	void mouseMoved(QObject* object, QMouseEvent* event);

	void multiSelection(QObject *object, QMouseEvent* event);
	void drag(QObject* object, QMouseEvent* event);
	void endDrag();

// SIGNALS SLOTS
	private: 
		void widgetSelected(ListObject& widget);
		void widgetUnselected(ListObject& widget);
	public slots:
		void moveElement(int src, int dst);
		void dropSelected();
		void stopUndoStack();
		void startUndoStack();
	signals:
		void undoed() const;
		void elementMoved(int src, int dst) const;
		void reordered() const;
		void firstObjectSelected(ListObject&) const;
		void noObjectSelected() const;
		void objectSelected() const;
		void oneObjectSelected(ListObject&) const;
		void noMoreOneObjectSelected() const;
		void moreThanOneObjectSelected() const;
		void firstObjectUnselected(ListObject&) const;
		void noObject() const;
		void onlyOneObject() const;
		void moreThanOneObject() const;

// MEMBERS
protected:
	QPoint topLeftPos;
	std::deque<ListObject*> widget_list;
	std::deque<int> spacing_list;
	SignalList* binded_list;
	QWidget* parent;

	param parameters;
	int spacing = 0;
	bool one_object_selected = false;
	bool _cstr = false;
	bool _slct = false;
	ListObject* one_selected = NULL;

	//Drag
	bool left_clicked = false;
	bool right_clicked = false;
	bool dragging = false;
	bool dragged_once = false;
	bool special = false;
	QPoint click_pos;
	int i_widget_click;
	int ex_i_widget_click = -1;
	int i_widget_tmp;
	
	QFrame* line;
	bool line_found = false;
	int line_index = -1;

	// Stack
	bool stack_active = false;
	UndoStack* undo_stack;
public:
	friend class ListOrdered;
	friend class ListCreated;
	friend class ListDropped;
};


