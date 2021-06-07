#pragma once
#include "VectorOfFigures.h"

class Validator {
private:
	Vector<String> splitted;
public:
	Validator();
	Validator(const Vector<String>&);

	bool validateOpen(std::ifstream&) const;
	bool validateClose() const;
	bool validateSave() const;
	bool validateSaveAs() const;
	bool validateHelp() const;
	bool validateCreate() const;
	bool validateIndex(size_t size) const;
	bool validatePrint() const;
	bool validateTranslate(const String&, const String&) const;
	bool validateWithin() const;
};