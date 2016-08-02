#include "ClickLabel.h"

#include "Source Files/Fonction/Fonction.h"

ClickLabel::ClickLabel(QWidget* parent, sf::Vector2i range, enum_size e_size, bool auto_emit) : ViewLabel(parent, e_size) {
	this->range = range;
	this->auto_emit = auto_emit;

	setFocusPolicy(Qt::TabFocus);
	setMouseTracking(true);

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
	Qm->accept();
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
	Qm->accept();
}

void ClickLabel::mouseMoveEvent(QMouseEvent* Qm) {
	if (!hasFocus())
		setFocus();
	Qm->accept();
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

int ClickLabel::checkRange(int* value) {
	int return_value = DEFAULT;
	if (*value > range.y) {
		*value = range.y;
		return_value += UP_LIMIT_REACHED + LIMIT_REACHED;
	}
	else if (*value < range.x) {
		*value = range.x;
		return_value += DOWN_LIMIT_REACHED + LIMIT_REACHED;
	}

	int num_digits = Fonction::numDigits(*value);
	if (num_digits == 1)
		return_value += ONE_DIGIT;
	else if (num_digits == Fonction::numDigits(range.y))
		return_value += MAX_DIGIT;

	return return_value;
}

void ClickLabel::endValueTyping() {
	if (text_initiated) {
		write_back = false;
		text_initiated = false;
		if (!auto_emit)
			if (ex_keyboard_value != value)
				emit valueChanged(value);
	}
}

void ClickLabel::keyPressEvent(QKeyEvent* Qk) {
	int key = Qk->key();
	if (key >= 0x30 && key <= 0x39) { // Key_0 - Key_9
		if (!text_initiated) {
			ex_keyboard_value = value;
			text_initiated = true;
		}

		if (!write_back) {
			write_back = true;
			int new_value = key - 0x30;
			if (checkRange(&new_value) & UP_LIMIT_REACHED)
				write_back = false;
			changeValue(new_value);
		}
		else {
			int new_value = value*10 + key - 0x30;
			if (checkRange(&new_value) & UP_LIMIT_REACHED)
				write_back = false;
			changeValue(new_value);
		}
	}
	else if (key == Qt::Key_Backspace) {
		if (!text_initiated) {
			ex_keyboard_value = value;
			text_initiated = true;
		}

		int new_value = value / 10;
		if (checkRange(&new_value) & DOWN_LIMIT_REACHED)
			write_back = false;
		else
			write_back = true;
		changeValue(new_value);
	}
	else
		endValueTyping();
	Qk->accept();
		
}

void ClickLabel::focusInEvent(QFocusEvent* event) {
	QWidget::focusInEvent(event);
	setText(QString()); // Force text display (see QTBUG-53982)
	setText(QString::fromStdString(prefixe + std::to_string(value)));
	write_back = false;

	emit focusIn();
}

void ClickLabel::focusOutEvent(QFocusEvent* event) {
	QWidget::focusOutEvent(event);
	endValueTyping();

	emit focusOut();
}

void ClickLabel::run() {
	write_back = false;
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