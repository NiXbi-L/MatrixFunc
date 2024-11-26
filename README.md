# MatrixFunc

MatrixFunc - это библиотека для работы с матрицами в языке программирования C. Она предоставляет функции для создания, заполнения, вывода, а также для выполнения основных операций над матрицами, таких как сложение, умножение и транспонирование.

## Коды выхода

- **2** - Incorrect size when creating the matrix (Неправильный размер при создании матрицы)
- **3** - Matrix cannot be NULL (Матрица не может быть NULL)
- **4** - Incorrect rand range (Неправильный диапазон генератора случайных чисел)
- **5** - Matrix size error (Ошибка в размере матрицы)

## Структура матрицы

```c
typedef struct Matrix {
    int** matrix_body;
    int columns;
    int rows;
} Matrix;
```

## Функции библиотеки

- **`int* matrix_get_num (Matrix* matrix, int x, int y)`**  
  Получает значение элемента матрицы по заданным координатам.

- **`void matrix_fill (Matrix* matrix, int fill_num)`**  
  Заполняет матрицу заданным значением.

- **`Matrix* matrix_create (int rows, int columns, int fill_num)`**  
  Создает новую матрицу с заданным количеством строк и столбцов. Если `fill_num` не равен `NULL`, матрица будет заполнена этим значением.

- **`void matrix_fill_rand (Matrix* matrix, int max, const int min)`**  
  Заполняет матрицу случайными числами в заданном диапазоне.

- **`Matrix* matrix_addition (Matrix* matrixA, Matrix* matrixB)`**  
  Складывает две матрицы одинакового размера.

- **`Matrix* matrix_multiplication (Matrix* A, Matrix* B)`**  
  Умножает две матрицы.

- **`void matrix_clear (Matrix* matrix)`**  
  Освобождает память, выделенную под матрицу.

- **`Matrix* matrix_copy (Matrix* matrix)`**  
  Создает копию заданной матрицы.

- **`void matrix_transpiration (Matrix* matrix)`**  
  Транспонирует матрицу.

- **`void matrix_print (Matrix* matrix, int Indent)`**  
  Выводит матрицу на экран. Второй аргумент определяет количество пробелов перед выводом строк матрицы, кроме первой.

## Примеры использования

### Создание матрицы

```c
// Создание матрицы
Matrix* M = matrix_create(3, 3, NULL); // Выделение памяти под матрицу
Matrix* M = matrix_create(2, 3, 5);    // Выделение памяти под матрицу и заполнение ее пятерками
```

### Случайное заполнение

```c
matrix_fill_rand(m2, 5, NULL); 
matrix_fill_rand(m2, 5, 0); // Алгоритм работы разный, но результат один и тот же
```

### Вывод матрицы

```c
printf("Matrix m5 = ");
matrix_print(m5, sizeof("Matrix m5 = ") - 1); // 2 аргументом передается количество пробелов перед выводом строк матрицы кроме первой.
```
