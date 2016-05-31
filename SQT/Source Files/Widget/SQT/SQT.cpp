#include "Source Files/Widget/SQT/SQT.h"

#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif

#include <QtGui>
#include "Source Files/Application/IO/Input.h"

SQT::SQT(QWidget* Parent, const QPoint& Position, const QSize& Size) : QWidget(Parent)
{
    // Mise en place de quelques options pour autoriser le rendu direct dans le widget
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // Changement de la police de focus, pour autoriser notre widget à capter les évènements clavier
    setFocusPolicy(Qt::StrongFocus);

    // Définition de la position et de la taille du widget
    move(Position);
    resize(Size);

	myInitialized = false;
}

void SQT::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {
		#ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif
		
		sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
		setVerticalSyncEnabled(true);

        OnInit();
        myInitialized = true;
    }
}

QPaintEngine* SQT::paintEngine() const
{
    return 0;
}

void SQT::paintEvent(QPaintEvent*)
{
    OnUpdate();
	display();
	update();
}