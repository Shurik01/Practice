/*
 * Автор: Пархоменко А. В.
 * Задача: Дана действительная матрица размера n x m. Определить числа b1, ..., bm, равные соответственно:
 * разностям наибольших и наименьших значений элементов строк.
 */

#include <stdio.h>
#include <math.h>       // математический модуль
#include <stdlib.h>
#include <time.h>

 //Максимальное количество строк матрицы
const unsigned N = 100;

//Максимальное количество столбцов матрицы
const unsigned M = 100;

/**
 * @brief Вычисляет разность между максимальным и минимальным элементами каждой строки матрицы
 * @param mat Матрица размером N x M
 * @param size_line Количество строк в матрице
 * @param size_col Количество столбцов в матрице
 */
void mat_dif_max_min(float mat[N][M], unsigned size_line, unsigned size_col) {
    float mat_min;
    float mat_max;
    float mat_res;
    
    for (unsigned i = 0; i < size_line; ++i) {
        // Инициализация минимума и максимума для текущей строки
        mat_min = mat[i][0];
        mat_max = mat[i][0];
        
        for (unsigned j = 0; j < size_col; ++j) {
            // Поиск минимального элемента в строке
            if (mat[i][j] < mat_min)
                mat_min = mat[i][j];
            
            // Поиск максимального элемента в строке
            if (mat[i][j] > mat_max)
                mat_max = mat[i][j];
        }

        // Вычисление и вывод разности для текущей строки
        if (mat_min < 0) 
        mat_res = mat_max + mat_min;

        else
        mat_res = mat_max - mat_min;
        printf("b%u = %3.2f\n", i + 1, mat_res);
    }
}

/**
 * @brief Выводит матрицу на экран
 * @param mat Матрица для вывода
 * @param size_line Количество строк в матрице
 * @param size_col Количество столбцов в матрице
 */
void mat_output(float mat[N][M], unsigned size_line, unsigned size_col) {
    for (unsigned i = 0; i < size_line; ++i) {      // цикл по строкам
        for (unsigned j = 0; j < size_col; ++j) {   // цикл по столбцам
            printf("%6.2f  ", mat[i][j]);
        }
        printf("\n");  // переход на новую строку после вывода каждой строки матрицы
    }
}

/**
 * @brief Заполняет матрицу случайными значениями в диапазоне [-100, 100]
 * @param mat Матрица для заполнения
 * @param size_line Количество строк в матрице
 * @param size_col Количество столбцов в матрице
 */
void mat_random(float mat[N][M], unsigned size_line, unsigned size_col) {
    for (unsigned i = 0; i < size_line; ++i) {      // цикл по строкам
        for (unsigned j = 0; j < size_col; ++j) {   // цикл по столбцам
            mat[i][j] = 1.0 * rand() / RAND_MAX * 200 - 100;
        }
    }
}

/**
 * Главная функция программы
 * Запрашивает у пользователя размеры матрицы, заполняет ее случайными значениями,
 * выводит матрицу на экран, затем вычисляет и выводит разности между
 * максимальными и минимальными элементами каждой строки
 */
int main() {
    srand(time(NULL));  // инициализация генератора случайных чисел текущим временем
    
    float mat[N][M];    // матрица

    unsigned size_line; // количество строк
    unsigned size_col;  // количество столбцов

    printf("Дана действительная матрица размера n x m. Определить числа b1, ..., bm, равные соответственно:\n");
    printf("разностям наибольших и наименьших значений элементов строк.\n");

    printf("Задайте количество строк матрицы (n) \n");
    scanf("%u", &size_line);

    printf("Задайте количество столбцов матрицы (m) \n");
    scanf("%u", &size_col);

    printf("Исходные значения:\n");
    mat_random(mat, size_line, size_col);  // заполнение матрицы случайными значениями
    mat_output(mat, size_line, size_col);  // вывод матрицы

    printf("\nРезультат:\n");
    mat_dif_max_min(mat, size_line, size_col);  // вычисление и вывод разностей
   
    return 0;
}