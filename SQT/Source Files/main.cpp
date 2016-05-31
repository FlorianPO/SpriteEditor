#include "Source Files/Widget/SQT/SQT.h"
#include "Source Files/Widget/SQT/SFML.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QSplitter>
#include <QPainter>
#include "ui_SQT.h"
#include "Source Files/Widget/Gui/w_Gui.h"

#include "Source Files/Widget/MainWindow/MainQt.h"

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);
	QTCREATE("SFML Qt");

	//Ui_SQTClass* m = new Ui_SQTClass;
    //m->setupUi(MainFrame);
	SFML* SFMLView = new SFML(QTWINDOW, QPoint(150, 0), QSize(800, 600));
	w_Gui* b = new w_Gui(QTWINDOW);
	SFMLView->show();

    return App.exec();
}
