#include "Line.h"

void Line::copy(const Line& other)
{
	setX(other.x);
	setY(other.y);
	this->x2 = other.x2;
	this->y2 = other.y2;
	setFillColor(other.fillColor);
}

void Line::erase()
{
	delete[] this->fillColor;
}

Line::Line(): Figure(), x2(0), y2(0){}

Line::Line(double x1, double y1, double x2, double y2, const char* fillColor) : Figure(x1, y1, fillColor), x2(x2), y2(y2){}

Line::Line(const Line& other)
{
	copy(other);
}

Line& Line::operator=(const Line& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Line::~Line()
{
	erase();
}

void Line::print() const
{
	std::cout << "Line's x1: " << this->x << std::endl;
	std::cout << "Line's y1: " << this->y << std::endl;
	std::cout << "Line's x2: " << this->x2 << std::endl;
	std::cout << "Line's y2: " << this->y2 << std::endl;
	std::cout << "Line's fill color: " << this->fillColor << std::endl;
}

void Line::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> x2 >> y2 >> fillColor;
}
