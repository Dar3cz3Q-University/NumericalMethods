#include "Numerical_Methods.h"

#include "matrix/Matrix.h"
#include "Integrals/Trapeze.h"
#include "Integrals/Simpson.h"
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"
#include "Orthonormalization/GramSchmidt.h"
#include "Approximation/Approximation.h"
#include "DifferentialEquations/DifferentialEquations.h"

#include "Integrals/UnitQuadrature.h"

#define VECTOR_TYPE NumericalMethods::Vector::Vector3D

double func1(double x)
{
	return (pow(x, 2) * pow(sin(x), 3));
};

double func2(double x)
{
	return ((x - 1) * exp(pow(x, 2)));
};

double func3(double x)
{
	if (fabs(x) < NumericalMethods::EPSILON)
		return 0;

	return (sin(x) / x);
};

double func4(double x)
{
	if (fabs(x) < NumericalMethods::EPSILON)
		return 0;

	return (sin(1 / x));
};

static double test(double x)
{
	return sin(-x) + exp(-x) - pow(x, 3);
}

static double stefanBoltzmann(double t)
{
	return (-1e-12 * pow(t, 4));
}

// TODO Split tasks to other .cpp files

int main(int argc, char** argv) 
{
	std::cout.precision(10);

	// Zadanie 1
	{
		double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

		std::cout << "w[-4] = " << NumericalMethods::horner(-4, a, 4) << std::endl;
		std::cout << "w[-1] = " << NumericalMethods::horner(-1, a, 4) << std::endl;
	}


	// Zadanie 2
	{
		double b[4] = { 1.0 / 2.0, -7.0 / 6.0, 5.0 / 3.0, -4.0 };
		double xn[3] = { 0, -1.0, -4.0 };

		std::cout << "w[0] = " << NumericalMethods::hornerN(0, b, xn, 4) << std::endl;
		std::cout << "w[2] = " << NumericalMethods::hornerN(2, b, xn, 4) << std::endl;
	}

	// Zadanie 3
	{
		double a[4] = { 1.0 / 2.0, 4.0 / 3.0, -13.0 / 6.0, -2.0 };

		double b_r[4] = { -4.0, 5.0 / 3.0, -7.0 / 6.0, 1.0 / 2.0 };
		double xn_r[3] = { -4.0, -1.0, 0 };

		double* result = NumericalMethods::WspNew_WspNat(b_r, xn_r, 4);

		std::cout << "Poprawne wspolczynniki:\n";

		for (int i = 3; i >= 0; i--)
		{
			std::cout << a[i] << "\n";
		}

		std::cout << "Obliczone wspolczynniki:\n";

		for (int i = 0; i < 4; i++)
		{
			std::cout << result[i] << "\n";
		}

		delete[] result;
	}

	// Zadanie 4
	{
		NumericalMethods::Point points[5];

		points[0] = NumericalMethods::Point(-2, 5);
		points[1] = NumericalMethods::Point(-1, -2);
		points[2] = NumericalMethods::Point(0, 4);
		points[3] = NumericalMethods::Point(1, -7);
		points[4] = NumericalMethods::Point(2, 2);

		std::ofstream file;
		file.open("Res/Lagrange_Results.txt");

		for (double i = -2; i <= 2.01; i += 0.01)
		{
			double y = NumericalMethods::lagrange(points, i, 5);
			file << i << ", " << y << "\n";
		}

		file.close();
	}

	// Zadanie 5
	{
		NumericalMethods::Point points[5];

		points[0] = NumericalMethods::Point(-2, 5);
		points[1] = NumericalMethods::Point(-1, -2);
		points[2] = NumericalMethods::Point(0, 4);
		points[3] = NumericalMethods::Point(1, -2);
		points[4] = NumericalMethods::Point(2, 2);

		double* result = NumericalMethods::newton(points, 5);

		std::cout << "\n";

		for (int i = 0; i < 5; i++)
		{
			std::cout << result[i] << "\n";
		}

		delete[] result;
	}

	// Zadanie 6
	{
		int n = 5;
		int m = n + 1;

		// Tablica wspolczynnikow
		double* A = new double[n * n]
			{
				1, -3, 4, 6.8, 9,
					-3, 2, 4.6, 6.3, -10,
					2, -1, 2.8, -8.4, -5,
					-6, 2, 7, -0.5, -0.9,
					5, -2, -0.5, 12, -4
			};

		// Tablica wynikow
		double* b = new double[n]
			{
				74.64,
					-40.26,
					-2.32,
					12.6,
					-8.9
			};

		// Tablica obliczonych wartosci
		double* results = NumericalMethods::gauss_crout(A, b, n);

		if (results != nullptr)
		{
			// Wyświetlenie wynikow
			for (int i = 0; i < n; i++)
			{
				std::cout << "x" << i + 1 << " = " << results[i] << "\n";
			}
		}
		else
		{
			std::cout << "Mozliwe dzielenie przez 0\n";
		}

		delete[] A;
		delete[] b;
		delete[] results;
	}

	// Zadanie 7
	{
		int n = 3;

		double* check;
		double* L = new double[n * n] {0};
		double* U = new double[n * n] {0};

		double* A1 = new double[n * n]
			{
				60, 30, 20,
					30, 20, 15,
					20, 15, 12
			};
		std::cout << "Macierz A1\n";
		if (!NumericalMethods::doolittle(A1, L, U, n))
		{
			std::cout << "Nie mozna rozlozyc macierzy\n";
		}
		else
		{
			std::cout << "Macierz gornotrojkatna:\n";
			NumericalMethods::Matrix::Print(U, n);

			std::cout << "Macierz dolnotrojkatna:\n";
			NumericalMethods::Matrix::Print(L, n);
		}

		check = NumericalMethods::Matrix::Multiply(L, U, n);
		std::cout << (NumericalMethods::Matrix::AreEqual(A1, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

		delete[] A1;
		delete[] check;

		double* A2 = new double[n * n]
			{
				3, 0, 1,
					0, -1, 3,
					1, 3, 0
			};
		std::cout << "\nMacierz A2\n";
		if (!NumericalMethods::doolittle(A2, L, U, n))
		{
			std::cout << "Nie mozna rozlozyc macierzy\n";
		}
		else
		{
			std::cout << "Macierz gornotrojkatna:\n";
			NumericalMethods::Matrix::Print(U, n);

			std::cout << "Macierz dolnotrojkatna:\n";
			NumericalMethods::Matrix::Print(L, n);
		}

		check = NumericalMethods::Matrix::Multiply(L, U, n);
		std::cout << (NumericalMethods::Matrix::AreEqual(A2, check, n) ? "Rozklad poprawny" : "Cos poszlo nie tak");

		delete[] A2;
		delete[] check;

		double* A3 = new double[n * n]
			{
				2, 1, -2,
					4, 2, -1,
					6, 3, 11
			};
		std::cout << "\nMacierz A3\n";
		if (!NumericalMethods::doolittle(A3, L, U, n))
		{
			std::cout << "Nie mozna rozlozyc macierzy\n";
		}
		else
		{
			std::cout << "Macierz gornotrojkatna:\n";
			NumericalMethods::Matrix::Print(U, n);

			std::cout << "Macierz dolnotrojkatna:\n";
			NumericalMethods::Matrix::Print(L, n);
		}
		delete[] A3;

		delete[] L;
		delete[] U;
	}

	// Zadanie 8.1
	{
		std::cout << "Funkcja 1\n";

		double a = 0.0;
		double b = 4.5;

		double correct_result = -4.402577;

		double h = 10e-2;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 0; i < 5; i++)
		{
			std::cout << "h: " << h << "\n";
			std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func1) << "\n";
			std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func1) << "\n";
			h /= 10;
		}
	}

	// Zadanie 8.2
	{
		std::cout << "Funkcja 2\n";

		double a = -2.0;
		double b = 2.0;

		double correct_result = -32.90526;

		double h = 10e-2;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 0; i < 5; i++)
		{
			std::cout << "h: " << h << "\n";
			std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func2) << "\n";
			std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func2) << "\n";
			h /= 10;
		}
	}

	// Zadanie 8.3
	{
		std::cout << "Funkcja 3\n";

		double a = 10e-6;
		double b = 1;

		double correct_result = 0.946831;

		double h = 10e-2;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 0; i < 5; i++)
		{
			std::cout << "h: " << h << "\n";
			std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func3) << "\n";
			std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func3) << "\n";
			h /= 10;
		}
	}

	// Zadanie 8.4
	{
		std::cout << "Funkcja 4\n";

		double a = 10e-4;
		double b = 1;

		double correct_result = 0.5040661;

		double h = 10e-2;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 0; i < 5; i++)
		{
			std::cout << "h: " << h << "\n";
			std::cout << "quad_t (trapeze): " << NumericalMethods::Integrals::trapeze(a, b, h, &func4) << "\n";
			std::cout << "quad_s (Simpson): " << NumericalMethods::Integrals::simpson(a, b, h, &func4) << "\n";
			h /= 10;
		}
	}

	// Zadanie 9.1
	{
		std::cout << "Funkcja 1\n";

		double a = 0.0;
		double b = 4.5;

		double correct_result = -4.402577;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 2; i <= 5; i++)
		{
			std::cout << "n: " << i << "\n";
			std::cout << "Gauss-Legendre: " << NumericalMethods::Integrals::gauss_Legendre(a, b, 10e-5, i, &func1) << "\n";
		}
	}

	// Zadanie 9.2
	{
		std::cout << "Funkcja 2\n";

		double a = -2.0;
		double b = 2.0;

		double correct_result = -32.90526;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		for (int i = 2; i <= 5; i++)
		{
			std::cout << "n: " << i << "\n";
			std::cout << "Gauss-Legendre: " << NumericalMethods::Integrals::gauss_Legendre(a, b, 10e-6, i, &func2) << "\n";
		}
	}

	// Zadanie 9.3
	{
		std::cout << "Funkcja 3\n";

		double a = -2.0;
		double b = 2.0;

		double correct_result = 122.2095;

		std::cout << "Poprawny wynik: " << correct_result << "\n";

		// od stopnia najwyzszego do 0
		double w1[] = { 1, 2, 1, -2 };
		double w2[] = { 2, 1, -1, 10 };

		std::cout << "Gauss-Legendre dla wielomianow: " << NumericalMethods::Integrals::gauss_Legendre5(w1, w2, a, b, 10e-6, 4) << "\n";
		std::cout << "Gauss-Legendre dla wielomianow: " << NumericalMethods::Integrals::gauss_Legendre5(w1, w2, a, b, 10e-6, 4) << "\n";
	}

	// Zadanie 10
	{
		using namespace NumericalMethods::Vector;
		using namespace NumericalMethods::Orthonormalization;

		PROFILE_APP_FUNCTION();
		int n = 3;

		VECTOR_TYPE vectors[] = {
			VECTOR_TYPE(0, 3, 4),
			VECTOR_TYPE(1, 0, 1),
			VECTOR_TYPE(1, 1, 3)
		};

		VECTOR_TYPE* basis = GramSchmidt<VECTOR_TYPE>(vectors, n);

		for (int i = 0; i < n; i++)
		{
			std::cout << vectors[i] << "\n";
		}
		std::cout << "\n";

		for (int i = 0; i < n; i++)
		{
			std::cout << basis[i] << "\n";
		}

		delete[] basis;
	}

	// Zadanie 11
	{
		double a = 0.0, b = 1.0;
		uint32_t n = 5;

		double** result = NumericalMethods::Orthonormalization::GramSchmidt(a, b, n);

		for (uint32_t i = n; i > 0; i--) std::cout << "\t" << "x^" << (i - 1);
		std::cout << "\n";
		for (uint32_t i = 0; i < n; i++)
		{
			std::cout << "G" << i << "\t";
			for (uint32_t j = 0; j < n; j++)
			{
				if (result[i][j] != 0) std::cout << result[i][j];
				std::cout << "\t";
			}
			std::cout << "\n";
		}

		for (uint32_t i = 0; i < n; i++) delete result[i];
		delete result;
	}

	// Zadanie 12
	{
		double a = 0.0, b = 1.0;
		uint32_t n = 5;

		double* result = NumericalMethods::Approximation::ApproximatePolynomial(a, b, &test, n);

		for (uint32_t i = n; i > 0; i--) std::cout << "\t" << "x^" << (i - 1);
		std::cout << "\n";
		for (uint32_t i = 0; i < n; i++) std::cout << result[i] << "\t";
		std::cout << "\n";

		std::ofstream file;
		file.open("Res/Approximation_Results.csv");

		for (double x = -2; x <= 2; x += 0.001)
		{
			double w = NumericalMethods::horner(x, result, n);
			double f = test(x);
			file << x << "," << w << "," << f << "\n";
		}

		file.close();

		delete[] result;
	}

	// Zadanie 13
	{
		double t0 = 1200.0;
		double dtime = 300.0; // seconds

		double result = NumericalMethods::DifferentialEquations::Euler(&stefanBoltzmann, 0.1, t0, dtime);
		std::cout << "Wynik Euler: " << result << "\n";

		result = NumericalMethods::DifferentialEquations::RungeKutta4(&stefanBoltzmann, 0.1, t0, dtime);
		std::cout << "Wynik Runge-Kutta: " << result << "\n";
	}
}