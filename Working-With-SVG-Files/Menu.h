#pragma once
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

class Menu {
private:
	std::string command;
	std::vector<std::string> splitted;
public:
	void start();
	void splitCommand();
};





