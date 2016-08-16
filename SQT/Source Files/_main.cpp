#include "Source Files/QtApp/QtApp.h"
#include "Source Files/QtApp/SQT/SFMLView.h"
#include "Source Files/Widget/Gui/Gui.h"
#include "Source Files/Application/Queue/QueueController.h"

int main(int argc, char **argv) {
	QTAPP_CREATE(argc, argv, "SFMLView Qt");

	INIT_GUI(QTWINDOW);
	INIT_SFML(QTWINDOW);

	GUI->show();
	SFML->show();

	QTWINDOW->resize(QSize(1200, 700));

	GUI->findSpace();
	SFML->findSpace();

	QUEUE->updateAtStart();
	SFML->setFocus();
	SFML->execute();
	return QTAPP->exec();
}
