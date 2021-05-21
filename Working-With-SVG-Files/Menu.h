#pragma once
#include "ParseData.h"
#include "String.h"
#include "VectorOfFigures.h"
#include "Validator.h"

class Menu {
private:
	String currentFileName;
	String command;
	Vector<String> splitted;

	void determineCommand(VectorOfFigures&, std::ifstream&, String&, Validator&);
	void splitCommand();
	void commandOpen(std::ifstream&, Validator&);
	void commandClose(std::ifstream&);
	void commandSave(VectorOfFigures&, std::ifstream&);
	void commandSaveAs(VectorOfFigures&, std::ifstream&);
	void commandHelp();
	void commandCreate(VectorOfFigures&, Validator&);
	void commandErase(VectorOfFigures&, Validator&);
	void commandTranslate(VectorOfFigures&, Validator&);

public:
	void start();
};





