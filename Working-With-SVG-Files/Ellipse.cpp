#include "Ellipse.h"

Ellipse::Ellipse(): Figure(), rx(0), ry(0){}

Ellipse::Ellipse(double x1, double y1, double _rx, double _ry, const String& fillColor) : Figure(x1, y1, fillColor), rx(_rx), ry(_ry){}

void Ellipse::print() const
{
	std::cout << "Ellipse " << this->x << " " << this->y << " " << this->rx << " " << this->ry << " " << this->fillColor << std::endl;
}

void Ellipse::loadDataFromFile(std::istream& in)
{
	in >> x >> y >> rx >> ry >> fillColor;
}

void Ellipse::saveDataToFile(std::ostream& out) const
{
	out << "\t" << "<ellipse cx=\"" << this->x << "\" cy=\"" << this->y << "\" rx=\"" << this->rx << "\" ry=\"" << this->ry << "\" fill=\"" << this->fillColor << "\" />";
}

bool Ellipse::withinRect(double x2, double y2, double width, double height) const
{
	return abs(x - rx) >= x2 && abs(y - ry) >= y2 && x <= (x2 + width - rx) && y <= (y2 + height - ry);
}

bool Ellipse::withinCircle(double x2, double y2, double r) const
{
	return (x - rx) > (x2 - r) && (y - ry) > (y2 - r) && (x + rx) <= (x2 + r) && (y + ry) <= (y2 + r);
}

