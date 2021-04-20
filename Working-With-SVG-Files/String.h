#pragma once
#include <iostream>
#include <fstream>

class String {
private:
	char* data;
	size_t size;

	void copy(const String&);
	void erase();
public:
	String(); //Част от Г4
	String(const String&); //Част от Г4
	String& operator=(const String&); //Част от Г4
	String(size_t size); //Задава начален размер на низа
	String(const char* data); //Задава начална стойност на низа
	~String(); //Част от Г4

	template<typename T>
	friend void mySwap(T&, T&);

	size_t getSize() const; //Връща размера на низа
	String concat(const String&); //Конкатенира два низа (низ1 = "а", низ2 = "b", низ1.concat(низ2) = "ab")
	String* split(const char* delimiter); //Разделя низа по подаден символ или низ
	String generateStr(size_t&, int); // Генерира временен стринг, който използваме в split метода
	friend size_t delimitersCounter(const String&, const char*); // Намира броя на даден разделител в един стринг
	void reverse(); //Обръща елементите на низа
	void clear(); //Изчиства елементите на низа
	bool empty(); //Проверява дали низа е празен

	char& operator[](int index); //Връща символ от низа
	bool operator==(const char*) const;
	bool operator!=(const char*) const;
	void operator+=(const String&); //Добавя към един низ друг
	String operator+(const String&); //Събира два низа и връща нов низ
	void append(const String&); //Добавя към един низ друг
	void pushBack(char); //Добавя символ в края на низа
	void popBack(); //Премахва символ от края на низа
	int find(const char*); //Търси и връща първия индекс, на който се среща подадения низ или символ. Ако не съществува такъв индекс връща -1;
	int findWithIndex(int, const char*); // Използвам метода за намиране на индекса на разделителя, от даден индекс натам
	int compare(const String&); //Сравнява два низа лексикографски
	void swap(String&); //Разменя стойностите на два низа

	void print(); //Извежда на стандартния изход низ
	int toInt();

	friend std::istream& operator>>(std::istream& in, String& str);

};
