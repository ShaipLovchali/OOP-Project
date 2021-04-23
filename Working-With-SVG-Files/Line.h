#pragma once
#include "Figure.h"

class Line : public Figure{
private:
	double x2, y2;

	void copy(const Line&);
	void erase();
public:
	Line();
	Line(double, double, double, double, const char*);
	Line(const Line&);
	Line& operator=(const Line&);
	~Line();

	void print() const;
};