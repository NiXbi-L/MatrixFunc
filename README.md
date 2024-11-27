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

### `int getRandomNumber(int min, int max)`

Генерирует случайное число в заданном диапазоне.

- **Параметры:**
  - `min` (int): Минимальное значение диапазона.
  - `max` (int): Максимальное значение диапазона.
- **Возвращает:**
  - Случайное число в заданном диапазоне.
- **Коды выхода:**
  - **4** - Если `min` больше `max`.

### `int* matrix_get_num(Matrix* matrix, int x, int y)`

Получает значение элемента матрицы по заданным координатам.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
  - `x` (int): Координата столбца.
  - `y` (int): Координата строки.
- **Возвращает:**
  - Указатель на элемент матрицы.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

### `void matrix_fill(Matrix* matrix, int fill_num)`

Заполняет матрицу заданным значением.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
  - `fill_num` (int): Значение для заполнения.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

### `Matrix* matrix_create(int rows, int columns, int fill_num)`

Создает новую матрицу с заданным количеством строк и столбцов. Если `fill_num` не равен `NULL`, матрица будет заполнена этим значением.

- **Параметры:**
  - `rows` (int): Количество строк.
  - `columns` (int): Количество столбцов.
  - `fill_num` (int): Значение для заполнения.
- **Возвращает:**
  - Указатель на созданную матрицу.
- **Коды выхода:**
  - **2** - Если `rows` или `columns` меньше или равны 0.

### `void matrix_fill_rand(Matrix* matrix, int max, const int min)`

Заполняет матрицу случайными числами в заданном диапазоне.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
  - `max` (int): Максимальное значение диапазона.
  - `min` (int): Минимальное значение диапазона.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.
  - **4** - Если `min` больше `max`.

### `Matrix* matrix_addition(Matrix* matrixA, Matrix* matrixB)`

Складывает две матрицы одинакового размера.

- **Параметры:**
  - `matrixA` (Matrix*): Указатель на первую матрицу.
  - `matrixB` (Matrix*): Указатель на вторую матрицу.
- **Возвращает:**
  - Указатель на результирующую матрицу.
- **Коды выхода:**
  - **3** - Если `matrixA` или `matrixB` равны `NULL`.
  - **5** - Если размеры матриц не совпадают.

### `Matrix* matrix_multiplication(Matrix* A, Matrix* B)`

Умножает две матрицы.

- **Параметры:**
  - `A` (Matrix*): Указатель на первую матрицу.
  - `B` (Matrix*): Указатель на вторую матрицу.
- **Возвращает:**
  - Указатель на результирующую матрицу.
- **Коды выхода:**
  - **3** - Если `A` или `B` равны `NULL`.
  - **5** - Если количество столбцов матрицы `A` не равно количеству строк матрицы `B`.

### `void matrix_clear(Matrix* matrix)`

Освобождает память, выделенную под матрицу.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

### `Matrix* matrix_copy(Matrix* matrix)`

Создает копию заданной матрицы.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
- **Возвращает:**
  - Указатель на копию матрицы.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

### `Matrix* matrix_transpiration(Matrix* matrix)`

Транспонирует матрицу.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
- **Возвращает:**
  - Указатель на транспонированную матрицу.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

### `void matrix_print(Matrix* matrix, int Indent)`

Выводит матрицу на экран. Второй аргумент определяет количество пробелов перед выводом строк матрицы, кроме первой.

- **Параметры:**
  - `matrix` (Matrix*): Указатель на матрицу.
  - `Indent` (int): Количество пробелов перед выводом строк.
- **Коды выхода:**
  - **3** - Если `matrix` равен `NULL`.

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
```bash
Matrix m5 = | 4 5 4 |
            | 2 1 1 |
```

### Сложение матриц

```c
Matrix* m1 = matrix_create(3, 3, NULL);
Matrix* m2 = matrix_create(3, 3, NULL);
matrix_fill_rand(m1, 10, 1);
matrix_fill_rand(m2, 10, 1);
Matrix* m3 = matrix_addition(m1, m2);
printf("Matrix m3 = ");
matrix_print(m3, sizeof("Matrix m3 = ") - 1);
```

### Умножение матриц

```c
Matrix* m4 = matrix_create(2, 3, NULL);
Matrix* m5 = matrix_create(3, 2, NULL);
matrix_fill_rand(m4, 5, 1);
matrix_fill_rand(m5, 5, 1);
Matrix* m6 = matrix_multiplication(m4, m5);
printf("Matrix m6 = ");
matrix_print(m6, sizeof("Matrix m6 = ") - 1);
```

### Транспонирование матрицы

```c
Matrix* m7 = matrix_create(2, 3, NULL);
matrix_fill_rand(m7, 5, 1);
printf("Matrix m7 before transposition = ");
matrix_print(m7, sizeof("Matrix m7 before transposition = ") - 1);
m7 = matrix_transpiration(m7);
printf("Matrix m7 after transposition = ");
matrix_print(m7, sizeof("Matrix m7 after transposition = ") - 1);
```

### Копирование матрицы

```c
Matrix* m8 = matrix_create(3, 3, NULL);
matrix_fill_rand(m8, 10, 1);
Matrix* m9 = matrix_copy(m8);
printf("Matrix m9 (copy of m8) = ");
matrix_print(m9, sizeof("Matrix m9 (copy of m8) = ") - 1);
```

### Заполнение матрицы константой

```c
Matrix* m10 = matrix_create(2, 2, NULL);
matrix_fill(m10, 7);
printf("Matrix m10 filled with 7 = ");
matrix_print(m10, sizeof("Matrix m10 filled with 7 = ") - 1);
```

### Получение элемента матрицы

```c
Matrix* m11 = matrix_create(2, 2, NULL);
matrix_fill_rand(m11, 10, 1);
int* element = matrix_get_num(m11, 1, 1);
printf("Element at (1, 1) in m11 = %d\n", *element);
```
