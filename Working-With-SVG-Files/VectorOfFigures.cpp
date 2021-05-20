#include "VectorOfFigures.h"
#include <string>

VectorOfFigures::VectorOfFigures() : figures(){}

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

void VectorOfFigures::create(Vector<String>& splitted)
{
	char* figureType = splitted[1].getData();
	Figure* fig;

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
	else {
		std::cout << "Invalid figure type" << std::endl;
		return;
	}

	figures.push_back(fig);
}

void VectorOfFigures::erase(int index)
{
	if (index <= 0 || index > figures.getCapacity()) {
		std::cout << "Invalid index of figure" << std::endl;
		return;
	}
	figures.pop_by_data(figures[index - 1]);
	std::cout << "Erased figure " << index << std::endl;
}

void VectorOfFigures::translateAll(double vertical, double horizontal)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		this->figures[i]->setX(this->figures[i]->getX() + vertical);
		this->figures[i]->setY(this->figures[i]->getY() + horizontal);
	}
	std::cout << "Translated all figures" << std::endl;
}

void VectorOfFigures::translate(int index, double vertical, double horizontal)
{
	if (index <= 0 || index > figures.getCapacity()) {
		std::cout << "Invalid index of figure" << std::endl;
		return;
	}

	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		if (i + 1 == index) {
			this->figures[i]->setX(this->figures[i]->getX() + vertical);
			this->figures[i]->setY(this->figures[i]->getY() + horizontal);
		}
	}
	std::cout << "Translated figure number " << index << std::endl;
}

void VectorOfFigures::within(Vector<String>& splitted)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		bool isWithin = false;
		if (splitted[1] == "rect") {
			isWithin = figures[i]->withinRect(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod());
			if (isWithin) {
				figures[i]->print();
			}
		}
		else if (splitted[1] == "circle") {
			isWithin = figures[i]->withinCircle(splitted[2].stod(), splitted[3].stod(), splitted[4].stod());
			if (isWithin) {
				figures[i]->print();
			}
		}
		else if (splitted[1] == "ellipse") {
			isWithin = figures[i]->withinEllipse(splitted[2].stod(), splitted[3].stod(), splitted[4].stod(), splitted[5].stod());
			if (isWithin) {
				figures[i]->print();
			}
		}
	}
}

size_t VectorOfFigures::size() const
{
	return figures.getCapacity();
}

void VectorOfFigures::printFigures() const
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		figures[i]->print();
	}
}

void VectorOfFigures::saveFiguresToFile(const char* fileName, std::ifstream& in)
{
	std::ofstream out("text.txt");
	char line[100];

	while (in.getline(line, 100)) {
		String line2(line);
		if (line2.find("<svg>") != -1) {
			out << "<svg>\n";
			for (size_t i = 0; i < figures.getCapacity(); ++i)
			{
				this->figures[i]->saveDataToFile(out);
				out << "\n";
			}
			break;
		}
		out << line2;
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
