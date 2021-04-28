#pragma once
#include "Menu.h"

void Menu::start()
{
	do {
		std::cout << "Please, enter a command: ";
		std::cin >> command;
		splitCommand();

		determineCommand();	
	} while (splitted[0] != "exit");
}

void Menu::splitCommand()
{
	splitted.clear();
	String subStr;
	for (size_t i = 0; command[i]; ++i)
	{
		if (command[i] == ' ') {
			splitted.push_back(subStr);
			subStr = "";
			continue;
		}
		subStr.pushBack(command[i]);
	}
	
	splitted.push_back(subStr);
}

char* Menu::toCharArr(const String& str)
{
	char* fillColor = new char[str.getSize() + 1];
	for (size_t i = 0; i < str.getSize(); i++)
	{
		fillColor[i] = str[i];
	}
	fillColor[str.getSize()] = '\0';

	return fillColor;
}

void Menu::determineCommand()
{
	if (splitted[0] == "open") {
		//char* fileName = toCharArr(splitted[1]);
		ParseData input;
		if (input.loadFile() != -1) {
			std::cout << "Successfully opened file" << std::endl;
		}
	}
	else if (splitted[0] == "close") {
		std::cout << "Closed file.. " << std::endl;
	}
	else if (splitted[0] == "save") {
		std::cout << "Saved file.. " << std::endl;
	}
	else if (splitted[0] == "saveas") {
		std::cout << "Saved file in .. " << std::endl;
	}
	else if (splitted[0] == "help") {
		std::cout << "help.. " << std::endl;
	}
	else if (splitted[0] == "print") {
		ParseData parser;
		parser.parseSvg();
		parser.printFigures();
	}
	else if (splitted[0] == "create") {
		std::cout << "Created.. " << std::endl;
	}
	else if (splitted[0] == "erase") {
		std::cout << "Erased.. " << std::endl;
	}
	else if (splitted[0] == "translate") {
		std::cout << "Translated.. " << std::endl;
	}
	else if (splitted[0] == "within") {
		std::cout << "Within.. " << std::endl;
	}
	else if (splitted[0] == "exit") {
		std::cout << "Exiting the program.." << std::endl;
	}
	else {
		std::cout << "You have enterned an invalid command!" << std::endl;
	}
}


