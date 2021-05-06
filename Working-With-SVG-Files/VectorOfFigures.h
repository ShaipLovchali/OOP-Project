#pragma once
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Vector.cpp"
#include <fstream>

class VectorOfFigures {
private:
	Vector<Figure*> figures;
public:
	VectorOfFigures();
	void loadFromStream();
	Figure* getFigureType(const char*);
	void create(Figure*);
	void erase(size_t n);
	size_t size() const;
	void printFigures() const;
};