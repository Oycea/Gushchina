//Гущиной Маргариты ПМИ-13БО
//ЛАБОРАТОРНАЯ РАБОТА №6. РАБОТА С МАТРИЦАМИ
//
//Задание 1. МАТРИЦЫ И ОПЕРАЦИИ НАД НИМИ
//Вариант 10. f(x) = 2x^3 − 2x^2 − x. Найти: f(f(A)).

#include <iostream>
#include <iomanip>
#include"matrix_operation.h"
using namespace std;

int input_validation() {
	int num;
	cin >> num;
	while ((std::cin.fail()) || (num <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Некорректные данные. Попробуйте снова" << endl;
		cin >> num;
	}
	return num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int size;

	cout << "Введите размер матрицы: ";
	size = input_validation();
	cout << endl << "Заполните матрицу: " << endl;

	double** matrix_a = input_matrix(size); //Заполнение матрицы А
	double** matrix_b = create_zero_matrix(size); //Заполнение матрицы для вычислений
	double** matrix_res = create_zero_matrix(size); //Заполнение матрицы для вычислений

	//Вычисление f(A) и вывод промежуточных результатов
	cout << "I. Вычисление функции f(A)=2*A^3-2*A^2-A " << endl << endl;
	matrix_res = polynominal_in_matrix(matrix_a, size);

	copy_elements(matrix_res, matrix_a, size);

	//Вычисление f(f(A)) и вывод промежуточных результатов
	cout << endl << "II. Вычисление функции f(f(A))=2*f(A)^3-2*f(A)^2-f(A) " << endl << endl;
	matrix_res=polynominal_in_matrix(matrix_a, size);

	//Вывод ответа
	cout << endl << endl << "ОТВЕТ: " << endl;
	output(matrix_res, size);

	//Очистка памяти
	free(matrix_a, size);
	free(matrix_b, size);
	free(matrix_res, size);

	system("pause");
	return 0;
}