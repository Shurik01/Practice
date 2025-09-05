#include <stdio.h>
#include <math.h>       // математический модуль
#include "file.h"


/*
 * Автор: Пархоменко Александра
 * Задача: Дано натуральное n. Записать в файл g целые числа b 1 , ..., b n , 
 * определенные так, как указано в задачах а)-д) задачи 139.(bn = 2^(i+1))
 */

int main() {
    int n;

    char file_num[] = "num_data.txt";

    printf("Введите n\n");
    scanf("%i", &n);
    // заполнение файла числами
    file_fill(file_num, n);   
    
    return 0;
}