/************************************************

Materia: Graficas Computacionales
Fecha: 14 de Agosto del 2017
Autor: A01166322 Francisco Vil lafranca

************************************************/

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"

using namespace std;




int main() 
{

	std::cout << "Fuck tha police" << std::endl;
	
	Circle killme(5);
	Circle killmeAdvanced(1, "red");
	std::cout << killme.GetRadius() << std::endl;
	std::cout << killmeAdvanced.GetColor() << std::endl;
	std::cin.get();

	
	return 0;
}