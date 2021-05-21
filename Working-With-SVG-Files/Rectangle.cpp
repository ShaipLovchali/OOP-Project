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
	std::cout << "Rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " " << this->fillColor << std::endl;
}

void Rectangle::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> width >> height >> fillColor;
}

void Rectangle::saveDataToFile(std::ostream& out)
{
	out << "\t" << "<rect x=\"" << this->x << "\" y=\"" << this->y << "\" width=\"" << this->width << "\" height=\"" << this->height << "\" fill=\"" << this->fillColor << "\" />";
}

bool Rectangle::withinRect(double x2, double y2, int width2, int height2)
{
	return x + width <= width2 && y + height <= height2;
}

bool Rectangle::withinCircle(double x2, double y2, double r)
{
	return x + width <= r && y + height <= r;
}



