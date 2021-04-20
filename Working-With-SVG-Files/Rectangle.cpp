#include "Rectangle.h"

void Rectangle::copy(const Rectangle& other)
{
	setX(other.x);
	setY(other.y);
	setWidth(other.width);
	setHeight(other.height);
	setFillColor(other.fillColor);
}

void Rectangle::erase()
{
	delete[] this->fillColor;
}

Rectangle::Rectangle() : x(0), y(0), width(0), height(0), fillColor(nullptr){}

Rectangle::Rectangle(double x, double y, int width, int height, const char* fillColor)
{
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setFillColor(fillColor);
}

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

void Rectangle::setX(double x)
{
	this->x = x;
}

void Rectangle::setY(double y)
{
	this->y = y;
}

void Rectangle::setWidth(int width)
{
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	this->height = height;
}

void Rectangle::setFillColor(const char* fillColor)
{
	this->fillColor = new char[strlen(fillColor) + 1];

	for (size_t i = 0; fillColor[i]; ++i) {
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

double Rectangle::getX() const
{
	return this->x;
}

double Rectangle::getY() const
{
	return this->y;
}

int Rectangle::getWidth() const
{
	return this->width;
}

int Rectangle::getHeight() const
{
	return this->height;
}

char* Rectangle::getFillColor() const
{
	return this->fillColor;
}

void Rectangle::print() const
{
	std::cout << "Rectangle's x coordinate is: " <<  this->x << std::endl;
	std::cout << "Rectangle's y coordinate is: " << this->y << std::endl;
	std::cout << "Rectangle's width is: " << this->width << std::endl;
	std::cout << "Rectangle's height is: " << this->height << std::endl;
	std::cout << "Rectangle's color is: " << this->fillColor << std::endl;
}

