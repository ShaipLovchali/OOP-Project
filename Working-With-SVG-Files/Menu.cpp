#pragma once
#include "Menu.h"

void Menu::start()
{
	ParseData parser;
	parser.parseSvg();

	VectorOfFigures v;
	v.loadFromStream();

	std::ifstream f;
	do {
		std::cout << "Please, enter a command: ";
		std::cin >> command;
		splitCommand();

		determineCommand(parser, v, f, currentFileName);
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
			subStr.clear();
			continue;
		}
		subStr.pushBack(command[i]);
	}
	
	splitted.push_back(subStr);
}

void Menu::determineCommand(ParseData& parser, VectorOfFigures& v, std::ifstream &in, String& currFileName)
{
	if (splitted[0] == "open") {
		char* fileName = splitted[1].getData();
		if (in.is_open()) {
			std::cout << "There is a currently loaded file" << std::endl;
		}
		else {
			in.open(fileName);
			currentFileName = splitted[1];
			if (!in) {
				std::cout << "No such file existing" << std::endl;
			}
			else {
				std::cout << "Successfully opened file" << std::endl;
			}
		}
	}
	else {
		if (splitted[0] == "exit") {
			std::cout << "Exiting the program.." << std::endl;
		}else {
			if (!in.is_open()) {
				std::cout << "There is not an open file" << std::endl;
			}
			else {
				if (splitted[0] == "close") {
					in.close();
					std::cout << "Closed file.. " << std::endl;
				}
				else if (splitted[0] == "save") {
					v.saveFiguresToFile(currentFileName.getData(), in);
					std::cout << "Saved file.. " << std::endl;
				}
				else if (splitted[0] == "saveas") {
					char* fileName = splitted[1].getData();
					v.saveAsFiguresToFile(fileName, in);
					std::cout << "Saved file in .. " << std::endl;
				}
				else if (splitted[0] == "help") {
					std::cout << "The following commands are supported:" << std::endl;
					std::cout << " open <file> - opens <file>" << std::endl;
					std::cout << " close closes currently opened file" << std::endl;
					std::cout << " save saves the currently open file" << std::endl;
					std::cout << " saveas <file> saves the currently open file in <file>" << std::endl;
					std::cout << " help prints this information" << std::endl;
					std::cout << " exit exists the program" << std::endl;
				}
				else if (splitted[0] == "print") {
					v.printFigures();
				}
				else if (splitted[0] == "create") {
					v.create(splitted);
				}
				else if (splitted[0] == "erase") {
					int index = splitted[1].stod();
					v.erase(index);
				}
				else if (splitted[0] == "translate") {
					double vertical;
					double horizontal;

					if (splitted[1].find("vertical") != -1) {
						vertical = splitted[1].getValue('=').stod();
						horizontal = splitted[2].getValue('=').stod();
						v.translateAll(vertical, horizontal);
					}
					else {
						int index = splitted[1].stod();
						vertical = splitted[2].getValue('=').stod();
						horizontal = splitted[3].getValue('=').stod();
						v.translate(index, vertical, horizontal);
					}
				}
				else if (splitted[0] == "within") {
					v.within(splitted);
				}
				else {
					std::cout << "You have enterned an invalid command!" << std::endl;
				}
			}
		}
	}
}




