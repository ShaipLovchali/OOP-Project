#pragma once
#include "Figure.h"

class Rectangle : public Figure{
private:
	int width, height;

	void copy(const Rectangle&);
	void erase();
public:
	Rectangle();
	Rectangle(double, double, int, int, const char*);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	~Rectangle();

	void print() const override;
	void loadDataFromFile(std::istream&) override;
	void saveDataToFile(std::ostream&) override;
	bool withinRect(double, double, int, int);
	bool withinCircle(double, double, double);
	bool withinEllipse(double, double, double, double);
};