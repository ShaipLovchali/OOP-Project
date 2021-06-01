#include "Figure.h"

Figure::Figure() : x(0), y(0), fillColor(""){}

Figure::Figure(double _x, double _y, const String& _fillColor) : x(_x), y(_y), fillColor(_fillColor) {}

void Figure::setX(double x)
{
	this->x = x;
}

void Figure::setY(double y)
{
	this->y = y;
}

void Figure::setFillColor(const String& fillColor)
{
	this->fillColor = fillColor;
}

double Figure::getX() const
{
	return this->x;
}

double Figure::getY() const
{
	return this->y;
}

String Figure::getFillColor() const
{
	return this->fillColor;
}

