#include "Circle.h"

Circle::Circle() : Figure(), r(0){}

Circle::Circle(double cx, double cy, double _r, const String& fillColor) : Figure(cx, cy, fillColor), r(_r) {}

void Circle::print() const
{
	std::cout << "Circle " << this->x << " " << this->y << " " << this->r << " " << this->fillColor << std::endl;
}

void Circle::loadDataFromFile(std::istream& in)
{
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
	return (x - r) > (x2 - r2) && (y - r) > (y2 - r2) && (x + r) <= (x2 + r2) && (y + r) <= (y2 + r2);
}

