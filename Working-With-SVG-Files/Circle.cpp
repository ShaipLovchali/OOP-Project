#include "Circle.h"

void Circle::copy(const Circle& other)
{
	copyFig(other.x, other.y, other.fillColor);
	this->r = other.r;
}

Circle::Circle() : Figure(), r(0){}

Circle::Circle(double cx, double cy, double _r, const char* fillColor) : Figure(cx, cy, fillColor), r(_r) {}

Circle::Circle(const Circle& other)
{
	copy(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other) {
		delete[] this->fillColor;
		copy(other);
	}
	return *this;
}

void Circle::print() const
{
	std::cout << "Circle " << this->x << " " << this->y << " " << this->r << " " << this->fillColor << std::endl;
}

void Circle::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> r >> fillColor;
}

void Circle::saveDataToFile(std::ostream& out) const
{
	out << "\t" << "<circle cx=\"" << this->x << "\" cy=\"" << this->y << "\" r=\"" << this->r << "\" fill=\"" << this->fillColor << "\" />";
}

bool Circle::withinRect(double x2, double y2, double width, double height) const
{
	return abs(x - r) >= x2 && abs(y - r) >= y2 && x <= (x2 + width - r) && y <= (y2 + height - r);
}

bool Circle::withinCircle(double x2, double y2, double r2) const
{
	if ((x2 - r2) <= 0 && (y2 - r2) <= 0) {
		return ((x + r) <= (x2 + r2) && y <= r2) || ((y + r) <= (y2 + r2) && x <= r2);
	}

	double distance = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	return distance <= abs(r - r2);
}

