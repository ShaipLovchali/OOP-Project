#pragma once
#include <iostream>
#include <cstring>

class Figure {
protected:
	double x, y;
	char* fillColor;
public:
	Figure();
	Figure(double x, double y, const char* fillColor);
};
