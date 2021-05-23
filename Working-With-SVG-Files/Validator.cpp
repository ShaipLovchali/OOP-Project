#include "Validator.h"

Validator::Validator(){}

Validator::Validator(const Vector<String>& other) : splitted(other){}

bool Validator::validateOpen(std::ifstream& in) const
{
	if (in.is_open()) {
		std::cout << "There is a currently loaded file" << std::endl;
		return false;
	}

	if (splitted.getCapacity() < 2) {
		std::cout << "You didnt enter a file name" << std::endl;
		return false;
	}
	char* fileName = splitted[1].getData();

	std::ifstream temp(fileName);
	if (!temp) {
		std::cout << "No such file existing" << std::endl;
		return false;
	}
	
	return true;
}

bool Validator::validateClose(std::ifstream& in, const char* currFileName) const
{
	if (splitted.getCapacity() < 2) {
		std::cout << "You didnt enter a file name" << std::endl;
		return false;
	}
	char* fileName = splitted[1].getData();

	if (strcmp(fileName, currFileName) != 0) {
		std::cout << fileName << " is not opened" << std::endl;
		return false;
	}

	return true;
}


bool Validator::validateCreate() const
{
	String figureType = splitted[1];
	if (figureType != "rect" && figureType != "circle" && figureType != "ellipse") {
		std::cout << "Invalid figure" << std::endl;
		return false;
	}
	if (figureType == "circle") {
		if (splitted.getCapacity() < 6) {
			std::cout << "Not valid circle data" << std::endl;
			return false;
		}
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber()) {
			std::cout << "Not valid circle data" << std::endl;
			return false;
		}
	}
	else {
		if (splitted.getCapacity() < 7) {
			std::cout << "Not valid data" << std::endl;
			return false;
		}
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber() || !splitted[5].isANumber()) {
			std::cout << "Not valid data" << std::endl;
			return false;
		}
	}
	return true;
}

bool Validator::validateIndex(size_t size) const
{
	if (splitted.getCapacity() < 2) {
		std::cout << "You didnt enterned a index" << std::endl;
		return false;
	}

	int index = splitted[1].stod();
	if (index <= 0 || index > size) {
		std::cout << "Invalid index of figure" << std::endl;
		return false;
	}
	return true;
}

bool Validator::validateTranslate(const String& vertical, const String& horizontal) const
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

bool Validator::validateWithin() const
{
	String figureType = splitted[1];
	if (figureType != "rect" && figureType != "circle") {
		std::cout << "Invalid figure" << std::endl;
		return false;
	}
	if (figureType == "circle") {
		if (splitted.getCapacity() < 5) {
			std::cout << "Not valid circle data" << std::endl;
			return false;
		}
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber()) {
			std::cout << "Not valid circle data" << std::endl;
			return false;
		}
	}
	else {
		if (splitted.getCapacity() < 6) {
			std::cout << "Not valid rectangle data" << std::endl;
			return false;
		}
		if (!splitted[2].isANumber() || !splitted[3].isANumber() || !splitted[4].isANumber() || !splitted[5].isANumber()) {
			std::cout << "Not valid rectangle data" << std::endl;
			return false;
		}
	}
	return true;
}
