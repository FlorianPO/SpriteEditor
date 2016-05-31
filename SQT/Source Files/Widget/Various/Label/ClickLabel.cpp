#include "Source Files/Widget/Various/Label/ClickLabel.h"
#include <QtWidgets/QApplication>
#include <QMouseEvent>

ClickLabel::ClickLabel(QWidget* parent, sf::Vector2i range, enum_size e_size, bool auto_emit) : ViewLabel(parent, e_size) {
	this->range = range;
	this->auto_emit = auto_emit;

	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(run()));
	timer.setInterval(16);
}

void ClickLabel::mousePressEvent(QMouseEvent* Qm) {
	switch (Qm->button()) {
		case Qt::LeftButton:
			add = true;
			ex_value = value;
			frame_cpt = 0;
			run();
			timer.start();
			break;
		case Qt::RightButton:
			sub = true;
			ex_value = value;
			frame_cpt = 0;
			run();
			timer.start();
			break;
		default: 
			break;
	}
}

void ClickLabel::mouseReleaseEvent(QMouseEvent* Qm) {
	switch (Qm->button()) {
		case Qt::LeftButton:
			add = false;
			timer.stop();
			break;
		case Qt::RightButton:
			sub = false;
			timer.stop();
			break;
		default: 
			break;
	}
	if (!auto_emit)
		if (ex_value != value)
			emit valueChanged(value);
}

void ClickLabel::wheelEvent(QWheelEvent* Qw) {
    QPoint numDegrees = Qw->angleDelta();
    if (!numDegrees.isNull()) {
		add = numDegrees.y() > 0;
		sub = numDegrees.y() < 0;
        ex_value = value;
		frame_cpt = 0;
		run();
		add = false;
		sub = false;
    }

	if (!auto_emit)
		if (ex_value != value)
			emit valueChanged(value);

    Qw->accept();
}

void ClickLabel::checkRange(int* value) {
	if (*value > range.y)
		*value = range.y;
	if (*value < range.x)
		*value = range.x;
}

void ClickLabel::run() {
	if (frame_cpt == 0 || frame_cpt > 20) {
		int incr_value = static_cast<int>(add) - static_cast<int>(sub);

		Qt::KeyboardModifiers special = QApplication::keyboardModifiers();
		if (special & Qt::ShiftModifier && special & Qt::ControlModifier)
			incr_value = incr_value * 100;
		else if (special & Qt::ShiftModifier)
			incr_value = incr_value * 50;
		else if (special & Qt::ControlModifier)
			incr_value = incr_value * 5;

		int new_value = value + incr_value;
		checkRange(&new_value);
		changeValue(new_value);
	}
	frame_cpt++;
}

void ClickLabel::changeValue(int value) {
	if (this->value != value) {
		setText(QString::fromStdString(prefixe + std::to_string(value)));
		this->value = value;
		if (auto_emit)
			emit valueChanged(value);
	}
}