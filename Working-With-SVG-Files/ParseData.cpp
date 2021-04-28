#pragma once
#include "ParseData.h"

int ParseData::loadFile()
{
	char fileName[] = "figures.svg";

	pugi::xml_parse_result result = doc.load_file(fileName);
	if (!result) {
		std::ofstream newFile(fileName);
		newFile.close();
		return -1;
	}
}

void ParseData::parseSvg()
{
	loadFile();
	pugi::xml_node svgTag = doc.child("svg");

	for (pugi::xml_node tag = svgTag.first_child(); tag; tag = tag.next_sibling()) {
		getAttr = "";
		for (pugi::xml_attribute attr = tag.first_attribute(); attr; attr = attr.next_attribute())
		{
			getAttr += attr.value();
			getAttr += " ";
		}

		split();

		if (strcmp(tag.name(), "rect") == 0) {
			Rectangle* r = new Rectangle(3, 2, 4, 4, "blue");
			figures.push_back(r);
		}
		else if (strcmp(tag.name(), "circle") == 0) {
			Circle* c = new Circle(2, 2, 3, "red");
			figures.push_back(c);
		}
		else if (strcmp(tag.name(), "line") == 0) {
			Line* l = new Line(4, 1, 4, 1, "green");
			figures.push_back(l);
		}
	}
}

void ParseData::split()
{
	splitted.clear();
	String subStr = "";
	for (size_t i = 0; i < getAttr.getSize(); ++i)
	{
		if (getAttr[i] == ' ') {
			splitted.push_back(subStr);
			subStr = "";
			continue;
		}
		subStr.pushBack(getAttr[i]);
	}
}

char* ParseData::toCharArr(const String& str, size_t index)
{
	char* fillColor = new char[splitted[index].getSize() + 1];
	for (size_t i = 0; i < splitted[index].getSize(); i++)
	{
		fillColor[i] = splitted[index][i];
	}
	fillColor[splitted[index].getSize()] = '\0';

	return fillColor;
}

void ParseData::printFigures() const
{
	for (size_t i = 0; i < figures.getSize(); ++i)
	{
		figures[i]->print();
	}
}

