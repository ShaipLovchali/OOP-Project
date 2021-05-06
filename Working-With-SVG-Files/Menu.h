#pragma once
#include "ParseData.h"
#include "VectorOfFigures.h"

class Menu {
private:
	String command;
	Vector<String> splitted;

	void determineCommand(ParseData&, VectorOfFigures&);
	void splitCommand();
	char* toCharArr(const String&);
public:
	void start();
};





