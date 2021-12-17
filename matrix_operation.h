#ifndef _MATRIX_OPERATION_H_
#define _MATRIX_OPERATION_H_

//Выделение памяти для матрицы
double** memory_allocation_matrix(int size);

//Заполнение матрицы
double** input_matrix(int size);

//Создание нулевой матрицы
double** create_zero_matrix(int size);

//Обнуление всех элементов матрицы
double** zero_matrix(double** matrix, int size);

//Построение минора матрицы по выбранноиу элементу
double** create_minor(double** matr, int size, int row_idx, int column_idx);

//Вычисление определителя матрицы
double calculating_determinant(double** matrix, int size);

//Построение транспонированной матрицы
double** create_transposed_matrix(double** matrix, int size);

//Построение обратной матрицы
double** create_inverse_matrix(double** matrix, int size);

//Создание единичной квадратной матрицы
double** create_identity_matrix(int size);

//Умножение матрицы на матрицу
double** matrix_multiplication_by_matrix(double** matrix_1, double** matrix_2, int size);

//Умножение матрицы на число
double** matrix_multiplication_by_number(double** matrix, int k, int size);

//Разность двух матриц
double** substraction_of_matrices(double** matrix_1, double** matrix_2, int size);

//Сумма двух матриц
double** sum_of_matrices(double** matrix_1, double** matrix_2, int size);

//Копирование элементов из одной матрицы в другую
double** copy_elements(double** matrix_1, double** matrix_2, int size);

//Проверка матриц на равенство
bool is_identity_matrix(double** matrix_1, double** matrix_2, int size);

//Вывод матрицы
void output(double** matrix, int size);

//Решение матричного уравнения 5*Х + Х*А = В с промежуточным выводом
bool equation_solution(double** matrix_a, double** matrix_b, int size);

//Освобождение памяти матрицы
void free(double** matrix, int size);

#endif //_MATRIX_OPERATION_H_
