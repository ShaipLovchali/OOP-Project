#pragma once
#include "Figure.h"

class Circle : public Figure{
private:
	double r;

	void copy(const Circle&);
	void erase();
public:
	Circle();
	Circle(double, double, double, const char*);
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	~Circle();

	void print() const;
	void loadDataFromFile(std::istream&);
	void saveDataToFile(std::ostream&) const;
	bool withinRect(double, double, int, int) const;
	bool withinCircle(double, double, double) const;
};