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
	void setX(double);
	void setY(double);
	void setFillColor(const char*);

	double getX() const;
	double getY() const;
	char* getFillColor() const;

	virtual void print() const = 0;
	virtual void loadDataFromFile(std::istream&) = 0;
	virtual void saveDataToFile(std::ostream&) const = 0;
	virtual bool withinRect(double, double, int, int) const = 0;
	virtual bool withinCircle(double, double, double) const = 0;
};
