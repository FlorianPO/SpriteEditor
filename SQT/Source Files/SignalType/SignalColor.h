#pragma once

#include "stdenum.h"

class SignalColor : public QObject
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SignalColor(int r, int g, int b, int a = 255);
	~SignalColor() {}

// METHODS
public:
	inline sf::Color getColor() const { return sf::Color(r, g, b, a); }
	inline int getR() const { return r; }
	inline int getG() const { return g; }
	inline int getB() const { return b; }
	inline int getA() const { return a; }

// SIGNALS SLOTS
	public slots:
		void setColor(const sf::Color& color);
		void setColor(int r, int g, int b, int a);
		void setR(int r);
		void setG(int g);
		void setB(int b);
		void setA(int a);
	signals:	
		void colorChanged() const;
		void RChanged(int r) const;
		void GChanged(int g) const;
		void BChanged(int b) const;
		void AChanged(int a) const;

// MEMBERS
private:
	int r;
	int g;
	int b;
	int a;
};

