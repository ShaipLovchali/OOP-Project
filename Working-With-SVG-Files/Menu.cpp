#include "Menu.h"

void Menu::start()
{
	VectorOfFigures v;

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

void Menu::commandOpen(VectorOfFigures& v, std::ifstream& in, const Validator& validator) {
	bool isValid = validator.validateOpen(in);

	if (isValid) {
		char* fileName = splitted[1].getData();
		in.open(fileName);

		v.loadFromFile(fileName);

		currentFileName = splitted[1];
		std::cout << "Successfully opened " << currentFileName << std::endl;
	}
}

void Menu::commandClose(VectorOfFigures& v, std::ifstream& in, const Validator& validator)
{
	bool isValid = validator.validateClose();

	if (isValid) {
		in.close();
		v.clearFigures();
		std::cout << "Successfully closed " << currentFileName << std::endl;
	}
}

void Menu::commandSave(VectorOfFigures& v, std::ifstream& in)
{
	v.saveFiguresToFile(currentFileName.getData(), in);
	std::cout << "Successfully saved " << currentFileName << std::endl;
}

void Menu::commandSaveAs(VectorOfFigures& v, std::ifstream& in)
{
	v.saveAsFiguresToFile(currentFileName.getData(), in);
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

void Menu::commandPrint(VectorOfFigures& v, const Validator& validator)
{
	bool isValid = validator.validatePrint();

	if (isValid) {
		v.printFigures();
	}
}

void Menu::commandCreate(VectorOfFigures& v, const Validator& validator)
{
	bool isValid = validator.validateCreate();
	if (isValid) {
		v.create(splitted);
	}
}

void Menu::commandErase(VectorOfFigures& v, const Validator& validator)
{
	bool isValid = validator.validateIndex(v.size());

	if (isValid) {
		int index = splitted[1].stod();
		v.erase(index);
	}
}

void Menu::commandTranslate(VectorOfFigures& v, const Validator& validator)
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

void Menu::commandWithin(VectorOfFigures& v, const Validator& validator)
{
	bool isValid = validator.validateWithin();
	
	if (isValid) {
		v.within(splitted);
	}
}

void Menu::determineCommand(VectorOfFigures& v, std::ifstream &in, String& currFileName, Validator& validator)
{
	String firstCommand = splitted[0];

	if (firstCommand == "open") {
		commandOpen(v, in, validator);
	}
	else {
		if (firstCommand == "exit") {
			std::cout << "Exiting the program..." << std::endl;
		}else {
			if (!in.is_open()) {
				std::cout << "There is not an open file" << std::endl;
			}
			else {
				if (firstCommand == "close") {
					commandClose(v, in, validator);
				}
				else if (firstCommand == "save") {
					commandSave(v, in);
				}
				else if (firstCommand == "saveas") {
					commandSaveAs(v, in);
				}
				else if (firstCommand == "help") {
					commandHelp();
				}
				else if (firstCommand == "print") {
					commandPrint(v, validator);
				}
				else if (firstCommand == "create") {
					commandCreate(v, validator);
				}
				else if (firstCommand == "erase") {
					commandErase(v, validator);
				}
				else if (firstCommand == "translate") {
					commandTranslate(v, validator);
				}
				else if (firstCommand == "within") {
					commandWithin(v, validator);
				}
				else {
					std::cout << "You have enterned an invalid command!" << std::endl;
				}
			}
		}
	}
}