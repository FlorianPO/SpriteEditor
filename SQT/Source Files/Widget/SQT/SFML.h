#pragma once

#include "stdafx.h"
#include "Source Files/Widget/SQT/SQT.h"

class SFML : public SQT
{
public:
    SFML(QWidget* Parent, const QPoint& Position, const QSize& Size);

private:
	void OnInit() override;
	void OnUpdate() override;

	void keyPressEvent(QKeyEvent* Qk) override;
	void keyReleaseEvent(QKeyEvent* Qk) override;
	void mousePressEvent(QMouseEvent* Qm) override;
	void mouseReleaseEvent(QMouseEvent* Qm) override;
};