//������� ��������� ���-13��
//������������ ������ �6. ������ � ���������
//
//������� 3. ��������� ���������
//������� 10. 

#include<iostream>
#include <iomanip>
#include<cmath>
#include"matrix_operation.h"
using namespace std;

//�������� ������������ ����� ������� �������
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
	cout << "������� ���������� ��������� 5*� + �*� = �" << endl;
	int size;
	double det;
	cout << endl << "������� ������ ���������� ������: ";
	size = natural_number_check();
	cout << endl;
	double** matrix_a;
	double** matrix_b;
	double** matrix_x;

	//�������� ������ ��� ����������
	cout << "������� ������� �: " << endl;
	matrix_a = input_matrix(size);
	cout << "������� ������� �: " << endl;
	matrix_b = input_matrix(size);
	matrix_x = create_zero_matrix(size);

	//������� ��������� � ��������� �������
	cout << "����������� ��������� � ���� �(5� + �) = � " << endl;
	cout << "5� = " << endl;
	double** identity_matrix = create_identity_matrix(size);
	identity_matrix = matrix_multiplication_by_number(identity_matrix, 5, size);
	output(identity_matrix, size);

	cout << endl << "5� + � = " << endl;
	matrix_a = sum_of_matrices(matrix_a, identity_matrix, size);
	output(matrix_a, size);

	cout << endl << "��� ������� � �� ������������ ����� ����� �������� ������� � 5� + �" << endl;
	det = calculating_determinant(matrix_a, size);
	if (det == 0)
		cout << "���������� ����������" << endl;
	else {
		matrix_a = create_inverse_matrix(matrix_a, size);
		output(matrix_a, size);

		cout << endl << endl << "������� �� �������� ������� ������� �" << endl;
		cout << "�����: " << endl;
		matrix_x = matrix_multiplication_by_matrix(matrix_a, matrix_b, size);
	}

	//����� ������
	output(matrix_x, size);

	//������� ������
	free(matrix_a, size);
	free(matrix_b, size);
	free(matrix_x, size);;
	system("pause");
	return 0;
}