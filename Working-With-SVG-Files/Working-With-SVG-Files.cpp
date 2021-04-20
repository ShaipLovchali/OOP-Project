#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Figures.h"
#include "String.h"

int main()
{
	std::cout << "> ";
	String input(32);
	std::cin >> input;

	String* commands = input.split(" ");

	while (!(commands[0] == "exit")) {
		if (commands[0] == "open") {

		}
		else if (commands[0] == "close") {

		}
		else if (commands[0] == "save") {

		}
		else if (commands[0] == "save as") {

		}
		else if (commands[0] == "help") {
			std::cout << "The following commands are supported: " << std::endl;
			std::cout << "open <file> opens <file>" << std::endl;
			std::cout << "close	closes currently opened file" << std::endl;
			std::cout << "save saves the currently open file" << std::endl;
			std::cout << "saveas <file>	saves the currently open file in <file>" << std::endl;
			std::cout << "help prints this information" << std::endl;
		}
		else if (commands[0] == "print") {

		}
		else if (commands[0] == "create") {

		}
		else if (commands[0] == "erase") {
			int index = commands[1].toInt();
			
		}
		else if (commands[0] == "translate") {
			int index = commands[1].toInt();

		}
		else if (commands[0] == "within") {
			String region = commands[1];

		}
		std::cout << "> ";
		std::cin >> input;
		commands = input.split(" ");
	}

	
	/*Rectangle rect1(3, 2, 4, 5, "blue");
	Rectangle rect2 = rect1;
	rect2.print();
	
	std::cout << rect2.getFillColor() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	Circle c1(1, 2, 3.4, "red");
	Circle c2;
	c2 = c1;
	c2.print();

	std::cout << "---------------------------------------------" << std::endl;

	Line l1(3.4, 2.8, 12, 15, "pink");
	l1.print();*/
}
