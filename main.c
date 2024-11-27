#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Header.h"

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != '\0');
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

