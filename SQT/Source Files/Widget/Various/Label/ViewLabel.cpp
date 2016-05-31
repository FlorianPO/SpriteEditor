#include "Source Files/Widget/Various/Label/ViewLabel.h"

ViewLabel::ViewLabel(QWidget* parent, enum_size e_size) : QLabel(parent) {
	QSize size;
	switch (e_size) {
		case DEFAULT: size = QSize(49, 17); break;
		case EXTENDED: size = QSize(57, 17); break;
		case WIDE: size = QSize(65, 17); break;
	}
	resize(size);

	setAutoFillBackground(false);
	setStyleSheet(QLatin1String("font: 75 10pt \"Calibri\";\n"
		"font-weight: bold;\n"));
	setAlignment(Qt::AlignCenter);
	setFrameShape(QFrame::StyledPanel);
	setFrameShadow(QFrame::Sunken);
}

void ViewLabel::changeValue(int value) {
	if (this->value != value) {
		setText(QString::fromStdString(prefixe + std::to_string(value)));
		this->value = value;
	}
}