#pragma once
#include <iostream>
#include <cstring>

class Circle {
private:
	double cx, cy, r;
	char* fillColor;

	void copy(const Circle&);
	void erase();
public:
	Circle();
	Circle(double, double, double, const char*);
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	~Circle();

	void setCX(double);
	void setCY(double);
	void setR(double);
	void setFillColor(const char*);

	double getCX() const;
	double getCY() const;
	double getR() const;
	char* getFillColor() const;

	void print() const;
};