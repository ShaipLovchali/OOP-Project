#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

class Menu {
private:
	std::string command;
	std::vector<std::string> splitted;

	void determineCommand();
	void splitCommand();
public:
	void start();
};





