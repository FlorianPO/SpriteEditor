#include "SQT.h"

#ifdef Q_WS_X11
	#include <Qt/qx11info_x11.h>
	#include <X11/Xlib.h>
#endif

SQT::SQT(QWidget* parent, bool auto_refresh) : QWidget(parent) {
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoSystemBackground);
	
	this->auto_refresh = auto_refresh;
}

void SQT::showEvent(QShowEvent* qs) {
	QWidget::showEvent(qs);
	if (!initialized) {
		#ifdef Q_WS_X11
			XFlush(QX11Info::display());
		#endif

		create();
		initialized = true;
	}
	refreshOnce();
}

void SQT::moveEvent(QMoveEvent* qm) {
	QWidget::moveEvent(qm);
	refreshOnce();
}

void SQT::resizeEvent(QResizeEvent* qr) {
	QWidget::resizeEvent(qr);
	refreshOnce();
}

void SQT::refresh() {
	OnUpdate();
	display();
	update();
}

void SQT::refreshOnce() {
	if (QWidget::isVisible()) {
		refresh_once = true;
		QCoreApplication::postEvent(this, new QPaintEvent(QRect()));
	}
}

void SQT::create() {
	sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
	setFramerateLimit(60); // 60 FPS
}

QPaintEngine* SQT::paintEngine() const {
	return NULL;
}

void SQT::paintEvent(QPaintEvent* qp) {
	if (auto_refresh || refresh_once) {
		if (refresh_once)
			refresh_once = false;
		refresh();
	}
	qp->accept();
}