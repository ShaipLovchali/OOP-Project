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

		Figure* fig = getFig(tag.name());
		
		figures.push_back(fig);
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

Figure* ParseData::getFig(const char* figName)
{
	if (strcmp(figName, "rect") == 0) {
		return new Rectangle(splitted[0].toNum<double>(), splitted[1].toNum<double>(), splitted[2].toNum<int>(), splitted[3].toNum<int>(), toCharArr(splitted[4], 4));
	}
	else if (strcmp(figName, "circle") == 0) {
		return new Circle(splitted[0].toNum<double>(), splitted[1].toNum<double>(), splitted[2].toNum<double>(),toCharArr(splitted[3], 3));
	}
	else if (strcmp(figName, "line") == 0) {
		return new Line(splitted[0].toNum<double>(), splitted[1].toNum<double>(), splitted[2].toNum<double>(), splitted[3].toNum<double>(), toCharArr(splitted[4], 4));
	}
}

void ParseData::printFigures() const
{
	for (size_t i = 0; i < figures.getCapacity(); ++i)
	{
		figures[i]->print();
	}
}

