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

		Validator validator(splitted);
		determineCommand(v, f, currentFileName, validator);
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

void Menu::commandOpen(std::ifstream& in, Validator& validator) {
	char* fileName = splitted[1].getData();
	bool isValid = validator.validateOpen(in, fileName);

	if (isValid) {
		in.open(fileName);
		currentFileName = splitted[1];
		std::cout << "Successfully opened " << std::endl;
	}
}

void Menu::commandClose(std::ifstream& in)
{
	in.close();
	std::cout << "Successfully closed " << currentFileName << std::endl;
}

void Menu::commandSave(VectorOfFigures& v, std::ifstream& in)
{
	v.saveFiguresToFile(currentFileName.getData(), in);
	std::cout << "Successfully saved " << currentFileName << std::endl;
}

void Menu::commandSaveAs(VectorOfFigures& v, std::ifstream& in)
{
	char* fileName = splitted[1].getData();
	v.saveAsFiguresToFile(fileName, in);
	std::cout << "Successfully saved " << currentFileName << " in the path" << std::endl;
}

void Menu::commandHelp()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << " open <file> - opens <file>" << std::endl;
	std::cout << " close closes currently opened file" << std::endl;
	std::cout << " save saves the currently open file" << std::endl;
	std::cout << " saveas <file> saves the currently open file in <file>" << std::endl;
	std::cout << " help prints this information" << std::endl;
	std::cout << " exit exists the program" << std::endl;
}

void Menu::commandCreate(VectorOfFigures& v, Validator& validator)
{
	bool isValid = validator.validateCreate();
	if (isValid) {
		v.create(splitted);
	}
}

void Menu::commandErase(VectorOfFigures& v, Validator& validator)
{
	int index = splitted[1].stod();
	bool isValid = validator.validateIndex(v.size());
	if (isValid) {
		v.erase(index);
	}
}

void Menu::commandTranslate(VectorOfFigures& v, Validator& validator)
{
	double vertical;
	double horizontal;

	if (splitted[1].find("vertical") != -1) {
		bool isInputValid = validator.validateTranslate(splitted[1], splitted[2]);

		if (isInputValid) {
			vertical = splitted[1].getValue('=').stod();
			horizontal = splitted[2].getValue('=').stod();
			v.translateAll(vertical, horizontal);
		}
	}
	else {
		int index = splitted[1].stod();
		bool isIndexValid = validator.validateIndex(v.size());
		bool isInputValid = validator.validateTranslate(splitted[2], splitted[3]);

		if (isIndexValid && isInputValid) {
			vertical = splitted[2].getValue('=').stod();
			horizontal = splitted[3].getValue('=').stod();
			v.translate(index, vertical, horizontal);
		}
	}
}

void Menu::determineCommand(VectorOfFigures& v, std::ifstream &in, String& currFileName, Validator& validator)
{
	if (splitted[0] == "open") {
		commandOpen(in, validator);
	}
	else {
		if (splitted[0] == "exit") {
			std::cout << "Exiting the program..." << std::endl;
		}else {
			if (!in.is_open()) {
				std::cout << "There is not an open file" << std::endl;
			}
			else {
				if (splitted[0] == "close") {
					commandClose(in);
				}
				else if (splitted[0] == "save") {
					commandSave(v, in);
				}
				else if (splitted[0] == "saveas") {
					commandSaveAs(v, in);
				}
				else if (splitted[0] == "help") {
					commandHelp();
				}
				else if (splitted[0] == "print") {
					v.printFigures();
				}
				else if (splitted[0] == "create") {
					commandCreate(v, validator);
				}
				else if (splitted[0] == "erase") {
					commandErase(v, validator);
				}
				else if (splitted[0] == "translate") {
					commandTranslate(v, validator);
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




