#pragma once
#define PUGIXML_HEADER_ONLY
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Vector.cpp"
#include "String.h"
#include "pugixml.cpp"
#include <fstream>

class ParseData {
private:
	Vector<Figure*> figures;
	pugi::xml_document doc;
	String getAttr;
	Vector<String> splitted;
public:
	int loadFile();
	void parseSvg();
	void split();
	char* toCharArr(const String&, size_t index);
	void printFigures() const;
};
