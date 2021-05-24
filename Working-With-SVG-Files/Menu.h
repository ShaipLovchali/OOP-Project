#pragma once
#include "VectorOfFigures.h"
#include "Validator.h"

class Menu {
private:
	String currentFileName;
	String command;
	Vector<String> splitted;

	void determineCommand(VectorOfFigures&, std::ifstream&, String&, Validator&);
	void splitCommand();
	void commandOpen(VectorOfFigures&, std::ifstream&, const Validator&);
	void commandClose(std::ifstream&, const Validator&);
	void commandSave(VectorOfFigures&, std::ifstream&);
	void commandSaveAs(VectorOfFigures&, std::ifstream&);
	void commandHelp();
	void commandCreate(VectorOfFigures&, const Validator&);
	void commandErase(VectorOfFigures&, const Validator&);
	void commandTranslate(VectorOfFigures&, const Validator&);
	void commandWithin(VectorOfFigures&, const Validator&);

public:
	void start();
};





