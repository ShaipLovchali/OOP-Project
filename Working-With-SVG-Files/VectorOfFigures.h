#pragma once
#define PUGIXML_HEADER_ONLY
#include "pugixml.cpp"
#include <fstream>
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Vector.cpp"
#include "String.h"

class VectorOfFigures {
private:
	Vector<Figure*> figures;

	void addFigure(const Vector<String>&);
public:
	VectorOfFigures();

	void loadFromStream(const char*);
	void create(const Vector<String>&);
	void erase(int);
	void translateAll(double, double);
	void translate(int, double, double);
	void within(const Vector<String>&);

	size_t size() const;
	void clean();
	void printFigures() const;
	void saveFiguresToFile(const char*, std::ifstream&);
	void saveAsFiguresToFile(const char*, std::ifstream&);
};