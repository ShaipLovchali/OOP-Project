#include "Line.h"

void Line::copy(const Line& other)
{
	setX1(other.x1);
	setY1(other.y1);
	setX2(other.x2);
	setY2(other.y2);
	setFillColor(other.fillColor);
}

void Line::erase()
{
	delete[] this->fillColor;
}

Line::Line(): x1(0), y1(0), x2(0), y2(0), fillColor(nullptr){}

Line::Line(double x1, double y1, double x2, double y2, const char* fillColor)
{
	setX1(x1);
	setY1(y1);
	setX2(x2);
	setY2(y2);
	setFillColor(fillColor);
}

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

void Line::setX1(double x1)
{
	this->x1 = x1;
}

void Line::setY1(double y1)
{
	this->y1 = y1;
}

void Line::setX2(double x2)
{
	this->x2 = x2;
}

void Line::setY2(double y2)
{
	this->y2 = y2;
}

void Line::setFillColor(const char* fillColor)
{
	this->fillColor = new char[strlen(fillColor) + 1];

	for (size_t i = 0; fillColor[i]; ++i) {
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

void Line::print() const
{
	std::cout << "Line's x1: " << this->x1 << std::endl;
	std::cout << "Line's y1: " << this->y1 << std::endl;
	std::cout << "Line's x2: " << this->x2 << std::endl;
	std::cout << "Line's y2: " << this->y2 << std::endl;
	std::cout << "Line's fill color: " << this->fillColor << std::endl;
}
