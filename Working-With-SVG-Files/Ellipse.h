#pragma once
#include "Figure.h"

class Ellipse : public Figure{
private:
	double rx, ry;
public:
	Ellipse();
	Ellipse(double, double, double, double, const String&);

	void print() const;
	void loadDataFromFile(std::istream&);
	void saveDataToFile(std::ostream&) const;
	bool withinRect(double, double, double, double) const;
	bool withinCircle(double, double, double) const;
};