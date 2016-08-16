#include "SignalColor.h"

#include "Source Files/Application/Queue/QueueCOntroller.h"

SignalColor::SignalColor(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	QUEUE->beforeDisplay([=]() {
		emit colorChanged();
		emit RChanged(this->r);
		emit GChanged(this->g);
		emit BChanged(this->b);
		emit AChanged(this->a);
	});
}

void SignalColor::setColor(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	emit colorChanged();
	emit RChanged(this->r);
	emit GChanged(this->g);
	emit BChanged(this->b);
	emit AChanged(this->a);
}

void SignalColor::setColor(sf::Color color) {
	setColor(color.r, color.g, color.b, color.a);
}

void SignalColor::setR(int r) {
	this->r = static_cast<sf::Uint8>(r);
	emit RChanged(this->r);
	emit colorChanged();
}

void SignalColor::setG(int g) {
	this->g = static_cast<sf::Uint8>(g);
	emit GChanged(this->g);
	emit colorChanged();
}

void SignalColor::setB(int b) {
	this->b = static_cast<sf::Uint8>(b);
	emit BChanged(this->b);
	emit colorChanged();
}

void SignalColor::setA(int a) {
	this->a = static_cast<sf::Uint8>(a);
	emit AChanged(this->a);
	emit colorChanged();
}