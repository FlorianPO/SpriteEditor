#include "FComboBox.h"


FComboBox::FComboBox(QWidget* parent) : QComboBox(parent)
{
}

void FComboBox::addItem(const QString& name, void* data, bool hidden) {
	data_list.push_back({QComboBox::count(), name, data, hidden});
	QComboBox::addItem(name);
}

void FComboBox::selectItem(void* data) {
	FOR_I (data_list.size())
		if (data_list[i].data == data) {
			setCurrentIndex(i);
			return;
		}
}

void FComboBox::setItemText(void* data, const QString& text) {
	FOR_I (data_list.size())
		if (data_list[i].data == data) {
			QComboBox::setItemText(data_list[i].index, text);
			return;
		}
}

void FComboBox::hideItem(void* data) {
	FOR_I (data_list.size())
		if (data_list[i].data == data) {
			data_list[i].hidden = true;
			QComboBox::removeItem(data_list[i].index);
			for (int j=i+1; j < data_list.size(); j++)
				data_list[j].index--;
			return;
		}
}

void FComboBox::showItem(void* data) {
	FOR_I (data_list.size())
		if (data_list[i].data == data) {
			data_list[i].hidden = false;
			QComboBox::insertItem(data_list[i].index, data_list[i].name);
			for (int j=i+1; j < data_list.size(); j++)
				data_list[j].index++;
			return;
		}
}

void FComboBox::removeItem(void* data) {
	FOR_I (data_list.size())
		if (data_list[i].data == data) {
			if (!data_list[i].hidden)
				QComboBox::removeItem(data_list[i].index);
			for (int j=i+1; j < data_list.size(); j++)
				data_list[j].index--;
			data_list.erase(data_list.begin() + i);
			return;
		}
}