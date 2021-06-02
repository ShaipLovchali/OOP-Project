#pragma once
#include "Validator.h"

class Menu {
private:
	String command;
	Vector<String> splitted;
	VectorOfFigures v;
	std::ifstream in;
	Validator validator;
	String currentFileName;

	void determineCommand();
	void splitCommand();
	void commandOpen();
	void commandClose();
	void commandSave();
	void commandSaveAs();
	void commandHelp();
	void commandPrint();
	void commandCreate();
	void commandErase();
	void commandTranslate();
	void commandWithin();
public:
	void start();
};





