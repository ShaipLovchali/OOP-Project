#pragma once
#include "Figure.h"

class Rectangle : public Figure{
private:
	double width, height;

	void copy(const Rectangle&);
public:
	Rectangle();
	Rectangle(double, double, double, double, const char*);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);

	void print() const;
	void loadDataFromFile(std::istream&);
	void saveDataToFile(std::ostream&) const;
	bool withinRect(double, double, double, double) const;
	bool withinCircle(double, double, double) const;
};