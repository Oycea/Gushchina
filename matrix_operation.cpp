#include<iostream>
#include <iomanip>
#include<cmath>
#include"matrix_operation.h"
using namespace std;

//Выделение памяти для матрицы
double** memory_allocation_matrix(int size) {
	double** matrix = new double* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new double[size];
	return matrix;
}

//Заполнение матрицы
double** input_matrix(int size) {
	double** matrix = memory_allocation_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> matrix[i][j];
	return matrix;
}

//Создание нулевой матрицы
double** create_zero_matrix(int size) {
	double** matrix = memory_allocation_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	return matrix;
}

//Обнуление всех элементов матрицы
double** zero_matrix(double** matrix, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	return matrix;
}

//Построение минора матрицы
double** create_minor(double** matr, int size, int row_idx, int column_idx) {
	double** minor;
	if (size == 1) {
		minor = memory_allocation_matrix(size);
		minor[0][0] = matr[0][0];
	}
	else {
		minor = memory_allocation_matrix(size - 1);
		int minor_i = 0;
		for (int i = 0; i < size; i++) {
			if (i != row_idx) {
				for (int j = 0, minor_j = 0; j < size; j++) {
					if (j != column_idx) {
						minor[minor_i][minor_j] = matr[i][j];
						minor_j++;
					}
				}
				minor_i++;
			}
		}
	}
	return minor;
}

//Вычисление определителя матрицы
double calculating_determinant(double** matrix, int size) {
	if (size == 1)
		return matrix[0][0];
	else if (size == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	double det = 0;
	for (int k = 0; k < size; k++) {
		double** minor = memory_allocation_matrix(size - 1);
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j == k)
					continue;
				else if (j < k)
					minor[i - 1][j] = matrix[i][j];
				else
					minor[i - 1][j - 1] = matrix[i][j];
			}
		}
		det += pow(-1, k + 2) * matrix[0][k] * calculating_determinant(minor, size - 1);
	}
	return det;
}

//Построение транспонированной матрицы
double** create_transposed_matrix(double** matrix, int size) {
	double** transposed_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			transposed_matrix[i][j] = matrix[j][i];
	return transposed_matrix;
}

//Построение обратной матрицы
double** create_inverse_matrix(double** matrix, int size) {
	double det_minor;
	double det_matrix = calculating_determinant(matrix, size);
	double** minor;
	double** inverse_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			minor = create_minor(matrix, size, j, i);
			if (size == 1)
				det_minor = det_matrix;
			else
				det_minor = calculating_determinant(minor, size - 1);
			inverse_matrix[i][j] = 1 / det_matrix * pow(-1, i + j) * det_minor;
		}
	return inverse_matrix;
}

//Создание единичной квадратной матрицы
double** create_identity_matrix(int size) {
	double** identity_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j)
				identity_matrix[i][j] = 1;
	return identity_matrix;
}

//Умножение матрицы на матрицу
double** matrix_multiplication_by_matrix(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				matrix_res[i][j] += matrix_2[i][k] * matrix_1[k][j];
			}
		}
	}
	return matrix_res;
}

//Умножение матрицы на число
double** matrix_multiplication_by_number(double** matrix, int k, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = matrix[i][j] * k;
	return matrix;
}

//Разность двух матриц
double** substraction_of_matrices(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_res[i][j] = matrix_1[i][j] - matrix_2[i][j];
	return matrix_res;
}

//Сумма двух матриц
double** sum_of_matrices(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_res[i][j] = matrix_1[i][j] + matrix_2[i][j];
	return matrix_res;
}


//Копирование элементов из одной матрицы в другую
double** copy_elements(double** matrix_1, double** matrix_2, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_2[i][j] = matrix_1[i][j];
	return matrix_2;
}

//Проверка матриц на равенство
bool is_identity_matrix(double** matrix_1, double** matrix_2, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix_1[i][j] != matrix_2[i][j])
				return false;
	return true;
}

//Вывод матрицы
void output(double** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(15) << matrix[i][j];
		cout << endl;
	}
}

//Решение матричного уравнения 5*Х + Х*А = В с промежуточным выводом
bool equation_solution(double** matrix_a, double** matrix_b, int size) {
	double det;
	double** matrix_x = create_zero_matrix(size);
	if (size == 1) {
		cout << "Преобразуем к виду X * (1 + " << matrix_a[0][0] << ") = " << matrix_b[0][0] << endl;
		cout << "Вычислим X * " << matrix_a[0][0] + 5 << " = " << matrix_b[0][0] << endl;
		cout << "ОТВЕТ: " << matrix_b[0][0] / (matrix_a[0][0] + 5) << endl;
		return true;
	}
	else {
		//Решение уравнения с поэтапным выводом
		cout << "Преобразуем выражение к виду Х(5Е + А) = В " << endl;
		cout << "5Е = " << endl;
		double** identity_matrix = create_identity_matrix(size);
		identity_matrix = matrix_multiplication_by_number(identity_matrix, 5, size);
		output(identity_matrix, size);

		cout << endl << "5Е + А = " << endl;
		matrix_a = sum_of_matrices(matrix_a, identity_matrix, size);
		output(matrix_a, size);

		cout << endl << "Для деления В на получившуюся сумму найдём обратную матрицу к 5Е + А" << endl;
		det = calculating_determinant(matrix_a, size);
		if (det == 0) {
			cout << "Вычисления невозможны" << endl;
			return false;
		}
		matrix_a = create_inverse_matrix(matrix_a, size);
		output(matrix_a, size);

		cout << endl << endl << "умножим на обратную матрицу матрицу В" << endl;
		cout << "Ответ: " << endl;
		matrix_x = matrix_multiplication_by_matrix(matrix_a, matrix_b, size);
		//Вывод ответа
		output(matrix_x, size);
		free(matrix_x, size);
		return true;
	}
}

//Освобождение памяти матрицы
void free(double** matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}
