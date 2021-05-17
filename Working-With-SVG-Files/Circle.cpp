#include "Circle.h";

void Circle::copy(const Circle& other)
{
	setX(other.x);
	setY(other.y);
	this->r = other.r;
	setFillColor(other.fillColor);
}

void Circle::erase()
{
	delete[] this->fillColor;
}

Circle::Circle() : Figure(),r(0){}

Circle::Circle(double cx, double cy, double r, const char* fillColor) : Figure(cx, cy, fillColor), r(r) {}

Circle::Circle(const Circle& other)
{
	copy(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Circle::~Circle()
{
	erase();
}

void Circle::print() const
{
	std::cout << "Circle's x coordinate is: " << this->x << std::endl;
	std::cout << "Circle's y coordinate is: " << this->y << std::endl;
	std::cout << "Circle's radius is: " << this->r << std::endl;
	std::cout << "Circle's color is: " << this->fillColor << std::endl;
}

void Circle::loadDataFromFile(std::istream& in)
{
	fillColor = new char[32];
	in >> x >> y >> r >> fillColor;
}

void Circle::saveDataToFile(std::ostream& out)
{
	out << "\t" << "<circle cx=\"" << this->x << "\" cy=\"" << this->y << "\" r=\"" << this->r << "\" fill=\"" << this->fillColor << "\" />";
}
