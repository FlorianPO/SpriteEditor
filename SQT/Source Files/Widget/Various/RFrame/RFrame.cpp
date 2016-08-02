#include "RFrame.h"

RFrame::RFrame(QWidget *parent) : QWidget(parent)
{
	setMouseTracking(true);
	show();

	frame = new QFrame(parent);
	frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Raised);
	frame->show();
}

void RFrame::setFrameGeometry(const QPoint& pos, const QSize& size) {
	setGeometry(QRect(pos, QSize(size.width(), size.height()+grab_space)));
}

void RFrame::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		dragStartPosition = event->pos();
		dragStartGeometry = geometry();
		focusing = true;
	}
	event->accept();
}

void RFrame::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton)
		focusing = false;
	event->accept();
}

void RFrame::moveEvent(QMoveEvent* event) {
	if (frame != NULL)
		frame->setGeometry(QRect(event->pos(), QSize(size().width(), size().height()-grab_space)));
}

void RFrame::resizeEvent(QResizeEvent* event) {
	if (frame != NULL)
		frame->setGeometry(QRect(pos(), QSize(event->size().width(), event->size().height()-grab_space)));
}

void RFrame::mouseMoveEvent(QMouseEvent* event)  {
	if (!focusing)
		setCursor(Qt::SizeVerCursor);
	else {
		int y;
		if (event->y() > min_height+grab_space)
			y = event->y();
		else
			y = min_height+grab_space;
		setGeometry(QRect(
					QPoint(dragStartGeometry.left(), dragStartGeometry.top()),
					QSize(width(), y)));
	}
	event->accept();
}

/*
bool LayerPanel::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::Resize) {
		QResizeEvent* resize_event = static_cast<QResizeEvent*>(event);

		int YBottom = pos().y() + resize_event->size().height() + ui.Layer_frame->pos().y();
		int YBottomMain = QTWINDOW->size().height()-3;

		if (YBottom > YBottomMain) {
			setGeometry(QRect(pos(), 
			QSize(
				resize_event->size().width(), 
				YBottomMain - pos().y())));
			return true;
		}		
		else
			setGeometry(QRect(pos(), 
			QSize(
				resize_event->size().width(), 
				resize_event->size().height()+ui.Layer_frame->pos().y())));
	}
    return false;
}
*/