#pragma once

#include "stdafx.h"
#include "ui_SQT.h"

class SQT : public QWidget, public sf::RenderWindow
{
	Q_OBJECT
public:
	explicit SQT(QWidget *Parent, const QPoint& Position=QPoint(), const QSize& Size=QSize());
	virtual ~SQT() {}

	signals:
	public slots:

private:
    virtual void OnInit() {}
    virtual void OnUpdate() {}
    virtual QPaintEngine* paintEngine() const override;
    virtual void showEvent(QShowEvent*) override;
    virtual void paintEvent(QPaintEvent*) override;

    bool myInitialized;
};
