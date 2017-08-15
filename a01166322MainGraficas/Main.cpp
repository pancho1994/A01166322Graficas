/************************************************

Materia: Graficas Computacionales
Fecha: 14 de Agosto del 2017
Autor: A01166322 Francisco Vil lafranca

************************************************/

#include <iostream>

using namespace std;


int PerimetroRectangulo(int base, int altura) {
	int p = (base + altura) * 2;
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


		int main() {
			int PerimetroRectangulo(int base, int altura);

			float AreaTriangulo(float base, float altura);

			int Mayor(int numero1, int numero2, int numero3);

			int Menor(int numero1, int numero2, int numero3);

			void FilaEstrellas(int n);

			void MatrizEstrellas(int n);

			void PiramideEstrellas(int n);

			void FlechaEstrellas(int n);

			void Fibonacci(int n);

			bool EsPrimo(int numero);

	}