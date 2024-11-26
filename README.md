# MatrixFunc
Exit codes
2 - Incorrect size when creating the matrix (Неправильный размер при создании матрицы)
3 - Matrix cannot be NULL (Матрица не может быть NULL)
4 - Incorrect rand range (Неправильный диапазон генератора случайных чисел)
5 - Matrix size error (Ошибка в размере матрицы)
===========================================


#Структура матрицы
===========================================
typedef struct Matrix {
	int** matrix_body;
	int columns;
	int rows;
} Matrix;
===========================================


#Функции библиотеки
===========================================
int* matrix_get_num (Matrix* matrix, int x, int y)\n
void matrix_fill (Matrix* matrix, int fill_num)
Matrix* matrix_create (int rows, int columns, int fill_num)
void matrix_fill_rand (Matrix* matrix, int max, const int min)
Matrix* matrix_addition (Matrix* matrixA, Matrix* matrixB)
Matrix* matrix_multiplication (Matrix* A, Matrix* B)
void matrix_clear (Matrix* matrix)
Matrix* matrix_copy (Matrix* matrix)
void matrix_transpiration (Matrix* matrix)
void matrix_print (Matrix* matrix, int Indent)
===========================================

#Примеры
===========================================
//Создание матрицы
Matrix* M = matrix_create(3, 3, NULL); - Функция выделит память под матрицу
Matrix* M = matrix_create(2, 3, 5); - Функция выделит память под матрицу и заполнит ее пятерками

//Случайное заполнение
matrix_fill_rand(m2, 5, NULL); 
matrix_fill_rand(m2, 5, 0); - Алгоритм работы разный, но результат один и тот же

//Вывод матрицы
printf("Matrix m5 = ");
matrix_print(m5, sizeof("Matrix m5 = ") - 1); - 2 аргументом передается количество пробелов перед выводом строк матрицы кроме первой.
===========================================

