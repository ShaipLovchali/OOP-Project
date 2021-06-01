#pragma once
#include "Figure.h"

class Circle : public Figure{
private:
	double r;
public:
	Circle();
	Circle(double, double, double, const String&);
	
	void print() const;
	void loadDataFromFile(std::istream&);
	void saveDataToFile(std::ostream&) const;
	bool withinRect(double, double, double, double) const;
	bool withinCircle(double, double, double) const;
};