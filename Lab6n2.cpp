//Гущиной Маргариты ПМИ-13БО
//ЛАБОРАТОРНАЯ РАБОТА №6. РАБОТА С МАТРИЦАМИ
//
//Задание 2. ОПРЕДЕЛИТЕЛИ
//Вариант 8. Проверка ортогональности матрицы.

#include<iostream>
#include<cmath>
#include"input_check.h"
#include"matrix_operation.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	double det;
	double** matrix;
	double** inverse_matrix;
	double** transposed_matrix;

	cout << "ПРОВЕРКА ОТРОГОНАЛЬНОСТИ МАТРИЦЫ" << endl;
	cout << endl << "Введите размер матрицы: ";
	size = matrix_size_check();
	cout << endl << "Ведите элементы матрицы: " << endl;

	matrix = input_matrix(size); //Заполнение проверяемой матрицы

	det = calculating_determinant(matrix, size); //Вычисление определителя
	//Если определитель равен 0, то обратную матрицу построить нельзя ->
	// -> введённая матрица не является ортогональной
	if (det == 0)
		cout << endl << "Матрица не является ортогональной" << endl;
	else {
		inverse_matrix = create_inverse_matrix(matrix, size); //Создание обратной матрицы
		output(inverse_matrix, size);
		transposed_matrix = create_transposed_matrix(matrix, size); //Создание транспонированной матрицы
		if (is_identity_matrix(inverse_matrix, transposed_matrix, size) == false)
			cout << endl << "Матрица не является ортогональной" << endl;
		else
			cout << endl << "Матрица является ортогональной" << endl;

		//Очистка памяти
		free(inverse_matrix, size);
		free(transposed_matrix, size);
	}

	//Очистка памяти
	free(matrix, size);

	system("pause");
	return 0;
}