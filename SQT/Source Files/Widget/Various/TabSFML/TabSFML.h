#pragma once

#include "stdafx.h"
#include "Source Files/Widget/SQT/SQT.h"
#include "Source Files/Widget/Various/TabSFML/TabObject.h"

class TabSFML : public SQT
{
// CONSTRUCTOR
public:
	explicit TabSFML(QWidget* Parent, const QPoint& Position=QPoint(), const QSize& Size=QSize());
	virtual ~TabSFML() {}

// METHODS
	void add(TabObject* tab_object); //Add at the end of list
	void add(TabObject* tab_object, int index); //Insert at a specific index 
	void remove(TabObject* tab_object);
	void remove(int index);

// MEMBERS
private:
	std::vector<TabObject*> element_list;
	sf::View camera;
	int max_height = 0;
	int scroll_speed = 5;

	void reOrder();

	void OnUpdate() override;
	void mousePressEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;
};