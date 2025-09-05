//для предотвращения многократного включения одного и того же заголовочного файла.
#ifndef MATRIX_H
#define MATRIX_H

#define max_size 100

/* Автор: Пархоменко А.В.
 * Модуль для работы с матрицей.
 */


/**
 * @brief Выводит матрицу на экран
 * @param mat Матрица для вывода
 * @param rows Количество строк в матрице
 * @param cols Количество столбцов в матрице
 */
void mat_output(float mat[max_size][max_size], unsigned rows, unsigned cols);


/**
 * @brief Заполняет матрицу случайными значениями в диапазоне [-100, 100]
 * @param mat Матрица для заполнения
 * @param rows Количество строк в матрице
 * @param cols Количество столбцов в матрице
 */
void mat_random(float mat[max_size][max_size], unsigned rows, unsigned cols);

/**
 * @brief Ищет наибольшее значение из элементов в области под побочной диагональю(включая элементы на диагонали)
 * @param mat Квадратная матрица действительных чисел
 * @param n Порядок матрицы
 */
float mat_max(float mat[max_size][max_size], unsigned n);
#endif