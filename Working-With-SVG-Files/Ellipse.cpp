#include "Ellipse.h"

void Ellipse::copy(const Ellipse& other)
{
	setX(other.x);
	setY(other.y);
	this->rx = other.rx;
	this->ry = other.ry;
	setFillColor(other.fillColor);
}

void Ellipse::erase()
{
	delete[] this->fillColor;
}

Ellipse::Ellipse(): Figure(), rx(0), ry(0){}

Ellipse::Ellipse(double x1, double y1, double rx, double ry, const char* fillColor) : Figure(x1, y1, fillColor), rx(rx), ry(ry){}

Ellipse::Ellipse(const Ellipse& other)
{
	copy(other);
}

Ellipse& Ellipse::operator=(const Ellipse& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Ellipse::~Ellipse()
{
	erase();
}

void Ellipse::print() const
{
	std::cout << "Ellipse's x1: " << this->x << std::endl;
	std::cout << "Ellipse's y1: " << this->y << std::endl;
	std::cout << "Ellipse's rx: " << this->rx << std::endl;
	std::cout << "Ellipse's ry: " << this->ry << std::endl;
	std::cout << "Ellipse's fill color: " << this->fillColor << std::endl;
}

void Ellipse::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> rx >> ry >> fillColor;
}

void Ellipse::saveDataToFile(std::ostream& out)
{
	out << "<ellipse cx=\"" << this->x << "\" cy=\"" << this->y << "\" rx=\"" << this->rx << "\" ry=\"" << this->ry << "\" fill=\"" << this->fillColor << "\" />";
}
