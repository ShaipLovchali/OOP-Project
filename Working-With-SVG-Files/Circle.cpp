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
	std::cout << "Circle " << this->x << " " << this->y << " " << this->r << " " << this->fillColor << std::endl;
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

bool Circle::withinRect(double x2, double y2, int width, int height)
{
	if (x2 == 0 && y2 == 0) {
		return (x + r) <= width && (y + r) <= height;
	}

	bool isCorner1out = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) >= r;
	bool isCorner2out = sqrt(((x2 + width) - x) * ((x2 + width) - x) + (y2 - y) * (y2 - y)) >= r;
	bool isCorner3out = sqrt((x2 - x) * (x2 - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= r;
	bool isCorner4out = sqrt(((x2 + width) - x) * ((x2 + width) - x) + ((y2 + height) - y) * ((y2 + height) - y)) >= r;
	return isCorner1out && isCorner2out && isCorner3out && isCorner4out;
}

bool Circle::withinCircle(double x2, double y2, double r2)
{
	if ((x2 - r2) <= 0 && (y2 - r2) <= 0) {
		return ((x + r) <= (x2 + r2) && y <= r2) || ((y + r) <= (y2 + r2) && x <= r2);
	}

	double distance = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	return distance <= abs(r - r2);
}

