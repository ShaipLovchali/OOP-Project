#include "Menu.h"

void Menu::start()
{
	do {
		std::cout << "Please, enter a command: ";
		getline(std::cin, command);
		splitCommand();

		determineCommand();
	} while (splitted[0] != "exit");
}

void Menu::splitCommand()
{
	splitted.clear();
	std::string subStr = "";
	for (size_t i = 0; i < command.size(); ++i)
	{
		if (command[i] == ' ') {
			splitted.push_back(subStr);
			subStr = "";
			continue;
		}
		subStr += command[i];
	}
	
	splitted.push_back(subStr);
}

void Menu::determineCommand()
{
	if (splitted[0] == "open") {
		std::cout << "Open file.. " << std::endl;
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
		std::cout << "Printed.. " << std::endl;
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


