#pragma once

namespace Matrix {
	/// <summary>
	/// Funkcja do wyswietlenia macierzy
	/// </summary>
	/// <param name="matrix">Wskaznik do macierzy</param>
	/// <param name="n">Wymiar macierzy</param>
	void print(const double* matrix, const unsigned int n);

	/// <summary>
	/// Funkcja do kopiowania macierzy
	/// </summary>
	/// <param name="matrix">Wskaznik do macierzy</param>
	/// <param name="n">Wymiar macierzy</param>
	/// <returns>Wskaznik do nowej macierzy</returns>
	double* copy(const double* matrix, const unsigned int n);

	/// <summary>
	/// Funkcja do mnozenia macierzy kwadratowych
	/// </summary>
	/// <param name="matrix1">Wskaznik do macierzy</param>
	/// <param name="matrix2">Wskaznik do macierzy</param>
	/// <param name="n">Wymiar macierzy</param>
	/// <returns>Wskaznik do nowej macierzy</returns>
	double* multiply(const double* matrix1, const double* matrix2, const unsigned int n);

	/// <summary>
	/// Funkcja do sprawdzenia czy macierze sa sobie rowne
	/// </summary>
	/// <param name="matrix1">Wskaznik do pierwszej macierzy</param>
	/// <param name="matrix2">Wskaznik do drugiej macierzy</param>
	/// <param name="n">Wymiar macierzy</param>
	/// <returns>True, macierze sa takie same, w przeciwnym wypadku false</returns>
	bool areEqual(const double* matrix1, const double* matrix2, const unsigned int n);
}
