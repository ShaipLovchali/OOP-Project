#pragma once
#include "ParseData.h"
#include "String.h"
#include "VectorOfFigures.h"

class Menu {
private:
	String currentFileName;
	String command;
	Vector<String> splitted;

	void determineCommand(ParseData&, VectorOfFigures&, std::ifstream&, String&);
	void splitCommand();
public:
	void start();
};





