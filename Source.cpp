#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable: 4996)

typedef struct Matrix {
	int** matrix_body;
	int columns;
	int rows;
} Matrix;

//lib func
int getRandomNumber(int min, int max) {
	if (min > max) {
		exit(4);
	}
	else
	{
		if (min != NULL) {
			return min + rand() % (max - min + 1);
		}
		else {
			return rand() % max;
		}
	}
};

int* matrix_get_num(Matrix* matrix, int x, int y) {
	if (matrix == NULL) {
		exit(3);
	}
	else {
		return &((matrix->matrix_body)[y][x]);
	}
}

void matrix_fill(Matrix* matrix, int fill_num) {
	if (matrix == NULL) {
		exit(3);
	}
	else {
		for (int y = 0; y < matrix->columns; y++) {
			for (int x = 0; x < matrix->rows; x++) {
				*matrix_get_num(matrix, x, y) = fill_num;
			}
		}
	}
}
Matrix* matrix_create(int rows, int columns, int fill_num) {
	if (rows <= 0 || columns <= 0) {
		exit(2);
	}
	else
	{
		Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
		matrix->rows = rows;
		matrix->columns = columns;

		matrix->matrix_body = (int**)malloc(rows * sizeof(int*));

		if (fill_num != 0) {

			for (int y = 0; y < rows; y++) {
				(matrix->matrix_body)[y] = (int*)malloc(columns * sizeof(int));
			};
			if (fill_num != NULL) {
				matrix_fill(matrix, fill_num);
			}
		}
		else {
			for (int y = 0; y < rows; y++) {
				(matrix->matrix_body)[y] = (int*)calloc(columns, sizeof(int));
			};
		}

		return matrix;
	}
}

void matrix_fill_rand(Matrix* matrix, int max, const int min) {
	if (matrix == NULL) {
		exit(3);
	}
	else
	{
		for (int y = 0; y < matrix->rows; y++) {
			for (int x = 0; x < matrix->columns; x++) {
				*matrix_get_num(matrix, x, y) = getRandomNumber(min, max);
			}
		}
	}

}
Matrix* matrix_addition(Matrix* matrixA, Matrix* matrixB) {
	if (matrixA == NULL || matrixB == NULL) exit(3);
	if (matrixA->rows != matrixB->rows && matrixA->columns != matrixB->columns) {
		exit(5);
	}
	else {
		Matrix* matrixC = matrix_create(matrixA->rows, matrixA->columns, NULL);
		for (int y = 0; y < matrixA->rows; y++) {
			for (int x = 0; x < matrixA->columns; x++) {
				*matrix_get_num(matrixC, x, y) = *matrix_get_num(matrixA, x, y) + *matrix_get_num(matrixB, x, y);
			}
		}
		return matrixC;
	}
}


Matrix* matrix_multiplication(Matrix* A, Matrix* B) {
	if (A == NULL || B == NULL) exit(3);
	if (A->columns != B->rows) {
		exit(5);
	}

	Matrix* result = matrix_create(A->rows, B->columns, NULL);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < B->columns; j++) {
			int sum = 0;
			for (int k = 0; k < A->columns; k++) {
				sum += *matrix_get_num(A, k, i) * *matrix_get_num(B, j, k);
			}
			*matrix_get_num(result, j, i) = sum;
		}
	}

	return result;
}

void matrix_clear(Matrix* matrix) {
	for (int y = 0; y < matrix->rows; y++) {
		free((matrix->matrix_body)[y]);
	}
	free(matrix->matrix_body);
	free(matrix);
}
Matrix* matrix_copy(Matrix* matrix) {
	if (matrix == NULL) exit(3);
	Matrix* copiedMatrix = matrix_create(matrix->rows, matrix->columns, NULL);
	for (int y = 0; y < copiedMatrix->rows; y++) {
		for (int x = 0; x < copiedMatrix->columns; x++) {
			*matrix_get_num(copiedMatrix, x, y) = *matrix_get_num(matrix, x, y);
		}
	}
	return copiedMatrix;
}

Matrix* matrix_transpiration(Matrix* matrix) {
	Matrix* newMatrix = matrix_create(matrix->columns, matrix->rows, NULL);
	for (int y = 0; y < newMatrix->rows; y++) {
		for (int x = 0; x < newMatrix->columns; x++) {
			*matrix_get_num(newMatrix, x, y) = *matrix_get_num(matrix, y, x);
		}
	}
	
	matrix_clear(matrix);
	return newMatrix;
}

void matrix_print(Matrix* matrix, int Indent) {
	if (matrix == NULL) {
		exit(3);
	}
	else
	{
		for (int y = 0; y < matrix->rows; y++) {
			for (int i = 0; i < Indent; i++) if (y != 0) printf(" ");
			printf("| ");
			for (int x = 0; x < matrix->columns; x++) {
				printf("%i ", *matrix_get_num(matrix, x, y));
			}
			printf("|\n");
		}
	}
}

//main func

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	srand(time(NULL));
	Matrix* m = matrix_create(3, 3, NULL);
	Matrix* m1 = matrix_create(3, 3, NULL);

	printf("Mattrix rand_fill + addition\n========================================================================\n");
	matrix_fill_rand(m, 20, 10);
	matrix_fill_rand(m1, 20, 10);
	printf("MatrixA = ");
	matrix_print(m, sizeof("MatrixA = ") - 1);
	printf("\nMatrixB = ");
	matrix_print(m1, sizeof("MatrixB = ") - 1);
	printf("\nMatrixC = ");
	matrix_print(matrix_addition(m, m1), sizeof("MatrixC = ") - 1);
	printf("========================================================================\n\n");

	printf("Mattrix rand_fill + multiplication\n========================================================================\n");
	Matrix* m2 = matrix_create(2, 3, NULL);
	Matrix* m3 = matrix_create(3, 2, NULL);

	matrix_fill_rand(m2, 5, 1);
	matrix_fill_rand(m3, 5, 1);

	printf("MatrixA = ");
	matrix_print(m2, sizeof("MatrixA = ") - 1);
	printf("\nMatrixB = ");
	matrix_print(m3, sizeof("MatrixB = ") - 1);
	printf("\nMatrixC = ");
	matrix_print(matrix_multiplication(m2, m3), sizeof("MatrixC = ") - 1);
	printf("========================================================================\n\n");

	printf("Mattrix m copy to m4\n========================================================================\n");
	Matrix* m4 = matrix_copy(m);
	printf("Matrix m4 = ");
	matrix_print(m4, sizeof("Matrix m4 = ") - 1);
	printf("========================================================================\n\n");

	printf("Mattrix rand_fill + transpiration\n========================================================================\n");
	Matrix* m5 = matrix_create(2, 3, NULL);
	matrix_fill_rand(m5, 5, 1);
	printf("Matrix m5 = ");
	matrix_print(m5, sizeof("Matrix m5 = ") - 1);
	m5 = matrix_transpiration(m5);
	printf("\nMatrix m5 = ");
	matrix_print(m5, sizeof("Matrix m5 = ") - 1);
	printf("========================================================================\n\n");

	return 0;
}
// Exit codes
// 2 - Incorrect size when creating the matrix
// 3 - Matrix not NULL
// 4 - Incorrect rand range
// 5 - Matrix size error