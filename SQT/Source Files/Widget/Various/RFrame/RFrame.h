#pragma once

#include "stdafx.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>

class RFrame : public QWidget
{
	Q_OBJECT
public:
	explicit RFrame(QWidget *parent, const QPoint& position=QPoint(), const QSize& size=QSize());
	~RFrame() {}

	void setFrameGeometry(const QPoint& pos, const QSize& size);

	QFrame* getFrame() { return frame; }
	int getBottomY() { return geometry().height() + geometry().y();}

private:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void moveEvent(QMoveEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

	QFrame* frame=NULL;
	QPoint dragStartPosition;
	QRect dragStartGeometry;

	bool focusing = false;
	const int grab_space = 8;
	const int min_height = 5;
};

