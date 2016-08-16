#pragma once

#include "stdenum.h"

class FLineEdit : public QLineEdit
{
  Q_OBJECT
// CONSTRUCTOR
public:
	FLineEdit(QWidget* parent=NULL) : QLineEdit(parent) {}
	~FLineEdit() {}

// SIGNALS SLOTS
signals:
	void focussed();
	void unFocussed();

// METHODS
protected:
	void focusInEvent(QFocusEvent *Qf) override;
	void focusOutEvent(QFocusEvent *Qf) override;
	void keyPressEvent(QKeyEvent *Qk) override;
};

