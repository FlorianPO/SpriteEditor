#pragma once

#include "stdenum.h"

class SQT : public QWidget, public sf::RenderWindow
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SQT(QWidget *Parent, const QSize& Size=QSize(), bool auto_refresh=true);
	virtual ~SQT() {}

// METHODS
public:
	void refresh();
protected:
	void create();
private:
    virtual void OnUpdate() {}
    virtual QPaintEngine* paintEngine() const override;
    virtual void showEvent(QShowEvent*) override;
    virtual void paintEvent(QPaintEvent*) override;

// MEMBERS
private:
    bool initialized = false;
	bool auto_refresh = true;
};
