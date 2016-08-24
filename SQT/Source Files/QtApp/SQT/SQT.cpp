#include "SQT.h"

#ifdef Q_WS_X11
	#include <Qt/qx11info_x11.h>
	#include <X11/Xlib.h>
#endif

SQT::SQT(QWidget* Parent, const QSize& Size, bool auto_refresh) : QWidget(Parent) {
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoSystemBackground);
	
	this->auto_refresh = auto_refresh;
	resize(Size);
}

void SQT::showEvent(QShowEvent*) {
	if (!initialized) {
		#ifdef Q_WS_X11
			XFlush(QX11Info::display());
		#endif

		create();
		
		initialized = true;
	}
}

void SQT::refresh() {
	OnUpdate();
	display();
	update();
}

void SQT::create() {
	sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
	setFramerateLimit(60); // 60 FPS
}

QPaintEngine* SQT::paintEngine() const {
	return NULL;
}

void SQT::paintEvent(QPaintEvent*) {
	if (auto_refresh) {
		OnUpdate();
		display();
		update();
	}
}