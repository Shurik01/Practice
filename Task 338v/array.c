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
int create_arr(int arr_a[25], int *arr_b, int*new_arr, unsigned size){
  int num = 0;
  for (unsigned i = 0; i < size; ++i){
    boolean flag = 0;
    for (unsigned j = 0; j < 25; ++j){
        if (arr_b[i] == arr_a[j]){
            flag = 1;
            break;
        }
    }
    if (flag == 0)
       new_arr[num++] = arr_b[i];   
  }
  return num;
}

/* @brief функция для вывода массива 
@param arr: динамический массив целых чисел
*/
void arr_output(int *arr, unsigned size){
     for (unsigned i = 0; i < size; ++i) {
        printf( "%d  ",arr[i]);
     }
}

int main() {
srand(time(NULL));

const unsigned size_a = 25;
int arr_a[size_a]; //массив, содержащий последовательность a1,..., a25
int *arr_b; // указатель на массив
int *arr_res; //итоговый массив
unsigned size_res; //количество элементов в итоговом массиве
unsigned size_b; //количество элементов в массиве

printf("Даны натуральное число n, целые числа a1,..., a25, b1,..., bn.\nСреди a1,..., a25 нет повторяющихся чисел, нет их и среди b1,..., bn.\nПолучить все члены последовательности b1,..., bn, которые не входят в последовательность a1,..., a25.\n");

printf("Введите 25 элементов массива a\n");

for (unsigned i = 0; i < 25; ++i){
    scanf("%i", &arr_a[i]);
}

printf("Введите размер массива b: \n");

scanf("%u", &size_b);

// выделение памяти под динамический массив: n * sizeof (int) байт
arr_b = malloc(size_b * sizeof(int));
arr_res = malloc(size_b * sizeof(int));
printf("Введите %u элементов массива b:\n", size_b);
for (unsigned i = 0; i < size_b; ++i){
    scanf("%i", &arr_b[i]);
}

size_res = create_arr(arr_a, arr_b, arr_res, size_b);
arr_output(arr_res, size_res);

//очищаем память
free(arr_b);
free(arr_res);
return 0;

}