#include "TabSFML.h"

#include "Source Files/Fonction/Fonction.h"
#include "TabObject.h"

TabSFML::TabSFML(QWidget* Parent, const QSize& Size) : SQT(Parent, Size) {
	camera.setSize(Size.width(), Size.height());
	camera.setCenter(Size.width() / 2.f, Size.height() / 2.f);

	setMouseTracking(true);
}

void TabSFML::OnUpdate() {
	setView(camera);
	clear(sf::Color::White);
	FOR_I (element_list.size())
		element_list[i]->draw(this);
}

void TabSFML::mouseMoveEvent(QMouseEvent* Qm) {
	if (!QWidget::hasFocus())
		setFocus();
	Qm->accept();
}

void TabSFML::mousePressEvent(QMouseEvent* Qm) {
	FOR_I (element_list.size())
		if (Fonction::mouseOnRect(element_list[i]->getBounds(), *this)) {
			element_list[i]->tabSelect();
			break;
		}
	Qm->accept();
}

void TabSFML::wheelEvent(QWheelEvent* Qw) {
	sf::Vector2f size = camera.getSize();
	sf::FloatRect canevas = sf::FloatRect(0, 0, size.x, max_height);

	if (canevas.height > size.y) {
		camera.move(0, -(Qw->delta() / 120)*scroll_speed);
		sf::Vector2f center = camera.getCenter();

		if (center.y < size.y / 2)
			camera.setCenter(center.x, size.y / 2);
		else if (center.y >= canevas.top + canevas.height - size.y / 2)
			camera.setCenter(camera.getCenter().x, canevas.top + canevas.height - size.y / 2);
	}
	Qw->accept();
}

void TabSFML::add(TabObject* tab_object) {
	element_list.push_back(tab_object);
	reOrder();
}

void TabSFML::add(TabObject* tab_object, int index) {
	element_list.insert(element_list.begin() + index, tab_object);
	reOrder();
}

void TabSFML::remove(TabObject* tab_object) {
	FOR_I (element_list.size())
		if (element_list[i] == tab_object) {
			element_list.erase(element_list.begin() + i);
			break;
		}
	reOrder();
}

void TabSFML::remove(int index) {
	element_list.erase(element_list.begin() + index);
}

void TabSFML::reOrder() {
	sf::Vector2f size = camera.getSize();

	int height = 2;
	int width = 2;
	int max_row_height = 0;

	FOR_I (element_list.size()-1) {
		element_list[i]->setPosition(width, height);

		sf::FloatRect bound = element_list[i]->getBounds();
		width += bound.width + 1;
		max_row_height = std::max<int>(max_row_height, bound.height);

		if (width + bound.width > size.x) {
			width = 2;
			height += max_row_height + 1;
			max_row_height = 0;
		}
	}
	LAST(element_list)->setPosition(width, height);
	max_height = height + 1 + LAST(element_list)->getBounds().height;
}