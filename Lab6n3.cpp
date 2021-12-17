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

	//Решение матричного уравнения 5*Х + Х*А = В с промежуточным выводом
	equation_solution(matrix_a, matrix_b, size);

	//Очистка памяти
	free(matrix_a, size);
	free(matrix_b, size);
	system("pause");
	return 0;
}
