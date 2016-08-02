#pragma once

#include "stdenum.h"
#include "Source Files/SignalType/SignalInit.h"

class SignalColor : public QObject, SignalInit
{
	Q_OBJECT
// CONSTRUCTOR
public:
	SignalColor(int r, int g, int b, int a = 255);
	~SignalColor() {}

// METHODS
public:
	inline sf::Color getColor() { return sf::Color(r, g, b, a); }
	inline int getR() { return r; }
	inline int getG() { return g; }
	inline int getB() { return b; }
	inline int getA() { return a; }
protected:
	void initSignals() override;

// SIGNALS SLOTS
	public slots:
		void setColor(sf::Color color);
		void setColor(int r, int g, int b, int a);
		void setR(int r);
		void setG(int g);
		void setB(int b);
		void setA(int a);
	signals:	
		void colorChanged(SignalColor*);
		void RChanged(int r);
		void GChanged(int g);
		void BChanged(int b);
		void AChanged(int a);

// MEMBERS
private:
	int r;
	int g;
	int b;
	int a;
};

