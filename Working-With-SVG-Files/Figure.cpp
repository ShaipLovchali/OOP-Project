#include "Figure.h"

Figure::Figure() : x(0), y(0), fillColor(nullptr){}

Figure::Figure(double x, double y, const char* fillColor) : x(x), y(y), fillColor(new char[strlen(fillColor) + 1]){
	for (size_t i = 0; fillColor[i]; ++i)
	{
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

void Figure::setX(double x)
{
	this->x = x;
}

void Figure::setY(double y)
{
	this->y = y;
}

void Figure::setFillColor(const char* fillColor)
{
	this->fillColor = new char[strlen(fillColor) + 1];
	for (size_t i = 0; fillColor[i]; ++i)
	{
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

double Figure::getX() const
{
	return this->x;
}

double Figure::getY() const
{
	return this->y;
}

char* Figure::getFillColor() const
{
	return this->fillColor;
}

