#pragma once

#include "stdenum.h"
#include "Source Files/QtApp/SQT/SQT.h"

#define INIT_SFML SFMLView::createInstance
#define SFML SFMLView::getInstance()

class SFMLView : public SQT
{
	Q_OBJECT
// INSTANCE
private:	static SFMLView* _t;
public:		inline static void createInstance(QWidget* p) { _t = new SFMLView(p); }
			inline static SFMLView* getInstance() { return _t; }
// CONSTRUCTOR
public:
    SFMLView(QWidget* parent);
	~SFMLView() {}

// SIGNALS SLOTS
	public slots:
		void findSpace();
	private slots:
		void dealGui();

// METHODS
public:
	void execute();
private:
	void OnUpdate() override;

	void mousePressEvent(QMouseEvent* Qm) override;
	void mouseReleaseEvent(QMouseEvent* Qm) override;
	void mouseMoveEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;
};