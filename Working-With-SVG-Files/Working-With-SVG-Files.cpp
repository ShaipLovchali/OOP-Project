#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Menu.h"

#include "pugixml.cpp"

int main()
{
	/*pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("figures.svg");
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

	
	/*Rectangle r1(3, 2, 4, 5, "blue");

	Circle c1(1, 2, 3.4, "red");
	
	Line l1(3.4, 2.8, 12, 15, "pink");
	
	std::vector<Figure*> figures;
	figures.push_back(&r1);
	figures.push_back(&c1);
	figures.push_back(&l1);

	for (size_t i = 0; i < figures.size(); ++i)
	{
		figures[i]->print();
	}*/
}
