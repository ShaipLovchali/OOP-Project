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

void Ellipse::saveDataToFile(std::ostream& out) const
{
	out << "\t" << "<ellipse cx=\"" << this->x << "\" cy=\"" << this->y << "\" rx=\"" << this->rx << "\" ry=\"" << this->ry << "\" fill=\"" << this->fillColor << "\" />";
}

bool Ellipse::withinRect(double x2, double y2, int width, int height) const
{
	if (x2 == 0 && y2 == 0) {
		return (x + rx) <= width && (y + ry) <= height;
	}
	bool isCorner1out = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) >= rx && sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) >= ry;
	bool isCorner2out = sqrt(((x2 + width) - x) * ((x2 + width) - x) + (y2 - y) * (y2 - y)) >= rx && sqrt(((x2 + width) - x) * ((x2 + width) - x) + (y2 - y) * (y2 - y)) >= ry;
	bool isCorner3out = sqrt((x2 - x) * (x2 - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= rx && sqrt((x2 - x) * (x2 - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= ry;
	bool isCorner4out = sqrt(((x2 + width) - x) * ((x2 + width) - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= rx && sqrt(((x2 + width) - x) * ((x2 + width) - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= ry;
	return isCorner1out && isCorner2out && isCorner3out && isCorner4out;
}

bool Ellipse::withinCircle(double x2, double y2, double r) const
{
	return (x + rx) <= (x2 + r) && (y + ry) <= (y2 + r);
	/*double distance = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	return distance <= abs(rx - r) && distance <= abs(ry - r);*/
}

