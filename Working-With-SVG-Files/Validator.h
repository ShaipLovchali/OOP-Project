#pragma once
#include "VectorOfFigures.h"
#include "Vector.cpp"
#include "String.h"

class Validator {
private:
	Vector<String> splitted;
public:
	Validator();
	Validator(const Vector<String>&);

	bool validateOpen(std::ifstream&, const char*);
	bool validateCreate();
	bool validateIndex(size_t size);
	bool validateTranslate(const String&, const String&);
};