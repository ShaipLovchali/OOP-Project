#include "String.h"

// Използвам функцията за заместител на strlen
int length(const char* data) {
	int size = 0;
	for (size_t i = 0; data[i]; ++i)
	{
		++size;
	}
	return size;
}

template<typename T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

void String::copy(const String& other)
{
	this->size = other.size;
	this->data = new char[size + 1];

	for (size_t i = 0; i < size; ++i)
	{
		this->data[i] = other.data[i];
	}
	this->data[size] = '\0';
}

void String::erase()
{
	delete[] this->data;
}

String::String() : data(nullptr), size(0){}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

String::String(size_t size) : data(new char[size]), size(size){}

String::String(const char* data) : size(length(data)), data(new char[length(data) + 1])
{
	for (size_t i = 0; i < size; ++i)
	{
		this->data[i] = data[i];
	}
	this->data[size] = '\0';
}

String::~String()
{
	erase();
}

size_t String::getSize() const
{
	return this->size;
}

String String::concat(const String& other)
{
	String result;
	result.size = this->size + other.size;
	result.data = new char[result.size + 1];

	size_t count = 0;

	for (size_t i = 0; i < this->size; ++i)
	{
		result.data[count++] = this->data[i];
	}

	for (size_t j = 0; j < other.size; ++j)
	{
		result.data[count++] = other.data[j];
	}
	result.data[result.size] = '\0';

	return result;
}

String* String::split(const char* delimiter)
{
	String* result = new String[delimitersCounter(*this, delimiter) + 1];
	size_t counter = 0;

	size_t i = 0;
	int currentIndex = this->findWithIndex(i, delimiter);

	while (currentIndex != -1) {
		result[counter++] = generateStr(i, currentIndex);

		i += length(delimiter);
		currentIndex = this->findWithIndex(i, delimiter);
	}

	result[counter] = generateStr(i, size);

	return result;
}

String String::generateStr(size_t &i, int endIndex) {
	String result;
	result.size = endIndex - i;
	result.data = new char[endIndex - i + 1];

	size_t counter = 0;
	for (i; i < endIndex; ++i)
	{
		result.data[counter++] = this->data[i];
	}
	result.data[counter] = '\0';

	return result;
}

size_t delimitersCounter(const String& str, const char* delimiter)
{
	size_t count = 0;
	for (size_t i = 0; i < str.size; ++i)
	{
		if (str.data[i] == delimiter[0]) {
			bool contains = true;
			for (size_t j = 1; delimiter[j]; ++j)
			{
				if (str.data[i + j] != delimiter[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				++count;
			}
		}
	}

	return count;
}

void String::reverse()
{
	for (size_t i = 0; i < size / 2; ++i)
	{
		mySwap(data[i], data[size - i - 1]);
	}
}

void String::clear()
{
	const size_t len = size;
	for (size_t i = 0; i < len; ++i)
	{
		popBack();
	}
}

bool String::empty()
{
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] != ' ') {
			return false;
		}
	}
	return true;
}

const char& String::operator[](int index) const
{
	return this->data[index];
}

char& String::operator[](int index)
{
	return this->data[index];
}

void String::operator+=(const String& other)
{
	*this = this->concat(other);
}

String String::operator+(const String& other)
{
	String result = this->concat(other);

	return result;
}

bool String::operator==(const char* other)
{
	if (size != length(other)) {
		return false;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] != other[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(const char* other)
{
	return !(*this == other);
}

void String::append(const String& other)
{
	*this += other;
}

void String::pushBack(char a)
{
	char* newData = new char[size + 2];
	for (size_t i = 0; i < size; ++i)
	{
		newData[i] = this->data[i];
	}
	newData[size] = a;
	newData[size + 1] = '\0';

	delete[] this->data;
	this->data = newData;
	++size;
}

void String::popBack()
{
	if (size > 0) {
		char* newData = new char[size];
		for (size_t i = 0; i < size - 1; ++i)
		{
			newData[i] = this->data[i];
		}
		newData[size - 1] = '\0';

		delete[] this->data;
		this->data = newData;
		--size;
	}
}

int String::find(const char* subString) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == subString[0]) {
			bool contains = true;
			for (size_t j = 1; subString[j]; ++j)
			{
				if (data[i + j] != subString[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				return i;
			}
		}
	}
	return -1;
}

int String::findWithIndex(int index, const char* subString)
{
	for (size_t i = index; i < size; ++i)
	{
		if (data[i] == subString[0]) {
			bool contains = true;
			for (size_t j = 1; subString[j]; ++j)
			{
				if (data[i + j] != subString[j]) {
					contains = false;
					break;
				}
			}
			if (contains) {
				return i;
			}
		}
	}
	return -1;
}

int String::compare(const String& other)
{
	if (this->getSize() > other.getSize()) {
		return 1;
	}
	else if (this->getSize() < other.getSize()) {
		return -1;
	}
	
	for (size_t i = 0; i < size; ++i)
	{
		if (this->data[i] < other.data[i]) {
			return -1;
		}
		else if (this->data[i] > other.data[i]) {
			return 1;
		}
	}
	return 0;
}

void String::swap(String& other)
{
	mySwap(*this, other);
}

String String::getValue(const char& c) const
{
	String result;
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == c) {
			for (size_t j = i + 1; j < size; j++)
			{
				result.pushBack(data[j]);
			}
		}
	}
	return result;
}

bool String::isANumber()
{
	if ((data[0] < '0' || data[0] > '9') && data[0] != '-') {
		return false;
	}
	for (size_t i = 1; i < size; ++i)
	{
		if (data[i] < '0' || data[i] > '9') {
			return false;
		}
	}
	return true;
}

void String::print()
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << data[i];
	}
	std::cout << std::endl;
}

double String::stod()
{
	double beforeDecimalPoint = 0;
	double afterDecimalPoint = 0;
	bool isNegative = false;

	if (data[0] == '-') {
		data[0] = '0';
		isNegative = true;
	}

	int position = find(".");
	if (position == -1) {
		position = size;
	}

	for (int i = 0; i < position; ++i)
	{
		beforeDecimalPoint += (data[i] - '0') * pow(10, (position - i - 1));
	}

	int index = 1;
	for (int i = position + 1; i < size; i++)
	{
		afterDecimalPoint += (data[i] - '0') / pow(10, index);
		++index;
	}

	return  isNegative ? (-1) * beforeDecimalPoint + afterDecimalPoint : beforeDecimalPoint + afterDecimalPoint;
}

char* String::getData() const
{
	return this->data;
}
