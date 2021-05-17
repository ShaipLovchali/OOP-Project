#include "Rectangle.h"

void Rectangle::copy(const Rectangle& other) {
	setX(other.x);
	setY(other.y);
	this->width = other.width;
	this->height = other.height;
	setFillColor(other.fillColor);
}

void Rectangle::erase()
{
	delete[] this->fillColor;
}

Rectangle::Rectangle() : Figure(), width(0), height(0) {}

Rectangle::Rectangle(double x, double y, int width, int height, const char* fillColor) : Figure(x, y, fillColor), width(width), height(height){}

Rectangle::Rectangle(const Rectangle& other)
{
	copy(other);
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Rectangle::~Rectangle()
{
	erase();
}

void Rectangle::print() const
{
	std::cout << "Rectangle's x coordinate is: " <<  this->x << std::endl;
	std::cout << "Rectangle's y coordinate is: " << this->y << std::endl;
	std::cout << "Rectangle's width is: " << this->width << std::endl;
	std::cout << "Rectangle's height is: " << this->height << std::endl;
	std::cout << "Rectangle's color is: " << this->fillColor << std::endl;
}

void Rectangle::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> width >> height >> fillColor;
}


