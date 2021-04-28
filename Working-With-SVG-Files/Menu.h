#pragma once
#include "ParseData.h"

class Menu {
private:
	String command;
	Vector<String> splitted;

	void determineCommand();
	void splitCommand();
	char* toCharArr(const String&);
public:
	void start();
};





