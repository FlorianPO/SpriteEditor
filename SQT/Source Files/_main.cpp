#include "Source Files/QtApp/QtApp.h"
#include "Source Files/Widget/SQT/SFMLView.h"
#include "Source Files/Widget/Menu/Menu.h"
#include "Source Files/Widget/Gui/Gui.h"
#include "Source Files/Application/Queue/QueueController.h"

int main(int argc, char **argv) {
	QTAPP_CREATE(argc, argv, "SFMLView Qt");
	QTAPP_INIT;
	
	MENU->show();
	GUI->show();
	SFML->show();

	QTWINDOW->resize(QSize(1200, 700));

	QUEUE->updateAtStart();
	SFML->setFocus();
	SFML->execute();
	return QTAPP->exec();
}
