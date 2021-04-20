#include "Circle.h";

void Circle::copy(const Circle& other)
{
	setCX(other.cx);
	setCY(other.cy);
	setR(other.r);
	setFillColor(other.fillColor);
}

void Circle::erase()
{
	delete[] this->fillColor;
}

Circle::Circle() : cx(0), cy(0), r(0), fillColor(nullptr){}

Circle::Circle(double cx, double cy, double r, const char* fillColor)
{
	setCX(cx);
	setCY(cy);
	setR(r);
	setFillColor(fillColor);
}

Circle::Circle(const Circle& other)
{
	copy(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Circle::~Circle()
{
	erase();
}

void Circle::setCX(double cx)
{
	this->cx = cx;
}

void Circle::setCY(double cy)
{
	this->cy = cy;
}

void Circle::setR(double r)
{
	this->r = r;
}

void Circle::setFillColor(const char* fillColor)
{
	this->fillColor = new char[strlen(fillColor) + 1];

	for (size_t i = 0; fillColor[i]; ++i) {
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

double Circle::getCX() const
{
	return this->cx;
}

double Circle::getCY() const
{
	return this->cy;
}

double Circle::getR() const
{
	return this->r;
}

char* Circle::getFillColor() const
{
	return this->fillColor;
}

void Circle::print() const
{
	std::cout << "Circle's x coordinate is: " << this->cx << std::endl;
	std::cout << "Circle's y coordinate is: " << this->cy << std::endl;
	std::cout << "Circle's radius is: " << this->r << std::endl;
	std::cout << "Circle's color is: " << this->fillColor << std::endl;
}
