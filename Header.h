#pragma once
typedef struct Matrix {
	int** matrix_body;
	int columns;
	int rows;
} Matrix;

int getRandomNumber(int min, int max);
int* matrix_get_num(Matrix* matrix, int x, int y);
void matrix_fill(Matrix* matrix, int fill_num);
Matrix* matrix_create(int rows, int columns, int fill_num);
void matrix_fill_rand(Matrix* matrix, int max, const int min);
Matrix* matrix_addition(Matrix* matrixA, Matrix* matrixB);
Matrix* matrix_multiplication(Matrix* A, Matrix* B);
void matrix_clear(Matrix* matrix);
Matrix* matrix_copy(Matrix* matrix);
Matrix* matrix_transpiration(Matrix* matrix);
void matrix_print(Matrix* matrix, int Indent);
