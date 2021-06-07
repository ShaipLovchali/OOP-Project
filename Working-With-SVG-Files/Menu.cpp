#include "Menu.h"

void Menu::start()
{
	do {
		std::cout << "Please, enter a command: ";
		std::cin >> command;
		splitCommand();

		validator = splitted;
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
			subStr.clear();
			continue;
		}
		subStr.pushBack(command[i]);
	}
	
	splitted.push_back(subStr);
}

void Menu::commandOpen() {
	bool isValid = validator.validateOpen(fileStream);

	if (isValid) {
		char* fileName = splitted[1].getData();
		fileStream.open(fileName);

		figures.loadFromFile(fileName);

		currentFileName = splitted[1];
		std::cout << "Successfully opened " << currentFileName << std::endl;
	}
}

void Menu::commandClose()
{
	bool isValid = validator.validateClose();

	if (isValid) {
		fileStream.close();
		figures.clearFigures();
		std::cout << "Successfully closed " << currentFileName << std::endl;
	}
}

void Menu::commandSave()
{
	bool isValid = validator.validateSave();

	if (isValid) {
		figures.saveFiguresToFile(currentFileName.getData(), fileStream);
		std::cout << "Successfully saved " << currentFileName << std::endl;
	}
}

void Menu::commandSaveAs()
{
	bool isValid = validator.validateSaveAs();

	if (isValid) {
		figures.saveAsFiguresToFile(currentFileName.getData(), fileStream);
		std::cout << "Successfully saved " << currentFileName << " in the path" << std::endl;
	}
}

void Menu::commandHelp()
{
	bool isValid = validator.validateHelp();
	if (isValid) {
		std::cout << "The following commands are supported:" << std::endl;
		std::cout << " open <file> - opens <file>" << std::endl;
		std::cout << " close closes currently opened file" << std::endl;
		std::cout << " save saves the currently open file" << std::endl;
		std::cout << " saveas <file> saves the currently open file in <file>" << std::endl;
		std::cout << " help prints this information" << std::endl;
		std::cout << " exit exists the program" << std::endl;
	}
}

void Menu::commandPrint()
{
	bool isValid = validator.validatePrint();

	if (isValid) {
		figures.printFigures();
	}
}

void Menu::commandCreate()
{
	bool isValid = validator.validateCreate();
	if (isValid) {
		figures.create(splitted);
	}
}

void Menu::commandErase()
{
	bool isValid = validator.validateIndex(figures.size());

	if (isValid) {
		int index = splitted[1].stod();
		figures.erase(index);
	}
}

void Menu::commandTranslate()
{
	double vertical;
	double horizontal;

	if (splitted[1].find("vertical") != -1) {
		bool isInputValid = validator.validateTranslate(splitted[1], splitted[2]);

		if (isInputValid) {
			vertical = splitted[1].getValue('=').stod();
			horizontal = splitted[2].getValue('=').stod();
			figures.translateAll(vertical, horizontal);
		}
	}
	else {
		int index = splitted[1].stod();
		bool isIndexValid = validator.validateIndex(figures.size());
		bool isInputValid = validator.validateTranslate(splitted[2], splitted[3]);

		if (isIndexValid && isInputValid) {
			vertical = splitted[2].getValue('=').stod();
			horizontal = splitted[3].getValue('=').stod();
			figures.translate(index, vertical, horizontal);
		}
	}
}

void Menu::commandWithin()
{
	bool isValid = validator.validateWithin();
	
	if (isValid) {
		figures.within(splitted);
	}
}

void Menu::determineCommand()
{
	String firstCommand = splitted[0];

	if (firstCommand == "open") {
		commandOpen();
	}
	else {
		if (firstCommand == "exit") {
			std::cout << "Exiting the program..." << std::endl;
		}else {
			if (!fileStream.is_open()) {
				std::cout << "There is not an open file" << std::endl;
			}
			else {
				if (firstCommand == "close") {
					commandClose();
				}
				else if (firstCommand == "save") {
					commandSave();
				}
				else if (firstCommand == "saveas") {
					commandSaveAs();
				}
				else if (firstCommand == "help") {
					commandHelp();
				}
				else if (firstCommand == "print") {
					commandPrint();
				}
				else if (firstCommand == "create") {
					commandCreate();
				}
				else if (firstCommand == "erase") {
					commandErase();
				}
				else if (firstCommand == "translate") {
					commandTranslate();
				}
				else if (firstCommand == "within") {
					commandWithin();
				}
				else {
					std::cout << "You have enterned an invalid command!" << std::endl;
				}
			}
		}
	}
}