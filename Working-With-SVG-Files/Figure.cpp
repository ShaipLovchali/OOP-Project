#include "Figure.h"

Figure::Figure() : x(0), y(0), fillColor(nullptr){}

Figure::Figure(double x, double y, const char* fillColor) : x(x), y(y), fillColor(new char[strlen(fillColor) + 1])
{
	for (size_t i = 0; fillColor[i]; ++i)
	{
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}

void Figure::setFiguresData(double x, double y, const char* fillColor)
{
	this->x = x;
	this->y = y;
	this->fillColor = new char[strlen(fillColor) + 1];
	for (size_t i = 0; fillColor[i]; ++i)
	{
		this->fillColor[i] = fillColor[i];
	}
	this->fillColor[strlen(fillColor)] = '\0';
}