#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Menu.h"

#include "pugixml.cpp"

int main()
{
	/*pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("source.xml");
	pugi::xml_node panels = doc.child("svg");

	for (pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()) {
		std::cout << panel.name() << std::endl;
		for (pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute())
		{
			std::cout << " " << attr.name() << "=" << attr.value() << std::endl;
		}
		std::cout << std::endl;
	}*/

	/*Menu menu;
	menu.start();*/

	
	Rectangle rect1(3, 2, 4, 5, "blue");
	Rectangle rect2 = rect1;
	rect2.print();
	
	std::cout << "---------------------------------------------" << std::endl;

	Circle c1(1, 2, 3.4, "red");
	Circle c2;
	c2 = c1;
	c2.print();

	std::cout << "---------------------------------------------" << std::endl;

	Line l1(3.4, 2.8, 12, 15, "pink");
	Line l2 = l1;
	l2.print();
}
