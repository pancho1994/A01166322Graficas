/************************************************

Materia: Graficas Computacionales
Fecha: 23 de Agosto del 2017
Autor: A01166322 Francisco Vil lafranca

************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "InputFile.h"


int main(int argc, char* argv[])
{
	
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;
}