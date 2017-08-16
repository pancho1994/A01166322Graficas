/************************************************

Materia: Graficas Computacionales
Fecha: 14 de Agosto del 2017
Autor: A01166322 Francisco Vil lafranca

************************************************/

#include <iostream>

using namespace std;


int PerimetroRectangulo(int base, int altura) {
	int p = 2 * base + 2 * altura;
	return p;
}

float AreaTriangulo(float base, float altura) {
	  float a = (base * altura) / 2;
	  return a;
}

int Mayor(int numero1, int numero2, int numero3) {
	if ((numero2 < numero1) && (numero3 < numero1 ) ){
		return numero1;
	}
	else if ((numero1 < numero2) && (numero3 < numero2)) {
		return numero2;
	}
	else {
		return numero3;
	}
}

int Menor(int numero1, int numero2, int numero3) {
	if ((numero1 < numero2) && (numero1 < numero3)) {
		return numero1;
	}
	else if ((numero2 < numero1) && (numero2 < numero3)) {
		return numero2;
	}
	else {
		return numero3;
	}
}

void FilaEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		cout << "*";
	}
}

void MatrizEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void PiramideEstrellas(int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}


void FlechaEstrellas(int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
		for (int i = n + n; i < n; i--) {
			for (int k = 0; k < i; k++) {
				cout << "*";
			}
			cout << endl;
		}
	}
}


void Fibonachi(int n)
{
	if (n <= 0) return;
	int i = 1;
	if (n >= i)
		std::cout << i << " ";
	
	int j = 1;
	if (n >= 2)
		std::cout << j << " ";

	for (int k = 2; k < n; k++);
	{
		int temp = i + j; 
		i = j;
		j = temp;
		std::cout << temp << endl;

}


bool EsPrimo(int numero)
{
	if (numero <= 0)
		return false;

	for (int i = 2; i < numero; i++)
	{
		if (numero % i == 0) return false;
	}

	return true;

}

int main() 
{
	Fibonachi(5)

	std::cout << "Fuck tha police" << std::endl;
	int perimetro = PerimetroRectangulo(5, 3);
	std::cout << perimetro << std::endl;
	std::cin.get();

	


	return 0;
}