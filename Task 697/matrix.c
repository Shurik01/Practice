/*
 * Автор: Пархоменко А. В.
 * Задача: Даны матрицы А и В размера k x m и m x l соответственно. Найти произведение АВ.
 */

#include <stdio.h>
#include <math.h>       // математический модуль
#include <stdlib.h>
#include <time.h>

// Максимальный размер матрицы
const unsigned max_size = 100;

/**
 * @brief Находит произведение матриц A и B
 * @param mat_A Матрица размером k x m
 * @param mat_B Матрица размером m x l
 * @param mat_AB Результирующая матрица размером k x l
 * @param k Количество строк в матрице A
 * @param m Количество столбцов в матрице A и строк в матрице B
 * @param l Количество столбцов в матрице B 
 */
void mat_multiplication(float mat_A[max_size][max_size], 
                        float mat_B[max_size][max_size], 
                        float mat_AB[max_size][max_size], 
                        unsigned k, unsigned m, unsigned l) {
    for ( unsigned i = 0; i < k; ++i ) {
        for ( unsigned j = 0; j < l; ++j ) {
            mat_AB[i][j] = 0;
            for ( unsigned n = 0; n < m; ++n ) {
                mat_AB[i][j] += mat_A[i][n] * mat_B[n][j];
            }
        }
    }
}

/**
 * @brief Выводит матрицу на экран
 * @param mat Матрица для вывода
 * @param rows Количество строк в матрице
 * @param cols Количество столбцов в матрице
 */
void mat_output(float mat[max_size][max_size], unsigned rows, unsigned cols) {
    for ( unsigned i = 0; i < rows; ++i ) {
        for ( unsigned j = 0; j < cols; ++j ) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Заполняет матрицу случайными значениями в диапазоне [-100, 100]
 * @param mat Матрица для заполнения
 * @param rows Количество строк в матрице
 * @param cols Количество столбцов в матрице
 */
void mat_random(float mat[max_size][max_size], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
             /*RAND_MAX - это константа, определенная в стандартной библиотеке C 
            rand() возвращает число от 0 до RAND_MAX; 1.0 * rand() / RAND_MAX дает число от 0.0 до 1.0
            *200 расширяет диапазон до [0, 200]; - 100 сдвигает диапазон до [-100, 100]*/
            mat[i][j] = (float)rand() / RAND_MAX * 200.0f - 100.0f;
        }
    }
}

int main() {
    srand(time(NULL));  // инициализация генератора случайных чисел

    float mat_A[max_size][max_size];    // матрица A
    float mat_B[max_size][max_size];    // матрица B
    float mat_AB[max_size][max_size];   // результат A * B

    unsigned k, m, l;  // размеры матриц

    printf("Программа умножения матриц A(k x m) и B(m x l)\n");

    // Ввод размеров матриц
    printf("Введите количество строк матрицы A (k): ");
    scanf("%u", &k);
    printf("Введите количество столбцов матрицы A и строк матрицы B (m): ");
    scanf("%u", &m);
    printf("Введите количество столбцов матрицы B (l): ");
    scanf("%u", &l);

    // Заполнение матриц случайными числами
    mat_random(mat_A, k, m);
    mat_random(mat_B, m, l);

    // Вывод исходных матриц
    printf("\nМатрица A (%u x %u):\n", k, m);
    mat_output(mat_A, k, m);

    printf("Матрица B (%u x %u):\n", m, l);
    mat_output(mat_B, m, l);

    // Умножение матриц
    mat_multiplication(mat_A, mat_B, mat_AB, k, m, l);

    // Вывод результата
    printf("Результат умножения (A * B)");

    mat_output(mat_AB, k, l);

    return 0;
}