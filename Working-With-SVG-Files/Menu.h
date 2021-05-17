#pragma once
#include "ParseData.h"
#include "String.h"
#include "VectorOfFigures.h"

class Menu {
private:
	String command;
	Vector<String> splitted;

	void determineCommand(ParseData&, VectorOfFigures&);
	void splitCommand();
public:
	void start();
};





