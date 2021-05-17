#pragma once
#include "Menu.h"

void Menu::start()
{
	ParseData parser;
	parser.parseSvg();

	VectorOfFigures v;
	v.loadFromStream();
	do {
		std::cout << "Please, enter a command: ";
		std::cin >> command;
		splitCommand();

		determineCommand(parser,v);	
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

void Menu::determineCommand(ParseData& parser, VectorOfFigures& v)
{
	if (splitted[0] == "open") {
		char* fileName = splitted[1].getData();
		std::ifstream in(fileName);
		if (!in) {
			std::cout << "No such file existing" << std::endl;
		}
		else {
			std::cout << "Successfully opened file" << std::endl;
		}

		in.close();
	}
	else if (splitted[0] == "close") {
		std::cout << "Closed file.. " << std::endl;
	}
	else if (splitted[0] == "save") {
		v.saveFiguresToFile();
		std::cout << "Saved file.. " << std::endl;
	}
	else if (splitted[0] == "saveas") {
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
		Figure* fig;
		if (splitted[1] == "rect") {
			fig = new Rectangle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6].getData());
			v.create(fig);
			std::cout << "Successfully created rectangle" << std::endl;
		}
		else if (splitted[1] == "circle") {
			fig = new Circle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].getData());
			v.create(fig);
			std::cout << "Successfully created circle" << std::endl;
		}
		else if (splitted[1] == "ellipse") {
			fig = new Ellipse(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6].getData());
			v.create(fig);
			std::cout << "Successfully created ellipse" << std::endl;
		}
		else {
			std::cout << "Invalid figure type" << std::endl;
		}
	}
	else if (splitted[0] == "erase") {
		int num = splitted[1].stod();
		if (num > 0 && num <= v.size()) {
			v.erase(num);
			std::cout << "Erased figure " << num << std::endl;
		}
		else {
			std::cout << "There is no figure number " << num << std::endl;
		}
	}
	else if (splitted[0] == "translate") {
		double vertical = splitted[1].stod();
		double horizontal = splitted[2].stod();

		v.translateAll(vertical, horizontal);
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




