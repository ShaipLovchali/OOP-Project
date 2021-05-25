#include "VectorOfFigures.h"

VectorOfFigures::VectorOfFigures(){}

void VectorOfFigures::loadFromStream()
{
	std::ifstream in("data.svg");
	char figureType[32];
	in >> figureType;

	while (strcmp(figureType, "") != 0) {
		Figure* newFigure = getFigureType(figureType);

		newFigure->loadDataFromFile(in);
		figures.push_back(newFigure);

		in >> figureType;
	}
	in.close();
}

Figure* VectorOfFigures::getFigureType(const char* figureType)
{
	if (strcmp(figureType, "rect") == 0) {
		return new Rectangle();
	}
	else if (strcmp(figureType, "circle") == 0) {
		return new Circle();
	}
	else if (strcmp(figureType, "ellipse") == 0) {
		return new Ellipse();
	}
}

void VectorOfFigures::create(const Vector<String>& splitted)
{
	char* figureType = splitted[1].getData();
	Figure* fig = nullptr;

	if (strcmp(figureType, "rect") == 0) {
		fig = new Rectangle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6].getData());
		std::cout << "Successfully created rectangle" << std::endl;
	}
	else if (strcmp(figureType, "circle") == 0) {
		fig = new Circle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].getData());
		std::cout << "Successfully created circle" << std::endl;
	}
	else if (strcmp(figureType, "ellipse") == 0) {
		fig = new Ellipse(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod(), splitted[6].getData());
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

void VectorOfFigures::clean()
{
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
