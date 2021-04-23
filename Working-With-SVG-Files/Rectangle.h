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

	void print() const;
};