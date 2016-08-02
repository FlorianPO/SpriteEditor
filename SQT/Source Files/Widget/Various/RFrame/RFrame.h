#pragma once

#include "stdenum.h"

class RFrame : public QWidget
{
	Q_OBJECT
// CONSTRUCTOR
public:
	RFrame(QWidget *parent);
	~RFrame() {}

// METHODS
public:
	void setFrameGeometry(const QPoint& pos, const QSize& size);
	QFrame* getFrame() { return frame; }

private:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void moveEvent(QMoveEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

// MEMBERS
private:
	QFrame* frame=NULL;
	QPoint dragStartPosition;
	QRect dragStartGeometry;

	bool focusing = false;
	const int grab_space = 8;
	const int min_height = 5;
};

