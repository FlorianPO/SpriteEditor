#pragma once

#include "stdenum.h"

class SQT : public QWidget, public sf::RenderWindow
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SQT(QWidget* parent, bool auto_refresh=true);
	virtual ~SQT() {}

// METHODS
protected:
	void create();
    virtual void OnUpdate() {}
    QPaintEngine* paintEngine() const override;
    void showEvent(QShowEvent* qs) override;
    void paintEvent(QPaintEvent* qp) override;
	void moveEvent(QMoveEvent* qm) override;
	void resizeEvent(QResizeEvent* qr) override;

// SIGNAL SLOTS
	public slots:
		void refresh();
		void refreshOnce();

// MEMBERS
private:
    bool initialized = false;
	bool auto_refresh = true;
	bool refresh_once = false;
};
