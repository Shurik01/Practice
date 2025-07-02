#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <time.h> 

/* Автор: Пархоменко А.В.
 * Задача: Даны натуральное число n, целые числа a1,..., a25, b1,..., bn. 
 Среди a1,..., a25 нет повторяющихся чисел, нет их и среди b1,..., bn.
 Получить все члены последовательности b1,..., bn, которые не входят в последовательность a1,..., a25.
 */

/* @brief создает массив из членов последовательности b1, ..., bn, которые не входят в последовательность a1, ..., a25
@param arr_a: статистический массив из 25 целых чисел
@param arr_b: динамический массив целых чисел
@param new_arr: динамический массив, в который записываются члены arr_a, которые не входят в arr_b
@param size: размер массива b
@return номер числа в массиве*/
void create_arr(int arr_a[25], int *arr_b, int*new_arr, unsigned size){
  int num = 0;
  boolean flag = 0;
  for (unsigned i = 0; i < size; ++i){
    for (unsigned j = 0; j < 25; ++j){
        if (arr_b[i] == arr_a[j]){
            flag = 1;
        }
    if (flag == 0){
       new_arr[num] = arr_b[i];
       ++num; 
    }
    flag = 0;
    }
  }
}

/* @brief функция для вывода массива 
@param arr: динамический массив целых чисел
*/
void arr_output(int *arr, unsigned size){
     for (unsigned i = 0; i < size; ++i) {
        printf( "%d  ",arr[i]);
     }
}
/* @brief функция для заполнения массива случайными целыми числами от -100 до 100
@param arr: динамический массив целых чисел
@param size: размер массива*/
void arr_rand(int *arr, unsigned size){
  for (unsigned i = 0; i < size; ++i) {
    arr[i] = rand() % 200 - 100;
  }
}
int main() {
srand(time(NULL));

const unsigned size_a = 25;
int arr_a[size_a];
int *arr_b; // указатель на массив
int *arr_res;
unsigned size_b; //количество элементов в массиве
int a; //число, которое ищем в массиве
printf("Даны натуральное число n, целые числа a1,..., a25, b1,..., bn.\nСреди a1,..., a25 нет повторяющихся чисел, нет их и среди b1,..., bn.\nПолучить все члены последовательности b1,..., bn, которые не входят в последовательность a1,..., a25.\n");
printf("Введите размер массива: \n");
scanf("%u", &size_b);
// выделение памяти под динамический массив: n * sizeof (int) байт
arr_b = malloc(size_b * sizeof(int));
arr_res = malloc(size_b * sizeof(int));
printf("Массив, состоящий из n элементов:\n");
arr_rand(arr, n);
arr_output(arr, n);
printf("\n");
printf("Введите a (число, номер которого хотите найти)\n");
scanf("%d", &a);
// номер числа в массиве
int num = arr_find(arr, n, a);
if (num > 0) {
printf("Член в последовательности x1, ..., xn, равный a, идет под номером: %d", arr_find(arr, n, a));
}
else {printf("Такого члена нет в последовательности");
}


//очищаем память
free(arr);
return 0;

}