#pragma once

#include "stdenum.h"
#include "Source Files/Widget/SQT/SQT.h"

#define INIT_SFML SFMLView::createInstance
#define SFML SFMLView::getInstance()

class SFMLView : public SQT
{
// INSTANCE
private:	static SFMLView* _t;
public:		inline static void createInstance(QWidget* p) { _t = new SFMLView(p); }
			inline static SFMLView* getInstance() { return _t; }
// CONSTRUCTOR
public:
    SFMLView(QWidget* parent);
	~SFMLView() {}

// METHODS
public:
	void execute();
private:
	bool eventFilter(QObject *object, QEvent *event) override;
	void OnUpdate() override;

	void mousePressEvent(QMouseEvent* Qm) override;
	void mouseReleaseEvent(QMouseEvent* Qm) override;
	void mouseMoveEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;
};