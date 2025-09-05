#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Выводит матрицу на экран
 * @param mat Матрица для вывода
 * @param rows Количество строк в матрице
 * @param cols Количество столбцов в матрице
 */
void mat_output(float mat[max_size][max_size], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
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
            mat[i][j] = 1.0 * rand() / RAND_MAX * 200 - 100;
        }
    }
}


/**
 * @brief Ищет наибольшее значение из элементов в области под побочной диагональю(включая элементы на диагонали)
 * @param mat Квадратная матрица действительных чисел
 * @param n Порядок матрицы
 */
float mat_max(float mat[max_size][max_size], unsigned n){
    float max_mat = mat[0][n];
    for (unsigned i = 0; i < n; ++i){
        for (unsigned j = 0; j < n; ++j){
            //n-i-1:побочная диагональ
            if ( (j >= n - i - 1) && (mat[i][j] > max_mat) )
            max_mat = mat[i][j];
        }
    } 
    return max_mat;  
}