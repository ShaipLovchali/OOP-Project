#pragma once
#include <iostream>
#include <cstring>

class Rectangle {
private:
	double x, y;
	int width, height;
	char* fillColor;

	void copy(const Rectangle&);
	void erase();
public:
	Rectangle();
	Rectangle(double, double, int, int, const char*);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	~Rectangle();

	void setX(double);
	void setY(double);
	void setWidth(int);
	void setHeight(int);
	void setFillColor(const char*);

	double getX() const;
	double getY() const;
	int getWidth() const;
	int getHeight() const;
	char* getFillColor() const;

	void print() const;
};