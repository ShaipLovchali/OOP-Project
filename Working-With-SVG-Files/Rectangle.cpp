#include "Rectangle.h"

Rectangle::Rectangle() : Figure(), width(0), height(0) {}

Rectangle::Rectangle(double x, double y, double _width, double _height, const String& fillColor) : Figure(x, y, fillColor), width(_width), height(_height) {}

void Rectangle::print() const
{
	std::cout << "Rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " " << this->fillColor << std::endl;
}

void Rectangle::loadDataFromFile(std::istream& in)
{
	in >> x >> y >> width >> height >> fillColor;
}

void Rectangle::saveDataToFile(std::ostream& out) const
{
	out << "\t" << "<rect x=\"" << this->x << "\" y=\"" << this->y << "\" width=\"" << this->width << "\" height=\"" << this->height << "\" fill=\"" << this->fillColor << "\" />";
}

bool Rectangle::withinRect(double x2, double y2, double width2, double height2) const
{
	return x >= x2 && (x + width) <= (x2 + width2) && y >= y2 && (y + height) <= (y2 + height2);
}

bool Rectangle::withinCircle(double x2, double y2, double r) const
{
	bool isCorner1In = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2)) <= r;
	bool isCorner2In = sqrt(((x + width) - x2) * ((x + width) - x2) + (y - y2) * (y - y2)) <= r;
	bool isCorner3In = sqrt((x - x2) * (x - x2) + ((y + height) - y2) * ((y + height) - y2)) <= r;
	bool isCorner4In = sqrt(((x + width) - x2) * ((x + width) - x2) + ((y + height) - y2) * ((y + height) - y2)) <= r;
	return isCorner1In && isCorner2In && isCorner3In && isCorner4In;
}



