#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ����� ������� �� �����
void print_matrix(int** matrix, int y_size, int x_size) {
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

// ������������� ������� ��������� ������� � ���������� � ������
int** allocate_matrix(int y_size, int x_size)
{
	int** matrix = new int*[y_size];
	for (int i = 0; i < y_size; i++)
	{
		matrix[i] = new int[x_size];
		for (int j = 0; j < x_size; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

// ����������� �������� �� source_matrix � destination_matrix �� ��������� �� delta_x � delta_y
void copy_matrix(int** destination_matrix, int** source_matrix, int y_size, int x_size, int delta_y = 0, int delta_x = 0)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			destination_matrix[i][j] = source_matrix[i + delta_y][j + delta_x];
	}
}

// ������ ������� ����� �������� �������
void manual_matrix_fill(int** matrix, int y_size, int x_size)
{
	for(int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			cin >> matrix[i][j];
	}
}

// ���������� ������� ���������� �������
void random_matrix_fill(int** matrix, int y_size, int x_size)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			matrix[i][j] = rand() % 10;
	}
}


void main()
{
	srand(time(NULL));
	int y_size1, x_size1, y_size2, x_size2, decision, length = 2;
	system("chcp 1251");
	cout << "��� ������������ ���������" << endl <<
		"�������� ������������ ������ ������� ���������\n\n";

	//���� �������� ������� �������������
	
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> y_size1 >> x_size1;
	} while (y_size1 <= 0 || x_size1 <= 0);
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> y_size2 >> x_size2;
	} while (y_size2 <= 0 || x_size2 <= 0);

	int** first_prior_matrix = allocate_matrix(y_size1, x_size1);
	int** second_prior_matrix = allocate_matrix(y_size2, x_size2);

	//����� ������� ���������� � ���������� ������
	
	do
	{
		cout << "�������� ������ ���������� ������\n" <<
			"1 - ������� \n2 - ��������� �������\n";
		cin >> decision;
	} while (decision < 1 || decision > 2);
	switch (decision)
	{
	case 1:
		manual_matrix_fill(first_prior_matrix, y_size1, x_size1);
		manual_matrix_fill(second_prior_matrix, y_size2, x_size2);

		cout << "\n������� 1\n\n";
		print_matrix(first_prior_matrix, y_size1, x_size1);

		cout << "\n������� 2\n\n";
		print_matrix(second_prior_matrix, y_size2, x_size2);

		break;
	case 2:
		random_matrix_fill(first_prior_matrix, y_size1, x_size1);
		random_matrix_fill(second_prior_matrix, y_size2, x_size2);
		
		cout << "\n������� 1\n\n";
		print_matrix(first_prior_matrix, y_size1, x_size1);

		cout << "\n������� 2\n\n";
		print_matrix(second_prior_matrix, y_size2, x_size2);

		break;
	}

	//���������� ������ � ���������� �������
	
	while (length < y_size1 || length < y_size2 || length < x_size1 || length < x_size2)
		length *= 2;
	int** first_reduced_matrix = allocate_matrix(length, length);
	copy_matrix(first_reduced_matrix, first_prior_matrix, y_size2, x_size2);

	int** second_reduced_matrix = allocate_matrix(length, length);
	copy_matrix(second_reduced_matrix, second_prior_matrix, y_size2, x_size2);

	cout << "����������� �������\n";
	cout << "\n������� 1\n\n";
	print_matrix(first_reduced_matrix, length, length);

	cout << "\n������� 2\n\n";
	print_matrix(second_reduced_matrix, length, length);

	int half_length = length / 2;

	//��������� ������ �� ���������� � �� ����������
	/*****
	 *1 2*
	 *3 4*
	 *****/
	
	int** first_submatrix1 = allocate_matrix(half_length, half_length);
	copy_matrix(first_submatrix1, first_reduced_matrix, half_length, half_length);

	int** first_submatrix2 = allocate_matrix(half_length, half_length);
	copy_matrix(first_submatrix2, first_reduced_matrix, half_length, half_length, 0, half_length);

	int** first_submatrix3 = allocate_matrix(half_length, half_length);
	copy_matrix(first_submatrix3, first_reduced_matrix, half_length, half_length, half_length);

	int** first_submatrix4 = allocate_matrix(half_length, half_length);
	copy_matrix(first_submatrix4, first_reduced_matrix, half_length, half_length, half_length, half_length);

	int** second_submatrix1 = allocate_matrix(half_length, half_length);
	copy_matrix(second_submatrix1, second_reduced_matrix, half_length, half_length);

	int** second_submatrix2 = allocate_matrix(half_length, half_length);
	copy_matrix(second_submatrix2, second_reduced_matrix, half_length, half_length, 0, half_length);

	int** second_submatrix3 = allocate_matrix(half_length, half_length);
	copy_matrix(second_submatrix3, second_reduced_matrix, half_length, half_length, half_length);

	int** second_submatrix4 = allocate_matrix(half_length, half_length);
	copy_matrix(second_submatrix4, second_reduced_matrix, half_length, half_length, half_length, half_length);

	//�������� ������������� ������

	int** intermediate_matrix1 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix2 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix3 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix4 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix5 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix6 = allocate_matrix(half_length, half_length);
	int** intermediate_matrix7 = allocate_matrix(half_length, half_length);

	//���������� �������� ������������� ������

	for (int i = 0; i < half_length; i++)
	{
		for (int j = 0; j < half_length; j++)
		{
			intermediate_matrix1[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix1[i][j] += (first_submatrix1[i][z] + first_submatrix4[i][z]) * (second_submatrix1[z][j] + second_submatrix4[z][j]);
			}

			intermediate_matrix2[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix2[i][j] += (first_submatrix3[i][z] + first_submatrix4[i][z]) * second_submatrix1[z][j];
			}

			intermediate_matrix3[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix3[i][j] += first_submatrix1[i][z] * (second_submatrix2[z][j] - second_submatrix4[z][j]);
			}

			intermediate_matrix4[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix4[i][j] += first_submatrix4[i][z] * (second_submatrix3[z][j] - second_submatrix1[z][j]);
			}

			intermediate_matrix5[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix5[i][j] += (first_submatrix1[i][z] + first_submatrix2[i][z]) * second_submatrix4[z][j];
			}

			intermediate_matrix6[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix6[i][j] += (first_submatrix3[i][z] - first_submatrix1[i][z]) * (second_submatrix1[z][j] + second_submatrix2[z][j]);
			}

			intermediate_matrix7[i][j] = 0;
			for (int z = 0; z < half_length; z++)
			{
				intermediate_matrix7[i][j] += (first_submatrix2[i][z] - first_submatrix4[i][z]) * (second_submatrix3[z][j] + second_submatrix4[z][j]);
			}
		}
	}

	//�������� ��������������� ������
	
	int** auxiliary_�atrix1 = allocate_matrix(half_length, half_length);
	int** auxiliary_matrix2 = allocate_matrix(half_length, half_length);
	int** auxiliary_matrix3 = allocate_matrix(half_length, half_length);
	int** auxiliary_matrix4 = allocate_matrix(half_length, half_length);


	//������� �������� ��������������� ������ �� �������������
	
	for (int i = 0; i < half_length; i++)
	{
		for (int j = 0; j < half_length; j++)
		{
			auxiliary_�atrix1[i][j] = intermediate_matrix1[i][j] + intermediate_matrix4[i][j] - intermediate_matrix5[i][j] + intermediate_matrix7[i][j];
			auxiliary_matrix2[i][j] = intermediate_matrix3[i][j] + intermediate_matrix5[i][j];
			auxiliary_matrix3[i][j] = intermediate_matrix2[i][j] + intermediate_matrix4[i][j];
			auxiliary_matrix4[i][j] = intermediate_matrix1[i][j] - intermediate_matrix2[i][j] + intermediate_matrix3[i][j] + intermediate_matrix6[i][j];
		}
	}

	//�������� �������������� �������
	
	int** result_matrix = allocate_matrix(length, length);

	//��������� ���������� �� ��������������� ������ � ��������������
	
	for (int i = 0; i < half_length; i++)
	{
		for (int j = 0; j < half_length; j++)
		{
			result_matrix[i][j] = auxiliary_�atrix1[i][j];
			result_matrix[i][j + half_length] = auxiliary_matrix2[i][j];
			result_matrix[i + half_length][j] = auxiliary_matrix3[i][j];
			result_matrix[i + half_length][j + half_length] = auxiliary_matrix4[i][j];
		}
	}

	//������������ ������ �������������� �������
	
	int flag = 0, result_y_size = 100, result_x_size = 100;
	for (int i = 0; i < length; i++)
	{
		flag = 0;
		for (int j = 0; j < length; j++)
		{
			if (result_matrix[i][j] != 0)
			{
				flag++;
				result_y_size = 100;
			}
		}
		if (flag == 0 && i < result_y_size)
		{
			result_y_size = i;
		}
	}

	for (int i = 0; i < length; i++)
	{
		flag = 0;
		for (int j = 0; j < length; j++)
		{
			if (result_matrix[j][i] != 0)
			{
				flag++;
				result_x_size = 100;
			}
		}
		if (flag == 0 && i < result_x_size)
		{
			result_x_size = i;
		}
	}

	int** reduced_result_matrix = allocate_matrix(result_y_size, result_x_size);
	copy_matrix(reduced_result_matrix, result_matrix, result_y_size, result_x_size);

	//����� �������������� �������

	cout << "\n�������������� �������\n\n";
	print_matrix(reduced_result_matrix, result_y_size, result_x_size);

	system("pause");
	//������� ������������ ������

	for (int i = 0; i < y_size1; i++)
		delete[] first_prior_matrix[i];
	for (int i = 0; i < y_size2; i++)
		delete[] second_prior_matrix[i];
	for (int i = 0; i < length; i++)
	{
		delete[] first_reduced_matrix[i];
		delete[] second_reduced_matrix[i];
		delete[] result_matrix[i];
	}
	for (int i = 0; i < result_y_size; i++)
		delete[] reduced_result_matrix[i];
	for (int i = 0; i < half_length; i++)
	{
		delete[] first_submatrix1[i];
		delete[] first_submatrix2[i];
		delete[] first_submatrix3[i];
		delete[] first_submatrix4[i];
		delete[] second_submatrix1[i];
		delete[] second_submatrix2[i];
		delete[] second_submatrix3[i];
		delete[] second_submatrix4[i];
		delete[] auxiliary_�atrix1[i];
		delete[] auxiliary_matrix2[i];
		delete[] auxiliary_matrix3[i];
		delete[] auxiliary_matrix4[i];
		delete[] intermediate_matrix1[i];
		delete[] intermediate_matrix2[i];
		delete[] intermediate_matrix3[i];
		delete[] intermediate_matrix4[i];
		delete[] intermediate_matrix5[i];
		delete[] intermediate_matrix6[i];
		delete[] intermediate_matrix7[i];
	}
	delete[] first_prior_matrix, second_prior_matrix, first_reduced_matrix, second_reduced_matrix, result_matrix, reduced_result_matrix;
	delete[] first_submatrix1, first_submatrix2, first_submatrix3, first_submatrix4,
	delete[] second_submatrix1, second_submatrix2, second_submatrix3, second_submatrix4,
	delete[] auxiliary_�atrix1, auxiliary_matrix2, auxiliary_matrix3, auxiliary_matrix4;
	delete[] intermediate_matrix1, intermediate_matrix2, intermediate_matrix3, intermediate_matrix4, intermediate_matrix5, intermediate_matrix6, intermediate_matrix7;
}
