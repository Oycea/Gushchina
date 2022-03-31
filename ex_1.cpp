#include <iostream>
#include <iomanip>
#include "matrix_operation.h"
#include "correct_input.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	int size;
	cout << "������� ������ �������: ";
	correct_input_N(size);
	cout << endl << "��������� ������� A: " << endl;
	double** matrix_a = input_matrix(size); //���������� ������� �
	cout << endl << "��������� ������� B: " << endl;
	double** matrix_b = input_matrix(size); //���������� ������� B
	double** matrix_a_new = create_zero_matrix(size); //���������� ������� A+3 ��� ����������
	double** matrix_b_new = create_zero_matrix(size); //���������� ������� B*A ��� ����������
	double** matrix_A_stroke = create_zero_matrix(size); //���������� ������� A` ��� ����������
	double** matrix_B_stroke = create_zero_matrix(size); //���������� ������� B` ��� ����������

	//matrx_b * matrix_a = B_new;
	matrix_b_new = matrix_multiplication_by_matrix(matrix_b, matrix_a, size);
	//matrix_a + 3 = A_new;
	matrix_a_new = sqr_matrix_addition_num(matrix_a, size, 3);
	cout << "A_new = A + 3:\n";
	output(matrix_a_new, size);
	cout << "B_new = B * A:\n";
	output(matrix_b_new, size);

	//���������� f(A`) � ����� ������������� �����������
	cout << "I. ���������� ������� f(A + 3)=2*A_new^3-2*A_new^2-A_new " << endl << endl;
	matrix_A_stroke = polynominal_in_matrix(matrix_a_new, size);

	/*
	cout << endl << "II. ���������� ������� f(f(A))=2*f(A)^3-2*f(A)^2-f(A) " << endl << endl;
	matrix_res = polynominal_in_matrix(matrix_A_stroke, size);
	*/

	//���������� f(B`) � ����� ������������� �����������
	cout << "I. ���������� ������� f(B * A)=2*B_new^3-2*B_new^2-B_new " << endl << endl;
	matrix_B_stroke = polynominal_in_matrix(matrix_b_new, size);

	//����� ������
	cout << endl << endl << "������� A` : " << endl;
	output(matrix_A_stroke, size);

	cout << endl << endl << "������� B` : " << endl;
	output(matrix_B_stroke, size);

	//�������� ������� �� ���������������
	matrix_orthogonality_checker(matrix_A_stroke, size);
	//������� ���������� ��������� 5*� + �*� = � � ������������� �������
	double** matrix_equation = create_zero_matrix(size); //���������� ������� ��� ������
	matrix_equation = equation_solution(matrix_A_stroke, matrix_B_stroke, size);

	//������� ������
	free(matrix_a, size);
	free(matrix_b, size);
	free(matrix_b_new, size);
	free(matrix_a_new, size);
	free(matrix_A_stroke, size);
	free(matrix_B_stroke, size);
	free(matrix_equation, size);

	return 0;
}