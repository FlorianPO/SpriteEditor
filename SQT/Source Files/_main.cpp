#include "Source Files/QtApp/QtApp.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Widget/Gui/Gui.h"

int main(int argc, char **argv) {
	QTAPP_CREATE(argc, argv, "SFMLView Qt");

	INIT_SFML(QTWINDOW);
	SFML->show();
	INIT_GUI(QTWINDOW);
	GUI->show();

	SFML->move(QPoint(GUI->width(), 0));
	GUI->move(QPoint(0, 0));

	QTWINDOW->resize(QSize(1200, 700));

	SFML->setFocus();
	SFML->execute();
	return QTAPP->exec();
}
