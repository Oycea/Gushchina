//Гущиной Маргариты ПМИ-13БО
//ЛАБОРАТОРНАЯ РАБОТА №6. РАБОТА С МАТРИЦАМИ
//
//Задание 3. МАТРИЧНЫЕ УРАВНЕНИЯ
//Вариант 10. 

#include<iostream>
#include <iomanip>
#include<cmath>
#include"matrix_operation.h"
using namespace std;

//Проверка корректности ввода размера матрицы
int natural_number_check() {
	int size;
	cin >> size;
	while ((std::cin.fail()) || (size <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> size;
	}
	return size;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Решение матричного уравнения 5*Х + Х*А = В" << endl;
	int size;
	double det;
	cout << endl << "Введите размер квадратных матриц: ";
	size = natural_number_check();
	cout << endl;
	double** matrix_a;
	double** matrix_b;
	double** matrix_x;

	//Создание матриц для вычислений
	cout << "Введите матрицу А: " << endl;
	matrix_a = input_matrix(size);
	cout << "Введите матрицу В: " << endl;
	matrix_b = input_matrix(size);
	matrix_x = create_zero_matrix(size);

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
	if (det == 0)
		cout << "Вычисления невозможны" << endl;
	else {
		matrix_a = create_inverse_matrix(matrix_a, size);
		output(matrix_a, size);

		cout << endl << endl << "умножим на обратную матрицу матрицу В" << endl;
		cout << "Ответ: " << endl;
		matrix_x = matrix_multiplication_by_matrix(matrix_a, matrix_b, size);
	}

	//Вывод ответа
	output(matrix_x, size);

	//Очистка памяти
	free(matrix_a, size);
	free(matrix_b, size);
	free(matrix_x, size);;
	system("pause");
	return 0;
}