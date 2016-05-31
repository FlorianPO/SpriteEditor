#include "Source Files/Widget/MainWindow/MainQt.h"

MainQt* MainQt::_t;

MainQt::MainQt(QString name) {
	MainFrame = new QMainWindow();
    MainFrame->setWindowTitle(name);
    MainFrame->show();
	MainFrame->setMouseTracking(true);
}
