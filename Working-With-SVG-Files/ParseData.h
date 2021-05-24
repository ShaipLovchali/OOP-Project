#pragma once
#define PUGIXML_HEADER_ONLY
#include "pugixml.cpp"
#include <fstream>

class ParseData {
private:
	pugi::xml_document doc;
public:
	void parseSvg(const char*);
};
