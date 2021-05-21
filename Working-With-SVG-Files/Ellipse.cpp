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
	std::cout << "Ellipse " << this->x << " " << this->y << " " << this->rx << " " << this->ry << " " << this->fillColor << std::endl;
}

void Ellipse::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> rx >> ry >> fillColor;
}

void Ellipse::saveDataToFile(std::ostream& out)
{
	out << "\t" << "<ellipse cx=\"" << this->x << "\" cy=\"" << this->y << "\" rx=\"" << this->rx << "\" ry=\"" << this->ry << "\" fill=\"" << this->fillColor << "\" />";
}

bool Ellipse::withinRect(double x2, double y2, int width, int height)
{
	return x + rx <= width && y + ry <= height;
}

bool Ellipse::withinCircle(double x2, double y2, double r)
{
	return x + rx <= r && y + ry <= r;
}

