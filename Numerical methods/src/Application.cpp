#include "pch.h"
#include "Source.h"
#include "Point.h"
#include "Matrix.h"
#include "MathFunctions.h"

static void zadanie1() {
	double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

	std::cout << "w[-4] = " << horner(-4, a, 4) << std::endl;
	std::cout << "w[-1] = " << horner(-1, a, 4) << std::endl;
}

static void zadanie2() {
	double b[4] = { 1.0 / 2.0, -7.0 / 6.0, 5.0 / 3.0, -4.0 };
	double xn[3] = { 0, -1.0, -4.0 };

	std::cout << "w[0] = " << hornerN(0, b, xn, 4) << std::endl;
	std::cout << "w[2] = " << hornerN(2, b, xn, 4) << std::endl;
}

static void zadanie3() {
	double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

	double b_r[4] = { -4.0, 5.0 / 3.0, -7.0 / 6.0, 1.0 / 2.0 };
	double xn_r[3] = { -4.0, -1.0, 0 };

	double* result = WspNew_WspNat(b_r, xn_r, 4);

	std::cout << "Poprawne wspolczynniki:\n";

	for (int i = 3; i >= 0; i--) {
		std::cout << a[i] << "\n";
	}

	std::cout << "Obliczone wspolczynniki:\n";

	for (int i = 0; i < 4; i++) {
		std::cout << result[i] << "\n";
	}

	delete[] result;
}

static void zadanie4() {
	Point points[5];

	points[0] = Point(-2, 5);
	points[1] = Point(-1, -2);
	points[2] = Point(0, 4);
	points[3] = Point(1, -7);
	points[4] = Point(2, 2);

	std::ofstream file;
	file.open("Lagrange_Results.txt");

	for (double i = -2; i <= 2.01; i += 0.01) {
		double y = lagrange(points, i, 5);
		file << i << ", " << y << "\n";
	}

	file.close();
}

static void zadanie5() {
	Point points[5];

	points[0] = Point(-2, 5);
	points[1] = Point(-1, -2);
	points[2] = Point(0, 4);
	points[3] = Point(1, -2);
	points[4] = Point(2, 2);

	double* result = newton(points, 5);

	std::cout << "\n";

	for (int i = 0; i < 5; i++) {
		std::cout << result[i] << "\n";
	}

	delete[] result;
}

static void zadanie6() {
	int n = 5;
	int m = n + 1;

	// Tablica wspolczynnikow
	double* A = new double[n * n] {
		1, -3, 4, 6.8, 9,
		-3, 2, 4.6, 6.3, -10,
		2, -1, 2.8, -8.4, -5,
		-6, 2, 7, -0.5, -0.9, 
		5, -2, -0.5, 12, -4
	};

	// Tablica wynikow
	double* b = new double[n] {
		74.64,
		-40.26,
		-2.32,
		12.6,
		-8.9
	};

	// Tablica obliczonych wartosci
	double* results = gauss_crout(A, b, n);

	if (results != nullptr) {
		// Wyświetlenie wynikow
		for (int i = 0; i < n; i++) {
			std::cout << "x" << i + 1 << " = " << results[i] << "\n";
		}
	}
	else {
		std::cout << "Mozliwe dzielenie przez 0\n";
	}

	delete[] A;
	delete[] b;
	delete[] results;
}

static void zadanie7() {
	int n = 3;

	double* check;
	double* L = new double[n * n] {0};
	double* U = new double[n * n] {0};

	double* A1 = new double[n * n] {
		60, 30, 20,
		30, 20, 15,
		20, 15, 12
	};
	std::cout << "Macierz A1\n";
	if (!doolittle(A1, L, U, n)) {
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else {
		std::cout << "Macierz gornotrojkatna:\n";
		Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		Matrix::print(L, n);
	}

	check = Matrix::multiply(L, U, n);
	std::cout << (Matrix::areEqual(A1, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

	delete[] A1;
	delete[] check;

	double* A2 = new double[n * n] {
		3, 0, 1,
		0, -1, 3,
		1, 3, 0
	};
	std::cout << "\nMacierz A2\n";
	if (!doolittle(A2, L, U, n)) {
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else {
		std::cout << "Macierz gornotrojkatna:\n";
		Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		Matrix::print(L, n);
	}

	check = Matrix::multiply(L, U, n);
	std::cout << (Matrix::areEqual(A2, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

	delete[] A2;
	delete[] check;

	double* A3 = new double[n * n] {
		2, 1, -2,
		4, 2, -1,
		6, 3, 11
	};
	std::cout << "\nMacierz A3\n";
	if (!doolittle(A3, L, U, n)) {
		std::cout << "Nie mozna rozlozyc macierzy\n";
	}
	else {
		std::cout << "Macierz gornotrojkatna:\n";
		Matrix::print(U, n);

		std::cout << "Macierz dolnotrojkatna:\n";
		Matrix::print(L, n);
	}
	delete[] A3;

	delete[] L;
	delete[] U;
}

int main(int argc, int** argv) {
	
	zadanie7();

	return 0;
}