#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>


bool InputFile::Read(std::string filename)
{
	std::fstream fs;
	fs.open("Prueba.txt");

	if (fs.is_open()) {
		std::stringstream ss;
		ss << fs.rdbuf();
		_contents = ss.str();
		return true;

	}
	else {
		return false;
	}
}

std::string InputFile::GetContents()
{
	return std::string(_contents);
}