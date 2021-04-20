#pragma once
#include <iostream>
#include <cstring>

class Line {
private:
	double x1, y1, x2, y2;
	char* fillColor;

	void copy(const Line&);
	void erase();
public:
	Line();
	Line(double, double, double, double, const char*);
	Line(const Line&);
	Line& operator=(const Line&);
	~Line();

	void setX1(double);
	void setY1(double);
	void setX2(double);
	void setY2(double);
	void setFillColor(const char*);

	void print() const;
};