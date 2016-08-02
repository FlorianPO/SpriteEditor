#pragma once

#include "stdenum.h"

class ViewLabel : public QLabel
{
	Q_OBJECT
public:
	enum enum_size
	{
		DEFAULT = 0,
		EXTENDED,
		WIDE
	};

// CONSTRUCTOR
public:
	ViewLabel(QWidget* parent, enum_size e_size=DEFAULT);
	virtual ~ViewLabel() {}

// SIGNALS SLOTS
	public slots:
		virtual void changeValue(int value);

// METHODS
public:
	void setPrefixe(const std::string& string) { prefixe = string; }

// MEMBERS
protected:
	int value=-1;
	std::string prefixe="";
};

