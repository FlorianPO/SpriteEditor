#pragma once

#include "stdenum.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"

class ClickLabel : public ViewLabel
{
	Q_OBJECT
// CONSTRUCTOR
public:
	ClickLabel(QWidget* parent, sf::Vector2i range, enum_size e_size=DEFAULT, bool auto_emit = false);
	~ClickLabel() {}

// SIGNALS SLOTS
	private slots:
		void run();
	// VALUE
	public slots:
		void changeValue(int value) override;
	signals:
		void valueChanged(int value);
		void focusIn();
		void focusOut();

// METHODS
private:
	void mousePressEvent(QMouseEvent* Qm) override;
	void mouseReleaseEvent(QMouseEvent* Qm) override;
	void mouseMoveEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;
	void keyPressEvent(QKeyEvent* Qk) override;
	void focusInEvent(QFocusEvent *event) override;
	void focusOutEvent(QFocusEvent *event) override;

	void setValue(int value);
	int checkRange(int* value); // Returns check_info_enum combinaison
	void endValueTyping();

// ENUM
private:
	enum check_info_enum {
		NONE = 0x0,
		LIMIT_REACHED = 0x1,
		UP_LIMIT_REACHED = 0x2,
		DOWN_LIMIT_REACHED = 0x4,
		ONE_DIGIT = 0x8,
		MAX_DIGIT = 0x10
	};

// MEMBERS
private:
	QTimer timer;
	int ex_value;
	int frame_cpt;
	bool add = false;
	bool sub = false;
	bool auto_emit;
	sf::Vector2i range;

	int ex_keyboard_value;
	bool text_initiated = false;
	bool write_back = false;

	int value_at_focus_in;
};

