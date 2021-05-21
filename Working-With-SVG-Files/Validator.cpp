#include "Validator.h"

Validator::Validator(){}

Validator::Validator(const Vector<String>& other) : splitted(other){}

bool Validator::validateOpen(std::ifstream& in, const char* fileName)
{
	if (in.is_open()) {
		std::cout << "There is a currently loaded file" << std::endl;
		return false;
	}else {
		std::ifstream temp(fileName);
		if (!temp) {
			std::cout << "No such file existing" << std::endl;
			return false;
		}
	}
	return true;
}

bool Validator::validateCreate()
{
	String figureType = splitted[1];
	if (figureType != "rect" && figureType != "circle" && figureType != "ellipse") {
		std::cout << "Invalid figure" << std::endl;
		return false;
	}
	if (figureType == "circle") {
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber()) {
			std::cout << "Not valid circle data" << std::endl;
			return false;
		}
	}
	else {
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber() || !splitted[5].isANumber()) {
			std::cout << "Not valid data" << std::endl;
			return false;
		}
	}
	return true;
}

bool Validator::validateIndex(size_t size)
{
	int index = splitted[1].stod();
	if (index <= 0 || index > size) {
		std::cout << "Invalid index of figure" << std::endl;
		return false;
	}
	return true;
}

bool Validator::validateTranslate(const String& vertical, const String& horizontal)
{
	if (vertical.find("vertical") == -1 || vertical.find("=") == -1 || !vertical.getValue('=').isANumber()) {
		std::cout << "Your input for vertical translation is not valid" << std::endl;
		return false;
	}
	if (horizontal.find("horizontal") == -1 || horizontal.find("=") == -1 || !horizontal.getValue('=').isANumber()) {
		std::cout << "Your input for horizontal translation is not valid" << std::endl;
		return false;
	}

	return true;
}
