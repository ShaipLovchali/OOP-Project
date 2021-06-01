#pragma once
#include <iostream>
#include <cstring>
#include "String.h"

class Figure {
protected:
	double x, y;
	String fillColor;

public:
	Figure();
	Figure(double, double, const String&);

	void setX(double);
	void setY(double);
	void setFillColor(const String&);

	double getX() const;
	double getY() const;
	String getFillColor() const;

	virtual void print() const = 0;
	virtual void loadDataFromFile(std::istream&) = 0;
	virtual void saveDataToFile(std::ostream&) const = 0;
	virtual bool withinRect(double, double, double, double) const = 0;
	virtual bool withinCircle(double, double, double) const = 0;
};
