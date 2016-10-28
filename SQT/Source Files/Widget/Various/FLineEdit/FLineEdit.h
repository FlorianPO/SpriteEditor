#pragma once

#include "stdenum.h"

class FLineEdit : public QLineEdit
{
  Q_OBJECT
// CONSTRUCTOR
public:
	FLineEdit(QWidget* parent);
	~FLineEdit() {}

// SIGNALS SLOTS
signals:
	void focussed() const;
	void unFocussed() const;

// METHODS
protected:
	void focusInEvent(QFocusEvent *Qf) override;
	void focusOutEvent(QFocusEvent *Qf) override;
	void keyPressEvent(QKeyEvent *Qk) override;
};

