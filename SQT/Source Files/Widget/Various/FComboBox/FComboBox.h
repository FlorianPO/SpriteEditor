#pragma once

#include "stdenum.h"

class FComboBox : public QComboBox
{
	Q_OBJECT
// CONSTRUCTOR
public:
	FComboBox(QWidget* parent);
	~FComboBox() {}

// METHODS
public:
	void addItem(const QString& name, void* data, bool hidden=false);
	void selectItem(void* data);
	void setItemText(void* data, const QString& text);
	void hideItem(void* data);
	void showItem(void* data);
	void removeItem(void* data);
	template <typename T>
	T get(int index) const { return static_cast<T>(data_list[index].data); }

// MEMBERS
private:
	struct _data_type {
		int index;
		QString name;
		void* data;
		bool hidden;
	};

	std::vector<_data_type> data_list;
};

