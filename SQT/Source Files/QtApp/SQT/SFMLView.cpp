#include "SFMLView.h"

#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Tool/ToolController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Background/Background.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Camera/CameraController.h"
#include "Source Files/Widget/Gui/Gui.h"
#include "Source Files/Application/Resource/ResourceController.h"
#include "Source Files/Application/Input/ShortcutController.h"
#include "Source Files/QtApp/QtApp.h"
#include "Source Files/Application/Queue/QueueController.h"

SFMLView* SFMLView::_t;

SFMLView::SFMLView(QWidget* parent) : SQT(parent, QSize()) {
	setMouseTracking(true);

	QUEUE->atStart([this]() {
		QObject::connect(GUI, SIGNAL(globallyChanged()), this, SLOT(findSpace()));
	});

	INIT_CAMERA_CONTROLLER

	INIT_COLOR_CONTROLLER
	INIT_TOOL_CONTROLLER
	INIT_LAYER_CONTROLLER
	INIT_BRUSH_CONTROLLER
	INIT_COPY_CONTROLLER

	INIT_SELECTION_CONTROLLER
	INIT_CURSEUR

	INIT_BACKGROUND
	INIT_APP(this);

	SHORTCUT_CONTROLLER->createCoreShortcut(nInt::keyCombinaison(Qt::Key_Tab, nInt::AGAIN), [this](){dealGui();});
}

void SFMLView::findSpace() {
	QSize size;
	if (GUI->isVisible()) {
		move(QPoint(GUI->width(), GUI->pos().y()));
		size = QSize(QTWINDOW->size().width() - GUI->width(), GUI->size().height());
	}
	else {
		move(QPoint(0, GUI->pos().y()));
		size = QSize(QTWINDOW->size().width(), GUI->size().height());
	}
	// Even size
	size.setWidth((size.width()/2)*2);
	size.setHeight((size.height()/2)*2);

	resize(size);
	create();
	if (LAYER != NULL)
		CAMERA->updateView();
}

///////////////
///////////////
///////////////
void SFMLView::dealGui() {
	if (QWidget::hasFocus())
		if (GUI->isVisible())
			GUI->hide();
		else
			GUI->show();
}

void SFMLView::execute() {
	APP->load(RES->directory + "test.png"); // START
}

void SFMLView::OnUpdate() {
	INPUT->gerer();
	if (QWidget::hasFocus())
		APP->run(); //Processing
	APP->display(); //Displaying
}

void SFMLView::mousePressEvent(QMouseEvent* Qm) {
	INPUT->registerPressed(Qm->button());
	Qm->accept();
}

void SFMLView::mouseReleaseEvent(QMouseEvent* Qm) {
	INPUT->registerReleased(Qm->button());
	Qm->accept();
}

void SFMLView::mouseMoveEvent(QMouseEvent* Qm) {
	if (!QWidget::hasFocus())
		setFocus();
	Qm->accept();
}

void SFMLView::wheelEvent(QWheelEvent* Qw) {
	QPoint numDegrees = Qw->angleDelta();
	if (!numDegrees.isNull()) {
		if (numDegrees.y() > 0)
			INPUT->registerWheelUp();
		else
			INPUT->registerWheelDown();
	}
	Qw->accept();
}