#pragma once
#include <iostream>
#include <cstring>

class Figure {
protected:
	double x, y;
	char* fillColor;
public:
	Figure();
	Figure(double, double, const char*);
	void setFiguresData(double, double, const char*);

	virtual void print() const = 0;
};
