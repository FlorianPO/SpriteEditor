#include "SFMLView.h"

#include "Source Files/Application/Queue/QueueController.h"
#include "Source Files/Application/UndoStack/UndoStack.h"
#include "Source Files/Application/Selection/SelectionController.h"
#include "Source Files/Application/Curseur/Curseur.h"
#include "Source Files/Application/Brush/BrushController.h"
#include "Source Files/Application/Copy/CopyController.h"
#include "Source Files/Application/Layer/LayerController.h"
#include "Source Files/Application/Tool/ToolController.h"
#include "Source Files/Application/Color/ColorController.h"
#include "Source Files/Application/App.h"
#include "Source Files/Application/Input/InputController.h"
#include "Source Files/Application/Camera/CameraController.h"
#include "Source Files/Widget/Gui/Gui.h"

SFMLView* SFMLView::_t;

SFMLView::SFMLView(QWidget* parent) : SQT(parent, QSize()) {
	parent->installEventFilter(this);
	setMouseTracking(true);

	INIT_QUEUE_CONTROLLER
	INIT_UNDO_STACK
	INIT_CAMERA_CONTROLLER

	INIT_COLOR_CONTROLLER
	INIT_TOOL_CONTROLLER
	INIT_LAYER_CONTROLLER
	INIT_BRUSH_CONTROLLER
	INIT_COPY_CONTROLLER

	INIT_SELECTION_CONTROLLER
	INIT_CURSEUR

	INIT_APP(this);
}

void SFMLView::execute() {
	APP->loadFromPath("test.png"); // START
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

bool SFMLView::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::Resize) {
        QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
        QSize availableSize = QSize((resizeEvent->size().width() - GUI->width())/2*2, 
									(resizeEvent->size().height())/2*2);
		resize(availableSize);
		create();
		if (LAYER != NULL)
			CAMERA->centerOnLayer();
    }
    return false;
}