#include "SQT.h"

#ifdef Q_WS_X11
	#include <Qt/qx11info_x11.h>
	#include <X11/Xlib.h>
#endif

SQT::SQT(QWidget* Parent, const QSize& Size) : QWidget(Parent) {
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAttribute(Qt::WA_NoSystemBackground);

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

void SQT::create() {
	sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
	setFramerateLimit(60); // 60 FPS
}

QPaintEngine* SQT::paintEngine() const {
	return NULL;
}

void SQT::paintEvent(QPaintEvent*) {
	OnUpdate();
	display();
	update();
}