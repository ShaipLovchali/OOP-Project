#include "VectorOfFigures.h"

void VectorOfFigures::addFigure(const Vector<String>& splitted)
{
	Figure* fig = nullptr;

	if (splitted[0] == "rect") {
		fig = new Rectangle(splitted[1].stod(), splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5]);
	}
	else if (splitted[0] == "circle") {
		fig = new Circle(splitted[1].stod(), splitted[2].stod(), splitted[3].stod(), splitted[4]);
	}
	else if (splitted[0] == "ellipse") {
		fig = new Ellipse(splitted[1].stod(), splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5]);
	}
	else {
		return;
	}

	figures.push_back(fig);
}

VectorOfFigures::VectorOfFigures(){}

void VectorOfFigures::loadFromFile(const char* fileName)
{
	pugi::xml_document doc;
	doc.load_file(fileName);
	pugi::xml_node svgTag = doc.child("svg");

	for (pugi::xml_node tag = svgTag.first_child(); tag; tag = tag.next_sibling()) {
		Vector<String> data;

		data.push_back(tag.name());
		for (pugi::xml_attribute attr = tag.first_attribute(); attr; attr = attr.next_attribute())
		{
			data.push_back(attr.value());
		}
		addFigure(data);
	}
}

void VectorOfFigures::create(const Vector<String>& splitted)
{
	Figure* fig = nullptr;

	if (splitted[1] == "rect") {
		fig = new Rectangle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6]);
		std::cout << "Successfully created rectangle" << std::endl;
	}
	else if (splitted[1] == "circle") {
		fig = new Circle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5]);
		std::cout << "Successfully created circle" << std::endl;
	}
	else if (splitted[1] == "ellipse") {
		fig = new Ellipse(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6]);
		std::cout << "Successfully created ellipse" << std::endl;
	}

	figures.push_back(fig);
}

void VectorOfFigures::erase(int index)
{
	figures.pop_by_data(figures[index - 1]);
	std::cout << "Erased figure " << index << std::endl;
}

void VectorOfFigures::translateAll(double vertical, double horizontal)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		this->figures[i]->setX(this->figures[i]->getX() + horizontal);
		this->figures[i]->setY(this->figures[i]->getY() + vertical);
	}
	std::cout << "Translated all figures" << std::endl;
}

void VectorOfFigures::translate(int index, double vertical, double horizontal)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		if (i + 1 == index) {
			this->figures[i]->setX(this->figures[i]->getX() + horizontal);
			this->figures[i]->setY(this->figures[i]->getY() + vertical);
		}
	}
	std::cout << "Translated figure number " << index << std::endl;
}

void VectorOfFigures::within(const Vector<String>& splitted)
{
	size_t counter = 0;
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		bool isWithin = false;
		if (splitted[1] == "rect") {
			isWithin = figures[i]->withinRect(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod());
		}else if (splitted[1] == "circle") {
			isWithin = figures[i]->withinCircle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod());
		}
		if (isWithin) {
			++counter;
			std::cout << counter << ". ";
			figures[i]->print();
		}
	}
	if (counter == 0) {
		std::cout << "No figures are located within this region" << std::endl;
	}
}

size_t VectorOfFigures::size() const
{
	return figures.getCapacity();
}

void VectorOfFigures::clearFigures()
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		delete figures[i];
	}
	figures.clear();
}

void VectorOfFigures::printFigures() const
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		std::cout << i + 1 << ". ";
		figures[i]->print();
	}
}

void VectorOfFigures::saveFiguresToFile(const char* fileName, std::ifstream& in)
{
	std::ofstream out("text.txt");
	out << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
	out << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	out << "<svg>\n";

	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		this->figures[i]->saveDataToFile(out);
		out << "\n";
	}
	out << "</svg>";
	out.close();
	in.close();

	remove(fileName);
	std::rename("text.txt", fileName);
	in.open(fileName);
}

void VectorOfFigures::saveAsFiguresToFile(const char* newFileName, std::ifstream& in)
{
	std::ofstream out(newFileName);
	char line[100];
	while (in.getline(line, 100)) {
		String line2(line);
		out << line2;
		out << "\n";
	}
	out.close();
}
