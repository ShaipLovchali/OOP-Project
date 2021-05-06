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

	void print() const override;
	void loadDataFromFile(std::istream&) override;
};