#include "OpenAction.h"

#include "Source Files/Application/App.h"
#include "Source Files/Application/Input/InputController.h"

OpenAction::OpenAction() : QAction("Ouvrir...", NULL) {
	QObject::connect(this, SIGNAL(triggered()), this, SLOT(open()));

	setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
}

void OpenAction::open() {
	QString fileName = QFileDialog::getOpenFileName(NULL, "Ouvrir une image...", QString::fromStdString(APP->getPath().toAnsiString()), "Fichier image (*.png *.jpg *.bmp)");
	INPUT->reset();
	if (fileName != QString())
		APP->load(fileName.toStdString());
}

OpenActionAsLayer::OpenActionAsLayer() : QAction("Ouvrir en tant que calque...", NULL) {
	QObject::connect(this, SIGNAL(triggered()), this, SLOT(open_as_layer()));

	setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_O));
}

void OpenActionAsLayer::open_as_layer() {
	QString fileName = QFileDialog::getOpenFileName(NULL, "Ouvrir une image en tant que calque...", QString::fromStdString(APP->getPath().toAnsiString()), "Fichier image (*.png *.jpg *.bmp)");
	INPUT->reset();
	if (fileName != QString())
		APP->loadAsLayer(fileName.toStdString());
}