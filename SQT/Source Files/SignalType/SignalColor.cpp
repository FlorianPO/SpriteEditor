#include "Source Files/SignalType/SignalColor.h"

SignalColor::SignalColor(int r, int g, int b, int a) : QObject(), SignalController() {
	this->r = static_cast<sf::Uint8>(r);
	this->g = static_cast<sf::Uint8>(g);
	this->b = static_cast<sf::Uint8>(b);
	this->a = static_cast<sf::Uint8>(a);
}

void SignalColor::setColor(int r, int g, int b, int a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	initSignals();
}

void SignalColor::setColor(sf::Color color) {
	setColor(color.r, color.b, color.g, color.a);
}

void SignalColor::setR(int r) {
	this->r = static_cast<sf::Uint8>(r);
	emit RChanged(this->r);
	emit colorChanged(this);
}

void SignalColor::setG(int g) {
	this->g = static_cast<sf::Uint8>(g);
	emit GChanged(this->g);
	emit colorChanged(this);
}

void SignalColor::setB(int b) {
	this->b = static_cast<sf::Uint8>(b);
	emit BChanged(this->b);
	emit colorChanged(this);
}

void SignalColor::setA(int a) {
	this->a = static_cast<sf::Uint8>(a);
	emit AChanged(this->a);
	emit colorChanged(this);
}

void SignalColor::initSignals() {
	emit colorChanged(this);
	emit RChanged(this->r);
	emit GChanged(this->g);
	emit BChanged(this->b);
	emit AChanged(this->a);
}