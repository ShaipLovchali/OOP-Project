#pragma once
#include "ParseData.h"

void ParseData::parseSvg(const char* fileName)
{
	doc.load_file(fileName);
	pugi::xml_node svgTag = doc.child("svg");

	std::ofstream out("data.svg");

	for (pugi::xml_node tag = svgTag.first_child(); tag; tag = tag.next_sibling()) {
		out << tag.name() << " ";
		for (pugi::xml_attribute attr = tag.first_attribute(); attr; attr = attr.next_attribute())
		{
			out << attr.value() << " ";
		}
	}
	out.close();
}



