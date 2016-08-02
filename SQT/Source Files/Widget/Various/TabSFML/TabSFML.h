#pragma once

#include "stdenum.h"
#include "Source Files/Widget/SQT/SQT.h"
class TabObject; // Foward declaration

class TabSFML : public SQT
{
// CONSTRUCTOR
public:
	TabSFML(QWidget* Parent, const QSize& Size=QSize());
	~TabSFML() {}

// METHODS
public:
	void add(TabObject* tab_object); //Add at the end of list
	void add(TabObject* tab_object, int index); //Insert at a specific index 
	void remove(TabObject* tab_object);
	void remove(int index);
private:
	void reOrder();
	void OnUpdate() override;
	void mousePressEvent(QMouseEvent* Qm) override;
	void wheelEvent(QWheelEvent* Qw) override;

// MEMBERS
private:
	std::vector<TabObject*> element_list;
	sf::View camera;
	int max_height = 0;
	int scroll_speed = 5;
};