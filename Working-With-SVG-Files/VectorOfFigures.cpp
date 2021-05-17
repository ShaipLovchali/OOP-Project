#include "VectorOfFigures.h"

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
	else if (strcmp(figureType, "line") == 0) {
		return new Line();
	}
}

void VectorOfFigures::create(Figure* figure)
{
	figures.push_back(figure);
}

void VectorOfFigures::erase(size_t n)
{
	figures.pop_by_data(figures[n - 1]);	
}

void VectorOfFigures::translateAll(double vertical, double horizontal)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		this->figures[i]->setX(this->figures[i]->getX() + vertical);
		this->figures[i]->setY(this->figures[i]->getY() + horizontal);
	}
}

void VectorOfFigures::translate(size_t index, double vertical, double horizontal)
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		if (i + 1 == index) {
			this->figures[i]->setX(this->figures[i]->getX() + vertical);
			this->figures[i]->setY(this->figures[i]->getY() + horizontal);
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
