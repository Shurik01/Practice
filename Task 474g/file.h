#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <math.h>       // математический модуль

/*Автор: Пархоменко А.В.
 * Модуль для работы с файлами.*/

/// @brief заполняет текстовый файл с именем fname n числами, равными 2^(i+1), i = 1, 2, ..., n
/// @param fname имя файла
/// @param n количество чисел
void file_fill(char fname[], int n);

#endif