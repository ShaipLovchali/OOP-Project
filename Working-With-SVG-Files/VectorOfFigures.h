#pragma once
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Vector.cpp"
#include "String.h"
#include <fstream>

class VectorOfFigures {
private:
	Vector<Figure*> figures;
public:
	VectorOfFigures();
	void loadFromStream();
	Figure* getFigureType(const char*);
	void create(Figure*);
	void erase(size_t);
	void translateAll(double, double);
	void translate(size_t, double, double);

	size_t size() const;
	void printFigures() const;
	void saveFiguresToFile(const char*, std::ifstream&);
	void saveAsFiguresToFile(const char*, std::ifstream&);
};