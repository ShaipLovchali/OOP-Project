#pragma once
#include "Figure.h"

class Ellipse : public Figure{
private:
	double rx, ry;

	void copy(const Ellipse&);
	void erase();
public:
	Ellipse();
	Ellipse(double, double, double, double, const char*);
	Ellipse(const Ellipse&);
	Ellipse& operator=(const Ellipse&);
	~Ellipse();

	void print() const;
	void loadDataFromFile(std::istream&);
	void saveDataToFile(std::ostream&) const;
	bool withinRect(double, double, double, double) const;
	bool withinCircle(double, double, double) const;
};