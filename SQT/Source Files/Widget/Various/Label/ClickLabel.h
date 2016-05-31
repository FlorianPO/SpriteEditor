#pragma once

#include "stdafx.h"
#include "Source Files/Widget/Various/Label/ViewLabel.h"

class ClickLabel : public ViewLabel
{
	Q_OBJECT
public:
	
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

// METHODS
private:
	void mousePressEvent(QMouseEvent* Qm) override;
	void mouseReleaseEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;
	void checkRange(int* value);

// MEMBERS
private:
	QTimer timer;
	int ex_value;
	int frame_cpt;
	bool add = false;
	bool sub = false;
	bool auto_emit;
	sf::Vector2i range;
};

